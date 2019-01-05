#include "ptpch.h"
#include "LayerStack.h"

namespace Praction {
	
	LayerStack::LayerStack()
	{
		m_LayerInsert = m_Layers.begin();
	}

	// ~LayerStack destroys all owned layers
	LayerStack::~LayerStack()
	{
		for (Layer* layer : m_Layers)
			delete layer;
	}

	// PushLayer adds a layer to the layer stack (layers are owned by the layer stack)
	void LayerStack::PushLayer(Layer* layer)
	{
		m_LayerInsert = m_Layers.emplace(m_LayerInsert, layer);
	}

	// PushOverLay adds overlays to the second half of the layer stack
	void LayerStack::PushOverlay(Layer* overlay)
	{
		m_Layers.emplace_back(overlay);
	}

	// PopLayers removes a layer from the stack (does not destroy them)
	void LayerStack::PopLayer(Layer* layer)
	{
		auto it = std::find(m_Layers.begin(), m_Layers.end(), layer);
		if (it != m_Layers.end())
		{
			m_Layers.erase(it);
			m_LayerInsert--;
		}
	}

	// PopOverly removes an overlay
	void LayerStack::PopOverlay(Layer* overlay)
	{
		auto it = std::find(m_Layers.begin(), m_Layers.end(), overlay);
		if (it != m_Layers.end())
			m_Layers.erase(it);
	}

}