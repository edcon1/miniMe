#pragma once
#include "texture.h"
#include "renderer2D.h"
#include <iostream>

class GameObject
{
public:
	
	void setRender(aie::Renderer2D* renderer)
	{
		m_renderer = renderer;
	}

	void setTexture(aie::Texture* texture)
	{
		m_texture = texture;
	}

	// make render and texture functions and render them at 0,0

private:
	aie::Renderer2D* m_renderer;
	aie::Texture* m_texture;

};