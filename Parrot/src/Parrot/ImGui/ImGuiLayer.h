#pragma once

#include "Parrot/Core.h"
#include "Parrot/Layer.h"
#include "Parrot/Events/MouseEvent.h"
#include "Parrot/Events/KeyEvent.h"
#include "Parrot/Events/ApplicationEvent.h"

namespace Parrot
{
	class PARROT_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnUpdate() override;
		virtual void OnEvent(Event& evt) override;

	private:
		bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& evt);
		bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& evt);
		bool OnMouseMovedEvent(MouseMovedEvent& evt);
		bool OnMouseScrolledEvent(MouseScrolledEvent& evt);
		bool OnKeyPressedEvent(KeyPressedEvent& evt);
		bool OnKeyReleasedEvent(KeyReleasedEvent& evt);
		//bool OnKeyTypedEvent(KeyTypedEvent& evt);
		bool OnWindowResizeEvent(WindowResizeEvent& evt);

	private:
		float m_Time = 0.f;
	};
}
