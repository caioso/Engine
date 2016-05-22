#include "graphic_engine.hpp"

Sprite * GraphicEngine::_stage;

void GraphicEngine::Init ()
{
    GRRLIB_Init();
    _stage = new Sprite(0, 0);
}

void GraphicEngine::Render()
{
    RenderSprites (_stage);
}

void GraphicEngine::RenderSprites (Sprite * sprite)
{
    int __stack_size = sprite->GetChildren().size();
    
    // Break Condition
    if (__stack_size == 0) return;
    
    for (int i = 0; i < __stack_size; i++)
    {
        Sprite * __tmp = sprite->GetChildren()[i];
        RenderSprites(__tmp);
        if (__tmp->GetTexture() != NULL)
        {
            if (__tmp->_visibility == visible)
            {
                // Correct Position in terms of all parents
                float __x = 0, __y = 0;
                Sprite * __ref = __tmp->_parent;
                
                // Compute Relative positions
                while (__ref != NULL)
                {
                    __x += __ref->_x;
                    __y += __ref->_y;
                    __ref = __ref->_parent;
                }
                
                // Compute sprite animations if this is the case.
                if (__tmp->_frames.size() > 0)
                    UpdateSpriteAnimation(__tmp);
                
                // If not repeating, destroy the sprite
                if (!__tmp->_repeat && __tmp->_current_frame >= __tmp->_frames.size() - 1)
                {
                    Debug::Log("Test");
                    sprite->RemoveChild(__tmp);
                    __stack_size--;
                    i--;
                    __tmp = NULL;
                    continue;
                }
                
                GRRLIB_DrawImg(__tmp->_x + __x, __tmp->_y + __y, __tmp->GetTexture(), __tmp->_rotation, __tmp->_scaleX, __tmp->_scaleY, PPL_COLOR_WHITE);
            }
        }
        //else
        //    Debug::LogWarning("Sprite without texture loaded. Skipped.");
    }
}

void GraphicEngine::UpdateSpriteAnimation(Sprite* tmp)
{
    if (!tmp->_is_playing)
        return;
    else
    {
        if (tmp->_current_frame == tmp->_frames.size() - 1 && tmp->_repeat)
        {
            tmp->GotoFrame(0);
        }
        else if (tmp->_current_frame != tmp->_frames.size() - 1)
        {
            tmp->NextFrame();
        }
        else
            return;
    }
}