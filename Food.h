//Ahmad Aqeel
//22i-1134
#pragma once
#pragma once
#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
using namespace std;
using namespace sf;

//Here Showing Polymorphism, a food can be of different forms
class Food
{
public:
	Sprite Food_Sprite;
	Texture Food_Texture;
	virtual void ScoreBonus(int*) = 0;
	virtual void LivesBonus(int*) = 0;
};
class RectangularFood :public  Food
{
public:

	RectangularFood()
	{
		Food_Texture.loadFromFile("img/RedRectangle.png");
		Food_Sprite.setTexture(Food_Texture);
		Food_Sprite.setScale(0.5, 0.5);

	}
	void ScoreBonus(int *score) override
	{
          //if red rectangle is eaten, give an increment  of 10
		*(score) += 10;
	}
	void LivesBonus(int*lives) override
	{
		//if red rectangle is eaten, no increment in lives
		*(lives) += 0;
	}

};
class CircularFood :public  Food
{
public:

	CircularFood()
	{
		Food_Texture.loadFromFile("img/GreenCircle.png");
		Food_Sprite.setTexture(Food_Texture);
		Food_Sprite.setScale(0.3, 0.3);

	}
	void ScoreBonus(int *score) override
	{
		//if greenCircle is eaten, give an increment  of 20
		*(score)+= 20;
	}
	void LivesBonus(int* lives) override
	{
		//if red rectangle is eaten, no increment in lives
		*(lives) += 1;
	}


};

class HexagonalFood :public  Food
{
public:

	HexagonalFood()
	{
		Food_Texture.loadFromFile("img/OrangeHexagon.png");
		Food_Sprite.setTexture(Food_Texture);
		
		Food_Sprite.setScale(0.2, 0.2);

	}
	void  ScoreBonus(int *score) override
	{
		//if orange hexagon is eaten, give an increment  of 10
		*(score)+= 10;
	}
	void LivesBonus(int* lives) override
	{
		//if red rectangle is eaten, no increment in lives
		*(lives) += 0;;
	}


};

class TriangularFood :public  Food
{
public:

	TriangularFood()
	{
		Food_Texture.loadFromFile("img/WhiteTriangle.png");
		Food_Sprite.setTexture(Food_Texture);
		
		Food_Sprite.setScale(0.2, 0.2);

	}
	void ScoreBonus(int *score) override
	{

		*(score)+=0 ;
	}
	void LivesBonus(int* lives) override
	{
		//if red rectangle is eaten, no increment in lives
		*(lives) += 0;;
	}


};