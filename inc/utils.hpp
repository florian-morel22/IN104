#ifndef UTILS_HPP
#define UTILS_HPP

#include <SFML/Graphics.hpp>

void setOriginToCenter(sf::Sprite &myObject);

void setOriginToCenterShape(sf::Shape &myObject);

void scaleToMaxSize(sf::Sprite &Sprite, float maxwidth, float maxHeight);

void scaleToMinSize(sf::Sprite &Sprite, float maxwidth, float maxHeight);

void setTextCenterPosition(sf::Text &txt, sf::Vector2f center); //place le centre du texte txt a la position center

void scaleByRadius(sf::Sprite &sp, int radius); //Dimensionne un cercle au rayon radius

float norm(sf::Vector2f u); //Renvoie la norme de u

float arg(sf::Vector2f u); //Renvoie l'argument de u

std::vector<sf::Vector2f> coord_CP(int nbCP); //Renvoie nbCP positions de checkpoints tels qu'ils ne se superposent pas

sf::Vector2f verifAngle(sf::Vector2f target, sf::Vector2f pos, float angle, float thetaMax); //Renvoie une target qui permet au pod de ne pas tourner de plus de thetaMax

float power(sf::Vector2f target , sf::Vector2f pos, float angle, float powMax ); //Dimensionne la puissance du pod intelligent

#endif