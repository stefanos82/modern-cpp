#include <iostream>
#include <string>
#include <cassert>
#include <utility>

using uint32 = unsigned int;

class Demo
{
    std::string name_;
    uint32 age_;
public:
    Demo(std::string n, uint32 a) : name_{n}, age_{a} {}
    Demo(std::string n) : name_{n} {}
    Demo() : name_{""}, age_{0} {}

    std::string name() { return name_; }
    void name(std::string&& n) { name_ = std::move(n); }

    uint32 age() { return age_; }
    void age(uint32&& a) { age_ = a; }
};

int main()
{
    Demo c;
    std::cout << "Original values" << '\n';
    std::cout << "Name" << c.name() << '\t' << "Age: " << c.age() << '\n';
    c.name("John Doe");
    c.age(55);

    std::cout << "New values" << '\n';
    std::cout << "Name: " << c.name() << '\t' << "Age: " << c.age() << '\n';

    Demo d{"Jane Doe", 45};
    std::cout << "Original values" << '\n';
    std::cout << "Name: " << d.name() << '\t' << "Age: " << d.age() << '\n';
    
    d.name("John Smith");
    d.age(25);
    std::cout << "New values" << '\n';
    std::cout << "Name: " << d.name() << '\t' << "Age: " << d.age() << '\n';

    Demo e, f{"Jane Smith", 60};
    e = f;

    std::cout << "Name: " << e.name() << '\t' << "Age: " << e.age() << '\n';
}
