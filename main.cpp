#include <iostream>
#include <gl/glew.h>
#include <GLFW/glfw3.h>

#include "mygl.h"
#include "Header.h"

// glfwのpragma文
#pragma comment(lib,"glfw3.lib")
#pragma comment(lib,"opengl32.lib")
// glewのpragma文
#pragma comment(lib,"glew32.lib")

//プロジェクタ画面番号
#define FULLSCREEN 0
#define PROJECT_MONITOR_NUMBER (1)

// 最初だけ呼ばれる関数（サブスレッドのrunの中で呼ぶ）
int initCallFunc()
{
	// GLFWの初期化
	if (glfwInit() == GL_FALSE)
	{
		std::cerr << "Can't initilize GLFW" << std::endl;
		return 1;
	}

	// OpenGLのバージョンの選択
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#if FULLSCREEN 
	// モニターを検出
	Projection::SearchDisplay();
	if (PROJECT_MONITOR_NUMBER > Projection::Disps_Prop.size() - 1)
	{
		std::cerr << "ディスプレイ" << PROJECT_MONITOR_NUMBER << "が見つかりません" << std::endl;
		exit(0);
	}

	Projection::Disp_Prop dispProp = Projection::Disps_Prop[PROJECT_MONITOR_NUMBER];		// ディスプレイを指定

	// 枠無し描画
	glfwWindowHint(GLFW_DECORATED, GL_FALSE);
	myGL mygl(dispProp.width, dispProp.height);
	glfwSetWindowPos(mygl.getWindowID(), dispProp.x, dispProp.y);	// ウィンドウ位置
	glfwWindowHint(GLFW_DECORATED, GL_TRUE);
#else
	myGL mygl;
#endif

	mygl.init();
	while (mygl.shouldClose() == GL_FALSE)
	{
		// 描画
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
