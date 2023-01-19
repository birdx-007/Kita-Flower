#include "frameanimation.h"

FrameAnimation::FrameAnimation()
{

}

void FrameAnimation::initAnimation(std::vector<std::pair<QPixmap, int> > s)
{
    this->sprites=s;
    this->curSpriteIdx=0;
    this->curSpriteLeftFrames=this->sprites[this->curSpriteIdx].second;
}

void FrameAnimation::update()
{
    this->curSpriteLeftFrames--;
    if(this->curSpriteLeftFrames==0)
    {
        this->nextSprite();
    }
}

void FrameAnimation::nextSprite()
{
    this->curSpriteIdx=(this->curSpriteIdx+1)%this->sprites.size();
    this->curSpriteLeftFrames=this->sprites[this->curSpriteIdx].second;
}

int FrameAnimation::getCurSpriteIdx()
{
    return this->curSpriteIdx;
}

void FrameAnimation::setCurSpriteIdx(int idx)
{
    this->curSpriteIdx=idx;
}

int FrameAnimation::getCurSpriteLeftFrames()
{
    return this->curSpriteLeftFrames;
}

void FrameAnimation::setCurSpriteLeftFrames(int frame)
{
    this->curSpriteLeftFrames=frame;
}

QPixmap FrameAnimation::getCurSprite()
{
    return this->sprites[this->curSpriteIdx].first;
}
