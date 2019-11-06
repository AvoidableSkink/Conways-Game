#pragma once

#include "Renderer.hpp"
#include "LifeSimulator.hpp"

class RendererConsole : public Renderer {

public:
	void render(const LifeSimulator& simulation);
};
