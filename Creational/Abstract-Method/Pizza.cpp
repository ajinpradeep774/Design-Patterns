
class Pizza
{
    public:
      virtual void bake() = 0;  
}

class AmericanCheesePizza : public Pizza
{
    public:
     void bake() override;
}

class IndianCheesePizza : public Pizza
{
    public:
     void bake() override;
}

class AmericanPepperPizza: public Pizza
{
    public:
     void bake() override;
}

class IndianPepperPizza: public Pizza
{
    public:
     void bake() override;
}

class AmericanOnionPizza: public Pizza
{
    public:
     void bake() override;
}

class IndianOnionPizza: public Pizza
{
    public:
     void bake() override;
}

class PizzaFactory
{
    public:
     virtual Pizza* makeCheesePizza() = 0;
     virtual Pizza* makePepper() = 0;
     virtual Pizza* makeOnion() = 0;
}

class AmericanFactory: public PizzaFactory
{
    public:
      Pizza* makeCheesePizza() override
      {
        return new AmericanCheesePizza;
      }
      Pizza* makePepper() override
      {
        return new AmericanPepperPizza;
      }
      Pizza* makeOnion() override
      {
        return new AmericanOnionPizza;
      }

}

class IndianFactory: public PizzaFactory
{
    public:
      Pizza* makeCheesePizza() override
      {
        return new IndianCheesePizza;
      }
      Pizza* makePepper() override
      {
        return new IndianPepperPizza;
      }
      Pizza* makeOnion() override
      {
        return new IndianOnionPizza;
      }

}

int main()
{
    PizzaFactory *indianFactory = new IndianFactory();
    Pizza *cheesePizza = indianFactory->makeCheesePizza();
    Pizza *pepperPizza = indianFactory->makePepperPizza();
    Pizza *onionPizza = indianFactory->makeOnionPizza();

    cheesePizza->bake();
    pepperPizza->bake();
    onionPizza->bake();
}

