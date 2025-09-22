#include <iostream>
#include <thread>
#include <mutex>

class Singleton
{
    private:
        Singleton(){};
        Singleton(Singleton&) = delete;
        Singleton& operator=(Singleton&) = delete;
        Singleton(Singleton&&) = delete;
        Singleton& operator=(Singleton&&) = delete;

    public:
    static Singleton& getInstane()
    {
        static Singleton instance;
        return instance;
    }
};


int main()
{
    Singleton& ins = Singleton::getInstane();
}
