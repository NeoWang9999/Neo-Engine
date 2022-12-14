#pragma once
#include "NeoPCH.h"
#include "Core.h"
#include "Window.h"
#include "Neo/Events/Event.h"
#include "Neo/Events/ApplicationEvent.h"
#include "Neo/LayerStack.h"


namespace Neo {

    class NEO_API Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();
        void OnEvent(Event& e);

        void PushLayer(Layer* layer);
        void PushOverlay(Layer* layer);

        inline Window& GetWindow() { return *m_Window; }
        
        inline static Application& Get() { return *s_Instance; }
    private:
        bool OnWindowClose(WindowCloseEvent& e);

        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
        LayerStack m_LayerStack;

        static Application* s_Instance;
    };

    // To be defined in CLIENT
    Application* CreateApplication();

}
