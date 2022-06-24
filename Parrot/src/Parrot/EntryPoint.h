#pragma once

#ifdef PARROT_PLATFORM_WINDOWS

extern Parrot::Application* Parrot::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Parrot::CreateApplication();
	app->Run();
	return 0;
}

#endif // PARROT_PLATFORM_WINDOWS
