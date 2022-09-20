#pragma once

#include "Definitions.hpp"
#include "RHIDevice.hpp"

#include <volk.h>

#include <vk_mem_alloc.h>

namespace Ilum::Vulkan
{
class Device : public RHIDevice
{
  private:
	void CreateInstance();
	void CreatePhysicalDevice();
	void CreateLogicalDevice();

  public:
	Device();

	virtual ~Device() override;

	virtual void WaitIdle() override;

	virtual bool IsFeatureSupport(RHIFeature feature) override;

	bool IsFeatureSupport(VulkanFeature feature);

	VkInstance       GetInstance() const;
	VkPhysicalDevice GetPhysicalDevice() const;
	VkDevice         GetDevice() const;
	VmaAllocator     GetAllocator() const;

	VmaPool GetMemoryPool(VkBufferCreateInfo &buffer_info, VmaAllocationCreateInfo &allocation_info);
	VmaPool GetMemoryPool(VkImageCreateInfo &image_info, VmaAllocationCreateInfo &allocation_info);

	uint32_t GetQueueFamily(RHIQueueFamily family);
	uint32_t GetQueueCount(RHIQueueFamily family);

	void SetVulkanObjectName(const VkDebugUtilsObjectNameInfoEXT &info);

	void BeginDebugUtilsLabel(VkCommandBuffer cmd_buffer, const VkDebugUtilsLabelEXT &label);
	void EndDebugUtilsLabel(VkCommandBuffer cmd_buffer);

  private:
	// Supported extensions
	std::vector<const char *> m_supported_instance_extensions;
	std::vector<const char *> m_supported_device_features;
	std::vector<const char *> m_supported_device_extensions;

	std::unordered_map<RHIFeature, bool>    m_feature_support;
	std::unordered_map<VulkanFeature, bool> m_vulkan_feature_support;

  private:
	VkInstance       m_instance        = VK_NULL_HANDLE;
	VkPhysicalDevice m_physical_device = VK_NULL_HANDLE;
	VkDevice         m_logical_device  = VK_NULL_HANDLE;
	VmaAllocator     m_allocator       = VK_NULL_HANDLE;

	std::map<uint32_t, VmaPool> m_vma_pool;

	std::vector<VkExportMemoryAllocateInfoKHR *> vulkanExportMemoryAllocateInfoKHRs;

	// Queue Family
	uint32_t m_graphics_family = 0;
	uint32_t m_compute_family  = 0;
	uint32_t m_transfer_family = 0;

	uint32_t m_graphics_queue_count = 0;
	uint32_t m_compute_queue_count  = 0;
	uint32_t m_transfer_queue_count = 0;
};
}        // namespace Ilum::Vulkan