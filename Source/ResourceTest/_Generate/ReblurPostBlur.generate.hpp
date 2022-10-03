#include "E:/Workspace/Ilum/Source/Runtime/Renderer/Private/NRD_CUDA/ReblurPostBlur.hpp"
#include <rttr/registration.h>

namespace Ilum_1837784491397277808
{
RTTR_REGISTRATION
{
    
    rttr::registration::class_<Ilum::PostReblurBlur>("PostReblurBlur")(rttr::metadata("RenderPass", "Reblur Post Blur"), rttr::metadata("Category", "Nvidia Ray Tracing Denoisor"))
    
    
        .constructor<>()(rttr::policy::ctor::as_object)
        .method("CreateDesc", &Ilum::PostReblurBlur::CreateDesc)
        .method("Create", &Ilum::PostReblurBlur::Create)
    ;
}
}                                 