#pragma once
struct Block{
    int life;
    int health;
    SDL_Rect src, mover;
};

struct Player{
    int row, col;
    int life, health;
    SDL_Rect src, mover;
};