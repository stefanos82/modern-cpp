#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

bool isPalindrome(std::string s)
{
    auto rev = [](std::string ls) {
        std::reverse(ls.begin(), ls.end());
        return std::move(ls);
    }(s);

    if (rev == s)
        return true;
    else
        return false;
}

int main()
{
    std::vector<std::string> v{
        "abba", 
        "alone",
        "caddac",
        "mom",
        "daddy",
        "BOB"
    };

    for (auto a : v)
    {
        auto answer = isPalindrome(a);

        if (answer == true)
            std::cout << R"|(")|" << a << R"|(")|" << " is a palindrome." << '\n';
        else
            std::cout << R"|(")|" << a << R"|(")|" << " is not..." << '\n';
    }
}
