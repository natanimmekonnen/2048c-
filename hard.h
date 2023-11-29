#include <SFML/Graphics.hpp>
#include "functions.h"
void hardgame()
{

    string hold_score_string,hold_high_score_string;
    sf::RenderWindow window(sf::VideoMode(700, 1000), "2048");

    sf::Texture blank_Tile, number2, number4, number8, number16, number32, number64, number128, number256, number512, number1024, number2048, game_over_,undo_,restart_,you_won;
    //This declare variables of type sf::Texture and Then below load different images from files using the loadFromFile member function. These images represent the tiles with different numbers, the game over screen, the undo button, the restart button and the you won screen
    blank_Tile.loadFromFile("blank.png");
    number2.loadFromFile("2.png");
    number4.loadFromFile("4.png");
    number8.loadFromFile("8.png");
    number16.loadFromFile("16.png");
    number32.loadFromFile("32.png");
    number64.loadFromFile("64.png");
    number128.loadFromFile("128.png");
    number256.loadFromFile("256.png");
    number512.loadFromFile("512.png");
    number1024.loadFromFile("1024.png");
    number2048.loadFromFile("2048.png");
    game_over_.loadFromFile("game.png");
    undo_.loadFromFile("undo.png");
    restart_.loadFromFile("restart.png");
    you_won.loadFromFile("won.png");
//The below code declare variables of type sf::Sprite and associate them with the corresponding textures using the constructor. These sprites are drawable objects that can be displayed on a render window
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



    sf::Font font;//Declare a variable of type sf::Font and load a font from a file using the loadFromFile member function. This font will be used to display text on the window

    if(!font.loadFromFile("ARLRDBD.ttf"))
    {
        std::cout<<"error\n";
    }

    sf::Text twenty_forty_eight;// declare variables of type sf::Text and set their properties using various member functions. These text objects represent the title of the game, the score, the high score and the save game option. The properties include character size, fill color, font, position and string
    twenty_forty_eight.setCharacterSize(100);
    twenty_forty_eight.setFillColor(sf::Color(0,0,0));
    twenty_forty_eight.setFont(font);
    twenty_forty_eight.setPosition(10.f,75.f);
    twenty_forty_eight.setString("2048");




    sf::Text sc;//variable of type text that represents the score
    sc.setCharacterSize(50);
    sc.setFillColor(sf::Color(0,0,0));
    sc.setFont(font);
    sc.setPosition(320.f,100.f);

    sf::Text hs;//variable of type text that represents the highscore
    hs.setCharacterSize(50);
    hs.setFillColor(sf::Color(0,0,0));
    hs.setFont(font);
    hs.setPosition(500.f,100.f);


    sf::Text scoretext;//displays the score word
    scoretext.setCharacterSize(30);
    scoretext.setFillColor(sf::Color(0,0,0));
    scoretext.setFont(font);
    scoretext.setPosition(320.f,20.f);
    scoretext.setString("Score");

    sf::Text highscore;//displays the highscore word
    highscore.setCharacterSize(30);
    highscore.setFillColor(sf::Color(0,0,0));
    highscore.setFont(font);
    highscore.setPosition(500.f,20.f);
    highscore.setString("High Score");

    sf::Text save_game;//displays the button save game
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
//The next block of code uses a switch statement to handle different cases depending on which key was pressed. It calls different functions to move the tiles on the board according to the direction indicated by the key (W for up, S for down, A for left and D for right).
                switch(event.key.code)
                {case sf::Keyboard::W :
                    moveUp();
                    break;
                case sf::Keyboard::S :
                  moveDown();
                  break;
                case sf::Keyboard::A :
                    moveLeft();
                    break;
                case sf::Keyboard::D :
                        moveRight();
                        break;
                }
 //It below code calls holdhighscore and writehighscore functions to update and save the high score. It converts the score and highScore variables to strings using to_string function and sets them as the strings for sc and hs text objects using setString member function.
                holdhighscore(score);
                writehighscore();
                hold_score_string=to_string(score);
                hold_high_score_string=to_string(highScore);
                sc.setString(hold_score_string);
                hs.setString(hold_high_score_string);


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
             {//If undo Tile was clicked, it calls undo function to undo the last move

                undo();
             }
            if(coorx > 570 && coory > 205 && coorx < 570 + 60 && coory < 205 + 60)
             {//If restart Tile was clicked, it calls newGame function to start a new game.

                newGame();
             }

            if(coorx > 40 && coory > 20 &&  coory < 20 + 60)
             {//If save game text was clicked, it calls savegame function to save the game state and closes the window.

                savegame();
                window.close();
             }

            coorx=0;
            coory=0;// reset the mouse coordinates to zero after each event loop iteration. This is done to avoid triggering multiple clicks with a single mouse press.

        }




        window.clear(sf::Color(187,173,160));
        // Draw the text objects that represent the title of the game, the score, the high score and the save game option on top of the cleared window by calling the draw member function
        window.draw(twenty_forty_eight);
        window.draw(sc);
        window.draw(hs);
        window.draw(scoretext);
        window.draw(highscore);
        window.draw(save_game);
        //he next four lines set the position and scale of the undo_Tile and restart_Tile sprites using the setPosition and setScale member functions. These sprites represent the undo button and the restart button on the window
        undo_Tile.setPosition(450,200);
        undo_Tile.setScale(0.4,0.4);

        restart_Tile.setPosition(570,205);
        restart_Tile.setScale(0.30,0.30);
//The below code draw the undo_Tile and restart_Tile sprites on top of the window by calling the draw member function.
        window.draw(undo_Tile);
        window.draw(restart_Tile);
//The below use nested for loops to iterate over each tile on the board and check if it has a value of 0. If it does, it sets the position of the blankTile sprite using the setPosition member function and draws it on top of the window using the draw member function. This creates a grid of blank tiles on the window.
        for (int i=0; i<size; i++)
            for (int j=0; j<size; j++)
            {
                if (board[i][j] == 0)
                {
                    blankTile.setPosition(j*sizeofTile, ((i*sizeofTile)+300));
                    window.draw(blankTile);
                }

            }
 // The below lines use nested for loops to iterate over each tile on the board and check if it has a value other than 0. If it does, it sets the position of the corresponding sprite (number2Tile, number_4_Tile, etc.) using the setPosition member function and draws it on top of the window using the draw member function. This creates a grid of numbered tiles on top of the blank tiles on the window.
        for (int i=0; i<size; i++)
            for (int j=0; j<size; j++)
            {

                if (board[i][j] == 2)
                 {
                    number2Tile.setPosition((j*sizeofTile)+7.5, ((i*sizeofTile)+300+7.5));
                    window.draw(number2Tile);
                 }
                else if (board[i][j] == 4)
                 {
                    number_4_Tile.setPosition((j*sizeofTile)+7.5, ((i*sizeofTile)+300+7.5));
                    window.draw(number_4_Tile);
                 }
                else if (board[i][j] == 8)
                 {
                    number_8_Tile.setPosition((j*sizeofTile)+7.5, ((i*sizeofTile)+300+7.5));
                    window.draw(number_8_Tile);
                 }
                else if (board[i][j] == 16)
                 {
                    number_16_Tile.setPosition((j*sizeofTile)+7.5, ((i*sizeofTile)+300+7.5));
                    window.draw(number_16_Tile);
                 }
                else if (board[i][j] == 32)
                 {
                    number_32_Tile.setPosition((j*sizeofTile)+7.5, ((i*sizeofTile)+300+7.5));
                    window.draw(number_32_Tile);
                 }
                else if (board[i][j] == 64)
                 {
                    number_64_Tile.setPosition((j*sizeofTile)+7.5, ((i*sizeofTile)+300+7.5));
                    window.draw(number_64_Tile);
                 }
                else if (board[i][j] == 128)
                 {
                    number_128_Tile.setPosition((j*sizeofTile)+7.5, ((i*sizeofTile)+300+7.5));
                    window.draw(number_128_Tile);
                 }
                else if (board[i][j] == 256)
                 {
                    number_256_Tile.setPosition((j*sizeofTile)+7.5, ((i*sizeofTile)+300+7.5));
                    window.draw(number_256_Tile);
                 }
                else if (board[i][j] == 512)
                 {
                    number_512_Tile.setPosition((j*sizeofTile)+7.5, ((i*sizeofTile)+300+7.5));
                    window.draw(number_512_Tile);
                 }
                else if (board[i][j] == 1024)
                 {
                    number_1024_Tile.setPosition((j*sizeofTile)+7.5, ((i*sizeofTile)+300+7.5));
                    window.draw(number_1024_Tile);
                 }
                else if (board[i][j] == 2048)
                 {
                    number_2048_Tile.setPosition((j*sizeofTile)+7.5, ((i*sizeofTile)+300+7.5));
                    window.draw(number_2048_Tile);
                 }

            }
//Check if the game is over
            if(gameover())
                {

                    gameover_Tile.setPosition(181.5,500);
                    window.draw(gameover_Tile);
 //check if you win the game
 }
           if(win())
                {
                    you_won_Tile.setPosition(181.5,500);
                    window.draw(you_won_Tile);


                 }

        window.display();
    }

}


