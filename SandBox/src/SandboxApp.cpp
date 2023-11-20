
#include <Hazel.h>

class ExamplerLayer : public Hazel::Layer
{
public:
	ExamplerLayer()
		:Layer("Example")
	{
	}

	void OnUpdate() override
	{
		//HZ_INFO("ExampleLayer::Update");
		if (Hazel::Input::IsKeyPressed(HZ_KEY_TAB))
			HZ_TRACE("Tab key is pressed(poll)!");
	}

	void OnEvent(Hazel::Event& event) override
	{
		//HZ_TRACE("{0}", event);
		if (event.GetEventType() == Hazel::EventType::KeyPressed)
		{
			Hazel::KeyPressedEvent& e = (Hazel::KeyPressedEvent&)event;
			if(e.GetKeyCode() == HZ_KEY_TAB)
				HZ_TRACE("Tab key is pressed(event)!");
			HZ_TRACE("{0}", (char)e.GetKeyCode());
		}
	}
};


class Sandbox : public Hazel::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExamplerLayer());
		PushOverlay(new Hazel::ImGuiLayer());
	}
	~Sandbox()
	{

	}

private:

};


Hazel::Application* Hazel::CreateApplication()
{
	return new Sandbox();
}