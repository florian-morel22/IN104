#ifndef INC_GameLOGIC_H
#define INC_GameLOGIC_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include "CheckPoint.hpp"
#include "pod.hpp"


const unsigned int NUMBER_OF_LAPS = 3;
const float FRICTION_COEFF = 0.85;
const float ROTA_MAX = M_PI/3.;
const float POW_MAX = 100.;
const sf::Time PHYSICS_TIME_STEP = sf::milliseconds(100);
const std::string IMAGES_PATH = "../repository/Images/";
const std::string FONT_PATH = "../repository/";
const unsigned int WIDTH_VIEW = 16000;
const unsigned int HEIGHT_VIEW = 9000;

class Pod;

class Game : public sf::Drawable
{
    public :
    Game(std::vector<sf::Vector2f> checkpointsPositions); //create a Game with randpredefined positions

    void addPod(int manualPlayer); //can add various arguments here to chose the apparence or the decision making type of the pod
    void updatePhysics(sf::RenderWindow* pwindow); 
    void updateGraphics(sf::Time frameTime); //change pods sprites positions and rotations depending on the frame time

    void initDecompte();
    std::vector<sf::Sprite> decompteSprites_;
    std::vector<sf::Texture> decompteTextures_;
    sf::Time decompteTime_;


    // private :
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    sf::Texture backgroundTexture_;
    sf::Sprite backgroundSprite_;

    std::vector<Pod> pods_;
    std::vector<sf::Texture> podsTextures_;
    std::vector<sf::Sprite> podsSprites_;

    FinalCheckPoint finalCP_;
    std::vector<CheckPoint> otherCPs_;
    std::vector<sf::Vector2f> allCPs_;

    sf::Time lastFrameTime;
    sf::Time physicsTime; 

    std::string winner_; 
    sf::Text textwinner_; 
    sf::Font font_;
};

#endif