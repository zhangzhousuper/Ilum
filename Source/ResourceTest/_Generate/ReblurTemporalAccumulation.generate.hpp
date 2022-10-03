#include "E:/Workspace/Ilum/Source/Runtime/Renderer/Private/NRD_CUDA/ReblurTemporalAccumulation.hpp"
#include <rttr/registration.h>

namespace Ilum_9727372027355268762
{
RTTR_REGISTRATION
{
    
    rttr::registration::class_<Ilum::ReblurTemporalAccumulation>("ReblurTemporalAccumulation")(rttr::metadata("RenderPass", "Reblur Temporal Accumulation"), rttr::metadata("Category", "Nvidia Ray Tracing Denoisor"))
    
    
        .constructor<>()(rttr::policy::ctor::as_object)
        .method("CreateDesc", &Ilum::ReblurTemporalAccumulation::CreateDesc)
        .method("Create", &Ilum::ReblurTemporalAccumulation::Create)
    ;
}
}                                 