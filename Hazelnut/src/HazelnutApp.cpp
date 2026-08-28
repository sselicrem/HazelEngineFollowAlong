#include <Hazel.h>
#include <Hazel/Core/EntryPoint.h>

#include "EditorLayer.h"

namespace Hazel
{

	class Hazelnut : public Hazel::Application
	{
	public:
		Hazelnut(const Hazel::ApplicationSpecification& specification)
			: Hazel::Application(specification)
		{
			// PushLayer(new ExampleLayer());
			PushLayer(new EditorLayer());
		}

		~Hazelnut()
		{
		}
	};

	Application* CreateApplication(ApplicationCommandLineArgs args)
	{
		ApplicationSpecification spec;
		spec.Name = "Hazelnut";
		spec.CommandLineArgs = args;

		return new Hazelnut(spec);
	}
}