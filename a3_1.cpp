/*
 Name:        Michael
 Date:        September 8, 2018
 Instructor:  Dave Harden
 File Name:   a3_1.cpp
 Description:
 
 This program prompts the user to think of a number between one and 100.
 The program then proceeds at guessing the number through a binary search.
 
 */

#include<iostream>
using namespace std;

const int LOWER_BOUND = 1;
const int UPPER_BOUND = 100;

void playOneGame();
void getUserResponseToGuess( int guess, char& result );
int getMidpoint( int low, int high );






int main() {
    char response;
    cout << "Ready to play (y/n)? ";
    cin >> response;
    while( response == 'y' ) {
        playOneGame();
        cout << "Great! Do you want to play again (y/n)? ";
        cin >> response;
    }
}






/**
 * Plays one guessing game until the computer guesses the correct answer.
 * Once finished, the user is asked if they want to play again
 */
void playOneGame() {
    char userInput = '\0';
    //highGuess is set one integer higher than
    //the UPPER_BOUND in case the user guesses '100'
    int lowGuess = LOWER_BOUND, highGuess = (UPPER_BOUND + 1);
    cout << "Think of a number between "<< LOWER_BOUND
    <<" and "<<UPPER_BOUND <<".\n";
    while( userInput != 'c' ) {
        int midpoint = getMidpoint(lowGuess, highGuess);
        getUserResponseToGuess( midpoint, userInput);
        if( userInput == 'h' ) {
            lowGuess = midpoint;
        }else if( userInput == 'l' ) {
            highGuess = midpoint;
        }
    }
}






/**
 * Displays the computer's guess and prompts the user to enter if the their number is
 * lower('l'), higher('h'), or correct('c')
 
 * @param guess is the computer's guess
 * @param result is the user's response to the computer's guess
 */

void getUserResponseToGuess( int guess, char& result ) {
    cout << "My guess is " << guess <<
    ". Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: ";
    cin >> result;
}






/**
 * Returns the midpoint between two numbers
 
 * @param low is the smaller number
 * @param high is the bigger number
 * @return the midpoint between the smaller and bigger numbers
 */
int getMidpoint( int low, int high ) {
    return (low + high)/2;
}

/* CONSOLE OUTPUT
 
 Ready to play (y/n)? y
 Think of a number between 1 and 100.
 My guess is 50. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: l
 My guess is 25. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: l
 My guess is 13. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: l
 My guess is 7. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: c
 Great! Do you want to play again (y/n)? y
 Think of a number between 1 and 100.
 My guess is 50. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: l
 My guess is 25. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: l
 My guess is 13. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: l
 My guess is 7. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: h
 My guess is 10. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: h
 My guess is 11. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: c
 Great! Do you want to play again (y/n)? n
 Program ended with exit code: 0
 
 */
