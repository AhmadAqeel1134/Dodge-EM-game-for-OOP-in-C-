//Ahmad Aqeel
//22i-1134
#pragma once
#include <SFML/Graphics.hpp>
#include<string.h>
#include<iostream>
using namespace sf;
using namespace std;
#include"Food.h"
class Player 
{

private:
	float delta_x = 0, delta_y = 0;
public:
	Texture tex_player;
	Sprite sprite_player;
	float speed = 0.2;
	Food* BonusFood[4];
	 
	//default constructor
	Player()
	{
		BonusFood[0] = new RectangularFood();
		BonusFood[1] = new CircularFood();
		BonusFood[2] = new HexagonalFood();
		BonusFood[3] = new TriangularFood();
		tex_player.loadFromFile("img/car.png");
		sprite_player.setTexture(tex_player);

		sprite_player.setPosition(100,80);  //initial position of car
		sprite_player.setScale(0.09, 0.09);

	}

	void SetFood(int num)
	{
		if (num == 0)
			BonusFood[num]->Food_Sprite.setPosition(300,300);
		else if(num==1)
			BonusFood[num]->Food_Sprite.setPosition(630, 120);
		else if(num==2)
			BonusFood[num]->Food_Sprite.setPosition(130, 150);
		else if(num==3)
			BonusFood[num]->Food_Sprite.setPosition(325, 770);
	}
	void draw(RenderWindow& window, int num)
	{
		window.draw(sprite_player);
		window.draw(BonusFood[num]->Food_Sprite);
	}
	
	//function to auto move the car of player

	void movePlayer()              
	{
		//If you want to move car clockwise, uncomment the followingg part

		/*if (sprite_player.getPosition().x < 640 && sprite_player.getPosition().y >840)   //r
		{
			delta_x = speed;
			delta_y = 0;
		}
	

		else if (sprite_player.getPosition().x > 630 && sprite_player.getPosition().y > 80)//u
		{
			delta_x = 0;
			delta_y = -speed;
		}
		else if (sprite_player.getPosition().x > 60 && sprite_player.getPosition().y < 80)//l
		{
			delta_x = -speed;
			delta_y = 0;
		}

		else if (sprite_player.getPosition().x < 60 && sprite_player.getPosition().y < 950)//d
		{
			delta_x = 0;
			delta_y = speed;
		}
		*/

		//anti-clockwise  movement of Player's Car

		//rightward movement
		if (sprite_player.getPosition().x <630 && sprite_player.getPosition().y <85)   
		{
			
			delta_x = speed;
			delta_y = 0;
		 
		}
	//	downward movement
		else if (sprite_player.getPosition().x >630 && sprite_player.getPosition().y < 840)
		{
			
			delta_x = 0;
			delta_y = speed;
		}
		//leftward movementt
		else if (sprite_player.getPosition().x > 50 && sprite_player.getPosition().y > 840)
		{
			
			delta_x = -speed;
			delta_y = 0;
		}
		//upward
		else if (sprite_player.getPosition().x < 60 && sprite_player.getPosition().y > 80)
		{
			//cout << sprite_player.getPosition().x << " up  " << sprite_player.getPosition().y << endl;
			delta_x = 0;
			delta_y = -speed;
		}

		else if (sprite_player.getPosition().x > 100 && sprite_player.getPosition().x < 570 && sprite_player.getPosition().y>150 && sprite_player.getPosition().y < 155)   
		{
			delta_x = speed;
			delta_y = 0;
		}
		else if (sprite_player.getPosition().x >570 && sprite_player.getPosition().x < 575 && sprite_player.getPosition().y>148 && sprite_player.getPosition().y < 750)
		{
			
				delta_x = 0;
				delta_y = speed;
		}
		else if (sprite_player.getPosition().x <572 && sprite_player.getPosition().x >137 && sprite_player.getPosition().y >750)
		{
		
			delta_x = -speed;
			delta_y = 0;
		}
		else if (sprite_player.getPosition().x < 138 && sprite_player.getPosition().x>91 && sprite_player.getPosition().y > 120 && sprite_player.getPosition().y <755)
		{
			
				delta_x = 0;
				delta_y = -speed;
		}

		else if (sprite_player.getPosition().x > 200 && sprite_player.getPosition().x < 435 && sprite_player.getPosition().y>200 && sprite_player.getPosition().y < 215)
		{
			
			delta_x = speed;
			delta_y = 0;
		}
		else if (sprite_player.getPosition().x > 480 && sprite_player.getPosition().x<485  && sprite_player.getPosition().y >205  && sprite_player.getPosition().y <690 )
		{
		
			delta_x = 0;
			delta_y = speed;
		}
		else if (sprite_player.getPosition().x>225 && sprite_player.getPosition().x <485 && sprite_player.getPosition().y >690 && sprite_player.getPosition().y <695)
		{

			delta_x = -speed;
			delta_y = 0;
		}
		else if (sprite_player.getPosition().x > 220 && sprite_player.getPosition().x < 230 && sprite_player.getPosition().y >100)
		{
			delta_x = 0;
			delta_y = -speed;
		}
		else if (sprite_player.getPosition().x>275 && sprite_player.getPosition().x<400 && sprite_player.getPosition().y>290 && sprite_player.getPosition().y <300)
		{
			//cout << sprite_player.getPosition().x<<" up  "<< sprite_player.getPosition().y << endl;
			delta_x = speed;
			delta_y = 0;
		}
		else if (sprite_player.getPosition().x >400 && sprite_player.getPosition().x < 410 && sprite_player.getPosition().y>299 && sprite_player.getPosition().y <615)
		{
			//cout << sprite_player.getPosition().x << "   " << sprite_player.getPosition().y << endl;
			delta_x = 0;
			delta_y = speed;
		}
		else if (sprite_player.getPosition().x >285 && sprite_player.getPosition().x < 401 && sprite_player.getPosition().y>610 && sprite_player.getPosition().y < 625)
		{
			//cout << sprite_player.getPosition().x << "   " << sprite_player.getPosition().y << endl;
			delta_x = -speed;
			delta_y = 0;
		}
		else if (sprite_player.getPosition().x <285 && sprite_player.getPosition().x >275  && sprite_player.getPosition().y<616 && sprite_player.getPosition().y >360)
		{
			//cout << sprite_player.getPosition().x << "   " << sprite_player.getPosition().y << endl;
			delta_x = 0;
			delta_y = -speed;
		}

	    sprite_player.move(delta_x, delta_y);
	}

	void PlayerMovedByUser(string s)
	{
		bool AllowMovement = false;

		if (sprite_player.getPosition().x <315 && sprite_player.getPosition().y >=400 && sprite_player.getPosition().y <= 500)
		{
			
			AllowMovement = true;
		}
	   if (sprite_player.getPosition().x >= 315 && sprite_player.getPosition().x <= 680 && sprite_player.getPosition().y >= 390 && sprite_player.getPosition().y <= 500)
		{
			AllowMovement = true;
		}
	   if(sprite_player.getPosition().x>=300 && sprite_player.getPosition().x<=390 )
		   AllowMovement = true;



		if (AllowMovement)
		{
			if (s == "above")
			{
				delta_y = -0.2;
				delta_x = 0;
			}

			else if (s == "down")
			{
				delta_x = 0;
				delta_y = 0.2;
			}

			else if (s == "right")
			{
				delta_y = 0;
				delta_x = 0.2;
			}

			else if (s == "left")
			{
				delta_y = 0;
				delta_x = -0.2;
			}
		}
		sprite_player.move(delta_x, delta_y);

	}


	
};