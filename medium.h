#include <SFML/Graphics.hpp>
#include "function2.h"

void mediumgame()
{

    string hold_string_score2,hold_string_high_score2;
    sf::RenderWindow window(sf::VideoMode(700, 1000), "2048");

    sf::Texture blank_Tile, number2, number4, number8, number16, number32, number64, number128, number256, number512, number1024, number2048, game_over_,undo_,restart_,you_won;
    blank_Tile.loadFromFile("blank_2.png");
    number2.loadFromFile("2_2.png");
    number4.loadFromFile("4_2.png");
    number8.loadFromFile("8_2.png");
    number16.loadFromFile("16_2.png");
    number32.loadFromFile("32_2.png");
    number64.loadFromFile("64_2.png");
    number128.loadFromFile("128_2.png");
    number256.loadFromFile("256_2.png");
    number512.loadFromFile("512_2.png");
    number1024.loadFromFile("1024_2.png");
    number2048.loadFromFile("2048_2.png");
    game_over_.loadFromFile("game.png");
    undo_.loadFromFile("undo.png");
    restart_.loadFromFile("restart.png");
    you_won.loadFromFile("won.png");

    sf::Sprite blankTile(blank_Tile);
    sf::Sprite number2Tile(number2);
    sf::Sprite number_4_Tile(number4);
    sf::Sprite number_8_Tile(number8);
    sf::Sprite number_16_Tile(number16);
    sf::Sprite number_32_Tile(number32);
    sf::Sprite number_64_Tile(number64);
    sf::Sprite number_128_Tile(number128);
    sf::Sprite number_256_Tile(number256);
    sf::Sprite number_512_Tile(number512);
    sf::Sprite number_1024_Tile(number1024);
    sf::Sprite number_2048_Tile(number2048);
    sf::Sprite gameover_Tile(game_over_);
    sf::Sprite undo_Tile(undo_);
    sf::Sprite restart_Tile(restart_);
    sf::Sprite you_won_Tile(you_won);



    sf::Font font;

    if(!font.loadFromFile("ARLRDBD.ttf"))
    {
        std::cout<<"error\n";
    }

    sf::Text Twenty_forty_eight;
    Twenty_forty_eight.setCharacterSize(100);
    Twenty_forty_eight.setFillColor(sf::Color(0,0,0));
    Twenty_forty_eight.setFont(font);
    Twenty_forty_eight.setPosition(10.f,75.f);
    Twenty_forty_eight.setString("2048");




    sf::Text sc;
    sc.setCharacterSize(50);
    sc.setFillColor(sf::Color(0,0,0));
    sc.setFont(font);
    sc.setPosition(320.f,100.f);

    sf::Text hs;
    hs.setCharacterSize(50);
    hs.setFillColor(sf::Color(0,0,0));
    hs.setFont(font);
    hs.setPosition(500.f,100.f);


    sf::Text scoretext;
    scoretext.setCharacterSize(30);
    scoretext.setFillColor(sf::Color(0,0,0));
    scoretext.setFont(font);
    scoretext.setPosition(320.f,20.f);
    scoretext.setString("Score");

    sf::Text highscore;
    highscore.setCharacterSize(30);
    highscore.setFillColor(sf::Color(0,0,0));
    highscore.setFont(font);
    highscore.setPosition(500.f,20.f);
    highscore.setString("High Score");

    sf::Text save_game;
    save_game.setCharacterSize(20);
    save_game.setFillColor(sf::Color(0,0,0));
    save_game.setFont(font);
    save_game.setPosition(40.f,20.f);
    save_game.setString("Save Game");

    while (window.isOpen())
    {
        sf::Event event;
        int coorx,coory;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::KeyPressed )
             {

                switch(event.key.code)
                {case sf::Keyboard::W :
                    moveUp2();
                    break;
                case sf::Keyboard::S :
                  moveDown2();
                  break;
                case sf::Keyboard::A :
                    moveLeft2();
                    break;
                case sf::Keyboard::D :
                        moveRight2();
                        break;
                }
                holdhighscore2(score2);
                writehighscore2();



                hold_string_score2=to_string(score2);
                hold_string_high_score2=to_string(highScore2);
                sc.setString(hold_string_score2);

                hs.setString(hold_string_high_score2);


             }
            else if (event.type == sf::Event::Closed)
             {
                    window.close();
             }
            else if (event.type==sf::Event::MouseButtonPressed)
             {
                coorx = sf::Mouse::getPosition(window).x;
                coory = sf::Mouse::getPosition(window).y;
             }
            if(coorx > 450 && coory > 200 && coorx < 450 + 60 && coory < 200 + 60)
             {

                undo2();
             }
            if(coorx > 570 && coory > 205 && coorx < 570 + 60 && coory < 205 + 60)
             {

                newGame2();
             }

            if(coorx > 40 && coory > 20 &&  coory < 20 + 60)
             {

                savegame2();
                window.close();
             }

            coorx=0;
            coory=0;

        }




        window.clear(sf::Color(187,173,160));
        window.draw(Twenty_forty_eight);
        window.draw(sc);
        window.draw(hs);
        window.draw(scoretext);
        window.draw(highscore);
        window.draw(save_game);
        undo_Tile.setPosition(450,200);
        undo_Tile.setScale(0.4,0.4);

        restart_Tile.setPosition(570,205);
        restart_Tile.setScale(0.30,0.30);

        window.draw(undo_Tile);
        window.draw(restart_Tile);
        for (int i=0; i<size2; i++)
            for (int j=0; j<size2; j++)
            {
                if (board2[i][j] == 0)
                {
                    blankTile.setPosition(j*sizeofTile2, ((i*sizeofTile2)+300));
                    window.draw(blankTile);
                }

            }
        for (int i=0; i<size2; i++)
            for (int j=0; j<size2; j++)
            {

                if (board2[i][j] == 2)
                 {
                    number2Tile.setPosition((j*sizeofTile2)+7.5, ((i*sizeofTile2)+300+7.5));
                    window.draw(number2Tile);
                 }
                else if (board2[i][j] == 4)
                 {
                    number_4_Tile.setPosition((j*sizeofTile2)+7.5, ((i*sizeofTile2)+300+7.5));
                    window.draw(number_4_Tile);
                 }
                else if (board2[i][j] == 8)
                 {
                    number_8_Tile.setPosition((j*sizeofTile2)+7.5, ((i*sizeofTile2)+300+7.5));
                    window.draw(number_8_Tile);
                 }
                else if (board2[i][j] == 16)
                 {
                    number_16_Tile.setPosition((j*sizeofTile2)+7.5, ((i*sizeofTile2)+300+7.5));
                    window.draw(number_16_Tile);
                 }
                else if (board2[i][j] == 32)
                 {
                    number_32_Tile.setPosition((j*sizeofTile2)+7.5, ((i*sizeofTile2)+300+7.5));
                    window.draw(number_32_Tile);
                 }
                else if (board2[i][j] == 64)
                 {
                    number_64_Tile.setPosition((j*sizeofTile2)+7.5, ((i*sizeofTile2)+300+7.5));
                    window.draw(number_64_Tile);
                 }
                else if (board2[i][j] == 128)
                 {
                    number_128_Tile.setPosition((j*sizeofTile2)+7.5, ((i*sizeofTile2)+300+7.5));
                    window.draw(number_128_Tile);
                 }
                else if (board2[i][j] == 256)
                 {
                    number_256_Tile.setPosition((j*sizeofTile2)+7.5, ((i*sizeofTile2)+300+7.5));
                    window.draw(number_256_Tile);
                 }
                else if (board2[i][j] == 512)
                 {
                    number_512_Tile.setPosition((j*sizeofTile2)+7.5, ((i*sizeofTile2)+300+7.5));
                    window.draw(number_512_Tile);
                 }
                else if (board2[i][j] == 1024)
                 {
                    number_1024_Tile.setPosition((j*sizeofTile2)+7.5, ((i*sizeofTile2)+300+7.5));
                    window.draw(number_1024_Tile);
                 }
                else if (board2[i][j] == 2048)
                 {
                    number_2048_Tile.setPosition((j*sizeofTile2)+7.5, ((i*sizeofTile2)+300+7.5));
                    window.draw(number_2048_Tile);
                 }

            }

            if(gameover2())
                {

                    gameover_Tile.setPosition(181.5,500);
                    window.draw(gameover_Tile);
                }


           if(win2())
                {
                    you_won_Tile.setPosition(181.5,500);
                    window.draw(you_won_Tile);


                 }

        window.display();
    }

}



