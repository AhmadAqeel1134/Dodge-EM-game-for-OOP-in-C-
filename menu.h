//Ahmad Aqeel
//22i-1134

#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "game.h"
using namespace sf;

//creating a class to display a menu
class Menu
{
public:
	Sprite BackImg,Back;                  //represents an object as a two dimension image
	Texture BackImg_text,Back_text;           //texture holds image in memory
	Game objGame;
    sf::Music m;

	Menu()
	{
		//starting the constructors body
		BackImg_text.loadFromFile("img/background_1.png");
		BackImg.setTexture(BackImg_text);
		BackImg.setScale(1, 1);
        Back_text.loadFromFile("img/instruct.png");
        Back.setTexture(Back_text);
     
        m.openFromFile("Sound/DRIVE_chosic.com_.ogg");
        

	}
	
    void display_menu()
    {
      
        m.play();
        //here showing working for displaying menu
        RenderWindow windowm(VideoMode(720, 1080), "Game_Menu");
        Font objFont;
        objFont.loadFromFile("font/SEASRN__.ttf");         //font design

        //Displaying Different Options
       

        Text DisplayPlay("Play", objFont, 56);
        DisplayPlay.setFillColor(sf::Color::Cyan);
        DisplayPlay.setPosition(windowm.getSize().x / 2 - DisplayPlay.getGlobalBounds().width / 2, 300);

        Text DisplayInstructions("Instructions", objFont, 56);
        DisplayInstructions.setFillColor(sf::Color::Cyan);
        DisplayInstructions.setPosition(windowm.getSize().x / 2 - DisplayInstructions.getGlobalBounds().width / 2, 400);

        Text DisplayQuit("Quit", objFont, 56);
        DisplayQuit.setFillColor(sf::Color::Cyan);
        DisplayQuit.setPosition(windowm.getSize().x / 2 - DisplayQuit.getGlobalBounds().width / 2, 500);


        while (windowm.isOpen())
        {
            Event objEvent;

            while (windowm.pollEvent(objEvent))
            {
                if (objEvent.type == Event::Closed)  //this means is close button on top right is pressed,close the window
                    windowm.close();
            }
            if (objEvent.type == sf::Event::MouseButtonPressed)
            {
                if (objEvent.mouseButton.button == Mouse::Left)
                {
                    // Check if Play button was clicked,if clicked we start the game
                    if (DisplayPlay.getGlobalBounds().contains(Vector2f(objEvent.mouseButton.x, objEvent.mouseButton.y)))
                    {
                        cout << "Play button clicked" << endl;
                        objGame.Score = 0;
                        objGame.TotalLivesAvailable = 3;

                        m.stop();
                        objGame.start_game();
                    }
                    // Check if Quit button was clicked
                    else if (DisplayQuit.getGlobalBounds().contains(Vector2f(objEvent.mouseButton.x, objEvent.mouseButton.y)))
                    {
                        cout << "Quit button clicked" << endl;
                        windowm.close();
                    }
                    else if (DisplayInstructions.getGlobalBounds().contains(Vector2f(objEvent.mouseButton.x, objEvent.mouseButton.y)))
                    {
                        cout << "Instructions button clicked" << endl;
                        RenderWindow windowI(VideoMode(720, 1080), "Instructions");
                        while (windowI.isOpen())
                        {
                            Event objEvent;
                            while (windowI.pollEvent(objEvent))
                            {
                                if (objEvent.type == Event::Closed) // If cross is pressed
                                    windowI.close();                               // close the instructions screen
                            }
                            if (Keyboard::isKeyPressed(Keyboard::BackSpace)) // If Escape key is pressed
                                windowI.close();
                            windowI.clear(Color::Black);
                            windowI.draw(Back);
                            windowI.display();
                        }
                    }
                }
            }
            if (Keyboard::isKeyPressed(Keyboard::Escape)) // If Escape key is pressed program closes
                windowm.close();

            windowm.clear(Color::Black); // clears the screen
            windowm.draw(BackImg);         // setting background
            windowm.draw(DisplayPlay);
            windowm.draw(DisplayInstructions);
            windowm.draw(DisplayQuit);
            windowm.display();            // Display all the sprites
        }
    }
 
};
