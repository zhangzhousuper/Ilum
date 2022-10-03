#include "E:/Workspace/Ilum/Source/Runtime/Renderer/Private/NRD_CUDA/ReblurBlur.hpp"
#include <rttr/registration.h>

namespace Ilum_5541140503814592666
{
RTTR_REGISTRATION
{
    
    rttr::registration::class_<Ilum::ReblurBlur>("ReblurBlur")(rttr::metadata("RenderPass", "Reblur Blur"), rttr::metadata("Category", "Nvidia Ray Tracing Denoisor"))
    
    
        .constructor<>()(rttr::policy::ctor::as_object)
        .method("CreateDesc", &Ilum::ReblurBlur::CreateDesc)
        .method("Create", &Ilum::ReblurBlur::Create)
    ;
}
}                                 