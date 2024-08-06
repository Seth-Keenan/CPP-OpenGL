#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

int main(void)
{
    //Initalize the library
    glfwInit();  

    //This is just to tell glfw what verison of opengl we are using
    //ex 3.3 is major 3 minor 3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    //This is to specify that we are using the core profile which has only the new gl functions
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    //Create the window
    GLFWwindow * window = glfwCreateWindow(800, 800, "First OpenGL App", NULL, NULL);

    //fail checking
    if(window == NULL)
    {
        std::cout << "Failed to create the window" << std::endl;
        glfwTerminate();
        return -1;
    };

    //Context is a super important 
    glfwMakeContextCurrent(window);

    //Load glad to configure opengl
    gladLoadGL();

    //This will create a renderable space for GL
    glViewport(0,0,800,800);

    //Creating the background color
    glClearColor(0.54f, 0.18f, 0.63f, 1.0f);
    //Loading it into the buffer
    glClear(GL_COLOR_BUFFER_BIT);
    //Setting the buffer for the window
    glfwSwapBuffers(window);

    while(!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
    };

    //Successfully close the window
    glfwDestroyWindow(window);

    //Terminate the library
    glfwTerminate();
    return 0;
};