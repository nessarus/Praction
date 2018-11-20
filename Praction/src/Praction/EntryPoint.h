#pragma once

#ifdef PT_PLATFORM_WINDOWS

extern Praction::Application* Praction::CreateApplication();

int main(int argc, char** argv)
{
	Praction::Log::Init();
	PT_CORE_WARN("Initialized Log!");
	int a = 5;
	PT_INFO("Hello! Var={0}", a);


	auto app = Praction::CreateApplication();
	app->Run();
	delete app;
}
#endif
