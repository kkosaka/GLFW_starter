#include <iostream>
#include <gl/glew.h>
#include <GLFW/glfw3.h>

#include "mygl.h"
#include "Header.h"

// glfw��pragma��
#pragma comment(lib,"glfw3.lib")
#pragma comment(lib,"opengl32.lib")
// glew��pragma��
#pragma comment(lib,"glew32.lib")

//�v���W�F�N�^��ʔԍ�
#define FULLSCREEN 0
#define PROJECT_MONITOR_NUMBER (1)

// �ŏ������Ă΂��֐��i�T�u�X���b�h��run�̒��ŌĂԁj
int initCallFunc()
{
	// GLFW�̏�����
	if (glfwInit() == GL_FALSE)
	{
		std::cerr << "Can't initilize GLFW" << std::endl;
		return 1;
	}

	// OpenGL�̃o�[�W�����̑I��
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#if FULLSCREEN 
	// ���j�^�[�����o
	Projection::SearchDisplay();
	if (PROJECT_MONITOR_NUMBER > Projection::Disps_Prop.size() - 1)
	{
		std::cerr << "�f�B�X�v���C" << PROJECT_MONITOR_NUMBER << "��������܂���" << std::endl;
		exit(0);
	}

	Projection::Disp_Prop dispProp = Projection::Disps_Prop[PROJECT_MONITOR_NUMBER];		// �f�B�X�v���C���w��

	// �g�����`��
	glfwWindowHint(GLFW_DECORATED, GL_FALSE);
	myGL mygl(dispProp.width, dispProp.height);
	glfwSetWindowPos(mygl.getWindowID(), dispProp.x, dispProp.y);	// �E�B���h�E�ʒu
	glfwWindowHint(GLFW_DECORATED, GL_TRUE);
#else
	myGL mygl;
#endif

	mygl.init();
	while (mygl.shouldClose() == GL_FALSE)
	{
		// �`��
		mygl.display();

	}

	glfwTerminate();
	return 0;
}

int main()
{
	initCallFunc();

	return 0;
}
