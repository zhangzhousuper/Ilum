#pragma once

#include <RenderCore/RenderGraph/RenderGraph.hpp>

#include <glm/glm.hpp>

namespace Ilum::Pass
{
class VisibilityBufferPass
{
  public:
	static RenderPassDesc CreateDesc(size_t &handle);
};

RENDER_PASS_REGISTERATION(VisibilityBufferPass);
}        // namespace Ilum::Pass