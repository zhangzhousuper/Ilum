#include "Queue.hpp"
#include "Command.hpp"
#include "Device.hpp"
#include "Synchronization.hpp"

namespace Ilum::Vulkan
{
Queue::Queue(RHIDevice *device, RHIQueueFamily family, uint32_t queue_index) :
    RHIQueue(device, family, queue_index)
{
	vkGetDeviceQueue(static_cast<Device *>(p_device)->GetDevice(), static_cast<Device *>(p_device)->GetQueueFamily(family), queue_index % static_cast<Device *>(p_device)->GetQueueCount(family), &m_handle);
}

void Queue::Wait()
{
	vkQueueWaitIdle(m_handle);
}

void Queue::Submit(const std::vector<RHICommand *> &cmds, const std::vector<RHISemaphore *> &signal_semaphores, const std::vector<RHISemaphore *> &wait_semaphores)
{
	SubmitInfo submit_info = {};

	submit_info.cmd_buffers.reserve(cmds.size());
	submit_info.signal_semaphores.reserve(submit_info.signal_semaphores.size() + signal_semaphores.size());
	submit_info.wait_semaphores.reserve(submit_info.wait_semaphores.size() + wait_semaphores.size());

	for (auto &cmd : cmds)
	{
		static_cast<Command *>(cmd)->SetState(CommandState::Pending);
		submit_info.cmd_buffers.push_back(static_cast<Command *>(cmd)->GetHandle());
	}
	for (auto &signal_semaphore : signal_semaphores)
	{
		submit_info.signal_semaphores.push_back(static_cast<Semaphore *>(signal_semaphore)->GetHandle());
	}
	for (auto &wait_semaphore : wait_semaphores)
	{
		submit_info.wait_semaphores.push_back(static_cast<Semaphore *>(wait_semaphore)->GetHandle());
	}

	m_submit_infos.emplace_back(std::move(submit_info));
}

void Queue::Execute(RHIFence *fence)
{
	if (m_submit_infos.empty())
	{
		return;
	}

	std::vector<VkSubmitInfo> vk_submit_infos;
	vk_submit_infos.reserve(m_submit_infos.size());

	std::vector<std::vector<VkPipelineStageFlags>> pipeline_stage_flags(m_submit_infos.size());

	for (uint32_t i = 0; i < m_submit_infos.size(); i++)
	{
		auto &submit_info = m_submit_infos[i];

		pipeline_stage_flags[i].resize(std::max(submit_info.wait_semaphores.size(), 1ull));
		std::fill(pipeline_stage_flags[i].begin(), pipeline_stage_flags[i].end(), VK_PIPELINE_STAGE_ALL_COMMANDS_BIT);

		VkSubmitInfo vk_submit_info = {};
		vk_submit_info.sType        = VK_STRUCTURE_TYPE_SUBMIT_INFO;

		vk_submit_info.commandBufferCount   = static_cast<uint32_t>(submit_info.cmd_buffers.size());
		vk_submit_info.pCommandBuffers      = submit_info.cmd_buffers.data();
		vk_submit_info.signalSemaphoreCount = static_cast<uint32_t>(submit_info.signal_semaphores.size());
		vk_submit_info.pSignalSemaphores    = submit_info.signal_semaphores.data();
		vk_submit_info.waitSemaphoreCount   = static_cast<uint32_t>(submit_info.wait_semaphores.size());
		vk_submit_info.pWaitSemaphores      = submit_info.wait_semaphores.data();
		vk_submit_info.pWaitDstStageMask    = pipeline_stage_flags[i].data();

		vk_submit_infos.push_back(std::move(vk_submit_info));
	}

	vkQueueSubmit(m_handle, static_cast<uint32_t>(vk_submit_infos.size()), vk_submit_infos.data(), fence ? static_cast<Fence *>(fence)->GetHandle() : nullptr);

	m_submit_infos.clear();
}

bool Queue::Empty()
{
	return m_submit_infos.empty();
}

VkQueue Queue::GetHandle() const
{
	return m_handle;
}
}        // namespace Ilum::Vulkan