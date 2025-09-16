#include <iostream>
#include <string>

class Logger
{
    public:
    virtual void log(const std::string& msg) =0;
    virtual ~Logger(){};
};

class FileLogger : public Logger
{
    public:
    void log(const std::string& msg) override
    {
        std::cout<<"Writing to file : "<< msg<< std::endl;
    }
    ~FileLogger(){};
};

class ConsoleLogger : public Logger
{
    public:
    void log(const std::string& msg) override
    {
        std::cout<<"Writing to console : "<< msg<< std::endl;
    }
    ~ConsoleLogger(){};
};

class Factory
{
    public:
        virtual Logger* create() = 0;
        ~Factory(){};
};

class FileFactory : public Factory
{
    public:
        Logger* create() override
        {
            return new FileLogger();
        }
        ~FileFactory(){};
};

class ConsoleFactory : public Factory
{
    public:
        Logger* create() override
        {
            return new ConsoleLogger();
        }
        ~ConsoleFactory(){};
};

int main()
{
    Factory *fact = new ConsoleFactory();
    Logger *logger = fact->create();
    logger->log("Hello");

    return 0;
}
