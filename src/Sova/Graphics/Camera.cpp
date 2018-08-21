//
// Created by connor on 7/8/18.
//

#include <Modules/Gfx/Gfx.h>
#include "Camera.h"
#include "Container.h"
#include "Internal/InternalCamera.h"

namespace Sova
{
    Sova::Camera::Camera(int x, int y, int width, int height, Ref <Container> target, Color bckColor, float bckAlpha, bool autoDraw)
    {
        this->position = New<Point>(x, y);
        this->width = width;
        this->height = height;
        this->target = target;
        this->autoDraw = autoDraw;
        this->backgroundColor = bckColor;
        this->backgroundAlpha = bckAlpha;

        this->internalCamera = new InternalCamera(this);
    }

    Camera::~Camera() {
        delete this->internalCamera;
    }

    void Sova::Camera::draw(int xoffset, int yoffset)
    {
        if (!this->autoDraw) return;

        Oryol::Gfx::BeginPass(this->internalCamera->getCanvasPass());
        this->target->Draw(ThisRef<Camera>(), xoffset - this->position->x, yoffset - this->position->y);
        Oryol::Gfx::EndPass();
    }

    InternalCamera *Camera::getInternalCamera() {
        return this->internalCamera;
    }

}