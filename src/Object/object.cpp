#include "object.hpp"


void Object::setDest(int x, int y, int w, int h) {

    dest.x = x;
    dest.y = y;
    dest.w = w;
    dest.h = h;
}

void Object::setSource(int x, int y, int w, int h) {

    src.x = x;
    src.y = y;
    src.w = w;
    src.h = h;
}


void Object::setImage(const char fileName[], SDL_Renderer *ren) {

    SDL_Surface *surf = IMG_Load(fileName);
    tex = SDL_CreateTextureFromSurface(ren, surf);
}