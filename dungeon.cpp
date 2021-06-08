

#include "dungeon.hpp"
#include <time.h>

States gameState;
Block blocks[xGrid][yGrid];
Player player = {1, 1, 60, 10, {16, 287, 92, 130}, {50, 50, 50, 50}};

// Lama 06072
// fill this function to create dungeon.
void createDungeon()
{
	// To fill a block, call the setBlock function, the example is given here:
	// It Sets a fire block at row=3, and column=4, it reduces life by 4, and increases health by 5
	//blocks[3][4].src = Fire;  Other possible values for shape are: Rock, Corona, Burger, Well, Fire, Gold
	//blocks[3][4].life = -4;  -ve values reduces life, +ve values increases
	//blocks[3][4].health = 5;  -ve values reduces health, +ve values increases
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (i == 8 && j == 8)
			{
				blocks[i][j].src = Gold;
			}

			else if (i == 0 || i == (xGrid - 1) || j == 0 || j == (yGrid - 1))
			{
				blocks[i][j].src = Rock;
			}

			else
			{
				int random = rand() % 100;
				if (random >= 0 && random < 20)
				{
					blocks[i][j].src = Corona;
				}

				else if (random >= 20 && random < 50)
				{
					blocks[i][j].src = Burger;
				}

				else if (random >= 50 && random < 70)
				{
					blocks[i][j].src = Well;
				}

				else if (random >= 70 && random < 100)
				{
					blocks[i][j].src = Fire;
				}
			}
		}
	}
}

// This is a demo implementation of makeMove function
// It doesn't follow the game rules at all
// You have to implement it according to game logic
void makeMove(string direction)
{
	if (player.row == 8 && player.col == 8)
	{
		gameState = WON;
		cout << "You win" << endl;
	}
	else if (player.life > 0 && player.health > 0)
	{
		if (direction == "right")
		{
			if (SDL_RectEquals(&blocks[player.row][player.col + 1].src, &Fire) == true)
			{
				player.life -= 10;
				player.health -= 4;
			}
			else if (SDL_RectEquals(&blocks[player.row][player.col + 1].src, &Well) == true)
			{
				player.life -= 5;
				player.health += 2;
			}
			else if (SDL_RectEquals(&blocks[player.row][player.col + 1].src, &Corona) == true)
			{
				player.life -= 20;
				player.health -= 2;
			}
			else if (SDL_RectEquals(&blocks[player.row][player.col + 1].src, &Burger) == true)
			{
				player.life += 5;
				player.health += 0;
			}
			else
			{
				player.life -= 2;
			}
			player.col++;
			gameState = RUNNING;
		}
		if (direction == "left")
		{
			if (SDL_RectEquals(&blocks[player.row][player.col - 1].src, &Fire) == true)
			{
				player.life -= 10;
				player.health -= 4;
			}
			else if (SDL_RectEquals(&blocks[player.row][player.col - 1].src, &Well) == true)
			{
				player.life -= 5;
				player.health += 2;
			}
			else if (SDL_RectEquals(&blocks[player.row][player.col - 1].src, &Corona) == true)
			{
				player.life -= 20;
				player.health -= 2;
			}
			else if (SDL_RectEquals(&blocks[player.row][player.col - 1].src, &Burger) == true)
			{
				player.life += 5;
				player.health += 0;
			}
			else
			{
				player.life -= 2;
			}
			player.col--;
			gameState = RUNNING;
		}
		if (direction == "up")
		{
			if (SDL_RectEquals(&blocks[player.row - 1][player.col].src, &Fire) == true)
			{
				player.life -= 10;
				player.health -= 4;
			}
			else if (SDL_RectEquals(&blocks[player.row - 1][player.col].src, &Well) == true)
			{
				player.life -= 5;
				player.health += 2;
			}
			else if (SDL_RectEquals(&blocks[player.row - 1][player.col].src, &Corona) == true)
			{
				player.life -= 20;
				player.health -= 2;
			}
			else if (SDL_RectEquals(&blocks[player.row - 1][player.col].src, &Burger) == true)
			{
				player.life += 5;
				player.health += 0;
			}
			else
			{
				player.life -= 2;
			}
			player.row--;
			gameState = RUNNING;
		}
		if (direction == "down")
		{
			if (SDL_RectEquals(&blocks[player.row + 1][player.col].src, &Fire) == true)
			{
				player.life -= 10;
				player.health -= 4;
			}
			else if (SDL_RectEquals(&blocks[player.row + 1][player.col].src, &Well) == true)
			{
				player.life -= 5;
				player.health += 2;
			}
			else if (SDL_RectEquals(&blocks[player.row + 1][player.col].src, &Corona) == true)
			{
				player.life -= 20;
				player.health -= 2;
			}
			else if (SDL_RectEquals(&blocks[player.row + 1][player.col].src, &Burger) == true)
			{
				player.life += 5;
				player.health += 0;
			}
			else
			{
				player.life -= 2;
			}
			player.row++;
			gameState = RUNNING;
		}
	}
	else
	{
		gameState = LOST;
		cout << "You lose" << endl;
	}
}

//This function is drawing all the objects. It's complete, don't modify it.
void update(SDL_Renderer *gRenderer, SDL_Texture *assets, string direction)
{
	SDL_RenderClear(gRenderer);
	for (int row = 0; row < xGrid; row++)
	{
		for (int col = 0; col < yGrid; col++)
		{
			SDL_Rect mover = {col * yJump, row * xJump, xJump, yJump};
			SDL_RenderCopy(gRenderer, assets, &blocks[row][col].src, &mover);
		}
	}

	if (direction != "") //if default argument is used.
		makeMove(direction);
	// player.mover = SDL_Rect {player.col*yJump, player.row*xJump, xJump, yJump};
	player.mover.x = player.col * yJump;
	player.mover.y = player.row * xJump;
	player.mover.w = xJump;
	player.mover.h = yJump;
	SDL_RenderCopy(gRenderer, assets, &player.src, &player.mover);
	// display life
	int r = 0, c = 0;
	for (int i = 0; i < player.life; i++)
	{
		if (i % 10 == 0)
		{
			r = 0;
			c++;
		}
		SDL_Rect mover = {600 + r++ * 12, 100 + c * 20, 10, 15};
		SDL_RenderCopy(gRenderer, assets, &player.src, &mover);
	}

	for (int i = 0; i < player.health; i++)
	{
		SDL_Rect mover;
		mover.x = 600 + i * 12;
		mover.y = 300;
		mover.h = 10;
		mover.w = 10;
		//  = {600+i*12, 300, 10, 10};
		SDL_Rect src;
		src.x = 175;
		src.y = 461;
		src.w = 102;
		src.h = 90;
		//  = {175, 461, 102, 90};
		SDL_RenderCopy(gRenderer, assets, &src, &mover);
	}
	SDL_Rect mover, src;
	if (gameState == RUNNING)
	{
		src.x = 367;
		src.y = 23;
		src.w = 281;
		src.h = 75;
		// = {367, 23, 281, 75};
		mover.x = 600;
		mover.y = 400;
		mover.w = 100;
		mover.h = 50;
		//  = {600, 400, 100, 50};
		SDL_RenderCopy(gRenderer, assets, &src, &mover);
	}
	else if (gameState == LOST)
	{
		src.x = 372;
		src.y = 224;
		src.w = 182;
		src.h = 45;
		//  = {372, 224, 182, 45};
		mover.x = 600;
		mover.y = 400;
		mover.w = 100;
		mover.h = 50;
		//  = {600, 400, 100, 50};
		SDL_RenderCopy(gRenderer, assets, &src, &mover);
	}
	else if (gameState == WON)
	{
		src.x = 366;
		src.y = 125;
		src.w = 186;
		src.h = 45;
		//  = {366, 125, 186, 45};
		mover.x = 600;
		mover.y = 400;
		mover.w = 100;
		mover.h = 50;
		//  = {600, 400, 100, 50};
		SDL_RenderCopy(gRenderer, assets, &src, &mover);
	}

	SDL_RenderPresent(gRenderer);
	SDL_Delay(5);
}
