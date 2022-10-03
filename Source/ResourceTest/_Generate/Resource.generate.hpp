#include "E:/Workspace/Ilum/Source/Runtime/Resource/Public/Resource.hpp"
#include <rttr/registration.h>

namespace Ilum_16899070296989497513
{
RTTR_REGISTRATION
{
    rttr::registration::enumeration<Ilum::ResourceType>("ResourceType")
    (
        rttr::value("Model", Ilum::ResourceType::Model),
        rttr::value("Texture2D", Ilum::ResourceType::Texture2D),
        rttr::value("Scene", Ilum::ResourceType::Scene),
        rttr::value("RenderGraph", Ilum::ResourceType::RenderGraph)
    );
    
}
}                                 