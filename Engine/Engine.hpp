#ifndef C4B0CEFA_1011_497D_A74D_433EC8A8454E
#define C4B0CEFA_1011_497D_A74D_433EC8A8454E

#include "Render/Render.hpp"
#include "Utils/Time.hpp"
#include "Input/InputManager.hpp"

class Engine
{
private:
    static inline bool should_terminate_engine {false};
public:
    /**
     * @brief Inits engine
     * 
     * @return true success
     * @return false not success
     */
    static bool Init();

    /**
     * @brief Starts main engine loop
     * 
     */
    static void Loop();

    /**
     * @brief Clear engine's memory
     * 
     */
    static void Final();
};


#endif /* C4B0CEFA_1011_497D_A74D_433EC8A8454E */
