#pragma once

#ifdef NEO_PLATFORM_WINDOWS

extern Neo::Application* Neo::CreateApplication();


int main(int argc, char** argv)
{
    Neo::Log::Init();
    //Neo::Log::GetCoreLogger()->warn("Initalized Log!");
    //Neo::Log::GetClientLogger()->info("Hello!");

    NEO_CORE_WARN("Initialized Log!");
    int a = 1;
    NEO_INFO("HELLO! Var={0}", a);

    auto app = Neo::CreateApplication();
    app->Run();
    delete app;
}


#endif