#include <Ilum/Device/Window.hpp>
#include <Ilum/Editor/Editor.hpp>
#include <Ilum/Engine/Context.hpp>
#include <Ilum/Engine/Engine.hpp>
#include <Ilum/Renderer/Renderer.hpp>
#include <Ilum/Scene/Component/Camera.hpp>
#include <Ilum/Scene/Component/Hierarchy.hpp>
#include <Ilum/Scene/Component/Tag.hpp>
#include <Ilum/Scene/Component/Transform.hpp>
#include <Ilum/Scene/Scene.hpp>
#include <Ilum/Scene/System.hpp>
#include <Ilum/Timing/Timer.hpp>

int main()
{
	Ilum::Engine engine;

	for (auto i = 0; i < 10; i++)
	{
		auto entity = Ilum::Scene::instance()->createEntity("test" + std::to_string(i));
	}

	auto entity = Ilum::Scene::instance()->createEntity("test" + std::to_string(10));
	auto view = Ilum::Scene::instance()->getRegistry().view<Ilum::cmpt::Tag>();

	//for (auto& iter : view)
	//{
	//	LOG_INFO(iter.getComponent<Ilum::cmpt::Tag>().name);
	//}

	//std::for_each(std::execution::par_unseq, view.begin(), view.end(), [&view](auto entity) {
	//	std::cout << std::this_thread::get_id() << std::endl;
	//});

	//auto t = entity.hasComponent<Ilum::cmpt::Tag>();
	auto title = Ilum::Window::instance()->getTitle();
	while (!Ilum::Window::instance()->shouldClose())
	{
		engine.onTick();

		Ilum::Window::instance()->setTitle(title + " FPS: " + std::to_string(Ilum::Timer::instance()->getFPS()));
	}

	return 0;
}