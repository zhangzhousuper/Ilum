#pragma once

#include "Component.hpp"

#include <Resource/Importer/Model/ModelImporter.hpp>

#include <vector>

namespace Ilum
{
struct StaticMeshComponent : public Component
{
	std::string uuid;

	std::vector<std::string> materials;
};
}        // namespace Ilum