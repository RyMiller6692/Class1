#include <iostream>

class Animal {
public:
    virtual void makeSound() const = 0; 
    virtual ~Animal() {}              
};

class Dog : public Animal {
public:
    void makeSound() const override {
        std::cout << "Woof!" << std::endl;
    }
};

class Cat : public Animal {
public:
    void makeSound() const override {
        std::cout << "Meow!" << std::endl;
    }
};


void playSound(Animal* a) {
    if (a) {
        a->makeSound();
    }
}

int main() {
    Dog myDog;
    Cat myCat;

    playSound(&myDog);  
    playSound(&myCat);  

    return 0;
}
