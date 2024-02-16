#ifndef SSPRITECOMPONENT_H
#define SSPRITECOMPONENT_H


#include "Component/CComponent.h"


struct SSpriteComponent: public  CComponent
{
    SSpriteComponent(const char *textureId, const char *source, float width, float height, int frameCount, int frameSpeed = 200):
        CComponent(__FUNCTION__),
        textureId(textureId),
        source(source),
        frameWidth(width),
        frameHeight(height),
        frameCount(frameCount),
        frameSpeed(frameSpeed)
    {
    }
    const char *textureId;
    const char *source;
    float frameWidth, frameHeight;
    int frameCount;
    int col = 0;
    int row = 0;
    int frameSpeed;
    float scale = 1;
    int zOrder = 0;
};


#endif // SSPRITECOMPONENT_H
