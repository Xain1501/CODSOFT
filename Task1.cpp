#include <iostream>
#include <cstdlib>//included to use built in rand function
#include <time.h>//will use seed to randomize value
using namespace std;

int genRand()
{
   
    srand(time(NULL));//set seed using current time
    int num=rand() % 100 + 1; //generating a random number
    return num;
}


int  validateGuess(int guess)
{
    //making sure number entered is with in range;
    while (guess<1 || guess>100)
    {
        cout<<"You entered a wrong number.The range for entering is 1-100.Please re enter"<<endl;
        cin>>guess;
    }
    
    return guess;

}



int main()
{
    cout << "---------------------------------------------------" << endl
         << "--------Welcome To The Number Guessing GAME--------" << endl
         << "----------------------------------------------------" << endl;
//Instructions for the games displayed below
    cout << "Follow the Instructions below to play the game" << endl
         << endl
         << "1. Guess A Number from 1-100" << endl
         << "2. You have 10 tries to Guess the Number" << endl
         << endl
         << "Enjoyyy!!!" << endl
         << endl
         << endl;

    int num = genRand();//generating random number
    int guess,count = 0;
    const int TotalGuess = 10;

    cout << "Enter Guess" << endl;
    cin >> guess;

    guess=validateGuess(guess);

    while (TotalGuess != count)//check for within number of guesses
    {
        count++;
        if (guess > num)
        {
            cout << "Your guess is too High." << endl//if guess is high 
                 << "No. Of Guesses: " << count << endl
                 << endl;
        }
        else if (guess == num)//Win Condition
        {
            cout << "Congratulations!!! You guessed correctly"
                 << endl
                 << "No. Of Guesses: " << count << endl;
            break;
        }
        else
        {
            cout << "Your guess is too Low." << endl//if guess is low
                 << "No. Of Guesses: " << count << endl
                 << endl;
        }

        if (count != TotalGuess)
        {
            cout << "Sorry! Wrong Guess. You still have " << TotalGuess - count << " tries left. Enter Your Next Guess: " << endl;
            cin >> guess;
            guess=validateGuess(guess);
        }
    }

    if (count == TotalGuess)
    {
        cout << "Sorry! You have no guesses left. Better luck next time " << endl;
    }

    cout << endl<<"Rerun the program to play again." << endl<<endl;

    cout << "---------------------------------------------------"<< endl
         << "--------------------THE END-------------------------" << endl
         << "---------------------------------------------------" << endl;

    return 0;
}
