#include <iostream>
#include <cctype>

int main(int argc, char **argv)
{
    int i = 1;
    int j = 0;
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    }
    else 
    {
        while (argv[i])
        {
            while (argv[i][j])
            {
                std::cout << (char)std::toupper(static_cast<unsigned char>(argv[i][j]));
                j++;
            }
            j = 0;
            i++;
        }
        std::cout << std::endl;
    }
    return(0);
}

//mirar el comentario del makefile