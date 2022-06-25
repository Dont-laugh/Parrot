#pragma once

#include "Event.h"

namespace Parrot
{
	class PARROT_API MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(const float x, const float y) : m_MouseX(x), m_MouseY(y) { }

		inline float GetX() const { return m_MouseX; }
		inline float GetY() const { return m_MouseY; }

		virtual std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: (" << m_MouseX << ", " << m_MouseY << ")";
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	protected:
		float m_MouseX, m_MouseY;
	};

	class PARROT_API MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(const float xOffset, const float yOffset) : m_XOffset(xOffset), m_YOffset(yOffset) { }

		inline float GetXOffset() const { return m_XOffset; }
		inline float GetYOffset() const { return m_YOffset; }

		virtual std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseScrolledEvent: (" << m_XOffset << ", " << m_YOffset << ")";
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	private:
		float m_XOffset, m_YOffset;
	};

	class PARROT_API MouseButtonEvent : public Event
	{
	public:
		inline int GetMouseButton() const { return m_Button; }
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput | EventCategoryMouseButton)

	protected:
		MouseButtonEvent(const int button) : m_Button(button) { }
		int m_Button;
	};

	class PARROT_API MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(const int button) : MouseButtonEvent(button) { }

		virtual std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << m_Button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	class PARROT_API MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(const int button) : MouseButtonEvent(button) { }

		virtual std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << m_Button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};
}
