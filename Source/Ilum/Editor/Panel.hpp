#pragma once

#include <string>

namespace Ilum
{
class Panel
{
  public:
	Panel() = default;

	~Panel() = default;

	virtual void draw() = 0;

	const std::string &name() const
	{
		return m_name;
	}

  public:
	bool active = true;

  protected:
	std::string m_name;
};
}        // namespace Ilum