#include "Dragon.h"

Dragon::Dragon(std::string name, int damage, int defense, int hp, int level) 
    : name(name), damage(damage), defense(defense), hp(hp), level(level), currentState(nullptr) {};

Dragon::~Dragon()
{
    if (currentState == nullptr)
        delete currentState;
}

std::string Dragon::getName()
{ 
    return name; 
}

int Dragon::getDamage()
{ 
    return damage;
}

int Dragon::getDefense()  
{ 
    return defense; 
}

int Dragon::getHP()  
{ 
    return hp;
}

int Dragon::getLevel()  
{ 
    return level; 
}

void Dragon::setState(DragonState* state) 
{ 
    if (currentState != nullptr) 
        delete currentState;
    currentState = state; 
}

double Dragon::calculateCombatPower() 
{
    if (currentState) 
        return currentState->calculateCombatPower(this);
    
    return -1;
}

void Dragon::attack() 
{
    if (currentState) 
        currentState->attack(this);
}

void Dragon::move() 
{
    if (currentState) 
        currentState->move(this);
}

double NormalState::calculateCombatPower(Dragon* dragon)
{
    double power = (dragon->getDamage() + dragon->getDefense() + dragon->getHP()) * dragon->getLevel();
    std::cout << "Combat power in normal state: " << power << std::endl;
    return power;
}

void NormalState::attack(Dragon* dragon)
{
    std::cout << "Dragon " << dragon->getName() << " breathes yellow fire" << std::endl;
}

void NormalState::move(Dragon* dragon)
{
    std::cout << "Dragon " << dragon->getName() << " moves at normal speed" << std::endl;
}

double RageState::calculateCombatPower(Dragon* dragon)
{
    double power = (2 * dragon->getDamage() + dragon->getDefense() + dragon->getHP()) * dragon->getLevel();
    std::cout << "Combat power in rage state: " << power << std::endl;
    return power;
}

void RageState::attack(Dragon* dragon)
{
    std::cout << "Dragon " << dragon->getName() << " breathes red fire" << std::endl;
}

void RageState::move(Dragon* dragon)
{
    std::cout << "Dragon " << dragon->getName() << " moves quickly" << std::endl;
}

double DefensiveState::calculateCombatPower(Dragon* dragon)
{
    double power = (dragon->getDamage() + dragon->getDefense() * 1.5 + dragon->getHP() * 1.5) * dragon->getLevel();
    std::cout << "Combat power in defensive state: " << power << std::endl;
    return power;
}

void DefensiveState::attack(Dragon* dragon)
{
    std::cout << "Dragon " << dragon->getName() << " breathes green fire" << std::endl;
}

void DefensiveState::move(Dragon* dragon)
{
    std::cout << "Dragon " << dragon->getName() << " moves slowly" << std::endl;
}