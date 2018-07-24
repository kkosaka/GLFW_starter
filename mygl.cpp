#include "mygl.h"


/* �ŏ���1�񂾂��Ă΂��֐� */
void myGL::init()
{

	std::cout << "r�F���Z�b�g" << std::endl;
	std::cout << "q�F�I��" << std::endl;
}


/* ���C���̕`�揈�� */
void myGL::display()
{
	glClearColor(0.0f, 1.0f, 1.0f, 0.0f);
	// �E�B���h�E����������
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	// �J���[�o�b�t�@�����ւ�,�C�x���g���擾
	swapBuffers();

}


/* �L�[�{�[�h���쎞�̏��� */
void myGL::keyboard(GLFWwindow *window, int key, int scancode, int action, int mods)
{
	// this�|�C���^���擾
	myGL *const instance = static_cast<myGL*>(glfwGetWindowUserPointer(window));
	if (instance != NULL)
	{
		instance->keyStatus = action;
		switch (key){
		case GLFW_KEY_K:
			std::cout << "a";
			break;
		} 
	}

}
/* ���T�C�Y���̏��� */
void myGL::resize(GLFWwindow *const window, int width, int height)
{
	// �E�B���h�E�S�̂��r���[�|�[�g
	glViewport(0, 0, width, height);

	// this�|�C���^���擾
	myGL *const instance(static_cast<myGL *>(glfwGetWindowUserPointer(window)));
	if (instance != NULL)
	{
		instance->windowWidth = width;
		instance->windowHeight = height;
	}
}
