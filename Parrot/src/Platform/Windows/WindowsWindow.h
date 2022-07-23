#pragma once

#include "Parrot/Window.h"
#include "Parrot/Core.h"

struct GLFWwindow;

namespace Parrot
{
	class PARROT_API WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		virtual void OnUpdate() override;

		virtual inline unsigned int GetWidth() const override { return m_Data.Width; }
		virtual inline unsigned int GetHeight() const override { return m_Data.Height; }

		virtual inline void SetEventCallback(const EventCallback& callback) override { m_Data.Callback = callback; }
		virtual void SetVSync(bool enabled) override;
		virtual bool IsVSync() const override;

		virtual inline void* GetNativeWindow() const { return m_Window; }

	private:
		void Init(const WindowProps& props);
		void Shutdown();

	private:
		struct WindowData
		{
			std::string Title;
			EventCallback Callback;
			unsigned int Width, Height;
			bool VSync;
		};

		GLFWwindow* m_Window;
		WindowData m_Data;
	};
}
