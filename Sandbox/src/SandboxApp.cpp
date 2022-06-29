#include "Parrot.h"

class ExampleLayer : public Parrot::Layer
{
public:
	ExampleLayer() : Layer("Example") { }

	virtual void OnUpdate() override
	{
		PT_LOG("Example Layer::OnUpdate");
	}

	virtual void OnEvent(Parrot::Event& evt) override
	{
		PT_LOG("Example Layer::OnEvent {0}", evt);
	}
};

class Sandbox : public Parrot::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Parrot::ImGuiLayer());
	}

	~Sandbox() { }
};

Parrot::Application* Parrot::CreateApplication()
{
	return new Sandbox();
}
