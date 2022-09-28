#pragma once
#include <Neo/Events/Event.h>

namespace Neo {

    class NEO_API Layer
    {
    public:
        Layer(const std::string& name = "Layer");
        virtual ~Layer();

        virtual void OnAttach() {}
        virtual void OnDetach() {}
        virtual void OnUpdate() {}
        virtual void OnEvent(Event& event) {}

        inline const std::string& getName() { return m_DebugName; }
    private:
        std::string m_DebugName;
    };

}