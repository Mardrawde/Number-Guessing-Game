#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void guessNumber() {
    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "I'm thinking of a number between 1 and 100." << endl;
    
    // Generate a random number between 1 and 100
    srand(time(0));
    int secretNumber = rand() % 100 + 1;
    int attempts = 0;
    int guess;

    while (attempts < 10) {
        cout << "\nAttempt: " << attempts + 1 << endl;
        cout << "Enter your guess (between 1 and 100): ";
        cin >> guess;

        if (cin.fail()) {
            cin.clear(); // Clear error flag
            cin.ignore(INT_MAX, '\n'); // Discard input
            cout << "Invalid input! Please enter a valid number." << endl;
            continue;
        }

        if (guess < 1 || guess > 100) {
            cout << "Please enter a number within the range of 1 to 100." << endl;
            continue;
        }

        if (guess < secretNumber) {
            cout << "Too low! Try a higher number." << endl;
        } else if (guess > secretNumber) {
            cout << "Too high! Try a lower number." << endl;
        } else {
            cout << "Congratulations! You've guessed the number (" << secretNumber << ") correctly in " << attempts + 1 << " attempts!" << endl;
            return;
        }
        attempts++;
    }

    cout << "\nGame over! The number I was thinking of was " << secretNumber << ". Better luck next time!" << endl;
}

int main() {
    guessNumber();
    return 0;
}

