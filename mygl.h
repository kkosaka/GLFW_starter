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
	// �R���X�g���N�^
	myGL(int width = 640, int height = 480, const char *title = "Projection") : Window(width, height, title)
	{
		// �R�[���o�b�N
		glfwSetFramebufferSizeCallback(window, resize);
		glfwSetKeyCallback(window, keyboard);

		// �C���X�^���X��this�|�C���^���L�^
		glfwSetWindowUserPointer(window, this);
	};
	~myGL(){};

	// ��������
	void init();

	// ���t���[���s������
	void display();

	// �J���[�o�b�t�@�����ւ��ăC�x���g�����o��
	//void swapBuffers();

	void idle();


	// �R�[���o�b�N����
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
