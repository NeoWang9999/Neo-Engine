#include "NeoPCH.h"
#include "Application.h"

#include "Neo/Events/ApplicationEvent.h"
#include "Platform/Windows/WindowsWindow.h"

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

namespace Neo {

    Application::Application()
    {
        m_Window = std::unique_ptr<Window>(Window::Create());
        m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
    }

    Application::~Application()
    {
    }

    void Application::OnEvent(Event& e)
    {
        EventDispatcher dispacther(e);
        dispacther.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

        NEO_CORE_INFO("{0}", e.ToString());
    }

    void Application::Run()
    {
        while (m_Running)
        {
            glClearColor(1, 0, 1, 1);
            glClear(GL_COLOR_BUFFER_BIT);
            m_Window->OnUpdate();
        }
    }

    bool Application::OnWindowClose(WindowCloseEvent& e)
    {
        m_Running = false;
        return true;
    }
}
