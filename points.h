//Ahmad Aqeel
//22i-1134
#pragma once
#pragma once
#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
using namespace std;
using namespace sf;

class points
{
public:
	Sprite point_sprite;
	Texture point_texture;
	points();
	void SettingPoints(float, float, float, float);
};