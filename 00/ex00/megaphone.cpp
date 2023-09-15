#include <cstdlib>
#include <iostream>

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (EXIT_FAILURE);
    }
    for (int i = 1; i < argc; i++)
        std::cout << argv[i];
    std::cout << std::endl;
    return (EXIT_SUCCESS);
}
