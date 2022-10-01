#pragma once

namespace Ilum
{
class RHIDevice;
class RHIBuffer;
class RHICommand;
class RHIAccelerationStructure;

struct [[serialization(false), reflection(false)]] TLASDesc
{
	struct [[serialization(false), reflection(false)]] InstanceInfo
	{
		glm::mat4 transform;
		uint32_t  material_id;

		RHIAccelerationStructure *blas = nullptr;
	};

	std::string name;

	std::vector<InstanceInfo> instances;
};

struct [[serialization(false), reflection(false)]] BLASDesc
{
	std::string name;

	RHIBuffer *vertex_buffer = nullptr;
	RHIBuffer *index_buffer  = nullptr;

	uint32_t vertices_count  = 0;
	uint32_t indices_count   = 0;
	uint32_t vertices_offset = 0;
	uint32_t indices_offset  = 0;
};

class RHIAccelerationStructure
{
  public:
	RHIAccelerationStructure(RHIDevice *device);

	virtual ~RHIAccelerationStructure() = default;

	static std::unique_ptr<RHIAccelerationStructure> Create(RHIDevice *rhi_device);

	virtual void Update(RHICommand *cmd_buffer, const TLASDesc &desc) = 0;

	virtual void Update(RHICommand *cmd_buffer, const BLASDesc &desc) = 0;

  protected:
	RHIDevice *p_device = nullptr;
};
}        // namespace Ilum