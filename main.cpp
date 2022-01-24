#include <iostream>

using std::cout;
using std::endl;

enum BASE
{
    BINARY,
    OCTAL,
    DECIMAL,
    HEXADECIMAL,
    ROMAN
};

enum ROMAN
{
    I = 1,
    V = 5,
    X = 10,
    L = 50,
    C = 100,
    D = 500,
    M = 1000
};

int main(int argc, char **argv)
{
    for (int i = 1; i < argc; ++i)
    {
        cout << argv[i] << endl;
    }
    return 0;
}