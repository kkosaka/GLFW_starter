#ifndef MYGL_H
#define MYGL_H

#include <iostream>

#include <gl/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "window.h"
#include "texture.h"

class myGL : public Window
{

public:
	// コンストラクタ
	myGL(int width = 640, int height = 480, const char *title = "Projection") : Window(width, height, title)
	{
		// コールバック
		glfwSetFramebufferSizeCallback(window, resize);
		glfwSetKeyCallback(window, keyboard);

		// インスタンスのthisポインタを記録
		glfwSetWindowUserPointer(window, this);
	};
	~myGL(){};

	// 初期処理
	void init();

	// 毎フレーム行う処理
	void display();

	// カラーバッファを入れ替えてイベントを取り出す
	//void swapBuffers();

	void idle();


	// コールバック処理
	static void keyboard(GLFWwindow *window, int key, int scancode, int action, int mods);
	static void resize(GLFWwindow *const window, int width, int height);

	void close();
	void timer(int value);

private:
	//glsl
	GLuint program;
	GLuint vertexbuffer;
	GLuint texturebuffer;

	std::vector<Texture*> m_Texture;
};

#endif
