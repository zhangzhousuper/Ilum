#include "E:/Workspace/Ilum/Source/Runtime/Renderer/Private/BasePass/DebugPass.hpp"
#include <rttr/registration.h>

namespace Ilum_6656546402991808549
{
RTTR_REGISTRATION
{
    
    rttr::registration::class_<Ilum::DebugPass>("DebugPass")(rttr::metadata("RenderPass", "Debug Pass"), rttr::metadata("Category", "Base Pass"))
    
    
        .constructor<>()(rttr::policy::ctor::as_object)
        .method("CreateDesc", &Ilum::DebugPass::CreateDesc)
        .method("Create", &Ilum::DebugPass::Create)
    ;
}
}                                 