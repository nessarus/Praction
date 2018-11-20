#pragma once

#ifdef PT_PLATFORM_WINDOWS

extern Praction::Application* Praction::CreateApplication();

int main(int argc, char** argv)
{
	printf("Praction Engine\n");
	auto app = Praction::CreateApplication();
	app->Run();
	delete app;
}
#endif
