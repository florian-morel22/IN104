#include <SFML/Graphics.hpp>
#include <math.h>


 sf::RectangleShape setOriginToCenter(sf::RectangleShape object){ //Ne fonctionne pas

        sf::Vector2f size = object.getSize(); 
        object.setOrigin(size.x/2,size.y/2);
        return object;
}

int main()
{

    int height_screen = 1000;
    int width_screen = 1200;
    sf::RenderWindow window(sf::VideoMode(width_screen, height_screen), "Louis t'est con");
    
    sf::CircleShape shape(200.f);
    sf::RectangleShape rectangle(sf::Vector2f(120.f, 50.f));
    shape.setFillColor(sf::Color::Blue);
    rectangle.setFillColor(sf::Color(0, 255, 0, 128));
    rectangle.setPosition(100.f, 200.f);
    rectangle.setRotation(87.f);

    sf::ConvexShape convex;
    convex.setPointCount(4);
    convex.setPoint(0, sf::Vector2f(0.f, 0.f));
    convex.setPoint(1, sf::Vector2f(150.f, 0.f));
    convex.setPoint(2, sf::Vector2f(190.f, 90.f));
    convex.setPoint(3, sf::Vector2f(40.f, 90.f));
    convex.setFillColor(sf::Color::Red);
    convex.move(200.f, 500.f); //Position relative par rapport a la position precedente
    convex.rotate(30.f); //Rotation relative par rapport a la rotation precedente

    sf::RectangleShape rectangle2(sf::Vector2f(width_screen/2,height_screen/2));
    rectangle2 = setOriginToCenter(rectangle2);
    rectangle2.setPosition(width_screen/2,height_screen/2);
    
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
	    window.draw(convex);
        window.draw(rectangle);

        window.display();

    }

    return 0;
}
