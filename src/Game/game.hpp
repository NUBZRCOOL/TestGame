#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <SDL2/SDL.h>
#include "../Object/object.hpp"


class Game {

    private:

        SDL_Renderer *ren;
        SDL_Window *win;

        bool isRunnning;
        int count;
        int frameCount, timerFPS, lastFrame;

        Object ball;


    public:

        Game();
        ~Game();

        void loop();
        void Update() {}
        void Input() {}
        void Render();
        void Draw(Object o);

};



#endif