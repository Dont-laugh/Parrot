#include "ptpch.h"
#include "Application.h"
#include "Input.h"
#include "Events/ApplicationEvent.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"

namespace Parrot
{
	Application* Application::s_Instance = nullptr;

	Application::Application()
	{
		PT_CORE_ASSERT(!s_Instance, "Application already exists!")
		s_Instance = this;

		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		while (m_Running)
		{
			glClearColor(0.333f, 0.1f, 0.545f, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			for (auto layer : m_LayerStack)
			{
				layer->OnUpdate();
			}

			auto [x, y] = Input::GetMousePosition();
			PT_CORE_TRACE("mousePos: ({0}, {1})", x, y);

			m_Window->OnUpdate();
		}
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::OnWindowClose));

		PT_CORE_TRACE("{0}", e);

		// 从上往下遍历层级，处理事件
		for (auto& iter = m_LayerStack.end(); iter != m_LayerStack.begin(); )
		{
			(*--iter)->OnEvent(e);
			if (e.Handled())
			{
				break;
			}
		}
	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer* overlay)
	{
		m_LayerStack.PushOverlay(overlay);
		overlay->OnAttach();
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}
}

