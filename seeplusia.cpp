#include "seeplusia.hpp"
#include "mover.hpp"

int applesLeft = 30, nCrystalsFound = 0;
string location ="Forest";
string gameState = "Running";

//manually setting initial x and y coordinates
int x_coordinate = 200;
int y_coordinate = 160;

int crystals_left[3] = {1, 2, 3};
bool crystal1_collected =false;
bool crystal2_collected =false;


/*this helper function increments crystal count when crystal is collected*/

/*in this function i is index of crystal in crystals_left array initialised above*/

void collect_crystals(int C[],int i)
{
	if (C[i]>0)
	{
		nCrystalsFound+=1;
		C[i]=0;

	}
}


//following are movement functions that handle awrriors movements in all 4 directions and manages apple count.

bool move_up(int apples_used)//moves North only if move is valid, function is true if a location exists and move happens, it returns false and warrior doesnt move if no location is avaiable in North.
{
	if (apples_used < applesLeft)
	{
		moveNorth();
		y_coordinate= y_coordinate-160;
		applesLeft= applesLeft-apples_used;
		return true;
	}
	else 
	{
		return false;
	}

}

bool move_down(int apples_used)//moves South
{
	if (apples_used < applesLeft)
	{
		moveSouth();
		y_coordinate= y_coordinate+160;
		applesLeft= applesLeft-apples_used;
		return true;
	}
	else 
	{
		return false;
	}


}

bool move_right(int apples_used)//moves East
{
	if (apples_used < applesLeft)
	{
		moveEast();
		x_coordinate= x_coordinate+200;
		applesLeft= applesLeft-apples_used;
		return true;
	}
	else 
	{
		return false;
	}


}

bool move_left (int apples_used)//moves west
{
	if (apples_used < applesLeft)
	{
		moveWest();
		x_coordinate= x_coordinate-200;
		applesLeft= applesLeft-apples_used;
		return true;
	}
	else 
	{
		return false;
	}

}


//this function is for each possible move a warrior can make
void makeMove(string direction)
{
	if (applesLeft>0)
	{
		if (x_coordinate==200 && y_coordinate==160) // we start at forest
		{
			if (direction=="North")
			{
				move_up(1);
				applesLeft+=6;//apples incremented since we are at orchard
			}

			else if (direction=="South")
			{
				move_down(3);
			}

			else if (direction=="East")
			{
				move_right(1);
			}
			else if (direction=="West")
			{
				move_left(2);
			}
		}

		else if (x_coordinate==400 && y_coordinate==160) // we now arrive at Swamp moving in x direction
		{
			if (direction=="North")
			{
				move_up(2);
				if (crystal1_collected==false)
				{
					collect_crystals(crystals_left,0); //first crystal collected as we arrive at water fall
					crystal1_collected=true;

				}
			}

			else if (direction=="West")
			{
				move_left(1);
			}

			else
			{
				applesLeft-=1; //since nothing exists south or east of swamp only apple is lost warrior doesnt move
			}	

		}

		else if (x_coordinate==400 && y_coordinate==0)// we are at waterfall
		{
			if (direction=="West")
			{
				move_left(1);
				applesLeft+=6;
			}

			else
			{
				applesLeft-=1; //since nothing exists except for on the west side of waterfall
			}
			


		}

		else if (x_coordinate==200 && y_coordinate==0) // we move from forest above to the orchard
		{
			if (direction=="East")
			{
				move_right(1);

				if (crystal1_collected==false)
				{
					collect_crystals(crystals_left,0); //elven waterfall crystal
					crystal1_collected=true;
				}
			}

			else if (direction=="South")
			{
				move_down(1);
			}
			else
			{
				applesLeft-=1;
			}
			
		}
		
		else if (x_coordinate==200 && y_coordinate==320) // we are at vampire cove
		{
			if (direction == "North") 
				move_up(3);

			else if (direction == "South")
			{
				move_down(3);

				if (crystal2_collected==false)
				{
					collect_crystals(crystals_left,1); //crystal at hill collected
					crystal2_collected=true;

				}
			}

			else if (direction == "East")
			{
				move_right(1);
				collect_crystals(crystals_left,2); // crystal at marsh collected
				
			}

			else if (direction=="West")
			{
				applesLeft-=1;
			}

		}

		else if (x_coordinate==400 && y_coordinate==320) // we are at marsh 
		{
			if (direction == "South")
			{
				move_down(1);
				gameState = "Lost"; //player drowns in quicksand and dies
			}

			else if (direction == "West")
				move_left(1);

			else 
			{
				applesLeft-=1;
			}

		}

		else if (x_coordinate==200 && y_coordinate==480) // we are at the hill
		{
			if (direction == "East"){
				move_right(1);
				gameState = "Lost"; //  player drowns in quicksand and dies
				
			}
			else if (direction == "North") 
				move_up(3);

			else 
			{
				applesLeft-=1;
			}

		}

		else if (x_coordinate==0 && y_coordinate==160) //we now arrive at the bridge
		{
			if (direction == "West" && nCrystalsFound == 3 && applesLeft>=5)
			{
				move_left(5);
				gameState = "Won"; // player has won
			}

			else if (direction == "East") 
			{
				move_right(2);
			}

			else 
			{
				applesLeft-=1;
			}

		}
		
	} 

	else
	{
		gameState="Lost";
	}
	


}