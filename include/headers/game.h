#pragma once

#include<iostream>
#include<sdl/SDL.h>
#include<sdl/SDL_image.h>

class Game 
{
public:
    Game();
    ~Game();

    void run();

private:
    void init(const char* title, int x, int y, int w, int h, Uint32 flags);
    void eventhandler();
    void gameloop();

    SDL_Window* window;
    SDL_Renderer* renderer;

    int m_screenwidth;
    int m_screenheight;

    enum m_gameState {
    RUNNING, QUIT
    };
    int m_gamestate;
};