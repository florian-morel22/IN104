#include <SFML/Graphics.hpp>
#include <math.h>


sf::Sprite scaleToMaxSize(sf::Sprite sprite){
    // Redimensionne le sprite pour que son cote le plus soit de longueur max_size au maximum
    int max_size = 60; 
    sf::FloatRect rect = sprite.getLocalBounds();
    
    printf("%f, %f\n", rect.width, rect.height);
    if (rect.width>rect.height){
        if (rect.width <= max_size) return sprite;
        float ratio = max_size/rect.width;
        sprite.setScale(sf::Vector2f(ratio, ratio)); //On garde le ratio du rectangle
    }
    else{
        printf("okY\n");
        if (rect.height <= max_size) return sprite;
        printf("okYd\n");
        float ratio = max_size/rect.height;
        sprite.setScale(sf::Vector2f(ratio, ratio)); //On garde le ratio du rectangle
    }
    return sprite;
}


int main()
{

    int height_screen = 1080;
    int width_screen = 1920;
    sf::RenderWindow window(sf::VideoMode(width_screen, height_screen), "Louis t'est con");
    
    sf::Texture background;
    if (!background.loadFromFile("/home/ensta/IN104/repository/Images/background.png"))
    {
        printf("Texture error\n");
    }

    sf::Texture checkeredFlag;
    if (!checkeredFlag.loadFromFile("/home/ensta/IN104/repository/Images/checkeredFlag.png"))
    {
        printf("Texture error\n");
    }

    sf::Texture BSGCylon;
    if (!BSGCylon.loadFromFile("/home/ensta/IN104/repository/Images/BSGCylon.png"))
    {
        printf("Texture error\n");
    }

    sf::Texture BSGViper;
    if (!BSGViper.loadFromFile("/home/ensta/IN104/repository/Images/BSGViper.png"))
    {
        printf("Texture error\n");
    }

    sf::Texture NMSFighterG;
    if (!NMSFighterG.loadFromFile("/home/ensta/IN104/repository/Images/NMSFighterG.png"))
    {
        printf("Texture error\n");
    }

    sf::Texture NMSFighterY;
    if (!NMSFighterY.loadFromFile("/home/ensta/IN104/repository/Images/NMSFighterY.png"))
    {
        printf("Texture error\n");
    }

    sf::Texture SWAnakinsPod;
    if (!SWAnakinsPod.loadFromFile("/home/ensta/IN104/repository/Images/SWAnakinsPod.png"))
    {
        printf("Texture error\n");
    }

    sf::Texture SWMilleniumFalcon;
    if (!SWMilleniumFalcon.loadFromFile("/home/ensta/IN104/repository/Images/SWMilleniumFalcon.png"))
    {
        printf("Texture error\n");
    }

    sf::Sprite bg;
    bg.setTexture(background);
    
    sf::Sprite flag;
    flag.setTexture(checkeredFlag);
    flag.setScale(sf::Vector2f(0.21,0.21));
    flag.setPosition(sf::Vector2f(150.f,150.f));

    sf::Sprite spaceship1;
    spaceship1.setTexture(BSGCylon);
    
    sf::Sprite spaceship2;
    spaceship2.setTexture(BSGViper);
    
    sf::Sprite spaceship3;
    spaceship3.setTexture(NMSFighterG);
    
    sf::Sprite spaceship4;
    spaceship4.setTexture(NMSFighterY);
    
    sf::Sprite spaceship5;
    spaceship5.setTexture(SWAnakinsPod);
    
    sf::Sprite spaceship6;
    spaceship6.setTexture(SWMilleniumFalcon);
    spaceship6 = scaleToMaxSize(spaceship6);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        window.clear();
        //
        window.draw(bg);
        window.draw(flag);
        window.draw(spaceship1);
        window.draw(spaceship2);
        window.draw(spaceship3);
        window.draw(spaceship4);
        window.draw(spaceship5);
        window.draw(spaceship6);
        //
        window.display();       

    }

    return 0;
}
