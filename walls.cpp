//Ahmad Aqeel
//22i-1134
#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
using namespace std;
using namespace sf;
#include"walls.h"

Walls:: Walls()
{
	    wall_texture.loadFromFile("img/brick.png");
		wall_sprite.setTexture(wall_texture);
}
void Walls::MakingGameMap(float x_axis,float y_axis,float Xscale,float Yscale)
{
	wall_sprite.setPosition(x_axis, y_axis);
	wall_sprite.setScale(Xscale, Yscale);
}