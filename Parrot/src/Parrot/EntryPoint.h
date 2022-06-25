#pragma once

#ifdef PARROT_PLATFORM_WINDOWS

extern Parrot::Application* Parrot::CreateApplication();

int main(int argc, char** argv)
{
	Parrot::Log::Init();

	PT_CORE_TRACE("Welcome to PARROT Engine!");
	PT_CORE_LOG("Welcome to PARROT Engine!");
	PT_CORE_WARN("Welcome to PARROT Engine!");
	PT_CORE_ERROR("Welcome to PARROT Engine!");
	PT_CORE_FATAL("Welcome to PARROT Engine!");

	int a = 555;
	PT_CORE_LOG("a = {}", a);

	auto app = Parrot::CreateApplication();
	app->Run();
	return 0;
}

#endif // PARROT_PLATFORM_WINDOWS
