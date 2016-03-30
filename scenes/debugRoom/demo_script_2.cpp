#include "demo_script_2.hpp"

void DemoScript2::Start ()
{
    // Controller Test
    __remote_1 = new Controller(PPL_PLAYER_1);
    __remote_2 = new Controller(PPL_PLAYER_2);
    
    // Register Controller
    InputManager::RegisterController(__remote_1);
    InputManager::RegisterController(__remote_2);
    
    // Sprite Test
    __lv1 = new Sprite(scott, 80, 80, 96, 116);
    __lv2 = new Sprite(scott, 50, 50, 96, 116);
    __lv3 = new Sprite(scott, 50, 150, 96, 116);
    
    // Sound Effect and Music Test
    __sfx = new Sound(airwing, airwing_size, 1, 48000);
    __sfx1 = new Sound(sample, sample_size, 1, 22050/2);
    __msc = new Music(obstacles, obstacles_size, 1);
    __msc2 = new Music(magi, magi_size, -1);
    
    // Add Child
    GraphicEngine::_stage->AddChild(__lv1);
    __lv1->AddChild(__lv2);
    __lv1->AddChild(__lv3);
    
    // Play BGM
    AudioEngine::PlayMusic(__msc);
}

void DemoScript2::Update ()
{
    __lv1->_rotation++;
        
    // Check Behaviour
    if (__remote_1->CheckKeysOR(PPL_KEY_DOWN, 1, PPL_BUTTON_LEFT))
    {
        __lv2->_x -= 10;
        AudioEngine::StopSFX(__sfx);

    }
    if (__remote_1->CheckKeysOR(PPL_KEY_DOWN, 1, PPL_BUTTON_RIGHT))
    {
        AudioEngine::PlaySFX(__sfx1);
        __lv2->_x += 10;
    }
    if (__remote_1->CheckKeysOR(PPL_KEY_DOWN, 1, PPL_BUTTON_UP))
    {
        AudioEngine::PlayMusic(__msc2);
        __lv2->_y -= 10;
    }
    if (__remote_1->CheckKeysOR(PPL_KEY_DOWN, 1, PPL_BUTTON_DOWN))
    {
        AudioEngine::PlayMusic(__msc);
        __lv2->_y += 10;
    }
    if (__remote_1->CheckKeysOR(PPL_KEY_DOWN, 1, PPL_BUTTON_HOME) ||
        __remote_2->CheckKeysOR(PPL_KEY_DOWN, 1, PPL_BUTTON_HOME))
        exit(0);
    
    // Check Behaviour
    if (__remote_2->CheckKeysOR(PPL_KEY_DOWN, 1, PPL_BUTTON_LEFT))
        __lv3->_x -= 10;
    if (__remote_2->CheckKeysOR(PPL_KEY_DOWN, 1, PPL_BUTTON_RIGHT))
        __lv3->_x += 10;
    if (__remote_2->CheckKeysOR(PPL_KEY_DOWN, 1, PPL_BUTTON_UP))
        __lv3->_y -= 10;
    if (__remote_2->CheckKeysOR(PPL_KEY_DOWN, 1, PPL_BUTTON_DOWN))
        __lv3->_y += 10;
    
    if (__remote_1->CheckKeysOR(PPL_KEY_DOWN, 2, PPL_BUTTON_2, PPL_BUTTON_1))
    {
        AudioEngine::PlaySFX(__sfx);

        Debug::LogWarning("1 or 2 Button Pressed PLAYER 1");
    }

    if (__remote_2->CheckKeysAND(PPL_KEY_DOWN, 2, PPL_BUTTON_A, PPL_BUTTON_B))
    {
        Debug::LogWarning("A and B Button Pressed PLAYER 2");
    }

}

void DemoScript2::End () {}