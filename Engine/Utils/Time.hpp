#ifndef E9222090_8122_4CC4_86CF_F9EFF324E470
#define E9222090_8122_4CC4_86CF_F9EFF324E470

#include <GLFW/glfw3.h>

class Time
{
public:
    static inline double d_delta_time{0.0};
    static inline float delta_time{0.0};
    static inline double d_update_thread_delta_time{0.0};
    static inline float update_thread_delta_time{0.0};
public:
    static inline double GetSecondsSinceStart() { return glfwGetTime(); };
    static inline void UpdateDeltaTime()
    {
        current_frame_time = glfwGetTime();
        d_delta_time = current_frame_time - prev_frame_time;
        delta_time = d_delta_time;
        prev_frame_time = current_frame_time;
    }
    static inline void UpdateThreadDeltaTime()
    {
        current_thread_frame_time = glfwGetTime();
        d_update_thread_delta_time = current_thread_frame_time - prev_thread_frame_time;
        update_thread_delta_time = d_update_thread_delta_time;
        prev_thread_frame_time = current_thread_frame_time;
    }
private:
    static inline double prev_frame_time {0.0};
    static inline double current_frame_time {0.0};
    static inline double prev_thread_frame_time {0.0};
    static inline double current_thread_frame_time {0.0};
};


#endif /* E9222090_8122_4CC4_86CF_F9EFF324E470 */
