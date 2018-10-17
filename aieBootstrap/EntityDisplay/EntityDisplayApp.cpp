#include "EntityDisplayApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include <windows.h>
#include <iostream>

EntityDisplayApp::EntityDisplayApp() 
{

}

EntityDisplayApp::~EntityDisplayApp() 
{

}

bool EntityDisplayApp::startup()
{
	
	m_2dRenderer = new aie::Renderer2D();
	m_font = new aie::Font("./font/consolas.ttf", 32);


	setBackgroundColour(1, 1, 1);
	
	HANDLE fileHandle = OpenFileMapping(FILE_MAP_ALL_ACCESS, FALSE, L"numEntityCount");
	DWORD err = GetLastError();
	unsigned int* data = (unsigned int*)MapViewOfFile(fileHandle, FILE_MAP_ALL_ACCESS, 0, 0, sizeof(unsigned int));
	
	unsigned int numEntitys = *data;
	std::cout << numEntitys << std::endl;

	m_entities.resize(numEntitys);

	UnmapViewOfFile(data);
	CloseHandle(fileHandle);

	m_fileHandle = OpenFileMapping(FILE_MAP_ALL_ACCESS, FALSE, L"SharedEntityMemory");
	
	return true;
}

void EntityDisplayApp::shutdown()
{
	CloseHandle(m_fileHandle);
	delete m_font;
	delete m_2dRenderer;
}

void EntityDisplayApp::update(float deltaTime)
{

	// input example
	aie::Input* input = aie::Input::getInstance();

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();

	Entity* data = (Entity*)MapViewOfFile(m_fileHandle, FILE_MAP_ALL_ACCESS, 0, 0, sizeof(Entity) * m_entities.size());

	memcpy(m_entities.data(), data, sizeof(Entity) * m_entities.size());



	UnmapViewOfFile(data);
}

void EntityDisplayApp::draw() 
{

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// draw entities
	for (auto& entity : m_entities) {
		m_2dRenderer->setRenderColour(entity.r, entity.g, entity.b);
		m_2dRenderer->drawBox(entity.x, entity.y, entity.size, entity.size, entity.rotation);
	}
	
	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}