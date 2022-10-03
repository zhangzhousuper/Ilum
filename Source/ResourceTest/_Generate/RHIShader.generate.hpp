#include "E:/Workspace/Ilum/Source/Runtime/RHI/Public/RHI/RHIShader.hpp"
#include <rttr/registration.h>

namespace Ilum_3557711615831355350
{
RTTR_REGISTRATION
{
    rttr::registration::enumeration<Ilum::DescriptorType>("DescriptorType")
    (
        rttr::value("Sampler", Ilum::DescriptorType::Sampler),
        rttr::value("TextureSRV", Ilum::DescriptorType::TextureSRV),
        rttr::value("TextureUAV", Ilum::DescriptorType::TextureUAV),
        rttr::value("ConstantBuffer", Ilum::DescriptorType::ConstantBuffer),
        rttr::value("StructuredBuffer", Ilum::DescriptorType::StructuredBuffer),
        rttr::value("AccelerationStructure", Ilum::DescriptorType::AccelerationStructure)
    );
    rttr::registration::class_<Ilum::ShaderMeta::Variable>("Variable")
        .property("spirv_id", &Ilum::ShaderMeta::Variable::spirv_id)
        .property("location", &Ilum::ShaderMeta::Variable::location)
        .property("format", &Ilum::ShaderMeta::Variable::format)
    
        .constructor<>()(rttr::policy::ctor::as_object)
        .method("operator==", &Ilum::ShaderMeta::Variable::operator==)
    ;
    rttr::registration::class_<Ilum::ShaderMeta::Constant>("Constant")
        .property("spirv_id", &Ilum::ShaderMeta::Constant::spirv_id)
        .property("name", &Ilum::ShaderMeta::Constant::name)
        .property("size", &Ilum::ShaderMeta::Constant::size)
        .property("offset", &Ilum::ShaderMeta::Constant::offset)
        .property("stage", &Ilum::ShaderMeta::Constant::stage)
    
        .constructor<>()(rttr::policy::ctor::as_object)
        .method("operator==", &Ilum::ShaderMeta::Constant::operator==)
    ;
    rttr::registration::class_<Ilum::ShaderMeta::Descriptor>("Descriptor")
        .property("spirv_id", &Ilum::ShaderMeta::Descriptor::spirv_id)
        .property("name", &Ilum::ShaderMeta::Descriptor::name)
        .property("array_size", &Ilum::ShaderMeta::Descriptor::array_size)
        .property("set", &Ilum::ShaderMeta::Descriptor::set)
        .property("binding", &Ilum::ShaderMeta::Descriptor::binding)
        .property("type", &Ilum::ShaderMeta::Descriptor::type)
        .property("stage", &Ilum::ShaderMeta::Descriptor::stage)
    
        .constructor<>()(rttr::policy::ctor::as_object)
        .method("operator==", &Ilum::ShaderMeta::Descriptor::operator==)
    ;
    rttr::registration::class_<Ilum::ShaderMeta>("ShaderMeta")
        .property("descriptors", &Ilum::ShaderMeta::descriptors)
        .property("constants", &Ilum::ShaderMeta::constants)
        .property("inputs", &Ilum::ShaderMeta::inputs)
        .property("outputs", &Ilum::ShaderMeta::outputs)
        .property("hash", &Ilum::ShaderMeta::hash)
    
        .constructor<>()(rttr::policy::ctor::as_object)
        .method("operator+=", &Ilum::ShaderMeta::operator+=)
    ;
}
}                                 