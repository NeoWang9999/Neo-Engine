#include <Neo.h>

#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/ext/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale
#include <glm/ext/matrix_clip_space.hpp> // glm::perspective
#include <glm/ext/scalar_constants.hpp> // glm::pi

glm::mat4 camera(float Translate, glm::vec2 const& Rotate)
{
    glm::mat4 Projection = glm::perspective(glm::pi<float>() * 0.25f, 4.0f / 3.0f, 0.1f, 100.f);
    glm::mat4 View = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -Translate));
    View = glm::rotate(View, Rotate.y, glm::vec3(-1.0f, 0.0f, 0.0f));
    View = glm::rotate(View, Rotate.x, glm::vec3(0.0f, 1.0f, 0.0f));
    glm::mat4 Model = glm::scale(glm::mat4(1.0f), glm::vec3(0.5f));
    return Projection * View * Model;
}


class ExLayer : public Neo::Layer
{
public:
    ExLayer()
        : Layer("Example")
    {
        auto cam = camera(5.0f, { 0.5f, 0.5f });
        NEO_TRACE("{0}", (char)(cam.length));
        int a = 1;
        std::cout << static_cast <char>(a) << std::endl;
    }

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
