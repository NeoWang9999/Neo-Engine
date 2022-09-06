#include "NeoPCH.h"
#include "Application.h"

#include "Neo/Events/ApplicationEvent.h"
#include "Neo/Log.h"


namespace Neo {

	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);

		if (e.IsInCategory(EventCategoryApplication))
		{
			NEO_TRACE(e.ToString());
		}

		if (e.IsInCategory(EventCategoryInput))
		{
			NEO_TRACE(e.ToString());
		}

		while (true)
		{}
	}
}
