#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace Parrot
{
	class PARROT_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// 必须在客户端定义
	Application* CreateApplication();
}
