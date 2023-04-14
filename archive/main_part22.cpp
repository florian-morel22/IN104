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
    
    
    sf::RectangleShape rectangle2(sf::Vector2f(width_screen/2,height_screen/2));
    rectangle2 = setOriginToCenter(rectangle2);
    rectangle2.setPosition(width_screen/2,height_screen/2);
    
    /* Rotation de rectangle 2
    int angle = 0;
    int delta_angle = 10;
    sf::Time freq = sf::seconds(0.1);
    */

    /* Calcul des fps */
    int frame = 0;
    sf::Clock clock;
    sf::Time ones = sf::seconds(1);
    sf::Time t = clock.getElapsedTime();
    
    /* Fixation des fps */
    sf::Time pas = sf::seconds(0.0001f);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

                
        /* Rotation du rectangle de "delta_angle" degres tous les "freq" secondes
        
        rectangle2.setRotation(angle);
        window.draw(rectangle2);
        window.display();
        sf::Clock clock;
        sf::Time t = clock.getElapsedTime();
        while (t<freq){
            t = clock.getElapsedTime();
        }
        angle = (angle+delta_angle)%360;
        */

        
        
        
        /* Calcul des fps : 12000 fps en moyenne */

        t = clock.getElapsedTime();
        if (t<ones) frame = frame+1;
        else{
            printf("%d fps\n", frame);
            clock.restart();
            frame = 0;
        }
        
        /* Modification des fps */

        sf::Clock clock2;
        sf::Time t2 = clock2.getElapsedTime();
        while(t2<pas){
            t2 = clock2.getElapsedTime();
        }
        

    }

    return 0;
}
