#pragma once

#include "Application.h"
#include "Renderer2D.h"


class space_invaders_2_0App : public aie::Application {
public:


	space_invaders_2_0App();
	virtual ~space_invaders_2_0App();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();
	
	

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;
	aie::Texture*       m_invader;
	aie::Texture*       m_sheild;
	aie::Texture*       m_ship;


};



