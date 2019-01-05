#pragma once

#include "Praction/Core.h"
#include "Praction/Events/Event.h"

namespace Praction {

	// Layer should be subclassed and have its virtual function implimented
	class PRACTION_API Layer
	{
	public:
		// Constructor for a layer (takes in a layer name for debug purposes)
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		// OnAttach: When a layer is pushed on to the layer stack
		virtual void OnAttach() {}

		// OnDetach: a layer is removed from the layer stack
		virtual void OnDetach() {}

		// OnUpdate: Called by the application to update the frame
		virtual void OnUpdate() {}

		// When an event is sent to the layer it is sent here
		virtual void OnEvent(Event& event) {}

		inline const std::string& GetName() const { return m_DebugName; }
	protected:
		// storing the layer name (should be used only for debug purposes)
		std::string m_DebugName;
	};
}