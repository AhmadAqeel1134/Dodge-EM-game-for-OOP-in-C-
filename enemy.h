//Ahmad Aqeel
//22i-1134

#pragma once
#include <SFML/Graphics.hpp>
#include<string.h>
#include<iostream>
#include"player.h"
using namespace sf;
using namespace std;
class Enemy
{
public:
	Texture enemy_tex;
    Sprite enemy_sprite;
	float EnemySpeed = 0.2;


	Enemy()
	{
		
		enemy_tex.loadFromFile("img/enemy_2.png");
		enemy_sprite.setTexture(enemy_tex);
		enemy_sprite.setPosition(500,850);
		enemy_sprite.setScale(0.3, 0.3);

	}
	void moveEnemy()
	{
		

		float delta_x = 0, delta_y = 0;

		//logic to auto move enemy in clock wise direction

		//rightward movement 
		if (enemy_sprite.getPosition().x < 630 && enemy_sprite.getPosition().y >840)   
		{
			delta_x = EnemySpeed;
			delta_y = 0;
		}

		//upward movement
		else if (enemy_sprite.getPosition().x > 630 && enemy_sprite.getPosition().y > 80)
		{
			delta_x = 0;
			delta_y = -EnemySpeed;
		}

		//leftward movement
		else if (enemy_sprite.getPosition().x > 60 && enemy_sprite.getPosition().y < 80)
		{
			delta_x = -EnemySpeed;
			delta_y = 0;
		}

		//downward movement
		else if (enemy_sprite.getPosition().x < 60 && enemy_sprite.getPosition().y < 840)
		{
			delta_x = 0;
			delta_y = EnemySpeed;
		}
		
		enemy_sprite.move(delta_x, delta_y);

	}

	void MoveEnemyRandomly()
	{
		srand(time(0));

		int num =1+ rand() % 5;
		
			switch (num)
		{
			case 1:
				enemy_sprite.setPosition(200,150);
				moveEnemy();
				break;
			case 2:
				enemy_sprite.setPosition(470, 250);
				moveEnemy();
				break;
			case 3:
				enemy_sprite.setPosition(580, 740);
				moveEnemy();
				break;
			case 4:
				enemy_sprite.setPosition(409, 430);
				moveEnemy();
				break;
			case 5:
				enemy_sprite.setPosition(500, 850);
				moveEnemy();
				break;


		}
		
	}
	


};