#include "E:/Workspace/Ilum/Source/Runtime/Renderer/Private/BasePass/VisibilityBufferPass.hpp"
#include <rttr/registration.h>

namespace Ilum_408006763459870478
{
RTTR_REGISTRATION
{
    
    rttr::registration::class_<Ilum::VisibilityBufferPass>("VisibilityBufferPass")(rttr::metadata("RenderPass", "Visibility Buffer Pass"), rttr::metadata("Category", "Base Pass"))
    
    
        .constructor<>()(rttr::policy::ctor::as_object)
        .method("CreateDesc", &Ilum::VisibilityBufferPass::CreateDesc)
        .method("Create", &Ilum::VisibilityBufferPass::Create)
    ;
}
}                                 