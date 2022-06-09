#include <SFML/Graphics.hpp>
#include <cmath>
#include "view.h"
#include "textbox.h"
#include "vector"
#include "sstream"

int returnHeight(int height) {
    return height;
}
int returnWidth(int width) {
    return width;
}
int returnSizeX(int width) {
    return width/2;
}
int returnSizeY(int height) {
    return height/2;
}
string intToString(double number) {
    stringstream ss;
    string str;
    ss << number;
    ss >> str;
    return str;
}

int main()
{

    int x,y;
    bool hold;
    double equation,zoomCounter=0,Scaler = 32, widthness;
    float leftBorder = -1000, rightBorder = 1000,width = 1280,height = 720;
    float CenterX = width/2, CenterY = height/2;
    unsigned long long range = sqrt(leftBorder * leftBorder) + sqrt(rightBorder * rightBorder);


    RenderWindow window;
    window.create(sf::VideoMode(width,), "Graphing Calculator");   
    window.setFramerateLimit(60);
    View view(window.getDefaultView());
    view.reset(FloatRect(0, 0, window.getSize().x, window.getSize().y));
    const float zoomAmount{ 1.1f }; // zoom by 10%



    ContextSettings settings;
    settings.antialiasingLevel = 8;

    Font font;
    font.loadFromFile("C:/arial.ttf");
    Textbox textbox1(16,Color::White, true);
    textbox1.setFont(font);
    textbox1.setPosition({100,100});

    //init a font
    font.loadFromFile("C:/arial.ttf");
    Text text;
    text.setFont(font);
    text.setColor(sf::Color::White);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            switch (event.type) {
                case Event::Closed:
                    window.close();
                    break;
                case Event::MouseWheelScrolled:
                    if (event.mouseWheelScroll.delta > 0) {
                        if (zoomCounter < 32) {
                            zoomView({event.mouseWheelScroll.x, event.mouseWheelScroll.y}, window, (1.f / zoomAmount));
                            zoomCounter++;
                        }
                    }
                    else if (event.mouseWheelScroll.delta < 0)
                        if (zoomCounter > 0) {
                            zoomCounter--;
                            zoomView({ event.mouseWheelScroll.x, event.mouseWheelScroll.y }, window, zoomAmount);
                        }
                case::Event::KeyPressed:
                    if (event.key.code == sf::Keyboard::Enter) {
                        string str = textbox1.getText();

                        equation = stod(str);

                    }
                    else if (event.key.code == sf::Keyboard::Escape) {
                        view = window.getDefaultView();
                        window.setView(view);
                    }
                case Event::MouseMoved:
//                    std::cout << "mouse x,y: " << returnHeight(event.size.width) - returnSizeX(window.getSize().x)
//                    << " " << returnWidth(event.size.height) - returnSizeY(window.getSize().y) << std::endl;
                    break;
                case Event::TextEntered:
                    textbox1.typedOn(event);
                case Event::Resized:
                    FloatRect visibleArea(0, 0, event.size.width, event.size.height);
                    window.setView(sf::View(visibleArea));
                    view = window.getDefaultView();
                    window.setView(view);
                    zoomCounter = 0;
            }
        }

        window.clear(Color(Color::Black));

        VertexArray Line(LinesStrip, 2);
        Line[0].position = Vector2f(width/2, (0));
        Line[1].position = Vector2f(width/2, (height));
        window.draw(Line);
        Line[0].position = Vector2f((0), height/2);
        Line[1].position = Vector2f((width), height/2);
        window.draw(Line);


        font.loadFromFile("C:/arial.ttf");
        Text dimension;
        dimension.setFont(font);
        dimension.setColor(sf::Color::White);


        Scaler = 32, widthness = 8;
        if (zoomCounter >= 4 && zoomCounter < 16)  Scaler = 16, widthness = 4;
        if (zoomCounter >= 8 && zoomCounter < 16) Scaler = 8, widthness = 2;
        if (zoomCounter >= 16 && zoomCounter < 24) Scaler = 4, widthness = 1;
        if (zoomCounter >= 24) Scaler = 2, widthness = 0.5;


        for(float i = 0; i <= width/2; i+=Scaler) {
            Line[0].position = sf::Vector2f(width/2-i, height/2-(widthness));
            Line[1].position = sf::Vector2f(width/2-i, height/2+(widthness));
            window.draw(Line);
        }
        for(float i = 0; i <= width/2; i+=Scaler) {
            Line[0].position = sf::Vector2f(width/2+i, height/2-(widthness));
            Line[1].position = sf::Vector2f(width/2+i, height/2+(widthness));
            window.draw(Line);
        }
        for(float i = 0; i <= width/2; i+=Scaler) {
            Line[0].position = sf::Vector2f(width/2-(widthness), height/2-i);
            Line[1].position = sf::Vector2f(width/2+(widthness), height/2-i);
            window.draw(Line);
        }
        for(float i = 0; i <= width/2; i+=Scaler) {
            Line[0].position = sf::Vector2f(width/2-(widthness), height/2+i);
            Line[1].position = sf::Vector2f(width/2+(widthness), height/2+i);
            window.draw(Line);
        }


        size_t i = 0;
        VertexArray curve(LineStrip, 2);
        for (float x = leftBorder; x < rightBorder; x+= 0.01f) {
            float testEquation = pow(0.5,x)-(x-2)*(x-2)+1;
//            curve[i].position = Vector2f(x*x-height/2,x+width/2);
            curve.append(Vertex(Vector2f(x*x-height/2,x+width/2)));
            curve[i].color = {75, 251, 75};
            i++;
        }

        i = 0;
        sf::Transform rotation;
        rotation.rotate(270);
        window.draw(curve, rotation);
        textbox1.drawTo(window);


        std::ostringstream playerScoreString;
        playerScoreString << Scaler;
        text.setString("Rozmirnist: " + playerScoreString.str());
        const Vector2f Coord{ window.mapPixelToCoords({static_cast<int>(window.getPosition().x-(width/5)),window.getPosition().y}) };
        text.setCharacterSize((width/height*5));
        text.move(Coord);
        text.setPosition(Coord);
        window.draw(text);


        window.display();
    }

    return EXIT_SUCCESS;
}
