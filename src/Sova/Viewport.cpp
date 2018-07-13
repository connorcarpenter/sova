//
// Created by connor on 7/8/18.
//

#include "Viewport.h"

namespace Sova {
    Sova::Viewport::Viewport(int x, int y, int width, int height, Ref<Camera> camera)
    {
        this->position = NewRef<Point>(x, y);
        this->width = width;
        this->height = height;
        this->camera = camera;
    }

    void Viewport::draw() {
        this->camera->draw(this->position->x, this->position->y);
    }
}