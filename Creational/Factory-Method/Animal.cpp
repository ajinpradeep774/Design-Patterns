#include <iostream>
#include <memory>

// Product Interface
class Animal {
public:
    virtual void makeSound() const = 0;  // Pure virtual function
    virtual ~Animal() = default;         // Virtual destructor
};

// Concrete Product: Dog
class Dog : public Animal {
public:
    void makeSound() const override {
        std::cout << "Woof! Woof!" << std::endl;
    }
};

// Concrete Product: Cat
class Cat : public Animal {
public:
    void makeSound() const override {
        std::cout << "Meow! Meow!" << std::endl;
    }
};

// Creator (Factory Method) Interface
class AnimalCreator {
public:
    virtual std::unique_ptr<Animal> createAnimal() const = 0;  // Factory Method
    virtual ~AnimalCreator() = default;
};

// Concrete Creator: Dog Creator
class DogCreator : public AnimalCreator {
public:
    std::unique_ptr<Animal> createAnimal() const override {
        return std::make_unique<Dog>();
    }
};

// Concrete Creator: Cat Creator
class CatCreator : public AnimalCreator {
public:
    std::unique_ptr<Animal> createAnimal() const override {
        return std::make_unique<Cat>();
    }
};

// Client code
void clientCode(const AnimalCreator &creator) {
    // The client code works with an instance of a creator,
    // but the concrete product's class is determined by the subclass.
    std::unique_ptr<Animal> animal = creator.createAnimal();
    animal->makeSound();
}

int main() {
    // Create a Dog using the DogCreator
    std::cout << "Client: I'm creating a Dog." << std::endl;
    DogCreator dogCreator;
    clientCode(dogCreator);

    // Create a Cat using the CatCreator
    std::cout << "Client: I'm creating a Cat." << std::endl;
    CatCreator catCreator;
    clientCode(catCreator);

    return 0;
}
