#include <iostream>

using namespace std;

class Enemy {
    // member variables: name and health
    // parametrized constructor
    // member functions: takeDamage and getName
};

class Character {
public:
    void mageAttack(Enemy enemy) {
        // code for mage attacking enemy
    }
    void rogueAttack(Enemy enemy) {
        // code for rogue attacking enemy
    }
    void warriorAttack(Enemy enemy) {
        // code for warrior attacking enemy
    }
};

class AttackStrategy {
public:
    virtual void attack(Enemy &enemy) = 0;
};

class MageAttack : AttackStrategy {
public:
    int damageOnAttack = 10;
};

class RogueAttack : AttackStrategy {
public:
    int damageOnAttack = 15;
};

class WarriorAttack : AttackStrategy {
public:
    int damageOnAttack = 25;
};

int main() {
    // Create characters with different attack strategies
    Character warrior(new WarriorAttack());
    Character mage(new MageAttack());
    Character rogue(new RogueAttack());

    // Create enemies with initial health
    Enemy enemy1("Skull Crusher", 100);
    Enemy enemy2("Bone Breaker", 25);

    // Attack enemies with different characters
    warrior.attack(enemy1);
    mage.attack(enemy2);
    rogue.attack(enemy1);

    return 0;
}

// EXAMPLE OUTPUT:
// Warrior attack!
// Skull Crusher STRENGTH LEVEL IS: 75
// Mage attack!
// Bone Breaker STRENGTH LEVEL IS: 15
// Rogue attack!
// Skull Crusher STRENGTH LEVEL IS: 60
