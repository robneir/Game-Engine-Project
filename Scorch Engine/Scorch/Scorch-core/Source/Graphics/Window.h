#ifndef _WINDOW_
#define _WINDOW_

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace Scorch {
namespace Graphics {

#define MAX_KEYS				1024
#define MAX_MOUSE_BUTTONS		32

	class Window
	{
	public:
		// input private members.
		static bool m_keys[MAX_KEYS];
		static bool m_mouseButtons[MAX_MOUSE_BUTTONS];
		static double m_mouseX, m_mouseY;

	public:
		// window functions
		Window(char* title, int width, int height);
		~Window();
		void Update();
		void Clear() const;
		bool IsClosed() const;
		inline int getWidth() const { return m_width; }
		inline int getHeight() const { return m_height;  }

		// input functions
		bool isKeyPressed(unsigned int keyCode) const;
		bool isMouseButtonPressed(unsigned int buttonCode) const;
		void getMousePosition(double& x, double& y) const;

	private:
		// window private members.
		int m_width;
		int m_height;
		char* m_title;
		bool m_isClosed;
		GLFWwindow* m_window;

	private:
		bool init();
		// these callbacks are friends so they can access m_window and other members of Window.
		friend static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
		friend static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods); 
		friend static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
	}; // Window class

}; // Graphics namespace
}; // Scorch namespace

#endif