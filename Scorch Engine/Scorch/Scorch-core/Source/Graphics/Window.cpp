#include "Window.h"

namespace Scorch {
namespace Graphics {
	
	// initialize statics.
	bool Window::m_keys[MAX_KEYS];
	bool Window::m_mouseButtons[MAX_MOUSE_BUTTONS];
	double Window::m_mouseX;
	double Window::m_mouseY;
	// forward declare functions.
	void window_resize_callback(GLFWwindow* window, int width, int height);

	Window::Window(char* title, int width, int height) :
		m_width(width),
		m_height(height),
		m_title(title)
	{
		if (!init())
		{
			glfwTerminate();
		}

		// initialize all keys to false
		for (int i = 0; i < MAX_KEYS; i++)
		{
			m_keys[i] = false;
		}
		// initialize all keys to false
		for (int i = 0; i < MAX_MOUSE_BUTTONS; i++)
		{
			m_mouseButtons[i] = false;
		}
	}

	Window::~Window()
	{
		glfwTerminate();
	}

	/* initializes glfw (graphics library framework) 
		and creates a window. */
	bool Window::init()
	{
		// initialize glfw
		if (!glfwInit())
		{
			std::cout << "ERROR:: Main.cpp:: glfwInit():: could not initialize glfw." << std::endl;
			return false;
		}
		else
		{
			std::cout << "succesfully initialized glfw." << std::endl;
		}

		// create new window.
		m_window = glfwCreateWindow(m_width, m_height, m_title, NULL, NULL);
		if (!m_window)
		{
			// window or OpenGL context creation failed
			std::cout << "ERROR:: Window.cpp:: createWindow():: could not create window." << std::endl;
			return false;
		}

		/* This function makes the context of the specified window
		current on the calling thread. A context can only be made current
		on a single thread at a time and each thread can have only a
		single current context at a time. */
		glfwMakeContextCurrent(m_window);


		// set callback for when window size changes.
		glfwSetWindowSizeCallback(m_window, window_resize_callback);
		// sets window user pointer to be used in callbacks.
		glfwSetWindowUserPointer(m_window, this);
		// setup keyboard callbacks.
		glfwSetKeyCallback(m_window, key_callback);
		// setup mouse position callback.
		glfwSetCursorPosCallback(m_window, cursor_position_callback);
		// setup mouse callbacks.
		glfwSetMouseButtonCallback(m_window, mouse_button_callback);
		// disable vsync
		glfwSwapInterval(0);

		// initialize glew
		if (glewInit() != GLEW_OK)
		{
			std::cout << "ERROR:: Window.cpp:: createWindow():: could not initialize glew." << std::endl; \
			return false;
		}
		std::cout << "OpenGL version: " << glfwGetVersionString() << std::endl;

		return true;
	}

	/* returns if window should be closed. */
	bool Window::IsClosed() const
	{
		return (glfwWindowShouldClose(m_window) == 1);
	}

	/* gets event and swaps buffers. */
	void Window::Update()
	{
		// Check for Open GL syntax error and print if there is.
		GLenum error = glGetError();
		if (error != GL_NO_ERROR)
		{
			std::cout << "OpenGL error: " << error << std::endl;
		}

		glfwPollEvents();
		
		/* swap buffers because double buffering. */
		glfwSwapBuffers(m_window);
	}

	/* clears the color and depth buffers. */
	void Window::Clear() const
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	bool Window::isKeyPressed(unsigned int keyCode) const
	{
		if (keyCode >= MAX_KEYS)
		{
			// LOG THIS!
			return false;
		}
		return m_keys[keyCode];
	}

	bool Window::isMouseButtonPressed(unsigned int buttonCode) const
	{
		if (buttonCode >= MAX_KEYS)
		{
			// LOG THIS!
			return false;
		}
		return m_mouseButtons[buttonCode];
	}
	
	void Window::getMousePosition(double& x, double& y) const
	{
		x = m_mouseX;
		y = m_mouseY;
	}

	void window_resize_callback(GLFWwindow* window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}

	void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		Window* win = (Window*) glfwGetWindowUserPointer(window);
		if (action != GLFW_RELEASE)
		{
			win->m_keys[key] = true;
		}
	}

	void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
	{
		Window* win = (Window*)glfwGetWindowUserPointer(window);
		if (action != GLFW_RELEASE)
		{
			win->m_mouseButtons[button] = true;
		}
	}

	void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
	{
		Window* win = (Window*)glfwGetWindowUserPointer(window);
		win->m_mouseX = xpos;
		win->m_mouseY = ypos;
	}

}; // Graphics namespace
}; // Scorch namespace