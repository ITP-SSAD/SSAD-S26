
#include <iostream>
#include <string>

using namespace std;

class Enemy {
private:
    string name;
    int health;

public:
    Enemy(const string& enemyName, int enemyHealth) : name(enemyName), health(enemyHealth) {}

    void takeDamage(int damage) {
        health -= damage;
        cout << name << " STRENGTH LEVEL IS: " << health << endl;
        if (health <= 0) {
            cout << name << " IS DEAD" << endl;
        }
    }

    string getName() {
            return name;
    }
};

class AttackStrategy {
public:
    virtual void attack(Enemy &enemy) = 0;
};

class WarriorAttack : public AttackStrategy {
private:
    int damageOnAttack = 25;
public:
    void attack(Enemy &enemy) override {
        cout << "Warrior attack!" << endl;
        enemy.takeDamage(damageOnAttack);
    }
};

class MageAttack : public AttackStrategy {
private:
    int damageOnAttack = 10;
public:
    void attack(Enemy &enemy) override {
        cout << "Mage attack!" << endl;
        enemy.takeDamage(damageOnAttack);
    }
};

class RogueAttack : public AttackStrategy {
private:
    int damageOnAttack = 15;
public:
    void attack(Enemy &enemy) override {
        cout << "Rogue attack!" << endl;
        enemy.takeDamage(damageOnAttack);
    }
};

class Character {
private:
    AttackStrategy* attackStrategy;

public:
    Character(AttackStrategy* strategy) : attackStrategy(strategy) {}

    void attack(Enemy &enemy) {
        attackStrategy->attack(enemy);
    }
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
