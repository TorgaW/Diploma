#ifndef A79A247D_D4A9_42D2_9F1D_5A1AF9203796
#define A79A247D_D4A9_42D2_9F1D_5A1AF9203796

#include "Window.hpp"

class WindowsManager
{
private:
    static inline Window *main_window{nullptr};
    // static inline size_t windows_count{0};

public:
    static inline Window *GetMainWindow() { return main_window; };
    static inline GLFWwindow *GetMainWindowGLFW() { return main_window->glfw_win_ref; };
    static inline void SetMainWindow(Window *win) { main_window = win; };
    static Window *CreateWindow(const uint16_t width, const uint16_t height);
    static Window *CreateWindow();
};

#endif /* A79A247D_D4A9_42D2_9F1D_5A1AF9203796 */
