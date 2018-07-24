#include "mygl.h"


/* 最初に1回だけ呼ばれる関数 */
void myGL::init()
{

	std::cout << "r：リセット" << std::endl;
	std::cout << "q：終了" << std::endl;
}


/* メインの描画処理 */
void myGL::display()
{
	glClearColor(0.0f, 1.0f, 1.0f, 0.0f);
	// ウィンドウを消去する
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	// カラーバッファを入れ替え,イベントを取得
	swapBuffers();

}


/* キーボード操作時の処理 */
void myGL::keyboard(GLFWwindow *window, int key, int scancode, int action, int mods)
{
	// thisポインタを取得
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
/* リサイズ時の処理 */
void myGL::resize(GLFWwindow *const window, int width, int height)
{
	// ウィンドウ全体をビューポート
	glViewport(0, 0, width, height);

	// thisポインタを取得
	myGL *const instance(static_cast<myGL *>(glfwGetWindowUserPointer(window)));
	if (instance != NULL)
	{
		instance->windowWidth = width;
		instance->windowHeight = height;
	}
}
