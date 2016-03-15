#ifndef __BOARD__
#define __BOARD__

// Engine includes
#include "../../engine/engine.hpp"

// Required includes
#include "types/panel.hpp"
#include "types/logic_panel.hpp"
#include "types/changes.hpp"
#include "cursor.hpp"
#include "rules/rules_interface.hpp"

// Assets
#include "../../assets/graphics/dred.h"
#include "../../assets/graphics/dblue.h"
#include "../../assets/graphics/dgreen.h"
#include "../../assets/graphics/dyellow.h"
#include "../../assets/graphics/dpurple.h"
#include "../../assets/graphics/dred1.h"
#include "../../assets/graphics/dblue1.h"
#include "../../assets/graphics/dgreen1.h"
#include "../../assets/graphics/dyellow1.h"
#include "../../assets/graphics/dpurple1.h"
#include "../../assets/graphics/cursor.h"

// Board class centers everything regarding rules and board presentation.
// Animations are also defined in this class.
class Board
{
    // Graphics Elements
    private: Panel *** _boardGraphics;
    private: Panel ** _tmpGraphics;
    private: LogicPanel *** _boardLogic;
    private: LogicPanel ** _tmpLogic;
    private: Dim2D _dimensions;
    private: Point2D _position;
    private: Cursor * _cursor;
    private: RulesInterface * _rules;
    private: vector<Change> _changes;
    private: Sprite * _boardContainer;
    private: Sprite * _tmpContainer;

    // Control Elements
    private: Point2D _cursorPosition;

    // Default Constructor, Builds a random set of panels, based on the
    // dimension provided as argument. The board origin point is determined
    // by pos argument.
    // @param dim: the number of rows and columns in the board.
    // @param pos: the origin point used as reference for the board
    // coordinate system.
    // @param cur_pos: Initial cursor position.
    public: Board(RulesInterface * _rules, Dim2D dim, Point2D pos, Point2D cur_pos);

    // Updates cursor position and graphics position based on a point.
    // @param pos: relative position object, each unity in pos object
    // actually represents a columna and a row, which will be converted
    // to actual pixel values, in the function.
    public: void UpdateCursorPosition(Point2D pos);
    
    // Swap two panels based on the rules specification.
    public: void Swap();
    
    // Update Board Graphics once at each frame. Uses change language to
    // parse each change the rules have commited and update the frame
    // accordingly.
    public: void BindLogic();
    
    // Detect combos in the board and promp the related panels to be broken.
    public: void Detect();

    // Update panel position (vertically) to make the ilusion of gravity.
    public: void Fall();
    
    public: void Slide();
    
    public: void SpeedUp();
    
    public: void SlowDown();
    
    // Helper function. Update the state of panels above targetY.
    // @param targetX: horizontal position of the panel.
    // @param targetY: vertical position of the panel.
    private: void BlockAbove (unsigned int targetX, unsigned int targetY);
    
    // Decodes a type and returns the buffer related to the type.
    // @param type: panel type to be decode.
    // @return type buffer.
    private: const unsigned char *  decodeType (unsigned int type);
    
    private: const unsigned char *  decodeLightType (unsigned int type);

    // Returns current cursor position.
    // @return Point2D: current cursor position.
    public: Point2D getCursorPosition() { return _cursorPosition; }

    // Default Constructor
    public: ~Board ();
};

#endif // __BOARD__
