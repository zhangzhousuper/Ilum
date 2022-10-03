#include "E:/Workspace/Ilum/Source/Runtime/Resource/Private/Importer/Texture/TextureImporter.hpp"
#include <rttr/registration.h>

namespace Ilum_9806299782189688405
{
RTTR_REGISTRATION
{
    
    rttr::registration::class_<Ilum::TextureImportInfo>("TextureImportInfo")
        .property("desc", &Ilum::TextureImportInfo::desc)
        .property("data", &Ilum::TextureImportInfo::data)
        .property("thumbnail_data", &Ilum::TextureImportInfo::thumbnail_data)
    
        .constructor<>()(rttr::policy::ctor::as_object)
    
    ;
}
}                                 