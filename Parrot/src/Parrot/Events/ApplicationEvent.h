#pragma once

#include "Event.h"

namespace Parrot
{
	class PARROT_API WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(const unsigned width, const unsigned height) : m_Width(width), m_Height(height) { }

		inline unsigned int GetWidth() const { return m_Width; }
		inline unsigned int GetHeight() const { return m_Height; }

		virtual std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowResizeEvent: [" << m_Width << ", " << m_Height << "]";
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowResize)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)

	private:
		unsigned int m_Width, m_Height;
	};

	class PARROT_API WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() = default;
		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class PARROT_API AppTickEvent : public Event
	{
	public:
		AppTickEvent() = default;
		EVENT_CLASS_TYPE(AppTick)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class PARROT_API AppUpdateEvent : public Event
	{
	public:
		AppUpdateEvent() = default;
		EVENT_CLASS_TYPE(AppUpdate)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class PARROT_API AppRenderEvent : public Event
	{
	public:
		AppRenderEvent() = default;
		EVENT_CLASS_TYPE(AppRender)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};
}
