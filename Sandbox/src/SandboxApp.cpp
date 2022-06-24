#include "Parrot.h"

class Sandbox : public Parrot::Application
{
public:
	Sandbox() { }
	~Sandbox() { }
};

Parrot::Application* Parrot::CreateApplication()
{
	return new Sandbox();
}
