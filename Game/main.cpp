#include<iostream>
#include<string>

#include "EngineCore/EngineCore.h" 
#include "EngineCore/WindowCore/Window.h"

#include "GL/glew.h"
#include "GLFW/glfw3.h"

int main()
{
	EngineCore::WindowCore::Window wnd("Test", 1920, 1080);
	//EngineCore::WindowCore::Window wnd(5);
	std::cin.get();
}