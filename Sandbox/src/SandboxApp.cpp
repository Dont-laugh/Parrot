#include "Parrot.h"

class Sandbox : public Parrot::Application
{
public:
	Sandbox()
	{
		PushOverlay(new Parrot::ImGuiLayer());
	}

	~Sandbox() { }
};

Parrot::Application* Parrot::CreateApplication()
{
	return new Sandbox();
}
