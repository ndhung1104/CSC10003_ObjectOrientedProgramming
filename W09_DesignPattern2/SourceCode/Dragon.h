#include <iostream>
#include <string>

class Dragon;

class DragonState {
public:
    virtual double calculateCombatPower(Dragon* dragon) = 0;
    virtual void attack(Dragon* dragon) = 0;
    virtual void move(Dragon* dragon) = 0;
};

class Dragon {
private:
    std::string name;
    int damage;
    int defense;
    int hp;
    int level;
    DragonState* currentState;
    

public:
    Dragon(std::string name, int damage, int defense, int hp, int level);
    ~Dragon();
    std::string getName();
    int getDamage();
    int getDefense();
    int getHP();
    int getLevel();
    void setState(DragonState* state);

    double calculateCombatPower();

    void attack();

    void move();
};

class NormalState : public DragonState {
public:
    double calculateCombatPower(Dragon* dragon) override;

    void attack(Dragon* dragon) override;

    void move(Dragon* dragon) override;
};

class RageState : public DragonState {
public:
    double calculateCombatPower(Dragon* dragon) override;

    void attack(Dragon* dragon) override;

    void move(Dragon* dragon) override;
};

class DefensiveState : public DragonState {
public:
    double calculateCombatPower(Dragon* dragon) override;

    void attack(Dragon* dragon) override;

    void move(Dragon* dragon) override;
};