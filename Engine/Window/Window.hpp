#ifndef E7944AC3_19E5_43DB_BD19_1D396276158A
#define E7944AC3_19E5_43DB_BD19_1D396276158A

#include "../GL.hpp"

class Window
{
public:
    uint16_t width {0}, height {0};
    GLFWwindow *glfw_win_ref {nullptr};
public:
    inline void SetAsCurrentContext() { glfwMakeContextCurrent(glfw_win_ref); };
public:
    Window(uint16_t w_width, uint16_t w_height, GLFWwindow *glfw_ref_win) : 
    width(w_width), height(w_height), glfw_win_ref(glfw_ref_win) {};
    ~Window(){};
};


#endif /* E7944AC3_19E5_43DB_BD19_1D396276158A */
