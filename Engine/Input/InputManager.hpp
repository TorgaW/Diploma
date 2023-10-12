#ifndef E7A09C7A_302C_4416_83AA_C01DCF8421AD
#define E7A09C7A_302C_4416_83AA_C01DCF8421AD

#include "../Window/WindowsManager.hpp"

struct cursor_lock
{
    bool locked;
    size_t for_id;
    void set_locked(size_t id)
    {
        locked = true;
        for_id = id;
    }
    void unlock()
    {
        locked = false;
        for_id = 0;
    }
    void unlock_strict(size_t id)
    {
        if(id == for_id) 
        {
            locked = false;
            for_id = 0;
        }
    }
    bool is_locked(size_t id)
    {
        return locked && id == for_id;
    }
    bool is_free_or_locked_by(size_t id)
    {
        return (for_id == 0 && !locked) || (for_id == id && locked);
    }
};


class InputManager
{
public:
    static inline cursor_lock cursor_locked {false, 0};
    static inline void SetGLFWInputMode(int mode, int value)
    {
        glfwSetInputMode(WindowsManager::GetMainWindow()->glfw_win_ref, mode, value);
    };
};


#endif /* E7A09C7A_302C_4416_83AA_C01DCF8421AD */
