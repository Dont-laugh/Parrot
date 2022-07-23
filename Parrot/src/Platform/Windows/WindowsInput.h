#pragma once

#include "Parrot/Core.h"
#include "Parrot/Input.h"

namespace Parrot
{
	class PARROT_API WindowsInput : public Input
	{
	protected:
		virtual bool IsKeyPressedImpl(int keyCode) override;
		virtual bool IsMouseButtonPressedImpl(int button) override;
		virtual std::pair<float, float> GetMousePositionImpl();
		virtual float GetMouseXImpl() override;
		virtual float GetMouseYImpl() override;
	};
}
