#include<headers/game.h>

int main(int argc,  char* argv[])
{
    Game game;

    game.run();
    
    SDL_Quit();
    return 0;
}