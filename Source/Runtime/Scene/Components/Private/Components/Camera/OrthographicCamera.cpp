#include "Camera/OrthographicCamera.hpp"
#include "Transform.hpp"

#include <SceneGraph/Node.hpp>

#include <glm/gtc/matrix_transform.hpp>

#include <imgui.h>

namespace Ilum
{
namespace Cmpt
{
OrthographicCamera::OrthographicCamera(Node *node) :
    Camera("Orthographic Camera", node)
{
}

void OrthographicCamera::OnImGui()
{
	m_dirty |= ImGui::DragFloat("Aspect", &m_aspect, 0.01f, 0.f, std::numeric_limits<float>::max(), "%.3f");
	m_dirty |= ImGui::DragFloat("Scale", &m_scale, 0.01f, 0.f, std::numeric_limits<float>::max(), "%.3f");
	m_dirty |= ImGui::DragFloat("Offset X", &m_offset_x, 0.01f, 0.f, std::numeric_limits<float>::max(), "%.3f");
	m_dirty |= ImGui::DragFloat("Offset Y", &m_offset_y, 0.01f, 0.f, std::numeric_limits<float>::max(), "%.3f");
	m_dirty |= ImGui::DragFloat("Near Plane", &m_near, 0.01f, 0.f, std::numeric_limits<float>::max(), "%.3f");
	m_dirty |= ImGui::DragFloat("Far Plane", &m_far, 0.01f, 0.f, std::numeric_limits<float>::max(), "%.3f");
}

std::type_index OrthographicCamera::GetType() const
{
	return typeid(OrthographicCamera);
}

void OrthographicCamera::SetScale(float scale)
{
	m_dirty |= (m_scale != scale);
	m_scale = scale;
}

void OrthographicCamera::SetOffset(float x, float y)
{
	m_dirty |= ((m_offset_x != x) || (m_offset_y != y));
	m_offset_x = x;
	m_offset_y = y;
}

float OrthographicCamera::GetScale() const
{
	return m_scale;
}

float OrthographicCamera::GetOffsetX() const
{
	return m_offset_x;
}

float OrthographicCamera::GetOffsetY() const
{
	return m_offset_y;
}

void OrthographicCamera::UpdateProjection()
{
	if (m_dirty)
	{
		auto *transform = p_node->GetComponent<Cmpt::Transform>();

		float left = m_offset_x - m_scale * m_aspect*0.5f;
		float right = m_offset_x + m_scale * m_aspect * 0.5f;
		float top   = m_offset_y + m_scale * 0.5f;
		float bottom   = m_offset_y - m_scale * 0.5f;

		m_projection          = glm::ortho(left, right, bottom, top);
		m_inv_projection      = glm::inverse(m_projection);

		m_dirty = false;
	}
}
}        // namespace Cmpt
}        // namespace Ilum