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

string dectoroman(const string &arg)
{
    auto decimal = stoi(arg);
    stringstream roman;
    while (decimal >= 1000)
    {
        roman << 'M';
        decimal -= 1000;
    }
    if (decimal >= 900)
    {
        roman << "CM";
        decimal -= 900;
    }
    if (decimal >= 500)
    {
        roman << 'D';
        decimal -= 500;
        while (decimal >= 100)
        {
            roman << 'C';
            decimal -= 100;
        }
    }
    else if (decimal >= 400)
    {
        roman << "CD";
        decimal -= 400;
    }
    else
    {
        while (decimal >= 100)
        {
            roman << 'C';
            decimal -= 100;
        }
    }
    if (decimal >= 90)
    {
        roman << "XC";
        decimal -= 90;
    }
    if (decimal >= 50)
    {
        roman << 'L';
        decimal -= 50;
        while (decimal >= 10)
        {
            roman << 'X';
            decimal -= 10;
        }
    }
    else if (decimal >= 40)
    {
        roman << "XL";
        decimal -= 40;
    }
    else
    {
        while (decimal >= 10)
        {
            roman << 'X';
            decimal -= 10;
        }
    }
    if (decimal >= 9)
    {
        roman << "IX";
    }
    else if (decimal >= 5)
    {
        roman << 'V';
        decimal -= 5;
        for (int i = 0; i < decimal; ++i)
        {
            roman << 'I';
        }
    }
    else if (decimal >= 4)
    {
        roman << "IV";
    }
    else
    {
        for (int i = 0; i < decimal; ++i)
        {
            roman << 'I';
        }
    }
    return roman.str();
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
        cout << dectoroman(input) << endl;
    }
    return 0;
}