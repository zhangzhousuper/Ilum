#pragma once

#include "Utils/PCH.hpp"

#include "Engine/Subsystem.hpp"

namespace Ilum
{
class RenderTarget;
class CommandBuffer;
class Image2D;

class ImGuiContext : public TSubsystem<ImGuiContext>
{
  public:
	ImGuiContext(Context *context = nullptr);

	~ImGuiContext() = default;

	virtual bool onInitialize() override;

	virtual void onPreTick() override;

	virtual void onPostTick() override;

	virtual void onShutdown() override;

	void render(const CommandBuffer &command_buffer);

	const VkSemaphore &getRenderCompleteSemaphore() const;

	void *textureID(const Image2D *image);

	void setDockingSpace(bool enable);

  private:
	void config();

	void uploadFontsData();

  private:
	scope<RenderTarget>                                                m_render_target;
	VkDescriptorPool                                                   m_descriptor_pool = VK_NULL_HANDLE;
	std::array<VkSemaphore, 3>                                         m_render_complete;
	std::array<scope<CommandBuffer>, 3>                                m_command_buffers;
	std::unordered_map<const VkDescriptorImageInfo *, VkDescriptorSet> m_texture_id_mapping;
	bool                                                               m_dockspace_enable = false;
};
}        // namespace Ilum