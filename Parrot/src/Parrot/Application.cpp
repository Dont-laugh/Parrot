#include "Application.h"
#include "Log.h"
#include "Events/ApplicationEvent.h"

namespace Parrot
{
	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		PT_TRACE(e);

		while (true) { }
	}
}

