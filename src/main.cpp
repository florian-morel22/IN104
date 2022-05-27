#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <math.h>
#include "utils.hpp"
#include "CheckPoint.hpp"
#include "game.hpp"
#include "menu.hpp"



int main()
{
    //Initialisation de la fenetre et de la grille
    int width_screen = 1600;
    int height_screen = 900;
    sf::RenderWindow window(sf::VideoMode(width_screen, height_screen), "Space Race 2000");
    sf::View myview(sf::FloatRect(0,0,16000,9000));
    window.setView(myview);

    int gameMode = 0; // 2 parties dans le main : 0-MENU, 1-GAME
    int nbCP = 0;
    int manualPlayer = 0;

    sf::Event event;

    while (window.isOpen())
    {   
        if (gameMode == 0){ // Initialisation du menu
            Menu open_menu = Menu();
            
            while (gameMode == 0){

                while (window.pollEvent(event))
                {
                    if (event.type == sf::Event::Closed)
                    {
                        gameMode = -1;
                        window.close();
                    } 

                    if (event.type == sf::Event::MouseButtonPressed) 
                    {
                        if (event.mouseButton.button == sf::Mouse::Left)
                        {
                            sf::Vector2u windowSize = window.getSize();

                            int x = event.mouseButton.x*WIDTH_VIEW/windowSize.x;
                            int y = event.mouseButton.y*HEIGHT_VIEW/windowSize.y;
                            
                            //Start Button
                            if (1180<x && x<4840 && 7180<y && y<8020)
                            {
                                //Sauvegarde des parametres pour les transferer dans la partie GAME
                                manualPlayer = open_menu.manualPlayer_;
                                nbCP = open_menu.nbCP_; 

                                gameMode = 1; // On passe a la partie GAME
                            }    
                            
                            // +/- Buttons 
                            else if (1780<x && x<2060 && 4460<y && y<4680)
                            {
                                if (open_menu.nbCP_> 2)
                                    open_menu.nbCP_ -=1;
                            }
                            else if (3960<x && x<4200 && 4460<y && y<4680)
                            {
                                if (open_menu.nbCP_< 9)
                                    open_menu.nbCP_ +=1;
                            }
                            
                            // yes/no Buttons
                            else if (1960<x && x<2720 && 6200<y && y<6520)
                                open_menu.manualPlayer_ = 1;
                            else if (3460<x && x<4060 && 6200<y && y<6520)
                                open_menu.manualPlayer_ = 0;
                                       
                        }
                    }   
                }

                open_menu.param_caseYesNo();
                open_menu.param_nbCP();

                window.clear();
                window.draw(open_menu);
                window.display();

            }
        }

        if (gameMode == 1){

            //Initialisation du jeu et des variables
            float fps = 60;
            sf::Time refreshTime = sf::microseconds(1e6/fps);
            sf::Clock globalClock;
            sf::Clock refreshClock;
            sf::Time physicsTime = sf::Time::Zero;

            // Creation des positions aleatoires des Checkpoints
            std::vector<sf::Vector2f> Coord_CP = coord_CP(nbCP);
            
            Game gameSnapshot = Game(Coord_CP);
            gameSnapshot.addPod(manualPlayer);
            gameSnapshot.initDecompte();
                              
            while (gameMode == 1){
                
                while (window.pollEvent(event))
                {
                    if (event.type == sf::Event::Closed)
                    {
                        gameMode = -1;
                        window.close();
                    }
                    if (event.type == sf::Event::KeyPressed)
                    {
                        if (event.key.code == sf::Keyboard::Escape)    
                            gameMode = 0; //Retour au menu

                    }
                }
                
                //si on a depasse le refreshTime depuis la derniere frame
                if (refreshClock.getElapsedTime() >= refreshTime)
                {
                    
                    refreshClock.restart();
                    sf::Time frameTime = globalClock.getElapsedTime();
                    gameSnapshot.decompteTime_ = frameTime;


                    if (frameTime > physicsTime && frameTime.asMilliseconds() > 3000) // ">3000" car on commence le jeu seulement si le decompte de 3s est termine
                    { 
                        gameSnapshot.updateGraphics(physicsTime); //Muse a jour des graphiques du jeu
                        gameSnapshot.updatePhysics(&window);      //Mise a jour de la physique du jeu                   
                        physicsTime += PHYSICS_TIME_STEP;
                        frameTime = globalClock.getElapsedTime();
                    }
                    else 
                        gameSnapshot.updateGraphics(frameTime);
                    
                    window.clear();    
                    window.draw(gameSnapshot);
                    window.display();
                    
                }
            }
        }
    }

    return 0;
}