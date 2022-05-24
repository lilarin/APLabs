#include <SFML/Graphics.hpp>
#include <cmath>
#include <string>
#include <sstream>
#include <iostream>
#include "shunting_yard.h"

using namespace std;
using namespace sf;

string intToString(double number) {
    stringstream ss;             //create a stringstream
    string str;
    ss << number;                //add number to the stream
    ss >> str;                   //push the contents onto a string
    return str;                  //return the string
}


int main()
{
        string equation = "100000";

        float width = 1280, height = 720, renderWidth = 1280, renderHeight = 720, xOriginal = 0, yOriginal = 0,
        CenterX = (width/2), CenterY = (height/2);
        double Scaler = 10, PanX = 0, PanY = 0;


        bool hold = false;


        RenderWindow window;
        if (!window.isOpen()) {
            window.create(sf::VideoMode(renderWidth,renderHeight), "Graph plotter", Style::Close);
        }

        window.setFramerateLimit(60);

        ContextSettings settings;
        settings.antialiasingLevel = 8;


        Font font;
        font.loadFromFile("C:/arial.ttf");

        Text text;
        text.setFont(font);
        text.setCharacterSize(24);


        while (window.isOpen())
        {
            Event event;
            while (window.pollEvent(event))
            {
                switch (event.type) {
    //                case Event::MouseLeft:
    //                    button1.setColor(sf::Color(255, 255, 255));
    //                    button2.setColor(sf::Color(255, 255, 255));
                    case Event::Closed:
                        window.close();
                        break;
                    case Event::MouseWheelMoved:            //will check for mouse scrolling
                        if(Scaler == 1 && event.mouseWheel.delta <=-1)      //will not allow Scaler to become 0
                            Scaler = -1;
                        else if(Scaler == -1 && event.mouseWheel.delta >=1) //will not allow Scaler to become 0
                            Scaler = 1;
                        if(event.mouseWheel.delta<0)
                            Scaler-=Scaler*0.1;
                        if(event.mouseWheel.delta>0)
                            Scaler+=Scaler*0.1;
                        break;
                    case::Event::KeyPressed:
                        if (event.key.code == Keyboard::Escape) {
                            Scaler = 10;
                            CenterX = width/2;
                            CenterY = height/2;
                        }
                    case Event::MouseButtonPressed:
                        if (event.mouseButton.button == Mouse::Right) {
                            xOriginal = event.mouseButton.x;
                            yOriginal = event.mouseButton.y;
                            hold = true;
                        }
                        break;
                        {case Event::MouseMoved:
                            if(hold) {
                                PanX = event.mouseMove.x - xOriginal;
                                PanY = event.mouseMove.y - yOriginal;
                                CenterX+=PanX;
                                CenterY+=PanY;
                                xOriginal = event.mouseMove.x;
                                yOriginal = event.mouseMove.y;
                            }
                            break;}
                    case Event::MouseButtonReleased:
                        if (event.mouseButton.button == Mouse::Right) hold = false;
                        break;
                }
            }

            window.clear(Color::Black);

            font.loadFromFile("C:/arial.ttf");
            Text dimension;
            dimension.setFont(font);
            dimension.setColor(sf::Color::White);

            double FScaler = Scaler;
            while(width/FScaler > 20) {
                FScaler *= 2;
            }


            VertexArray Line(LinesStrip, 2);
            Line[0].color = {255, 255, 255};
            Line[1].color = {255, 255, 255};
            text.setFillColor({255, 255, 255});

            Line[0].position = Vector2f(CenterX, (0));                    //creates the y axis
            Line[1].position = Vector2f(CenterX, (height));                 // ''
            window.draw(Line);                                             //draws the y axis
            Line[0].position = Vector2f((0), CenterY);                    //creates the x axis
            Line[1].position = Vector2f((width), CenterY);                 //''
            window.draw(Line);


            double lastPositive = (width/2+(-1*(CenterX-width/2)))/Scaler,lastNegative = (-width/2+(-1*(CenterX-width/2)))/Scaler;
            for(double i = 0; i<=width/2+(-1*(CenterX-width/2)); i+=FScaler)    //creates the Positive X numbers on the grid
            {
                text.setString(intToString(i/Scaler));
                text.setPosition((i+CenterX),CenterY);
                window.draw(text);
            }
            for(double i = 0; i>=-width/2+(-1*(CenterX-width/2)); i-=FScaler)     //creates the Negative X numbers on the grid
            {
                text.setString(intToString(i/Scaler));
                text.setPosition((i+CenterX),CenterY);
                window.draw(text);
            }
            for(double i = 0; i<=height/2+(CenterY-height/2); i+=FScaler)           //creates the Positive Y numbers on the grid
            {
                text.setString(intToString(i/Scaler));
                text.setPosition(CenterX,CenterY-i);
                window.draw(text);
            }
            for(double i = 0; i>=-height/2+(CenterY-height/2); i-=FScaler)          //creates the Negative Y numbers on the grid
            {
                text.setString(intToString(i/Scaler));
                text.setPosition(CenterX,CenterY-i);
                window.draw(text);
            }

            for(double i = 0; i <= width/2+(CenterX-width/2); i+=FScaler)                          //creates the lines by the numbers Negative X grid
            {
                Line[0].position = Vector2f(CenterX-i, CenterY-(10));
                Line[1].position = Vector2f(CenterX-i, CenterY+(10));
                window.draw(Line);
            }
            for(double i = 0; i <= width/2+(-1*(CenterX-width/2)); i+=FScaler)                          //creates the lines by the numbers Positive X grid
            {
                Line[0].position = Vector2f(CenterX+i, CenterY-(10));
                Line[1].position = Vector2f(CenterX+i, CenterY+(10));
                window.draw(Line);
            }
            for(double i = 0; i <= height/2+(-1*(CenterY-height/2)); i+=FScaler)                          //creates the lines by the numbers
            {
                Line[0].position = Vector2f(CenterX-(10),CenterY+i);
                Line[1].position = Vector2f(CenterX+(10),CenterY+i);
                window.draw(Line);
            }
            for(double i = 0; i <= height/2+((CenterY-height/2)); i+=FScaler)                          //creates the lines by the numbers
            {
                Line[0].position = Vector2f(CenterX-(10),CenterY-i);
                Line[1].position = Vector2f(CenterX+(10),CenterY-i);
                window.draw(Line);
            }

            Line[0].color = {50, 50, 50};
            Line[1].color = {50, 50, 50};
            for(double i = 1; i <= width/2+(CenterX-width/2); i+=FScaler)                          //creates the lines by the numbers Negative X grid
            {
                Line[0].position = Vector2f(CenterX-i, 0);
                Line[1].position = Vector2f(CenterX-i, height);
                window.draw(Line);
            }
            for(double i = 1; i <= width/2+(-1*(CenterX-width/2)); i+=FScaler)                          //creates the lines by the numbers Positive X grid
            {
                Line[0].position = Vector2f(CenterX+i, 0);
                Line[1].position = Vector2f(CenterX+i, height);
                window.draw(Line);
            }
            for(double i = 1; i <= height/2+(-1*(CenterY-height/2)); i+=FScaler)                          //creates the lines by the numbers
            {
                Line[0].position = Vector2f(0,CenterY+i);
                Line[1].position = Vector2f(width,CenterY+i);
                window.draw(Line);
            }
            for(double i = 1; i <= height/2+((CenterY-height/2)); i+=FScaler)                          //creates the lines by the numbers
            {
                Line[0].position = Vector2f(0,CenterY-i);
                Line[1].position = Vector2f(width,CenterY-i);
                window.draw(Line);
            }


            Line[0].color = {75, 251, 75};
            Line[1].color = {75, 251, 75};

            for(double x = -20; x < 20; x += 1/Scaler)                  //draws the graph in increments of 0.1
            {
                ShuntingYard::variables["x"] = x;
                ShuntingYard::RPN rpn = ShuntingYard::reversePolishNotation(equation.c_str());
                ShuntingYard::Node* tree = ShuntingYard::parse(rpn);
                Line[0].position = sf::Vector2f((x*Scaler+CenterX),(eval(tree)*Scaler*-1+CenterY));
                ShuntingYard::variables["x"] = x+1/Scaler;
                Line[1].position = sf::Vector2f(((x+1/Scaler)*Scaler+CenterX),(eval(tree)*Scaler*-1+CenterY));
                window.draw(Line);
            }

            window.display();
            //displays everything drawn
        }
}