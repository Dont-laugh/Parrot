#pragma once

#include "Core.h"
#include "Layer.h"
#include <vector>

namespace Parrot
{
	/// <summary>
	/// 层级栈，下标从小到大，对应的层级从底层到表层
	/// 渲染顺序：begin->end；事件处理顺序：end->begin
	/// </summary>
	class PARROT_API LayerStack
	{
	public:
		LayerStack();
		~LayerStack();

		void PushLayer(Layer* layer);
		void PopLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
		void PopOverlay(Layer* overlay);

		std::vector<Layer*>::iterator begin() noexcept { return m_Layers.begin(); }
		std::vector<Layer*>::iterator end() noexcept { return m_Layers.end(); }

	private:
		std::vector<Layer*> m_Layers;
		std::vector<Layer*>::iterator m_InsertPos;
	};
}
