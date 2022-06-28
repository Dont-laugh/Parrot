#pragma once

#include "Core.h"
#include "Events/Event.h"
#include <string>

namespace Parrot
{
	class PARROT_API Layer
	{
	public:
		Layer(const std::string& name = "Layer") : m_DebugName(name) { }
		virtual ~Layer() = default;

		virtual void OnAttach() { }
		virtual void OnDetach() { }
		virtual void OnUpdate() { }
		virtual void OnEvent(Event& evt) { }

		inline const std::string& GetName() const { return m_DebugName; }

	protected:
		std::string m_DebugName;
	};
}
