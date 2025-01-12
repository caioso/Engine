#pragma once
#ifndef __RULES_INTERFACE__
#define __RULES_INTERFACE__

#include "../types/panel.hpp"
#include "../types/changes.hpp"
#include "../types/logic_panel.hpp"

class RulesInterface
{
    public: virtual void Swap (LogicPanel *** _boardLogic, int boardW, int boardH, std::vector<Change> &changes, Point2D *cursorPosition) = 0;
    public: virtual void Detect (LogicPanel *** _boardLogic, int boardW, int boardH, vector<Change> &changes, vector<LogicPanel **> &_garbageList) = 0;
    public: virtual void Fall (LogicPanel *** _boardLogic, int boardW, int boardH, vector<Change> &changes, vector<LogicPanel **> &_garbageList) = 0;
    public: virtual void Slide (int boardW, int boardH, std::vector<Change> &changes) = 0;
    public: virtual void PauseBoardSlide () = 0;
    public: virtual void ResumeBoardSlide () = 0;
    public: virtual void SpeedUp() = 0;
    public: virtual void BoardAlert(LogicPanel *** _boardLogic, int boardW, int boardH, vector<Change> &changes) = 0;
};

#endif // __RULES_INTERFACE__
