#include "Text.h"
#include <iostream>

using namespace std;
using namespace Text;

Text(string text, /*Condition condition*/)
{
    text = this->text;
}

string run()
{
    int index = 0, index2 = 0;
    string string1 = text, string2 = "";
    char c;

        switch (text[0]) {
    case '~':
        if (text[1] == '+')
        {
            //takes text after +, and adds it to inventory
            index = string1.find("~");
            index2 = string1.find(" ", index+1);
            string2 = string1.substr(index1+1, index2-(index1+1));
            return string2;
        }
        else
        {
            //"-item"
            index = string1.find("~");
            index2 = string1.find(" ", index+1);
            string2 = string1.substr(index1+1, index2-(index1+1));
            return string2;
        }
        break;
    case "?":
        index = string1.find("#");
        c = string1[index+1];
        index2 = string1.find("^", index+2);
        string2 = string1.substr(index1+2, index2-(index1+2));
        cout << "(" << c << ")" << string2 << endl;
        break;
    default:
        return text;
        }
}

void menu(string text)
{
    int index = 0, index2 = 0;
    string string1 = text, string2 = "";
    char c;
    index = string1.find("#");
    c = string1[index+1];
    index2 = string1.find("^", index+2);
    string2 = string1.substr(index1+2, index2-(index1+2));
    cout << "(" << c << ")" << string2 << endl;
    string command(string1, index2);
}

string command(string text, int index)
{

}
//Menu function implementation-----------------
