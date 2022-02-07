#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

//functions
void timer()
{
    sf::Clock clock;
    float time = 0;
    while (time < 5)
    {
        time = clock.getElapsedTime().asMilliseconds();
    }
}


//block main-----------------------------------------------------------------
int main()
{

    //random a number----------------------------------------------------------
    //sf::Window getWinSize;
    
    //shape. window and color---------------------------------------------------
    sf::RenderWindow window(sf::VideoMode(400, 400), "SFML works!");
    sf::CircleShape shape(10.f);
    shape.setFillColor(sf::Color::Green);

    //set random position
    sf::Vector2u getSizeWin = window.getSize();
    srand(time(0));

    int R = shape.getRadius();
    int randomPositionX = rand() % getSizeWin.x - R;
    int randomPositionY = rand() % getSizeWin.y - R;
    shape.setPosition(randomPositionX, randomPositionY);

    //cout << getSizeWin.x << endl;

    int angle = (rand() % 360) * 3.14 / 180;
    //int V = 7;

    float Vx = sin(angle);
    float Vy = cos(angle);

    //cout << x << "  " << y << "   " << angle << endl;

    //main loop------------------------------------------------------------------
    while (window.isOpen())
    {
        timer();
        shape.move(Vx, Vy);

        //Проверяем положение молекулы
        if (shape.getPosition().x > getSizeWin.x - (2*R))
        {
            Vx = -Vx;
        }
        if (shape.getPosition().x < (R/2))
        {
            Vx = -Vx;
        }
        if (shape.getPosition().y > getSizeWin.y - (2*R))
        {
            Vy = -Vy;
        }
        if (shape.getPosition().y < (R/2))
        {
            Vy = -Vy;
        }
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}