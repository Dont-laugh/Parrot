#pragma once

#include "Core.h"
#include "Window.h"
#include "Events/Event.h"
#include "Parrot/Events/ApplicationEvent.h"

namespace Parrot
{
	class PARROT_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
		void OnEvent(Event& e);

	private:
		bool OnWindowClose(WindowCloseEvent& e);

	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	// 必须在客户端定义
	Application* CreateApplication();
}
