#ifndef __CURSOR__
#define __CURSOR__

class Cursor : public Sprite
{
    public: Cursor (const unsigned char * image, int width = 65, int height = 32) : Sprite (image, width, height) {};
};

#endif // __CURSOR__
