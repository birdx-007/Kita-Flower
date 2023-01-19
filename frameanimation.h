#ifndef FRAMEANIMATION_H
#define FRAMEANIMATION_H

#include <vector>
#include <QPixmap>

class FrameAnimation
{
public:
    FrameAnimation();
    void initAnimation(std::vector<std::pair<QPixmap,int>> s);
    void update();
    void nextSprite();
    int getCurSpriteIdx();
    void setCurSpriteIdx(int idx);
    int getCurSpriteLeftFrames();
    void setCurSpriteLeftFrames(int frame);
    QPixmap getCurSprite();
private:
    int curSpriteIdx;
    int curSpriteLeftFrames;
    std::vector<std::pair<QPixmap,int>> sprites;//每一张图及其持续帧数
};

#endif // FRAMEANIMATION_H
