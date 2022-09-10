#pragma once
#include "NeoPCH.h"
#include "Core.h"
#include "Window.h"
#include "Neo/Events/Event.h"
#include "Neo/Events/ApplicationEvent.h"


namespace Neo {

    class NEO_API Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();
        void OnEvent(Event& e);
    private:
        bool OnWindowClose(WindowCloseEvent& e);
        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
    };

    // To be defined in CLIENT
    Application* CreateApplication();

}
