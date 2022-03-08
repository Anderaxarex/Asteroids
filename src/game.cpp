#include<../include/headers/game.h>

Game::Game() {
    window = nullptr;
    renderer = nullptr;
    m_screenheight = 1024;
    m_screenwidth = 600;
    m_gamestate = Game::m_gameState::RUNNING;
};
Game::~Game(){}

void Game::run()
{
    init("Asteroids!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_screenheight, m_screenwidth, SDL_WINDOW_SHOWN);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderPresent(renderer);
    gameloop();
}

void Game::drawrect(int x, int y, int w, int h)
{
    SDL_RenderClear(renderer);

    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawRect(renderer, &rect);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

    SDL_RenderPresent(renderer);

}


void Game::init(const char* title, int x, int y, int w, int h, Uint32 flags)
{
    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow(title, x, y, w, h, flags);
    renderer = SDL_CreateRenderer(window, -1, 0);

}

void Game::gameloop()
{
    while(m_gamestate != Game::m_gameState::QUIT)
    {
       Game::eventhandler(); 
    }
    
}

void Game::eventhandler()
{
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type)
    {
        case SDL_QUIT:
            Game::m_gameState::QUIT;
            SDL_DestroyWindow(window);
            SDL_DestroyRenderer(renderer);
            SDL_Quit();
        break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
                case SDLK_w:
                    std::cout<<"move forward"<<std::endl;
                    drawrect(200, 200, 200, 200);
                    break;
                case SDLK_a:
                    std::cout<<"move left"<<std::endl;
                    drawrect(300, 300, 200, 200);
                    break;
                case SDLK_s:
                    std::cout<<"move backwards"<<std::endl;
                    drawrect(400, 400, 200, 200);
                    break;
                case SDLK_d:
                    std::cout<<"move right"<<std::endl;
                    drawrect(400, 150, 200, 200);
                    break;
        break;
            
    }



}