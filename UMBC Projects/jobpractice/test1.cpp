#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{

    ifstream filein("input.txt");
    ofstream fileout("output.txt");

    string toreplace = "0";
    string replacewith = "1";

    string text, new_text="";
    while (getline(filein, text))
    {
        new_text = "";
        double num;

        while (sscanf(text.c_str(), "%lf;", &num))
        {
            if (num)
                new_text += "1;";
            else
                new_text += "0;";

            while (text.length() && text.at(0) != ';')
            {
                text.erase(0,1);
            }

            text.erase(0,1);

            if (text.empty())
                break;
        }

        fileout << new_text << endl;
    }

    return 0;
}
