#pragma once

#include "RHI/RHIQueue.hpp"

#include <volk.h>

namespace Ilum::Vulkan
{
class Queue : public RHIQueue
{
  public:
	Queue(RHIDevice *device, RHIQueueFamily family, uint32_t queue_index = 0);

	virtual ~Queue() = default;

	virtual void Wait() override;

	virtual void Submit(const std::vector<RHICommand *> &cmds, const std::vector<RHISemaphore *> &signal_semaphores = {}, const std::vector<RHISemaphore *> &wait_semaphores = {}) override;

	virtual void Execute(RHIFence *fence = nullptr) override;

	virtual bool Empty() override;

	VkQueue GetHandle() const;

  private:
	VkQueue m_handle = VK_NULL_HANDLE;

	struct SubmitInfo
	{
		std::vector<VkCommandBuffer> cmd_buffers;
		std::vector<VkSemaphore>     wait_semaphores;
		std::vector<VkSemaphore>     signal_semaphores;
	};

	std::vector<SubmitInfo> m_submit_infos;
};
}        // namespace Ilum::Vulkan