#pragma once

#include "Application.h"
#include "Renderer2D.h"

class vector3App : public aie::Application {
public:

	vector3App();
	virtual ~vector3App();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;
};