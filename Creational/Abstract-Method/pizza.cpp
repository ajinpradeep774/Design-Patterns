#include <iostream>

class AbstractPizza
{
    public:
    virtual void makePizza() =0;
    virtual ~AbstractPizza(){};
};

class AmericanPizza : public AbstractPizza
{
    public:
    void makePizza() override
    {
        std::cout<<"making AmericanPizza"<<std::endl;
    }
    ~AmericanPizza(){};
};

class ItalianPizza : public AbstractPizza
{
    public:
    void makePizza() override
    {
        std::cout<<"making ItalianPizza"<<std::endl;
    }
    ~ItalianPizza(){};
};

class AbstractBurger
{
    public:
    virtual void makeBurger() =0;
    virtual ~AbstractBurger(){};
};

class AmericanBurger : public AbstractBurger
{
    public:
    void makeBurger() override
    {
        std::cout<<"making AmericanBurger"<<std::endl;
    }
    ~AmericanBurger(){}
};

class ItalianBurger : public AbstractBurger
{
    public:
    void makeBurger() override
    {
        std::cout<<"making ItalianBurger"<<std::endl;
    }
    ~ItalianBurger(){}
};

class Factory
{
public:
    virtual AbstractBurger* createBurger() =0;
    virtual AbstractPizza* createPizza() =0;
};

class AmericanFactory : public Factory
{
public:
    AbstractBurger* createBurger()
    {
        return new AmericanBurger();
    }
    AbstractPizza* createPizza()
    {
        return new AmericanPizza();
    }

};

class ItalianFactory : public Factory
{
public:
    AbstractBurger* createBurger()
    {
        return new ItalianBurger();
    }
    AbstractPizza* createPizza()
    {
        return new ItalianPizza();
    }
};

int main()
{
    Factory *fac = new AmericanFactory();
    AbstractPizza *piz = fac->createPizza();
    AbstractBurger *bur = fac->createBurger();
    piz->makePizza();
}
