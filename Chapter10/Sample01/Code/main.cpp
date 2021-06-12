/* based by
 * [OpenGL入門から3DCGレンダラ実装まで その1 - Qiita]
 * (https://qiita.com/strv13570/items/f3926d49a50ae87086d1)
 */

#include "glad.h"
#include <GLFW/glfw3.h>

#include <iostream>
#include "Application.h"
#include "Sample.h"

#include <unistd.h>
#include <time.h>

const unsigned int WINDOW_WIDTH = 1440;
const unsigned int WINDOW_HEIGHT = 810;

Application* gApplication = 0;
GLuint gVertexArrayObject = 0;

void keyHandler(GLFWwindow*, int, int, int, int);
uint32_t getTick();

int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "advent_gl", nullptr, nullptr);

    if (!window)
    {
        std::cerr << "Failed to create window." << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, keyHandler);

    if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress)))
    {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    //add
    glGenVertexArrays(1, &gVertexArrayObject);
    glBindVertexArray(gVertexArrayObject);
    //initialize application 
    gApplication = new Sample();
    gApplication->Initialize();


    unsigned int lastTick = getTick();//GetTickCount();
    while (!glfwWindowShouldClose(window))
    {
      //update timer 
      unsigned int thisTick = getTick(); //GetTickCount();
      float deltaTime = float(thisTick - lastTick) * 0.001f;
      lastTick = thisTick;

    if (gApplication != 0)
    {
         gApplication->Update(deltaTime);
    }

      if (gApplication != 0)
      {
          //RECT clientRect;
          //GetClientRect(hwnd, &clientRect);
          //clientWidth = clientRect.right - clientRect.left;
          //clientHeight = clientRect.bottom - clientRect.top;
          //glViewport(0, 0, clientWidth, clientHeight);
          glEnable(GL_DEPTH_TEST);
          glEnable(GL_CULL_FACE);
          glPointSize(5.0f);
          glBindVertexArray(gVertexArrayObject);

          glClearColor(0.5f, 0.6f, 0.7f, 1.0f);
          glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
          float aspect = (float)WINDOW_WIDTH/(float)WINDOW_HEIGHT;
          //float aspect = (float)clientWidth / (float)clientHeight;
          
          gApplication->Render(aspect);
      }

      /*
      if (gApplication != 0)
      {
        SwapBuffers(hdc);
        if (vsynch != 0)
        {
            glFinish();
        }
      }
      */
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

void keyHandler(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    switch (key)
    {
        case GLFW_KEY_ESCAPE:
            if (action == GLFW_PRESS)
            {
                glfwSetWindowShouldClose(window, GLFW_TRUE);
            }
            break;
    }
}

uint32_t getTick() {
    struct timespec ts;
    unsigned theTick = 0U;
    clock_gettime( CLOCK_REALTIME, &ts );
    theTick  = ts.tv_nsec / 1000000;
    theTick += ts.tv_sec * 1000;
    return theTick;
}
