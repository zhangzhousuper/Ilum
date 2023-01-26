#include "Components/Light/EnvironmentLight.hpp"

#include <imgui.h>

namespace Ilum::Cmpt
{
EnvironmentLight::EnvironmentLight(Node *node) :
    Light("Environment Light", node)
{
}

void EnvironmentLight::OnImGui()
{
	if (ImGui::Button(m_texture.c_str(), ImVec2(ImGui::GetContentRegionAvail().x * 0.8f, 30.f)))
	{
		m_texture = "";
		m_update  = true;
	}

	if (ImGui::BeginDragDropSource())
	{
		ImGui::SetDragDropPayload("TextureCube", m_texture.c_str(), m_texture.length() + 1);
		ImGui::EndDragDropSource();
	}

	if (ImGui::BeginDragDropTarget())
	{
		if (const auto *pay_load = ImGui::AcceptDragDropPayload("TextureCube"))
		{
			m_texture = static_cast<const char *>(pay_load->Data);
			m_update = true;
		}
	}
}

void EnvironmentLight::Save(OutputArchive &archive) const
{
	archive(m_texture);
}

void EnvironmentLight::Load(InputArchive &archive)
{
	archive(m_texture);
	m_update = true;
}

std::type_index EnvironmentLight::GetType() const
{
	return typeid(EnvironmentLight);
}

size_t EnvironmentLight::GetDataSize() const
{
	return m_texture.length() + 1;
}

void *EnvironmentLight::GetData()
{
	return m_texture.data();
}
}        // namespace Ilum::Cmpt