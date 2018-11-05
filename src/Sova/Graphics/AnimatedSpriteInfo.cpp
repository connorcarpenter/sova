//
// Created by connor on 8/29/18.
//

#include "AnimatedSpriteInfo.h"

namespace Sova {
    AnimatedSpriteInfo::AnimatedSpriteInfo(Ref<Sova::String> fileName, int frameWidth, int frameHeight, int padding,
                                           int anchorX, int anchorY) {
        this->filename = fileName;
        this->frameWidth = frameWidth;
        this->frameHeight = frameHeight;
        this->padding = padding;
        this->anchorX = anchorX;
        this->anchorY = anchorY;
    }

    AnimatedSpriteInfo::AnimatedSpriteInfo(Ref<Sova::String> fileName, bool autoSize, int anchorX, int anchorY) {
        this->filename = fileName;
        this->anchorX = anchorX;
        this->anchorY = anchorY;
        this->autoSize = true;
    }
}
