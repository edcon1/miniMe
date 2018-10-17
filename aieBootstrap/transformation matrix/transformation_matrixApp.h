#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "GameObject.h"

class transformation_matrixApp : public aie::Application {
public:

	GameObject object;
	

	transformation_matrixApp();
	virtual ~transformation_matrixApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;
};