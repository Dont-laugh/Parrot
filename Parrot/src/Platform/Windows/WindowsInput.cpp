#include "ptpch.h"
#include "WindowsInput.h"
#include "GLFW/glfw3.h"
#include "Parrot/Application.h"

namespace Parrot
{
	#define GET_NATIVE_WINDOW static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow())

	Input* Input::s_Instance = new WindowsInput();

	bool WindowsInput::IsKeyPressedImpl(int keyCode)
	{
		auto window = GET_NATIVE_WINDOW;
		int state = glfwGetKey(window, keyCode);
		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}

	bool WindowsInput::IsMouseButtonPressedImpl(int button)
	{
		auto window = GET_NATIVE_WINDOW;
		int state = glfwGetMouseButton(window, button);
		return state == GLFW_PRESS;
	}

	std::pair<float, float> WindowsInput::GetMousePositionImpl()
	{
		double x, y;
		auto window = GET_NATIVE_WINDOW;
		glfwGetCursorPos(window, &x, &y);
		return { (float)x, (float)y };
	}

	float WindowsInput::GetMouseXImpl()
	{
		auto [x, y] = GetMousePositionImpl();
		return (float)x;
	}

	float WindowsInput::GetMouseYImpl()
	{
		auto [x, y] = GetMousePositionImpl();
		return (float)y;
	}
}
