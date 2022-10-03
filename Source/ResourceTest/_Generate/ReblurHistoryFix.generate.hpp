#include "E:/Workspace/Ilum/Source/Runtime/Renderer/Private/NRD_CUDA/ReblurHistoryFix.hpp"
#include <rttr/registration.h>

namespace Ilum_17805436591058900736
{
RTTR_REGISTRATION
{
    
    rttr::registration::class_<Ilum::ReblurHistoryFix>("ReblurHistoryFix")(rttr::metadata("RenderPass", "Reblur History Fix"), rttr::metadata("Category", "Nvidia Ray Tracing Denoisor"))
    
    
        .constructor<>()(rttr::policy::ctor::as_object)
        .method("CreateDesc", &Ilum::ReblurHistoryFix::CreateDesc)
        .method("Create", &Ilum::ReblurHistoryFix::Create)
    ;
}
}                                 