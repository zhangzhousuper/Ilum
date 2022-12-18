#pragma once

#include "Camera.hpp"

namespace Ilum
{
namespace Cmpt
{
class EXPORT_API PerspectiveCamera : public Camera
{
  public:
	PerspectiveCamera(Node *node);

	virtual ~PerspectiveCamera() = default;

	virtual void OnImGui() override;

	virtual std::type_index GetType() const override;

	void SetFov(float fov);

	float GetFov() const;

  protected:
	virtual void UpdateProjection() override;

  private:
	bool m_dirty = true;
	float m_fov   = 45.f;
};
}        // namespace Cmpt
}        // namespace Ilum