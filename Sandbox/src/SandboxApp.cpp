#include <Neo.h>

class ExLayer : public Neo::Layer
{
public:
    ExLayer()
        : Layer("Example")
    {}

    void OnUpdate() override
    {
        NEO_INFO("ExLayer::Update");
    }

    void OnEvent(Neo::Event& event) override
    {
        NEO_TRACE("{0}", event.ToString());
    }
};

class Sandbox : public Neo::Application
{
public:
    Sandbox()
    {
        PushLayer(new ExLayer());
    }

    ~Sandbox()
    {

    }

};


Neo::Application* Neo::CreateApplication()
{
    return new Sandbox();
}
