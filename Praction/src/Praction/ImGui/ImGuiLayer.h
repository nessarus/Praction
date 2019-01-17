#pragma once

#include "Praction/Layer.h"

namespace Praction {

	class PRACTION_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach();
		void OnDetach();

		void OnUpdate();
		void OnEvent(Event& event);
	private:
		float m_Time = 0.0f;

	};
}