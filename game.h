//Ahmad Aqeel
//22i-1134

#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
#include "walls.h"
#include "player.h"
#include "enemy.h"
#include "points.h"
#include"Food.h"
using namespace std;

const char title[] = "OOP-Project, Spring-2023_Dodge'EM";
using namespace sf;

class Game
{
public:
    Texture GameOverTex;
    Sprite GameOverSprite;
    Sprite background; // Game background sprite
    Texture bg_texture;
    int direction = 1; // Variable to store the direction of movement
    // bool pause_Game = 0;
// object of other classes as members of Main Class Game (Composition)
    Walls* objBrick[32];
    Player* objPlayer;
    Enemy* objEnemy;
    points* ObjPoint[54];
    Music m;
    Music m1;
    Music m2;
    Music m3;
    bool pause_Game = false;
    int num;
    bool IncSpeed = false;
    bool flag =false;
    bool DisappearEnemy = false;
    // variables to deal with score and Total Lives Available

    int Score = 0;
    int TotalLivesAvailable = 3;
    int TotalPoints = 54;
    int TotalPoints2 = 54;//for level 2
    int TotalPoints3 = 54;
    int LevelNum = 1;


    Game()
    {

        objPlayer = new Player;
        objEnemy = new Enemy;

        //Here Showing Polymorphism
        //base class pointer having address of derived class


        bg_texture.loadFromFile("img/Arena.png");
        background.setTexture(bg_texture);
        background.setScale(2, 1.5);
        int index = 0;
        while (index < 32)
        {
            // here giving memory to object of class Walls
            objBrick[index] = new Walls();
            ++index;
        }
        index = 0;
        while (index < 54)
        {
            // here giving memory to object of class ponts
            ObjPoint[index] = new points();
            ++index;
        }
        int x = 120;
        int y = 90;
        // here drawing the points
        for (int i = 0; i < 6; i++)
        {
            ObjPoint[i]->SettingPoints(x, y, 0.7, 0.7);
            x += 90;
        }
        x = 120;
        y = 860;
        for (int i = 6; i < 12; i++)
        {
            ObjPoint[i]->SettingPoints(x, y, 0.7, 0.7);
            x += 90;
        }

        x = 60;
        y = 160;

        for (int i = 12; i < 18; i++)
        {
            ObjPoint[i]->SettingPoints(x, y, 0.7, 0.7);
            y += 120;
        }

        x = 635;
        y = 160;
        for (int i = 18; i < 24; i++)
        {
            ObjPoint[i]->SettingPoints(x, y, 0.7, 0.7);
            y += 120;
        }

        x = 190;
        y = 150;
        for (int i = 24; i < 28; i++)
        {
            ObjPoint[i]->SettingPoints(x, y, 0.7, 0.7);
            x += 100;
        }

        x = 190;
        y = 770;
        for (int i = 28; i < 32; i++)
        {
            ObjPoint[i]->SettingPoints(x, y, 0.7, 0.7);
            x += 100;
        }

        x = 150;
        y = 220;
        for (int i = 32; i < 37; i++)
        {
            ObjPoint[i]->SettingPoints(x, y, 0.7, 0.7);
            y += 120;
        }

        x = 580;
        y = 220;
        for (int i = 37; i < 42; i++)
        {
            ObjPoint[i]->SettingPoints(x, y, 0.7, 0.7);
            y += 120;
        }

        x = 250;
        y = 220;
        for (int i = 42; i < 45; i++)
        {
            ObjPoint[i]->SettingPoints(x, y, 0.7, 0.7);
            x += 90;
        }

        x = 250;
        y = 700;
        for (int i = 45; i < 48; i++)
        {
            ObjPoint[i]->SettingPoints(x, y, 0.7, 0.7);
            x += 90;
        }

        x = 230;
        y = 300;
        for (int i = 48; i < 51; i++)
        {
            ObjPoint[i]->SettingPoints(x, y, 0.7, 0.7);
            y += 160;
        }

        x = 480;
        y = 300;
        for (int i = 51; i < 54; i++)
        {
            ObjPoint[i]->SettingPoints(x, y, 0.7, 0.7);
            y += 160;
        }

        objBrick[0]->MakingGameMap(20, 50, 7.2, 0.6);   // top line
        objBrick[1]->MakingGameMap(20, 50, 0.3, 20);    // left outer line
        objBrick[2]->MakingGameMap(20, 900, 7.48, 0.6); // bottom line
        objBrick[3]->MakingGameMap(680, 50, 0.3, 20);   // right outer line

        objBrick[4]->MakingGameMap(115, 130, 2, 0.3); // left first inner horizontal line
        objBrick[5]->MakingGameMap(115, 130, 0.2, 6); // left first inner vertical line
        objBrick[6]->MakingGameMap(420, 130, 2, 0.3); // right first ineer horizontal line
        objBrick[7]->MakingGameMap(600, 130, 0.2, 6); // right first inner vertical line

        objBrick[8]->MakingGameMap(215, 200, 1, 0.3);    // left second inner horizontal line
        objBrick[9]->MakingGameMap(417, 200, 1, 0.3);    // right second inner horizontal line
        objBrick[10]->MakingGameMap(200, 200, 0.2, 4.3); // left second inner vertical line
        objBrick[11]->MakingGameMap(509, 200, 0.2, 4.3); // right second innervertical line

        objBrick[12]->MakingGameMap(275, 270, 0.4, 0.3); // left third inner horizontal line
        objBrick[13]->MakingGameMap(420, 270, 0.4, 0.3); // right third inner horizontal line
        objBrick[14]->MakingGameMap(270, 270, 0.2, 2.7); // left third inner vertical line
        objBrick[15]->MakingGameMap(439, 270, 0.2, 2.7); // right third inner vertical  line

        objBrick[16]->MakingGameMap(115, 550, 0.2, 6); // left first inner vertical line from bottom
        objBrick[17]->MakingGameMap(600, 550, 0.2, 6); // right first inner vertical line from bottom
        objBrick[18]->MakingGameMap(115, 800, 2, 0.3); // left first inner horizontal line from bottom
        objBrick[19]->MakingGameMap(434, 800, 2, 0.3); // right first ineer horizontal line from bottom

        objBrick[20]->MakingGameMap(200, 550, 0.2, 4.3); // left second inner vertical line from bottom
        objBrick[21]->MakingGameMap(509, 550, 0.2, 4.3); // right second inner vertical line from bottom
        objBrick[22]->MakingGameMap(435, 730, 1, 0.3);   // right second inner horizontal line from bottom
        objBrick[23]->MakingGameMap(200, 730, 1.1, 0.3); // left second inner horizontal line from bottom

        objBrick[24]->MakingGameMap(270, 550, 0.2, 2.7); // left third inner vertical line from bottom
        objBrick[25]->MakingGameMap(439, 550, 0.2, 2.7); // right third inner vertical  line from bottom
        objBrick[26]->MakingGameMap(270, 655, 0.4, 0.3); // left third inner horizontal line form bottom
        objBrick[27]->MakingGameMap(420, 655, 0.4, 0.3); // right third inner horizontal line from bottom

        // middle pattern
        objBrick[28]->MakingGameMap(340, 430, 0.4, 0.3);
        objBrick[29]->MakingGameMap(340, 470, 0.4, 0.3);
        objBrick[30]->MakingGameMap(340, 440, 0.1, 0.7);
        objBrick[31]->MakingGameMap(368, 440, 0.1, 0.7);


;
    }

    bool Game_Over()
    {
        if (TotalLivesAvailable == 0)
        {
            
            return true;

        }
        else
            return false;
    }

    void start_game()
    {
        srand(time(0));
        RenderWindow window(VideoMode(720, 1080), title);
        Clock clock;
        Font objFont;

        objFont.loadFromFile("font/SEASRN__.ttf");

        Text GameScore;
        GameScore.setCharacterSize(18);
        GameScore.setFont(objFont);
        GameScore.setFillColor(sf::Color::White);
        GameScore.setStyle(sf::Text::Bold);

        Text DisplayLives;
        DisplayLives.setCharacterSize(18);
        DisplayLives.setFont(objFont);
        DisplayLives.setFillColor(sf::Color::White);
        DisplayLives.setStyle(sf::Text::Bold);

        Text DisplayLevel;
        DisplayLevel.setCharacterSize(18);
        DisplayLevel.setFont(objFont);
        DisplayLevel.setFillColor(sf::Color::White);
        DisplayLevel.setStyle(sf::Text::Bold);



        float timer = 0;
        float newTimer = 0;
        float newTimer1 = 0;

        int SpawningRate = 7;
        int DurationToIncSpeed = 10;
        int HideEnemy = 10;
        while (window.isOpen())
        {
            if (pause_Game)
            {
                if (Keyboard::isKeyPressed(Keyboard::R))
                {
                    pause_Game = false;
                }
            }

            if (!pause_Game)
            {
                float time = clock.getElapsedTime().asSeconds();
                clock.restart();
                timer += time;
              

                Event e;
                while (window.pollEvent(e))
                {
                    if (e.type == Event::Closed)
                        window.close();
                }

                window.clear(Color::Black);
                window.draw(background);

                // displaying the walls
                
                    for (int i = 0; i < 32; i++)
                    {
                        window.draw(objBrick[i]->wall_sprite);
                    }

                    // displaying points
                    for (int i = 0; i < 54; i++)
                        window.draw(ObjPoint[i]->point_sprite);
                    // displaying enemy car
                    window.draw(objEnemy->enemy_sprite);


                // calling the function the move the player's car

                objPlayer->movePlayer();
                objEnemy->moveEnemy();
                for (int i = 0; i < 54; i++)
                {
                    if (objPlayer->sprite_player.getGlobalBounds().intersects(ObjPoint[i]->point_sprite.getGlobalBounds()))
                    {
                        m.openFromFile("Sound/CollectPoint.ogg");
                        m.play();
                        // if palyer and points collides, give a incremnet in score
                        Score++;
                        TotalPoints--;
                        if (LevelNum == 2)
                            TotalPoints2--;
                        if (LevelNum == 3)
                            TotalPoints3--;

                        cout << "Score = " << Score << endl;
                        ObjPoint[i]->SettingPoints(740, 1200, 0.1, 0.1);
                    }
                }
                

                if (TotalPoints == 0)
                {
                    
                    LevelNum = 2;
                    int index = 0;
                    while (index < 54)
                    {
                        // here giving memory to object of class ponts
                        ObjPoint[index] = new points();
                        ++index;
                    }
                    int x = 120;
                    int y = 90;
                    // here drawing the points
                    for (int i = 0; i < 6; i++)
                    {
                        ObjPoint[i]->SettingPoints(x, y, 0.7, 0.7);
                        x += 90;
                    }
                    x = 120;
                    y = 860;
                    for (int i = 6; i < 12; i++)
                    {
                        ObjPoint[i]->SettingPoints(x, y, 0.7, 0.7);
                        x += 90;
                    }

                    x = 60;
                    y = 160;

                    for (int i = 12; i < 18; i++)
                    {
                        ObjPoint[i]->SettingPoints(x, y, 0.7, 0.7);
                        y += 120;
                    }

                    x = 635;
                    y = 160;
                    for (int i = 18; i < 24; i++)
                    {
                        ObjPoint[i]->SettingPoints(x, y, 0.7, 0.7);
                        y += 120;
                    }

                    x = 190;
                    y = 150;
                    for (int i = 24; i < 28; i++)
                    {
                        ObjPoint[i]->SettingPoints(x, y, 0.7, 0.7);
                        x += 100;
                    }

                    x = 190;
                    y = 770;
                    for (int i = 28; i < 32; i++)
                    {
                        ObjPoint[i]->SettingPoints(x, y, 0.7, 0.7);
                        x += 100;
                    }

                    x = 150;
                    y = 220;
                    for (int i = 32; i < 37; i++)
                    {
                        ObjPoint[i]->SettingPoints(x, y, 0.7, 0.7);
                        y += 120;
                    }

                    x = 580;
                    y = 220;
                    for (int i = 37; i < 42; i++)
                    {
                        ObjPoint[i]->SettingPoints(x, y, 0.7, 0.7);
                        y += 120;
                    }

                    x = 250;
                    y = 220;
                    for (int i = 42; i < 45; i++)
                    {
                        ObjPoint[i]->SettingPoints(x, y, 0.7, 0.7);
                        x += 90;
                    }

                    x = 250;
                    y = 700;
                    for (int i = 45; i < 48; i++)
                    {
                        ObjPoint[i]->SettingPoints(x, y, 0.7, 0.7);
                        x += 90;
                    }

                    x = 230;
                    y = 300;
                    for (int i = 48; i < 51; i++)
                    {
                        ObjPoint[i]->SettingPoints(x, y, 0.7, 0.7);
                        y += 160;
                    }

                    x = 480;
                    y = 300;
                    for (int i = 51; i < 54; i++)
                    {
                        ObjPoint[i]->SettingPoints(x, y, 0.7, 0.7);
                        y += 160;
                    }
                    for (int i = 0; i < 54; i++)
                        window.draw(ObjPoint[i]->point_sprite);
                    
                }

                if (TotalPoints2 == 0)
                {
                    LevelNum = 3;
                }

                if (LevelNum == 2)
                {
                    objEnemy->MoveEnemyRandomly();

                }
               
                //Here Displaying Score on Top of Screeen
                string ScoreDisplay = "Score : "; 
                string ScoreToString= to_string(Score);
                GameScore.setPosition(30, 20);
                GameScore.setString(ScoreDisplay);
                window.draw(GameScore);;
                GameScore.setPosition(110, 20);
                GameScore.setString(ScoreToString);
                window.draw(GameScore);

                //Displaying Lives
                string LivesDisplay = "Lives : ";
                string LivesToString = to_string(TotalLivesAvailable);
                DisplayLives.setPosition(400, 20);
                DisplayLives.setString(LivesDisplay);
                window.draw(DisplayLives);;
                DisplayLives.setPosition(480, 20);
                DisplayLives.setString(LivesToString);
                window.draw(DisplayLives);
                

                //Displaying Level
                String LevelsDisplay = "Level : ";
                String LevelToString = to_string(LevelNum);
                DisplayLevel.setPosition(250,20);
                DisplayLevel.setString(LevelsDisplay);
                window.draw(DisplayLevel);
                DisplayLevel.setPosition(320,20);
                DisplayLevel.setString(LevelToString);
                window.draw(DisplayLevel);



                if (timer > SpawningRate)
                {
                    num = rand() % 4;
                    objPlayer->SetFood(num);
                    timer = 0;
                    

                }
                else

                     objPlayer->draw(window, num);




                if (objPlayer->sprite_player.getGlobalBounds().intersects(objPlayer->BonusFood[0]->Food_Sprite.getGlobalBounds()))
                {
                    cout << "Red Rectangle Eaten\nGiveIncrease of 10" << endl;
                  objPlayer->BonusFood[0]->ScoreBonus(&Score);
                  objPlayer->BonusFood[0]->LivesBonus(&TotalLivesAvailable);
                    objPlayer->BonusFood[0]->Food_Sprite.setPosition(800, 1300);
                }
                if (objPlayer->sprite_player.getGlobalBounds().intersects(objPlayer->BonusFood[1]->Food_Sprite.getGlobalBounds()))
                {
                    cout << "Green Circle Eaten\nGiveIncrease of 20" << endl;
                    objPlayer->BonusFood[1]->ScoreBonus(&Score); ;
                    objPlayer->BonusFood[1]->LivesBonus(&TotalLivesAvailable);
                    objPlayer->BonusFood[1]->Food_Sprite.setPosition(800, 1300);
                }
                if (objPlayer->sprite_player.getGlobalBounds().intersects(objPlayer->BonusFood[2]->Food_Sprite.getGlobalBounds()))
                {
                    objPlayer->BonusFood[2]->Food_Sprite.setPosition(800, 1300);
                    cout << "Orange Hexagon Eaten\nGiveIncrease of 10" << endl;
                    objPlayer->BonusFood[2]->ScoreBonus(&Score); 
                    objPlayer->BonusFood[2]->LivesBonus(&TotalLivesAvailable);
                    IncSpeed = true;
                    objPlayer->speed = objPlayer->speed * 1.5;
                    
                }
                if (objPlayer->sprite_player.getGlobalBounds().intersects(objPlayer->BonusFood[3]->Food_Sprite.getGlobalBounds()))
                {
                    objPlayer->BonusFood[3]->Food_Sprite.setPosition(800, 1300);
                    DisappearEnemy = true;
                 }


               if(IncSpeed && DurationToIncSpeed > newTimer)
                {
                    cout << "Speed Increased" << objPlayer->speed<<endl;
                  
                    newTimer += time;
                }
                if(newTimer> DurationToIncSpeed)
                {
                    

                    objPlayer->speed = objPlayer->speed / 1.5;;
                    cout << "Speed Returned" << objPlayer->speed << endl;
                    newTimer = 0;
                    IncSpeed = false;
                }

                if (DisappearEnemy && HideEnemy > newTimer1)
                {
                    //sending enemy out of screen for 10 seconds
                    cout << "Hide Enemy" << endl;
                    objEnemy->enemy_sprite.setPosition(900, 1600);
                    newTimer1 += time;
                }
                if (newTimer1 > DurationToIncSpeed)
                {
                    objEnemy->enemy_sprite.setPosition(500,850);
                    cout << "BringEnemyBack" << objPlayer->speed << endl;
                    newTimer1 = 0;
                    DisappearEnemy = false;
                }
               

                if (objPlayer->sprite_player.getGlobalBounds().intersects(objEnemy->enemy_sprite.getGlobalBounds()))
                {
                    m1.openFromFile("Sound/collision.ogg");
                    m1.play();
                    --TotalLivesAvailable;
                    cout << "Total Lives Available " << TotalLivesAvailable << endl;
                    objPlayer->sprite_player.setPosition(100, 80);
                    objEnemy->enemy_sprite.setPosition(500, 850);
                }
                if (Game_Over())
                {
                    
                    GameOverTex.loadFromFile("img/background_1.png");
                    GameOverSprite.setTexture(GameOverTex);
                    RenderWindow windowG(VideoMode(720, 1080), "Game_Over");

                    m2.openFromFile("Sound/gameover.ogg");
                    m2.play();

                    Text DisplayOver("Game_Over", objFont, 56);
                    DisplayOver.setPosition(windowG.getSize().x / 2 - DisplayOver.getGlobalBounds().width / 2, 350);
                    DisplayOver.setFillColor(sf::Color::Cyan);

                    Text DisplayScore("Score : " + to_string(Score), objFont, 56);
                    DisplayScore.setPosition(windowG.getSize().x / 2 - DisplayScore.getGlobalBounds().width / 2, 450);
                    DisplayScore.setFillColor(sf::Color::Cyan);

                    while (windowG.isOpen())
                    {
                        Event GameOver;
                        while (windowG.pollEvent(GameOver))
                        {
                            if (GameOver.type == Event::Closed)
                                windowG.close(); // to close the screen
                        }

                        if (Keyboard::isKeyPressed(Keyboard::BackSpace)) // condition:press escape key to close the window
                            windowG.close();

                        windowG.draw(GameOverSprite);
                        windowG.draw(DisplayOver);
                        windowG.draw(DisplayScore);
                        windowG.display();
                    }
                    window.close();
                }
                if (Keyboard::isKeyPressed(Keyboard::P))
                {
                    pause_Game = true;
                }

                if (Keyboard::isKeyPressed(Keyboard::A))
                {
                    objPlayer->PlayerMovedByUser("left");
                }
                else if (Keyboard::isKeyPressed(Keyboard::W))
                {
                    objPlayer->PlayerMovedByUser("above");
                }
                else if (Keyboard::isKeyPressed(Keyboard::S))
                {
                    objPlayer->PlayerMovedByUser("down");
                }
                else if (Keyboard::isKeyPressed(Keyboard::D))
                {
                    objPlayer->PlayerMovedByUser("right");
                }

                window.display();
            }
        }
    }
};