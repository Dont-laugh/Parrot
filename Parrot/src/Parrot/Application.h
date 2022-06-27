#pragma once

#include "Core.h"
#include "Window.h"
#include "Events/Event.h"

namespace Parrot
{
	class PARROT_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	// 必须在客户端定义
	Application* CreateApplication();
}
