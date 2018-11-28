#include "Window.h"
#include<cassert>

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include "Vendor/Imgui/imgui.h"
#include "Vendor/Imgui/imgui_impl_glfw.h"
#include "Vendor/Imgui/imgui_impl_opengl3.h"

EngineCore::WindowCore::Window::Window(std::string Title, int width, int height)
	:
	m_height(height),
	m_width(width),
	m_title(Title)
{
	assert(glfwInit()); //Glfw Has To Initialize In Order To Move Forward

	const char* glsl_version = "#version 130";
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

	m_handle = glfwCreateWindow(m_width, m_height, m_title.c_str(), NULL, NULL); //Creates The MainWindow...

	assert(m_handle);
	
	/* Make the window's context current */
	glfwMakeContextCurrent(m_handle);

	//glfwSwapInterval(1); // Enable vsync
	bool err = glewInit();
	assert(err == GLEW_OK);
		
	std::cout << glGetString(GL_VERSION) << std::endl;

	//Initialize GU Interface
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	//ImGui_ImplGlfwGL3_Init(MainWindow, true);
	ImGui_ImplGlfw_InitForOpenGL(m_handle, true);
	ImGui_ImplOpenGL3_Init(glsl_version);
	ImGui::StyleColorsDark();//Imgui Style
		
}

EngineCore::WindowCore::Window::Window(int a)
{
	std::cout << "Hi" << std::endl;
}
