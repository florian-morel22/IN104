#include "pod.hpp"
#include "game.hpp"
#include <SFML/System/Vector2.hpp>


Decision::Decision(sf::Vector2f target, float power) 
{
    target_ = target;
    power_ = power;
};


Pod::Pod(sf::Vector2f pos, float angle, sf::Vector2f vel) 
{
    pos_ = pos;
    angle_ = angle;
    vel_ = vel;
};


Decision Pod::getDecision(Game gameSnapshot, sf::RenderWindow* pwindow) const 
{
    if (!manualPod_)  //Commande auto
    {
        sf::Vector2f target;
        if (nextCP_ == 0) target = gameSnapshot.finalCP_.getPosition();    // Si le pod vise le CheckPoint final
        else target = gameSnapshot.otherCPs_[nextCP_-1.f].getPosition();
            
        //On verifie si l'angle de rotation du pod est superieure a THETA_MAX
        target = verifAngle(target,pos_,angle_,ROTA_MAX); 
        

        float pow = 100; //La puissance par defaut
        //On definit la puissance du pod en fonction de son etat et de l'etat du jeu SI le pod est "intelligent"
        if (version_ == 1)
            pow = power(target, pos_, angle_, POW_MAX);
        
        
        return Decision(target, pow);        
        
    }
    
    else //Commande manuelle
    {
        sf::Vector2i targetpx = sf::Mouse::getPosition(*pwindow);
        
        //Ajustement de la position de la souris a la grille du jeu
        sf::Vector2u windowSize = (*pwindow).getSize();   
        sf::Vector2f target = {(float) targetpx.x*WIDTH_VIEW/windowSize.x, (float) targetpx.y*HEIGHT_VIEW/windowSize.y};    

        target = verifAngle(target,pos_,angle_,ROTA_MAX); 
        return Decision(target, 100);
    }
    
}; 

