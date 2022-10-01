#pragma once

#include "Renderer/RenderPass.hpp"

namespace Ilum
{
struct [[RenderPass("Reblur Post Blur"), Category("Nvidia Ray Tracing Denoisor")]] PostReblurBlur : public RenderPass
{
	virtual RenderPassDesc CreateDesc() override;

	virtual RenderGraph::RenderTask Create(const RenderPassDesc &desc, RenderGraphBuilder &builder, Renderer *renderer) override;
};
}        // namespace Ilum