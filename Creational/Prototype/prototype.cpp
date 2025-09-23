#include <iostream>
#include <string>

class Shape
{
    public:
    virtual ~Shape(){};
    virtual Shape* Clone() = 0;
    virtual void draw() =0;
};

class Circle : public Shape
{
private:
    int radius;
public:
    Circle(int rad):radius(rad){};
    ~Circle(){};
    Shape* Clone() override
    {
        return new Circle(*this);
    };
    void draw() override
    {
        std::cout<<"Drawing Circle with radius : "<< radius<<std::endl;
    };
};

class Rectangle : public Shape
{
private:
    int length;
    int width;
public:
    Rectangle(int l, int w):length(l), width(w){};
    ~Rectangle(){};
    Shape* Clone() override
    {
        return new Rectangle(*this);
    };
    void draw() override
    {
        std::cout<<"Drawing Rectangle with length and width : "<< length<< " "<< width <<std::endl;
    };
};

int main()
{
    Rectangle rec(5,8);
    Shape *sh = rec.Clone();
    sh->draw();

    return 0;
}
