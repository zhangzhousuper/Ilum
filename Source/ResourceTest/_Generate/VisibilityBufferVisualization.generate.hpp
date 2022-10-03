#include "E:/Workspace/Ilum/Source/Runtime/Renderer/Private/BasePass/VisibilityBufferVisualization.hpp"
#include <rttr/registration.h>

namespace Ilum_6604737856825927433
{
RTTR_REGISTRATION
{
    
    rttr::registration::class_<Ilum::VisibilityBufferVisualization>("VisibilityBufferVisualization")(rttr::metadata("RenderPass", "Visibility Buffer Visualization"), rttr::metadata("Category", "Visualization"))
    
    
        .constructor<>()(rttr::policy::ctor::as_object)
        .method("CreateDesc", &Ilum::VisibilityBufferVisualization::CreateDesc)
        .method("Create", &Ilum::VisibilityBufferVisualization::Create)
    ;
}
}                                 