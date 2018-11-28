#pragma once
#include<iostream>
#include<string>
#include<vector>

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include "Vendor/Imgui/imgui.h"
#include "Vendor/Imgui/imgui_impl_glfw.h"
#include "Vendor/Imgui/imgui_impl_opengl3.h"

namespace EngineCore { namespace WindowCore {
	class Window
	{
	private:
		std::string m_title;
		int m_width;
		int m_height;

		GLFWwindow* m_handle;
	public:
		Window(std::string Title, int width, int height);
		Window(int a);
	};
}}