#include <Neo.h>

class Sandbox : public Neo::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}

};


Neo::Application* Neo::CreateApplication()
{
	return new Sandbox();
}


