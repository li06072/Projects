#include "mover.hpp"
#include "seeplusia.hpp"

const int xJump=200, yJump=160;

SDL_Rect bg={0,0,800,600};
SDL_Rect bgSrc={21,367,757,586};
SDL_Rect warriorSrc={340, 120, 240, 220};
SDL_Rect warriorMover={430, 150, 100, 100};

//Screen dimension constants
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

void moveSouth(){ 
    if (warriorMover.y+yJump < SCREEN_HEIGHT)warriorMover.y+=yJump;    
}
void moveNorth(){
	if (warriorMover.y-yJump > 0)warriorMover.y-=yJump;
	else warriorMover.y = 0;
}
void moveEast(){
	if (warriorMover.x+xJump < SCREEN_WIDTH)warriorMover.x+=xJump;
}
void moveWest(){
	if (warriorMover.x-xJump > 0)warriorMover.x-=xJump;
}


void status(SDL_Renderer* gRenderer, SDL_Texture* assets){
	SDL_Rect statusSrc, statusMover;

	//Apples
	statusSrc.x=634;
	statusSrc.y=38;
	statusSrc.w=122;
	statusSrc.h=139;
	statusMover.x=30;
	statusMover.y=300;
	statusMover.w=20;
	statusMover.h=20;
	for(int i=0;i<applesLeft;i++){
		if(i%10==0){//go to new line
			statusMover.x=30;
			statusMover.y+=30;
		}
		SDL_RenderCopy( gRenderer, assets, &statusSrc, &statusMover );
		statusMover.x+=20;		
	}
	statusSrc.x = 635;
	statusSrc.y=215;
	statusMover.x=30;
	statusMover.y=450;

	for(int i=0;i<nCrystalsFound; i++){
		SDL_RenderCopy( gRenderer, assets, &statusSrc, &statusMover );
		statusMover.x+=20;
	}

	if (gameState=="Running"){
		statusSrc.x=0;
		statusSrc.y=0;
		statusSrc.w=579;
		statusSrc.h=54;
		statusMover.x=30;
		statusMover.y=500;
		statusMover.w=300;
		statusMover.h=60;
		SDL_RenderCopy( gRenderer, assets, &statusSrc, &statusMover );
	} 
	else if(gameState=="Won"){
		statusSrc.x=0;
		statusSrc.y=270;
		statusSrc.w=220;
		statusSrc.h=60;
		statusMover.x=30;
		statusMover.y=500;
		statusMover.w=300;
		statusMover.h=60;
		SDL_RenderCopy( gRenderer, assets, &statusSrc, &statusMover );
		cout<<"Game Won";
	}
	else if(gameState=="Lost"){
		statusSrc.x=0;
		statusSrc.y=136;
		statusSrc.w=270;
		statusSrc.h=55;
		statusMover.x=30;
		statusMover.y=500;
		statusMover.w=300;
		statusMover.h=60;
		SDL_RenderCopy( gRenderer, assets, &statusSrc, &statusMover );

	}
}

void moveWarrior(SDL_Renderer* gRenderer, SDL_Texture* assets, SDL_Keycode key){
    if (key == SDLK_UP){
        makeMove("North");
    }
    else if (key == SDLK_DOWN) {
        makeMove("South");
    }
    else if (key == SDLK_RIGHT) {
        makeMove("East");
    }
    else if (key == SDLK_LEFT) {
        makeMove("West");
    }
    else {
        std::cout<<"hello";
    }
    update(gRenderer, assets);
}

void update(SDL_Renderer* gRenderer, SDL_Texture* assets){


	SDL_RenderClear( gRenderer );
	SDL_RenderCopy( gRenderer, assets, &bgSrc, &bg );
	status(gRenderer, assets);
	SDL_RenderCopy( gRenderer, assets, &warriorSrc, &warriorMover );
	SDL_RenderPresent( gRenderer );	
	SDL_Delay(5);	
}