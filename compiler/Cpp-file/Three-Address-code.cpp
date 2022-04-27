
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

char input[20];
char op, op1, op2;

char temp[5] = {'v', 'w', 'x', 'y', 'z'};
int temp_pointer = 0;

void scan()
{
    for (int i = 0; i < strlen(input); i++)
    {
        if ((input[i] == '+') || (input[i] == '-') || (input[i] == '*') || (input[i] == '/'))
        {
            op = input[i];
            op1 = input[i - 1];
            op2 = input[i + 1];

            cout << "\n" << temp[temp_pointer] << "=" << op1 << op << op2 << "\n";
            input[i + 1] = temp[temp_pointer++];
        }
    }
}

int main()
{
    cout << "\nEnter expression:";
    cin >> input;
    input[strlen(input) - 1] = '\0';
    scan();

    return 0;
}

// x=a+b/c*d