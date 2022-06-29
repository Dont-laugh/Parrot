#include "ptpch.h"
#include "WindowsWindow.h"
#include "glad/glad.h"
#include "glfw/glfw3.h"
#include "Parrot/Events/ApplicationEvent.h"
#include "Parrot/Events/KeyEvent.h"
#include "Parrot/Events/MouseEvent.h"

namespace Parrot
{
	static bool s_GLFWInitialized = false;

	static void GLFWErrorCallback(int error_code, const char* description)
	{
		PT_CORE_ERROR("GLFW Error ({0}) : {1}", error_code, description);
	}

	Window* Window::Create(const WindowProps& props)
	{
		return new WindowsWindow(props);
	}

	WindowsWindow::WindowsWindow(const WindowProps& props)
	{
		Init(props);
	}

	WindowsWindow::~WindowsWindow()
	{
		Shutdown();
	}

	void WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	void WindowsWindow::SetVSync(bool enabled)
	{
		glfwSwapInterval(enabled ? 1 : 0);
		m_Data.VSync = enabled;
	}

	bool WindowsWindow::IsVSync() const
	{
		return m_Data.VSync;
	}

	void WindowsWindow::Init(const WindowProps& props)
	{
		if (!s_GLFWInitialized)
		{
			int success = glfwInit();
			PT_CORE_ASSERT(success, "Could not initialize GLFW!");
			glfwSetErrorCallback(GLFWErrorCallback);
			s_GLFWInitialized = true;
		}

		GLFWmonitor* monitor = glfwGetPrimaryMonitor();
		const GLFWvidmode* mode = glfwGetVideoMode(monitor);

		m_Data.Title = props.Title;
		m_Data.Width = mode->width * 0.75;
		m_Data.Height = mode->height * 0.75;

		PT_CORE_LOG("Creating window {0} ({1}, {2})", m_Data.Title, m_Data.Width, m_Data.Height);

		m_Window = glfwCreateWindow((int)m_Data.Width, (int)m_Data.Height, props.Title.c_str(), nullptr, nullptr);
		PT_CORE_ASSERT(m_Window, "Failed to create window!");
		glfwMakeContextCurrent(m_Window);

		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		PT_CORE_ASSERT(status, "Failed to initialize GLAD!");

		glfwSetWindowUserPointer(m_Window, &m_Data);

		SetVSync(true);


		#pragma region "Set Callback"

		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			data.Width = width;
			data.Height = height;

			data.Callback(WindowResizeEvent(width, height));
		});

		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			data.Callback(WindowCloseEvent());
		});

		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			switch (action)
			{
			case GLFW_PRESS:
				data.Callback(KeyPressedEvent(key, 0));
				break;
			case GLFW_RELEASE:
				data.Callback(KeyReleasedEvent(key));
				break;
			case GLFW_REPEAT:
				data.Callback(KeyPressedEvent(key, 1));
				break;
			}
		});

		glfwSetCharCallback(m_Window, [](GLFWwindow* window, unsigned int codepoint)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			data.Callback(KeyTypedEvent(codepoint));
		});

		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			switch (action)
			{
			case GLFW_PRESS:
				data.Callback(MouseButtonPressedEvent(button));
				break;
			case GLFW_RELEASE:
				data.Callback(MouseButtonReleasedEvent(button));
				break;
			}
		});

		glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xoffset, double yoffset)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			data.Callback(MouseScrolledEvent((float)xoffset, (float)yoffset));
		});

		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xpos, double ypos)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			data.Callback(MouseMovedEvent((float)xpos, (float)ypos));
		});

		#pragma endregion
	}

	void WindowsWindow::Shutdown()
	{
		if (m_Window != nullptr)
		{
			glfwDestroyWindow(m_Window);
		}
	}
}
