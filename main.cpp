#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::stringstream;
using std::stoi;
using std::reverse;

enum BASE
{
    BINARY,
    OCTAL,
    DECIMAL,
    HEXADECIMAL,
    ROMAN
};

string dectobin(const string &arg)
{
    auto decimal = stoi(arg);
    stringstream binary;
    while (decimal > 1)
    {
        int rem = decimal % 2;
        decimal /= 2;
        binary << rem;
    }
    binary << decimal;
    string result = binary.str();
    reverse(result.begin(), result.end());
    return result;
}

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
    string input = "-1";
    while (input != "")
    {
        cout << "Enter string: ";
        cin >> input;
        cout << dectobin(input) << endl;
    }
    return 0;
}