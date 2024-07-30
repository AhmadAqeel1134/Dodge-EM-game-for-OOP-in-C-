//Ahmad Aqeel
//22i-1134
#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
using namespace std;
using namespace sf;
#include"points.h"

points::points()
{
	point_texture.loadFromFile("img/PNG/Power-ups/pill_blue.png");
	point_sprite.setTexture(point_texture);
}
void points::SettingPoints(float x_axis, float y_axis, float Xscale, float Yscale)
{
	point_sprite.setPosition(x_axis, y_axis);
	point_sprite.setScale(Xscale, Yscale);
}