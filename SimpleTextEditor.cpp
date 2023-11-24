#include <iostream>
#include <stack>
#include <string>
using namespace std;

class CustomStack
{
    string text;
    stack<string> history;

public:
    void insert(string value)
    {
        history.push(text);
        text += value;
    }

    void deleteChars(int value)
    {
        history.push(text);
        text = text.substr(0, text.size() - value);
    }

    char get(int value)
    {
        return text[value - 1];
    }

    void undo()
    {
        if (!history.empty())
        {
            text = history.top();
            history.pop();
        }
    }
};

int main()
{
    CustomStack customStack;
    string command;
    while (getline(cin, command))
    {
        int op = command[0] - '0';
        if (op == 1)
        {
            string value = command.substr(2);
            customStack.insert(value);
        }
        else if (op == 2)
        {
            int value = stoi(command.substr(2));
            customStack.deleteChars(value);
        }
        else if (op == 3)
        {
            int value = stoi(command.substr(2));
            cout << customStack.get(value) << endl;
        }
        else if (op == 4)
        {
            customStack.undo();
        }
    }

    return 0;
}