#pragma once

//
// Created by connor on 7/8/18.
//

#include <functional>
#include <Sova/Network/HttpRequest.h>
#include <Sova/Time/Timer.h>

#include "Sova/References/Ref.h"
#include "Sova/Graphics/Internal/ShaderHandler.h"
#include "Sova/Graphics/Viewport.h"
#include "Loader.h"
#include "Sova/Common/List.h"
#include "Input.h"
#include "Sova/Network/Websocket.h"

using namespace Sova;

namespace Sova {

    class App : public Refable
    {
    public:
        App(int width, int height, Ref<String> windowTitle, Ref<ShaderHandler> shaderHandler);
        virtual const char* getClassName() { return "App"; }

        Ref<Loader> load(Ref<List<String>> resources);
        void start();
        void onUpdate(std::function<void(float)> updateFunction);
        //void addViewport(Ref<Viewport> viewport);
        Ref<Viewport> createViewport(int x, int y, int width, int height, Ref<Camera> camera);
        void drawCameras();
        void drawViewports();

        std::function<void(float)> updateFunction = nullptr;
        
        //Input
        bool keyPressed(Key::Code key);
        bool mouseButtonPressed(MouseButton::Code btn);
        int getMouseX();
        int getMouseY();

        //Window
        int width;
        int height;
        Ref<String> windowTitle = Null<String>();
        Ref<ShaderHandler> shaderHandler = Null<ShaderHandler>();
        
        //Resource loading
        Ref<Loader> loader = Null<Loader>();

        //Sockets
        Ref<Websocket> openWebsocket(Ref<String> address);
        Ref<HttpRequest> makeHttpRequest(Ref<String> method, Ref<String> address);

        //Network
        void updateWebsockets();
        void updateHttpRequests();

        //Global vars
        void setGlobal(void* globalPtr);
        void* getGlobal();

        //Timing
        Ref<Timer> makeTimer(std::function<void()> updateFunction, int msStart, int msRepeat);
        void updateTimers(double frameDelta);
        double getFps();

    private:
        Ref<List<Viewport>> viewports = Null<List<Viewport>>();
        Ref<List<Websocket>> websockets = Null<List<Websocket>>();
        Ref<List<HttpRequest>> httpRequests = Null<List<HttpRequest>>();
        Ref<List<HttpRequest>> finishedHttpRequests = Null<List<HttpRequest>>();
        Ref<List<Timer>> timers = Null<List<Timer>>();

        void* globalObj = nullptr;
    };

}