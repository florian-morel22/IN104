#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "menu.hpp"
#include "utils.hpp"
#include "game.hpp"


Menu::Menu()
{
    //Initialise le background
    if (!backgroundTexture_.loadFromFile(IMAGES_PATH + "/Menu_bg.png"))
    {
        printf("error");
    } 
    backgroundSprite_.setTexture(backgroundTexture_);
    setOriginToCenter(backgroundSprite_);
    scaleToMinSize(backgroundSprite_,HEIGHT_VIEW,WIDTH_VIEW);
    backgroundSprite_.setPosition(WIDTH_VIEW/2,HEIGHT_VIEW/2);

    nbCP_ = 2;
    manualPlayer_ = 0;

    //Initialise le texte qui sert pour afficher le nombre de checkpoints
    if (!nbCPFont_.loadFromFile(FONT_PATH + "/Trispace.ttf"))
        printf("error");
    nbCPText_.setFont(nbCPFont_);
    nbCPText_.setFillColor(sf::Color::White);
    nbCPText_.setCharacterSize(300);

    //Initialise l'image du rectangle qui sert a encadrer le yes/no
    if (!caseYesNoTexture_.loadFromFile(IMAGES_PATH + "/case_yesno.png"))
        printf("error");
    caseYesNoSprite_.setTexture(caseYesNoTexture_);
    setOriginToCenter(caseYesNoSprite_);
    scaleToMaxSize(caseYesNoSprite_,1000.f, 1000.f);   

}

void Menu::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(backgroundSprite_, states);
    target.draw(nbCPText_);
    target.draw(caseYesNoSprite_, states);
}

void Menu::param_nbCP()  //Change l'affichage du nombre de checkpoints
{
    if (nbCP_ == 9)
        nbCPText_.setString("random");
    else 
        nbCPText_.setString(std::to_string(nbCP_));
    
    setTextCenterPosition(nbCPText_,sf::Vector2f(3000.f, 4550.f));
}

void Menu::param_caseYesNo() //Change la position de la case qui entoure le yes/no
{
    if (manualPlayer_ == 0)
        caseYesNoSprite_.setPosition(3760.f, 6360.f);
    else
        caseYesNoSprite_.setPosition(2360.f, 6360.f);
  
}