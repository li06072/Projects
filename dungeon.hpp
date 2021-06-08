#include<iostream>
#include<string>
#include<SDL.h>
#include<SDL_ttf.h>
#include "block.hpp"

const int xJump=50, yJump=50;
const int xGrid = 10, yGrid = 10;

const SDL_Rect Rock = {151, 287, 147, 138};
		
const SDL_Rect Corona = {0,0, 123, 122};
    
const SDL_Rect Fire = {11, 134, 105, 109};
    
const SDL_Rect Burger = {145, 9, 112, 94};
    
const SDL_Rect Well = {154, 164, 102, 66};

const SDL_Rect Gold	 = {7, 443, 127, 114};
		

using namespace std;

enum States {RUNNING, LOST, WON};

void makeMove(string direction);
void createDungeon();
void update(SDL_Renderer* gRenderer, SDL_Texture* assets, string direction="");

