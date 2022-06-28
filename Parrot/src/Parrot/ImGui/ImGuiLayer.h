#pragma once

#include "Parrot/Core.h"
#include "Parrot/Layer.h"
#include "imgui.h"

namespace Parrot
{
	class PARROT_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnUpdate() override;
		virtual void OnEvent(Event& evt) override;

	private:

	};
}
