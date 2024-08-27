    #include <iostream>
    #include <string>
    #include <algorithm>

    using namespace std;
    int top = -1, stack[50];
    char arr[50];
    int j = 0;
    char c;
    int priority(char ch)
    {
        if (ch == '*' || ch == '/')
            return 3;
        else if (ch == '+' || ch == '-')
            return 2;
        else
            return 0;
    }
    int push(char val)
    {
        if (top == 49)
            cout << "Stack overflow";
        else
        {
            top++; // 0 0 
            stack[top] = val;
        }
    }
    int pop()
    {
        if (top == -1)
            cout << "Stack underflow";
        else
        {
            c = (char)stack[top];
            if (stack[top] != '(' && stack[top] != ')')
            {
                arr[j] = (char)stack[top];
                j++;
            }
            top--;
        }
    }
    char infix_to_postfix(string str)
    { // a*b*c/(a+b+c)*d/(f+k**g)/e
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == '*' || str[i] == '/' || str[i] == '+' || str[i] == '-' || str[i] == '(' || str[i] == ')')
            {
                if (str[i] == '*' || str[i] == '/' || str[i] == '+' || str[i] == '-')
                {
                    if (stack[top] == -1)
                        push(str[i]);
                    else if (priority(str[i]) > priority(stack[top]))
                    { // 2 > 3 = false
                        push(str[i]);
                    }
                    else
                    {
                        do
                        {
                            pop();
                        } while (stack[top] != '(' && priority(str[i]) <= priority(stack[top]) && stack[top] != -1);
                        push(str[i]);
                    }
                }
                else if (str[i] == '(')
                    push(str[i]);
                else
                {
                    do
                    {
                        pop();
                    } while (stack[top] != '(');
                    pop();
                }
            }
            else
            {
                arr[j] = str[i];
                j++;
            }
        }
        while (top > -1)
        {
            pop();
        }
    }
    int infix_to_prefix(string str)
    {
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == '*' || str[i] == '/' || str[i] == '+' || str[i] == '-' || str[i] == '(' || str[i] == ')')
            {
                if (str[i] == '*' || str[i] == '/' || str[i] == '+' || str[i] == '-')
                {
                    if (stack[top] == -1)
                        push(str[i]);
                    else if (priority(str[i]) > priority(stack[top]))
                    { // 2 > 3 = false
                        push(str[i]);
                    }
                    else
                    {
                        do
                        {
                            pop();
                        } while (stack[top] != ')' && priority(str[i]) <= priority(stack[top]) && stack[top] != -1);
                        push(str[i]);
                    }
                }
                else if (str[i] == ')')
                    push(str[i]);
                else
                {
                    do
                    {
                        pop();
                    } while (stack[top] != ')');
                    pop();
                }
            }
            else
            {
                arr[j] = str[i];
                j++;
            }
        }
        while (top > -1)
        {
            pop();
        }
    }
    int evaluate(char temp)
    {
        int array[50], k = 0;
        switch (temp)
        {
        case '+':
            array[k--] = array[k] + array[k--];
            k--;
        default:
            array[k] = temp;
            k++;
        }
    }
    int reverseArr(char arr[])
    {

        int count = 0;
        for (int i = 0; arr[i] != 0; i++)
            count++;
        for (int i = 0; count > 0; i++)
            cout << arr[--count];
    }

    int getInt(char c) {
        switch(c) {
            case '0': return 0;
            case '1': return 1;
            case '2': return 2;
            case '3': return 3;
            case '4': return 4;
            case '5': return 5;
            case '6': return 6;
            case '7': return 7;
            case '8': return 8;
            case '9': return 9;
        }
    }

    int result(char temp[])//56*423**-
    {
        int i, a, b;
        for (i = 0; temp[i] > 0; i++)// -
        {
            if (temp[i] >= '0' && temp[i] <= '9')
                push(temp[i]); // stack [6]
            else
            {
                pop();
                a = getInt(c) ;
                pop();
                b = getInt(c); 
                switch (temp[i])
                {
                case '+':
                    push(a + b);
                    break;
                case '-':
                    if (a > b)
                        push(a - b);
                    else 
                        push(b - a);

                    break;
                case '*':
                    push(a * b);
                    break;
                case '/':
                    if (a > b)
                        push(a / b);
                    else 
                        push (b / a);
                    break;
                }
            }
        }
        cout << "\nResult is : ";
        cout << stack[top];
    }
    int main()
    {
        string infix;
        int choice;
        char temp[50];

        cout << "\n--------------------------------------------" << endl;
        cout << "\nEnter the opreation you want to perform  : \n 1.Infix -> Postfix \n 2.Infix -> Prefix \n " << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the infix expression : ";
            cin >> infix; // 2 + 3
            infix_to_postfix(infix);
            for (int i = 0; arr[i] != 0; i++)
            {
                temp[i] = (char)arr[i];
                cout << (char)arr[i];
            }
            result(temp); // 56*423**-
            break;
        case 2:
            cout << "Enter the infix expression : ";
            cin >> infix;
            reverse(infix.begin(), infix.end());
            infix_to_prefix(infix);
            reverseArr(arr);
            break;
        default:
            cout << "Wrong choice";
            break;
        }
        cout << "\n--------------------------------------------\n";
        return 0;
    }
