#pragma once
#include <rttr/registration.h>
#include "E:/Workspace/Ilum/Source/Ilum/Scene/Component/Component.hpp"
#include "E:/Workspace/Ilum/Source/Ilum/Scene/Component/HierarchyComponent.hpp"
#include "E:/Workspace/Ilum/Source/Ilum/Scene/Component/StaticMeshComponent.hpp"
#include "E:/Workspace/Ilum/Source/Ilum/Scene/Component/TagComponent.hpp"
#include "E:/Workspace/Ilum/Source/Ilum/Scene/Component/TransformComponent.hpp"
#include "E:/Workspace/Ilum/Source/Ilum/Scene/Entity.hpp"
#include "E:/Workspace/Ilum/Source/Ilum/Scene/Precompile.hpp"
#include "E:/Workspace/Ilum/Source/Ilum/Scene/Scene.hpp"
// This code is generated by meta generator
namespace NAMESPACE_16385974733565502357
{
RTTR_REGISTRATION
{
using namespace Ilum;

rttr::registration::class_<Ilum::Component>("Ilum::Component")
	.property("update", &Ilum::Component::update)
	.constructor<>()(rttr::policy::ctor::as_object);

rttr::registration::class_<Ilum::HierarchyComponent>("Ilum::HierarchyComponent")
	.property("parent", &Ilum::HierarchyComponent::parent)
	.property("first", &Ilum::HierarchyComponent::first)
	.property("next", &Ilum::HierarchyComponent::next)
	.property("prev", &Ilum::HierarchyComponent::prev)
	.constructor<>()(rttr::policy::ctor::as_object);

rttr::registration::class_<Ilum::StaticMeshComponent>("Ilum::StaticMeshComponent")
	.property("uuid", &Ilum::StaticMeshComponent::uuid)
	.property("materials", &Ilum::StaticMeshComponent::materials)
	.constructor<>()(rttr::policy::ctor::as_object);

rttr::registration::class_<Ilum::TagComponent>("Ilum::TagComponent")
	.property("tag", &Ilum::TagComponent::tag)
	.constructor<>()(rttr::policy::ctor::as_object);

rttr::registration::class_<Ilum::TransformComponent>("Ilum::TransformComponent")
	.property("translation", &Ilum::TransformComponent::translation)
	.property("rotation", &Ilum::TransformComponent::rotation)
	.property("scale", &Ilum::TransformComponent::scale)
	.constructor<>()(rttr::policy::ctor::as_object);

SERIALIZER_REGISTER_TYPE(decltype(Ilum::Component::update))
SERIALIZER_REGISTER_TYPE(Ilum::Component)
SERIALIZER_REGISTER_TYPE(decltype(Ilum::HierarchyComponent::parent))
SERIALIZER_REGISTER_TYPE(decltype(Ilum::HierarchyComponent::first))
SERIALIZER_REGISTER_TYPE(decltype(Ilum::HierarchyComponent::next))
SERIALIZER_REGISTER_TYPE(decltype(Ilum::HierarchyComponent::prev))
SERIALIZER_REGISTER_TYPE(Ilum::HierarchyComponent)
SERIALIZER_REGISTER_TYPE(decltype(Ilum::StaticMeshComponent::uuid))
SERIALIZER_REGISTER_TYPE(decltype(Ilum::StaticMeshComponent::materials))
SERIALIZER_REGISTER_TYPE(Ilum::StaticMeshComponent)
SERIALIZER_REGISTER_TYPE(decltype(Ilum::TagComponent::tag))
SERIALIZER_REGISTER_TYPE(Ilum::TagComponent)
SERIALIZER_REGISTER_TYPE(decltype(Ilum::TransformComponent::translation))
SERIALIZER_REGISTER_TYPE(decltype(Ilum::TransformComponent::rotation))
SERIALIZER_REGISTER_TYPE(decltype(Ilum::TransformComponent::scale))
SERIALIZER_REGISTER_TYPE(decltype(Ilum::TransformComponent::local_transform))
SERIALIZER_REGISTER_TYPE(decltype(Ilum::TransformComponent::world_transform))
SERIALIZER_REGISTER_TYPE(Ilum::TransformComponent)
}
}

//Generate for Serialization

namespace cereal
{
template <class Archive>
void serialize(Archive& archive, Ilum::Component& v)
{
	archive(v.update);
}

template <class Archive>
void serialize(Archive& archive, Ilum::HierarchyComponent& v)
{
	archive(v.parent, v.first, v.next, v.prev);
}

template <class Archive>
void serialize(Archive& archive, Ilum::StaticMeshComponent& v)
{
	archive(v.uuid, v.materials);
}

template <class Archive>
void serialize(Archive& archive, Ilum::TagComponent& v)
{
	archive(v.tag);
}

template <class Archive>
void serialize(Archive& archive, Ilum::TransformComponent& v)
{
	archive(v.translation, v.rotation, v.scale, v.local_transform, v.world_transform);
}


}
