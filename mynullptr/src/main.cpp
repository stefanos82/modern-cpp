#include <iostream>
#include <boost/core/demangle.hpp>

const class mynullptr_t
{
public:
    /* return 0 for any class pointer */
    template<typename T>
    operator T*() const
    {
        return 0;
    }

    /* Return 0 for any member pointer */
    template<typename T, typename U>
    operator T U::*() const
    {
        return 0;
    }

    /* Safe boolean conversion */
    operator void*() const
    {
        return 0;
    }

private:
    /* Not allowed to get the address */
    void operator&() const;
} mynullptr = {};

int main()
{
    std::cout << "type of mynullptr: " 
        << boost::core::scoped_demangled_name(typeid(mynullptr).name()).get()
        << '\n';

    return 0;
}
