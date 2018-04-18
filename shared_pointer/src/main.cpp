#include <iostream>
#include <memory>
#include <boost/core/demangle.hpp>
 
std::shared_ptr<double> f()
{
    std::shared_ptr<double> p1 = std::make_shared<double>();
    std::shared_ptr<double> p2{new double}, p3 = p2;
    
    std::cout << "p3.use_count() = " << p3.use_count() << '\n';
    
    return p3;
}

int main()
{
    auto p = f();
    std::cout << "p's type is: "
        << boost::core::scoped_demangled_name(typeid(p).name()).get()
        << '\n';
    std::cout << "p.use_count() = " << p.use_count() << '\n';
}
