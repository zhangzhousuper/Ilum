#pragma once
#include <rttr/registration.h>
#include "E:/Workspace/Ilum/Source/Ilum/Renderer/BasePass/CopyPass.hpp"
#include "E:/Workspace/Ilum/Source/Ilum/Renderer/BasePass/DebugPass.hpp"
#include "E:/Workspace/Ilum/Source/Ilum/Renderer/BasePass/PresentPass.hpp"
#include "E:/Workspace/Ilum/Source/Ilum/Renderer/BasePass/TrianglePass.hpp"
#include "E:/Workspace/Ilum/Source/Ilum/Renderer/BasePass/VisibilityBufferPass.hpp"
#include "E:/Workspace/Ilum/Source/Ilum/Renderer/Precompile.hpp"
#include "E:/Workspace/Ilum/Source/Ilum/Renderer/RenderPass.hpp"
#include "E:/Workspace/Ilum/Source/Ilum/Renderer/Renderer.hpp"
// This code is generated by meta generator
namespace NAMESPACE_5430882148293022987
{
RTTR_REGISTRATION
{
using namespace Ilum;

rttr::registration::class_<Ilum::CopyPass>("Ilum::CopyPass")(rttr::metadata("RenderPass", "Copy Pass"), rttr::metadata("Category", "Basic Pass"))
	.method("CreateDesc", &Ilum::CopyPass::CreateDesc)
	.method("Create", &Ilum::CopyPass::Create)
	.constructor<>()(rttr::policy::ctor::as_object);

rttr::registration::class_<Ilum::DebugPass>("Ilum::DebugPass")(rttr::metadata("RenderPass", "Debug Pass"), rttr::metadata("Category", "Basic Pass"))
	.method("CreateDesc", &Ilum::DebugPass::CreateDesc)
	.method("Create", &Ilum::DebugPass::Create)
	.constructor<>()(rttr::policy::ctor::as_object);

rttr::registration::class_<Ilum::PresentPass>("Ilum::PresentPass")(rttr::metadata("RenderPass", "Present Pass"), rttr::metadata("Category", "Basic Pass"))
	.method("CreateDesc", &Ilum::PresentPass::CreateDesc)
	.method("Create", &Ilum::PresentPass::Create)
	.constructor<>()(rttr::policy::ctor::as_object);

rttr::registration::class_<Ilum::TrianglePass>("Ilum::TrianglePass")(rttr::metadata("RenderPass", "Triangle Pass"), rttr::metadata("Category", "Basic Pass"))
	.method("CreateDesc", &Ilum::TrianglePass::CreateDesc)
	.method("Create", &Ilum::TrianglePass::Create)
	.constructor<>()(rttr::policy::ctor::as_object);

rttr::registration::class_<Ilum::VisibilityBufferPass::Config>("Ilum::VisibilityBufferPass::Config")
	.property("a", &Ilum::VisibilityBufferPass::Config::a)(rttr::metadata("editor", "slider"), rttr::metadata("min", 0), rttr::metadata("max", 100))
	.property("m", &Ilum::VisibilityBufferPass::Config::m)
	.constructor<>()(rttr::policy::ctor::as_object);

rttr::registration::class_<Ilum::VisibilityBufferPass>("Ilum::VisibilityBufferPass")(rttr::metadata("RenderPass", "Visibility Buffer Pass"))
	.method("CreateDesc", &Ilum::VisibilityBufferPass::CreateDesc)
	.method("Create", &Ilum::VisibilityBufferPass::Create)
	.constructor<>()(rttr::policy::ctor::as_object);

rttr::registration::enumeration<Ilum::DummyTexture>("Ilum::DummyTexture")
(
	rttr::value("WhiteOpaque", Ilum::DummyTexture::WhiteOpaque),
	rttr::value("BlackOpaque", Ilum::DummyTexture::BlackOpaque),
	rttr::value("WhiteTransparent", Ilum::DummyTexture::WhiteTransparent),
	rttr::value("BlackTransparent", Ilum::DummyTexture::BlackTransparent)
);

SERIALIZER_REGISTER_TYPE(Ilum::CopyPass)
SERIALIZER_REGISTER_TYPE(Ilum::DebugPass)
SERIALIZER_REGISTER_TYPE(Ilum::PresentPass)
SERIALIZER_REGISTER_TYPE(Ilum::TrianglePass)
SERIALIZER_REGISTER_TYPE(decltype(Ilum::VisibilityBufferPass::Config::a))
SERIALIZER_REGISTER_TYPE(decltype(Ilum::VisibilityBufferPass::Config::m))
SERIALIZER_REGISTER_TYPE(Ilum::VisibilityBufferPass::Config)
SERIALIZER_REGISTER_TYPE(Ilum::VisibilityBufferPass)
}
}

//Generate for Serialization

namespace cereal
{
template <class Archive>
void serialize(Archive& archive, Ilum::CopyPass& v)
{
}

template <class Archive>
void serialize(Archive& archive, Ilum::DebugPass& v)
{
}

template <class Archive>
void serialize(Archive& archive, Ilum::PresentPass& v)
{
}

template <class Archive>
void serialize(Archive& archive, Ilum::TrianglePass& v)
{
}

template <class Archive>
void serialize(Archive& archive, Ilum::VisibilityBufferPass::Config& v)
{
	archive(v.a, v.m);
}

template <class Archive>
void serialize(Archive& archive, Ilum::VisibilityBufferPass& v)
{
}


}
