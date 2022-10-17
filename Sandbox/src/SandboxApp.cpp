#include <Neo.h>

class ExLayer : public Neo::Layer
{
public:
    ExLayer()
        : Layer("Example")
    {}

    void OnUpdate() override
    {
        //NEO_INFO("ExLayer::Update");
        if (Neo::Input::IsKeyPressed(NEO_KEY_TAB))
        {
            NEO_TRACE("Tab is pressed (Poll)");
        }
    }

    void OnEvent(Neo::Event& event) override
    {
        if (event.GetEventType() == Neo::EventType::KeyPressed)
        {
            Neo::KeyPressedEvent& e = (Neo::KeyPressedEvent&)event;
            if (e.GetKeyCode() == NEO_KEY_TAB)
                NEO_TRACE("Tab is pressed (Event)");
            NEO_TRACE("{0}", (char)e.GetKeyCode());

        }
    }
};

class Sandbox : public Neo::Application
{
public:
    Sandbox()
    {
        PushLayer(new ExLayer());
        PushOverlay(new Neo::ImGuiLayer());
    }

    ~Sandbox()
    {

    }

};


Neo::Application* Neo::CreateApplication()
{
    return new Sandbox();
}
