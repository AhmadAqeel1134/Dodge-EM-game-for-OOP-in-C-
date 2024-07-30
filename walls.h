//Ahmad Aqeel
//22i-1134
#pragma once
#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
using namespace std;
using namespace sf;

class Walls
{
public:
	Sprite wall_sprite;
	Texture wall_texture;
	Walls();
	void MakingGameMap(float, float, float, float);
};