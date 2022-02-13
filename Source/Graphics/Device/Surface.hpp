#pragma once

#include "../Vulkan.hpp"

struct SDL_Window;

namespace Ilum::Graphics
{
class Instance;
class PhysicalDevice;

class Surface
{
  public:
	Surface(const Instance &instance, const PhysicalDevice &physical_device, SDL_Window *window);
	~Surface();

	operator const VkSurfaceKHR &() const;

	const VkSurfaceKHR &            GetHandle() const;
	const VkSurfaceCapabilitiesKHR &GetCapabilities() const;
	const VkSurfaceFormatKHR &      GetFormat() const;

  private:
	const Instance &         m_instance;
	VkSurfaceKHR             m_handle       = VK_NULL_HANDLE;
	VkSurfaceCapabilitiesKHR m_capabilities = {};
	VkSurfaceFormatKHR       m_format       = {};
};
}        // namespace Ilum::Graphics