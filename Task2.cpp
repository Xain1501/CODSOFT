#include <iostream>

using namespace std;

inline double Add(double num1, double num2)
{
    //Addition
    double Result = num1 + num2;
    return Result;
}

inline double Sub(double num1, double num2)
{
    //Subtraction
    double Result = num1 - num2;
    return Result;
}

inline double Mul(double num1, double num2)
{
    //Multiplation
    double Result = num1 * num2;
    return Result;
}

inline double Div(double num1, double num2)
{   
    //Division
    if (num2 != 0)
    {
        double Result = num1 / num2;

        return Result;
    }
    else
    {
        //division by zero error chk
        cout << "Error: Division by zero is not allowed." << endl;
        return 0;
    }
}

int validateOP(int op)
{
    //chcking for correct operator
    while (op < 1 || op > 4)
    {
        cout << "Wrong operator number entered. Re-Enter: " << endl
             << "1: to Add both the numbers (+)" << endl
             << "2: to Subtract both the numbers (-)" << endl
             << "3: to Multiply both the numbers" << endl
             << "4: to divide both the numbers" << endl;
        cin >> op;
    }
    return op;
}
int main()
{
    cout << "---------------------------------------------------" << endl
         << "--------Welcome To Zain's Simple Calculator--------" << endl
         << "----------------------------------------------------" << endl;

    double num1;
    double num2;
    int op;
    int flag=1;
 while(flag==1)
 {
    cout << "Enter First number" << endl;
    cin >> num1;
    cout << "Enter Second number" << endl;
    cin >> num2;
    //operator choosing
    cout << "Enter" << endl
         << "1: To Add both the numbers (+)" << endl
         << "2: To Subtract both the numbers (-)" << endl
         << "3: To Multiply both the numbers (*)" << endl
         << "4: To divide both the numbers (/)" << endl
         <<"Your Choice: ";
    cin >> op;
    op = validateOP(op); //validating correct operotion

   
    switch (op)
    {
    case 1:
        cout << "Result: " << Add(num1, num2)<<endl;
        break;
    case 2:
        cout << "Result: "<< Sub(num1, num2)<<endl;
        break;
    case 3:
        cout << "Result: "<< Mul(num1, num2)<<endl;
        break;
    case 4:
        cout << "Result: "<< Div(num1, num2)<<endl;
        break;

    default:
        cout << "Wrong Input entered" << endl;
        break;
    }

// checking if user wants to perform more operations or not
    cout<<"Do you want to perform more arithmetic operation?"<<endl
        <<"Enter"<<endl
        <<"0: NO"<<endl
        <<"1:Yes"<<endl;
    cin>>flag;
 }
    cout << "---------------------------------------------------" << endl
         << "--------------------THANK YOU!!!--------------------" << endl
         << "----------------------------------------------------" << endl;

    return 0;
}