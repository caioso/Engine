#ifndef __GRAPHIC_ENGINE__
#define __GRAPHIC_ENGINE__

#include "../base/sprite.hpp"
#include "debug.hpp"
#include <string>
#include <grrlib.h>

// Handles graphics and image rendering in the system.
class GraphicEngine
{
    public: static Sprite * _stage;
    
    // Initialization Function
    public: static void Init();
    
    // World rendering method. The graphics engine will
    // render everything that is in the stage child list.
    // any other sprite in the system will not get rendered
    // by this class.
    public: static void Render ();
    
    // Renders Sprite lists for all children of _stage.
    // Must be called once each frame.
    private: static void RenderSprites (Sprite * sprite);
};

#endif // __GRAPHIC_ENGINE__