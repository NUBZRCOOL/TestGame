#include "game.hpp"
#include <iostream>
#include <SDL2/SDL.h>


Game::Game() {

    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG);
    SDL_CreateWindowAndRenderer(1080, 720, 0, &win, &ren);
    SDL_SetWindowTitle(win, "AAAAAaaAAaAAaaaaAaaA");

    isRunnning = true;
    count = 0;


    ball.setImage("snowball.png", ren);
    ball.setDest(100, 100, 100, 100);
    ball.setSource(100, 100, 100, 100);


    loop();
}

Game::~Game() {

    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
}


void Game::loop() {

    SDL_Event windowEvent;
    while (isRunnning) {

        if (SDL_PollEvent(&windowEvent)) {
            if (windowEvent.type == SDL_QUIT) {
                
                isRunnning = false;
            }
        }

        lastFrame = SDL_GetTicks();
        static int lastTime;

        if (lastFrame >= (lastTime + 1000)) {

            lastTime = lastFrame;
            frameCount = 0;
            count++;
        }


        Render();
        Input();
        Update();
    }
}


void Game::Render() {

    SDL_SetRenderDrawColor(ren, 255, 0, 0, 255);
    SDL_Rect rect;
    rect.x = rect.y = 100;
    rect.w = 200;
    rect.h = 100;

    SDL_RenderFillRect(ren, &rect);

    
    Draw(ball);


    frameCount++;
    int timerFps = SDL_GetTicks() - lastFrame;
    if (timerFps < (1000/60)) {

        SDL_Delay((1000/60) - timerFPS);
    }
    SDL_RenderPresent(ren);
}


void Game::Draw(Object o) {

    SDL_Rect dest = o.getDest();
    SDL_Rect src = o.getSource();

    SDL_RenderCopyEx(ren, o.getTex(), &src, &dest, 0, NULL, SDL_FLIP_NONE);
}