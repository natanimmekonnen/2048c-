
#include<SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include<fstream>
#include <string.h>
#include "easy.h"
#include "medium.h"
#include "hard.h"
using namespace std;


int menu()
{

 sf::RenderWindow window(sf::VideoMode(700, 1000), "2048");
 //creates a window using the sfml library it accepts the width, height and bits per pixel of the rendering region
 sf::Font font;
 //declares a variable of type sf::font which is a class for loading an manipulating character fonts

    if(!font.loadFromFile("ARLRDBD.ttf"))
    {
        std::cout<<"error\n";
    }
    //tires to load a font from a file using the loadFromFile function of the sf::Font class, and the parameter "ARLRDBD.TFF " is the name of the font file



    sf::Text menu1,menu2,menu3;
    //declares a variable of type sf::Text which is used to store and manipulate text objects
    menu1.setCharacterSize(70);
    //sets the character size of menu text object to 70 pixels
    menu1.setFillColor(sf::Color::Black);
    // This sets the fill color of the menu text object to black1
    menu1.setFont(font);
    //This sets the font of the menu text object to the font variable, which is a reference to a sf::Font object that must have been loaded previously
    menu1.setPosition(100.f,300.f);
    //This sets the position of the menu text object to (100, 300) pixels relative to its parent or the origin of the render target
    menu1.setString("New Game");
    //This sets the string to display by the menu text object to "New Game"

    menu2.setCharacterSize(70);
    menu2.setFillColor(sf::Color::Black);
    menu2.setFont(font);
    menu2.setPosition(100.f,500.f);
    menu2.setString("Continue Game");

    menu3.setCharacterSize(70);
    menu3.setFillColor(sf::Color::Black);
    menu3.setFont(font);
    menu3.setPosition(100.f,700.f);
    menu3.setString("Exit Game");
while(window.isOpen())
{
sf::Event event;
int coordinationx,coordinationy;
    while (window.pollEvent(event))
        {
        if (event.type == sf::Event::Closed)
            {  window.close();}
        else if (event.type==sf::Event::MouseButtonPressed)
            {
                coordinationx = sf::Mouse::getPosition(window).x;
                coordinationy = sf::Mouse::getPosition(window).y;
            }
        if(coordinationx > 100 && coordinationy > 300 && coordinationy < 300 + 60)
            {

               window.close();
               return 1;

            }
        if(coordinationx > 100 && coordinationy > 500 && coordinationy < 500 + 60)
            {
                window.close();
                return 2;

            }
        if(coordinationx > 100 && coordinationy > 700 && coordinationy < 700 + 60)
            {
                window.close();
                return 3;

            }


            coordinationx=0;
            coordinationy=0;

        }

        window.clear(sf::Color(187,173,160));
        window.draw(menu1);
        window.draw(menu2);
        window.draw(menu3);
        window.display();
}
}

int main()
{
    srand(time(0));




int gamenumber;

    gamenumber=menu();


if(gamenumber==1)
{ //if this condition turns true the new game part will procceed with the below code


 sf::RenderWindow window(sf::VideoMode(700, 1000), "2048");
//This constructs a new window with a video mode of 700 by 1000 pixels and a title of "2048"
 sf::Font font;
  //This declares a variable of type sf::Font, which is a class for loading and manipulating character fonts

    if(!font.loadFromFile("ARLRDBD.ttf"))
    {//This tries to load a font from a file named ARLRDBD.ttf and checks if the loading was successful or not
        std::cout<<"error\n";
    }

 sf::Text easy,medium,hard;
 //This declares three variables of type sf::Text, which are drawable classes that allow to easily display some text with custom style and color on a render target
    easy.setCharacterSize(70);
    //This sets the character size of the easy text object to 70 pixels
    easy.setFillColor(sf::Color::Black);
    //This sets the fill color of the easy text object to black
    easy.setFont(font);
    // This sets the font of the easy text object to the font variable, which is a reference to a sf::Font object that was loaded previously
    easy.setPosition(100.f,300.f);
    //This sets the position of the easy text object to (100, 300) pixels relative to its parent or the origin of the render target
    easy.setString("Easy");
    //This sets the string to display by the easy text object to �Easy�.
//The next eight lines do the same thing for the medium and hard text objects, but with different positions and strings
    medium.setCharacterSize(70);
    medium.setFillColor(sf::Color::Black);
    medium.setFont(font);
    medium.setPosition(100.f,500.f);
    medium.setString("Medium");

    hard.setCharacterSize(70);
    hard.setFillColor(sf::Color::Black);
    hard.setFont(font);
    hard.setPosition(100.f,700.f);
    hard.setString("Hard");
    //This starts a loop that runs as long as the window is open
    while(window.isOpen())
{
    sf::Event event;
    //This declares a variable of type sf::Event, which is a class that represents any event that can be triggered by SFML entities (such as windows or inputs)
    int coordinationx,coordinationy;
    //This declares two variables of type int, which will be used to store the mouse coordinates when a mouse button is pressed
    //This starts a loop that pops events from the window�s event queue and handles them one by one
    while (window.pollEvent(event))

        {
        if (event.type == sf::Event::Closed)
        //This checks if the event type is equal to sf::Event::Closed, which means that the user has requested to close the window (by clicking on its close button or using a keyboard shortcut)
            {
                window.close();
    //This closes the window and destroys all the attached resourses
            }
        //This checks if the event type is equal to sf::Event::MouseButtonPressed, which means that a mouse button has been pressed.
        else if (event.type==sf::Event::MouseButtonPressed)

            {
                coordinationx = sf::Mouse::getPosition(window).x;
                //This gets the coordinate of the mouse position relative to the window using the static function sf::Mouse::get position and assigns it to the coordination x variable
                coordinationy = sf::Mouse::getPosition(window).y;
                //This gets the coordinate of the mouse position relative to the window using the static function sf::Mouse::get position and assigns it to the coordination y variable
            }
            //The next twelve lines check if the mouse coordinates are within certain ranges that correspond to the positions and sizes of the text objects.
            // If they are, they close the window and return an integer value that indicates which text object was clicked.
            // These values are used later to start different game modes.
        if(coordinationx > 100 && coordinationy > 300 && coordinationy < 300 + 60)
            {




                window.close();
                newGame3();
                easygame();



            }
        if(coordinationx > 100 && coordinationy > 500 && coordinationy < 500 + 60)
            {

                window.close();
                newGame2();
                mediumgame();




            }
        if(coordinationx > 100 && coordinationy > 700 && coordinationy < 700 + 60)
            {
                window.close();
                newGame();
                hardgame();



            }


            coordinationx=0;
            coordinationy=0;

        }

        window.clear(sf::Color(187,173,160));
        //This clears the entire window with a color that has RGB values of (187,173,160)
        window.draw(easy);
        //draws the easy text object on top of the cleared window
        window.draw(medium);
        window.draw(hard);
        window.display();
        //This displays on screen what has been rendered to the window so far

        }
}
//if it chooses continue the below codes will be implemented
else if(gamenumber==2)
{

    sf::RenderWindow window(sf::VideoMode(700, 1000), "2048");
    sf::Font font;

    if(!font.loadFromFile("ARLRDBD.ttf"))
    {
        std::cout<<"error\n";
    }

 sf::Text easy,medium,hard;
    easy.setCharacterSize(70);
    easy.setFillColor(sf::Color::Black);
    easy.setFont(font);
    easy.setPosition(100.f,300.f);
    easy.setString("Easy");

    medium.setCharacterSize(70);
    medium.setFillColor(sf::Color::Black);
    medium.setFont(font);
    medium.setPosition(100.f,500.f);
    medium.setString("Medium");

    hard.setCharacterSize(70);
    hard.setFillColor(sf::Color::Black);
    hard.setFont(font);
    hard.setPosition(100.f,700.f);
    hard.setString("Hard");
    while(window.isOpen())
{
    sf::Event event;
    int coordinationx,coordinationy;
    while (window.pollEvent(event))
        {
        if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        else if (event.type==sf::Event::MouseButtonPressed)
            {
                coordinationx = sf::Mouse::getPosition(window).x;
                coordinationy = sf::Mouse::getPosition(window).y;
            }
        if(coordinationx > 100 && coordinationy > 300 && coordinationy < 300 + 60)
            {

             //works for the button easy game and uses the next functions
                window.close();
                if(loadgame3()==1)
                {
                    easygame();
                }
                else{
                    newGame3();
                    easygame();
                }




            }
        if(coordinationx > 100 && coordinationy > 500 && coordinationy < 500 + 60)
            {//works for the button medium game and uses the next functions

                window.close();
                if(loadgame2()==1)
                {
                    mediumgame();
                }
                else{
                    newGame2();
                    mediumgame();
                }

            }
        if(coordinationx > 100 && coordinationy > 700 && coordinationy < 700 + 60)
            {
            //works for the button hard game and uses the next functions
                window.close();
                  if(loadgame()==1)
                {
                    hardgame();
                }
                else
                {
                    newGame();
                    hardgame();
                }



            }


            coordinationx=0;
            coordinationy=0;

        }

        window.clear(sf::Color(187,173,160));
        window.draw(easy);
        window.draw(medium);
        window.draw(hard);
        window.display();

        }
}




}








