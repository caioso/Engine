#pragma once
#ifndef __LOGIC_PANEL__
#define __LOGIC_PANEL__

class LogicPanel
{
    // Logic Panel Type
    public: int _type;

    // Panel State
    // 0: Steady
    // 1: Falling
    // 2: Swapping
    // 3: Breaking
    // 4: Waiting to fall
    // 5: fall frame 1
    // 6: fall frame 2
    // 7: fall frame 3
    // 8: fall frame 4
    // 9: fall frame 5
    // 10: fall frame 6
    // 11: fall frame 7
    // 12: fall frame 8
    // 13: fall frame 9
    // 14: fall frame 10
    // 15: Garbage panel waiting to transform.
    // 16: Garbage panel being transformed into smaller garbage.
    public: int _state;

    // Fall delay counter
    public: int _wait;

    // Target wait value reached when break should be trigged.
    public: int _break_delay;

    // Chain side-effect flag
    public: int _in_chain;

    // Garbage only data
    public: int _positionX;
    public: int _positionY;
    public: int _sourceX;
    public: int _sourceY;
    public: int _width;
    public: int _height;
};

#endif // __LOGIC_PANEL__
