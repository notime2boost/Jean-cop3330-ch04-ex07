
 //*  UCF COP3330 Fall 2021 Assignment 5 Solution
 //*  Copyright 2021 Christopher Jean

#include "C:\Users\cjean\Desktop\Cop3330\Cop3330 C++\std_lib_facilities.h"

vector<string> s_digits;

void init_vector()
{
    s_digits.push_back("zero");
    s_digits.push_back("one");
    s_digits.push_back("two");
    s_digits.push_back("three");
    s_digits.push_back("four");
    s_digits.push_back("five");
    s_digits.push_back("six");
    s_digits.push_back("seven");
    s_digits.push_back("eight");
    s_digits.push_back("nine");
}


int get_number()
{
    int inp = 0;
    if (cin>>inp)
        return inp;
    cin.clear();
    string inp_s;
    cin >> inp_s;
    for (int i = 0; i<s_digits.size(); ++i) {
        if (s_digits[i]==inp_s)
            return i;
    }
    return(-1);
}

int main()
{
    init_vector();
    cout << "Enter two values (number or single digit spelled out) separated by\n"
        << "a character (+, -, * or /). Enter 'q' as operator to exit.\n";
    while (true) {
        int val1 = 0;
        int val2 = 0;
        char op = 0;
        val1 = get_number();
        cin >> op;
        val2 = get_number();
        if (val1==-1 || val2==-1)
            cout << "Numbers must be int or, when spelled out, single digit\n";
        else {
            switch (op) {
            case '+':
                cout << "The sum of " << val1 << " and " << val2 << " is " << val1+val2 << ".\n";
                break;
            case '-':
                cout << "The difference of " << val1 << " and " << val2 << " is " << val1-val2 << ".\n";
                break;
            case '*':
                cout << "The product of " << val1 << " and " << val2 << " is " << val1*val2 << ".\n";
                break;
            case '/':
                if (val2==0)
                    cout << "No division by zero!\n";
                else
                    cout << "The ratio of " << val1 << " and " << val2 << " is " << double(val1)/val2 << ".\n";
                break;
            case 'q':
                return 0;
            default:
                cout << "This is not a valid operation (use +, -, * or /)\n";
                break;
            }
        }
    }
}