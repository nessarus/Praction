#pragma once

#include "Praction/Core.h"
#include "Layer.h"

#include <vector>

namespace Praction {

	// LayerStack is a wrapper over a vector of layers (m_Layers)
	class PRACTION_API LayerStack
	{
	public:
		LayerStack();
		~LayerStack();

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
		void PopLayer(Layer* layer);
		void PopOverlay(Layer* overlay);

		// begins, end allows us to iterate using a range based for loop, forwards and backwards.
		std::vector<Layer*>::iterator begin() { return m_Layers.begin(); }
		std::vector<Layer*>::iterator end() { return m_Layers.end(); }
	private:
		// m_Layer is a vector of layers
		std::vector<Layer*> m_Layers;

		// m_LayerInsert allows us to iterate over the layers and go reverse order for events
		std::vector<Layer*>::iterator m_LayerInsert;
	};
}
