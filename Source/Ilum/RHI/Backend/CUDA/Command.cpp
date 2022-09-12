#include "Command.hpp"
#include "Descriptor.hpp"
#include "PipelineState.hpp"
#include "Shader.hpp"
#include "Texture.hpp"

namespace Ilum::CUDA
{
Command::Command(RHIDevice *device, RHIQueueFamily family) :
    RHICommand(device, family)
{
}

void Command::Begin()
{
	m_state = CommandState::Recording;
	m_calls.clear();
}

void Command::End()
{
	m_state = CommandState::Executable;
}

void Command::BeginMarker(const std::string &name, float r, float g, float b, float a)
{
}

void Command::EndMarker()
{
}

void Command::BeginRenderPass(RHIRenderTarget *render_target)
{
}

void Command::EndRenderPass()
{
}

void Command::BindVertexBuffer(RHIBuffer *vertex_buffer)
{
}

void Command::BindIndexBuffer(RHIBuffer *index_buffer, bool is_short)
{
}

void Command::BindDescriptor(RHIDescriptor *descriptor)
{
	p_descriptor = descriptor;
}

void Command::BindPipelineState(RHIPipelineState *pipeline_state)
{
	p_pipeline_state = pipeline_state;
}

void Command::SetViewport(float width, float height, float x, float y)
{
}

void Command::SetScissor(uint32_t width, uint32_t height, int32_t offset_x, int32_t offset_y)
{
}

void Command::Dispatch(uint32_t thread_x, uint32_t thread_y, uint32_t thread_z, uint32_t block_x, uint32_t block_y, uint32_t block_z)
{
	ASSERT(p_descriptor != nullptr && p_pipeline_state != nullptr);

	m_calls.emplace_back([=]() {
		auto *shader     = p_pipeline_state->GetShader(RHIShaderStage::Compute);
		auto &param_data = static_cast<Descriptor *>(p_descriptor)->GetParamData();
		if (shader)
		{
			auto *cuda_kernal     = static_cast<const Shader *>(shader);
			auto  kernal_function = cuda_kernal->GetFunction();
			auto  global_param    = cuda_kernal->GetGlobalParam();

			cuMemcpyHtoD(global_param, param_data.data(), param_data.size());

			cuLaunchKernel(
			    kernal_function,
			    (thread_x + block_x - 1) / block_x,
			    (thread_y + block_y - 1) / block_y,
			    (thread_z + block_z - 1) / block_z,
			    block_x, block_y, block_z, 0,
			    nullptr, nullptr, nullptr);

			cuMemcpyDtoH(param_data.data(), global_param, param_data.size());
		}
	});
}

void Command::Draw(uint32_t vertex_count, uint32_t instance_count, uint32_t first_vertex, uint32_t first_instance)
{
}

void Command::DrawIndexed(uint32_t index_count, uint32_t instance_count, uint32_t first_index, uint32_t vertex_offset, uint32_t first_instance)
{
}

void Command::CopyBufferToTexture(RHIBuffer *src_buffer, RHITexture *dst_texture, uint32_t mip_level, uint32_t base_layer, uint32_t layer_count)
{
}

void Command::CopyTextureToBuffer(RHITexture *src_texture, RHIBuffer *dst_buffer, uint32_t mip_level, uint32_t base_layer, uint32_t layer_count)
{
}

void Command::CopyBufferToBuffer(RHIBuffer *src_buffer, RHIBuffer *dst_buffer, size_t size, size_t src_offset, size_t dst_offset)
{
}

void Command::BlitTexture(RHITexture *src_texture, const TextureRange &src_range, const RHIResourceState &src_state, RHITexture *dst_texture, const TextureRange &dst_range, const RHIResourceState &dst_state, RHIFilter filter)
{
}

void Command::ResourceStateTransition(const std::vector<TextureStateTransition> &texture_transitions, const std::vector<BufferStateTransition> &buffer_transitions)
{
}

void Command::Execute()
{
	for (auto &task : m_calls)
	{
		task();
	}
}
}        // namespace Ilum::CUDA