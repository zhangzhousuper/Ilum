#include "E:/Workspace/Ilum/Source/Runtime/Scene/Public/Scene/Component/TagComponent.hpp"
#include <rttr/registration.h>

namespace Ilum_12205283628851249319
{
RTTR_REGISTRATION
{
    
    rttr::registration::class_<Ilum::TagComponent>("TagComponent")
        .property("tag", &Ilum::TagComponent::tag)
    
        .constructor<>()(rttr::policy::ctor::as_object)
    
    ;
}
}                                 