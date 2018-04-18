#include <iostream>
#include <memory>

std::unique_ptr<double> f()
{
    return std::unique_ptr<double>{new double};
}

int main()
{
    std::unique_ptr<double> dp{new double};
    *dp = 7.98;
    std::cout << "dp = " << dp.get() << '\t';
    std::cout << "addressof(*dp): " << std::addressof(*dp) << '\n';
    std::cout << "*dp = " << *dp << '\n';

    std::unique_ptr<double> dp2{std::move(dp)}, dp3;
    std::cout << "dp2 = " << dp2.get() << '\t';
    std::cout << "*dp2 = " << *dp2 << '\n';

    dp3 = std::move(dp2);
    std::cout << "dp3 = " << dp3.get() << '\t';
    std::cout << "*dp3 = " << *dp3 << '\n';

    std::unique_ptr<double> dp4;
    dp4 = f();
    *dp4 = 9.99;
    std::cout << "dp4 = " << dp4.get() << '\t';
    std::cout << "*dp4 = " << *dp4 << '\n';

    std::unique_ptr<double[]> da{new double[3]};
    for (unsigned i = 0; i < 3; ++i)
    {
        da[i] = i * i + 1.99;
    }

    for (unsigned i = 0; i < 3; ++i)
    {
        std::cout << "value: " << da[i] << "\taddress: " << &da[i] << '\n';
    }
}
