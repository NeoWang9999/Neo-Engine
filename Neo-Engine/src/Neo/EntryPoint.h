#pragma once

#ifdef NEO_PLATFORM_WINDOWS

extern Neo::Application* Neo::CreateApplication();


int main(int argc, char** argv)
{
	auto app = Neo::CreateApplication();
	app->Run();
	delete app;
}


#endif