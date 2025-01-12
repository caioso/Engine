#ifndef __SPRITE__
#define __SPRITE__

#include <grrlib.h>
#include <vector>

#include "../system/debug.hpp"
#include "../types/visibility.hpp"
#include "../types/transformation.hpp"

using namespace std;

// Class that represents a drawable Sprite asset.
// The coordinate system of any Sprite starts at the top-left corner
// of the asset.
class Sprite
{
    friend class AnimationEngine;
    friend class GraphicEngine;

    public: float _x;
    public: float _y;
    public: float _width;
    public: float _height;
    public: float _rotation;
    public: float _scaleX;
    public: float _scaleY;
    public: char _alpha;
    public: Sprite * _parent;
    public: Visibility _visibility;
    private: bool _isAnimating;
    private: GRRLIB_texImg* _tex;
    private: vector<Sprite*> _children;
    public: int _offsetX;
    public: int _offsetY;

    // Animation
    public: vector<GRRLIB_texImg*> _frames;
    public: vector<Transformation> _transformations;
    private: unsigned int _current_frame;
    private: bool _is_playing;
    private: bool _repeat;
    public: bool _auto_destroy;
    public: int _animation_delay;
    private: int _current_delay;

    // Generic Constructor Method.
    // This Constructor makes sure the Sprite position is set to (0,0).
    public: Sprite () : _x(0), _y(0), _width(0), _height(0), _rotation(0), _scaleX(1), _scaleY(1), _alpha(255), _parent(NULL), _tex(NULL), _offsetX(0), _offsetY(0), _current_frame(0), _is_playing(false), _repeat(true), _auto_destroy(true), _animation_delay(0), _current_delay(0) {}

    // Coordinate defining constructor. Width and height set null.
    // @param x: asset x coordinate.
    // @param y: asset y coordinate.
    public: Sprite (float x, float y) : _x(x), _y(y), _width(0), _height(0), _rotation(0), _scaleX(1), _scaleY(0), _alpha(255), _parent(NULL), _tex(NULL), _offsetX(0), _offsetY(0),  _current_frame(0), _is_playing(false), _repeat(true), _auto_destroy(true), _animation_delay(0), _current_delay(0) {}

    // Asset defining constructor. The Sprite coordinates are set to (0,0). Width and height set null.
    // @param asset: unsigned char array of the asset.
    public: Sprite (GRRLIB_texImg* asset);

    // Asset defining constructor. The Sprite coordinates are set to (0,0).
    // @param asset: unsigned char array of the asset.
    // @param width: sprite image width.
    // @param height: sprite image height.
    public: Sprite (GRRLIB_texImg* asset, float width, float height);

    // Full definition constructor.
    // @param asset: unsigned char array of the asset.
    // @param x: asset x coordinate.
    // @param y: asset y coordinate.
    // @param width: sprite image width.
    // @param height: sprite image height.
    public: Sprite (GRRLIB_texImg* asset, float x, float y, float width, float height);

    // Return Texture Object
    public: GRRLIB_texImg*  GetTexture() { return _tex; }

    // Return IsAnimating attribute
    public: bool GetIsAnimating() { return _isAnimating; }

    // Manually loads an asset object into the Sprite.
    // @param asset: asset array.
    // @param width: asset width.
    // @param height: asset height.
    // @param offsetX: sprite coordinate offset X (default 0).
    // @param offsetY: sprite coordinate offset Y (default 0).
    public: void SetAsset (GRRLIB_texImg* asset, float width, float height, int offsetX = 0, int offsetY = 0);

    // Add child Sprite to the current Sprite children list.
    // @param child: Child sprite to be stored in this Sprite children list.
    public: void AddChild (Sprite* child);

    // Add child Sprite to the current Sprite children list at a specific position.
    // @param child: Child sprite to be stored in this Sprite children list.
    // @param index: Inteded child index.
    public: void AddChildAt (Sprite* child, int index);

    // Remove child Sprite to the current Sprite children list, based on a Sprite reference.
    // @param child: Child sprite to be removed in this Sprite children list.
    public: void RemoveChild (Sprite* child);

    // Return children list vector
    public: vector<Sprite*> GetChildren () { return _children;}

    // Initializes the sprite object in GRRLIB.
    private: void DefineSprite ();

    // Returns the number of children in a sprite list.
    // @return: children list size.
    public: size_t GetChildrenNumber () { return _children.size(); }

    // Register frame in the animation list.
    // @param _frame: Frame texture reference.
    // @return inform if the operation was successful.
    public: bool RegisterFrame (GRRLIB_texImg * _frame);

    // Register frame in the animation list.
    // @param _frame: Frame texture reference.
    // @param _transformation: Transfromation
    // @return inform if the operation was successful.
    public: bool RegisterFrameWithTransformation (GRRLIB_texImg * _frame, Transformation _transformation);

    // Starts animation or resume if previously paused.
    public: void Play () { _is_playing = true; }

    // Pause animation.
    public: void Pause () { _is_playing = false; }

    // Stop animation and restart current frame.
    public: void Stop () { _is_playing = false; _current_frame = 0; }

    // Renders a target frame and stops animation.
    // @param target_frame: Frame number to be rendered (0-based).
    public: void GotoAndStop (unsigned int target_frame);

    // Returns Current frame
    // @return current animation frame.
    public: int GetCurrentFrame () { return _current_frame; }

    // Returns Is Playing State
    // @return Is playing state.
    public: bool GetIsPlaying () { return _is_playing; }

    // Renders a target frame and play animation.
    // @param target_frame: Frame number to be rendered (0-based).
    public: void GotoAndPlay (unsigned int target_frame);

    // Renders a target frame.
    // @param target_frame: Frame number to be rendered (0-based).
    private: void GotoFrame (unsigned int target_frame);

    // Go to next frame.
    private: void NextFrame ();

    // Set repeat switch.
    // @param repeat: repeat value.
    public: void SetRepeat (bool repeat) { _repeat = repeat; }

    // Standard Destructir
    public: virtual ~Sprite();
};

#endif // __SPRITE__
