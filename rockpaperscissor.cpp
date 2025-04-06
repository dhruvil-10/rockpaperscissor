#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

//  generate computer's choice
int generateComputerChoice() {
    return rand() % 3 + 1; // Generate a random number between 1 and 3
}

// Function to determine the winner of a round
int determineWinner(int playerChoice, int computerChoice) 
{
    if (playerChoice == computerChoice)
        return 0; // Draw
    else if ((playerChoice == 1 && computerChoice == 3) || 
            (playerChoice == 2 && computerChoice == 1) ||
            (playerChoice == 3 && computerChoice == 2))
        return 1; // Player wins
    else
        return 2; // Computer wins
}
int main() 
{
    srand(time(0)); // Seed the random number generator

    int playerPoints = 0;
    int computerPoints = 0;
    int level = 1;

    cout << "************************Welcome to Rock-Paper-Scissors game!************************\n";
    cout << "---->Level " << level <<"  <----"<< endl;
    while (playerPoints < 5 && computerPoints < 5) {
        int playerChoice;
        cout << "Enter your choice (1 for Rock, 2 for Paper, 3 for Scissors): ";
        cin >> playerChoice;             //// Player's choice

       
        while (playerChoice < 1 || playerChoice > 3) {                    //  checking INVALID choice
            cout << "Invalid choice! Please enter 1, 2, or 3: ";
            cin >> playerChoice;
        }

       
        int computerChoice = generateComputerChoice();                   //  Computer's choice

        
        int winner = determineWinner(playerChoice, computerChoice);           // RETURN the winner

       
       cout << "You chose ";                                              // Display 
        switch (playerChoice) {
            case 1:
                cout << "Rock. ";
                break;
            case 2:
                cout << "Paper. ";
                break;
            case 3:
                cout << "Scissors. ";
                break;
        }
        cout << "Computer chose ";
        switch (computerChoice) {
            case 1:
                cout << "Rock. ";
                break;
            case 2:
                cout << "Paper. ";
                break;
            case 3:
                cout << "Scissors. ";
                break;
        }

        
        if (winner == 0)                             // Display the winner and update points
            cout << "It's a draw!\n";
        else if (winner == 1) {
            cout << "You win this round!\n";
            playerPoints++;
        } else {
            cout << "Computer wins this round!\n";
            computerPoints++;
        }

        // Display current points
        cout << "Player points: " << playerPoints << ",     Computer points: " << computerPoints << endl;

        // Check if level up is needed
        if (playerPoints == 5 && level < 3) {
            level++;
            playerPoints = 0;
            computerPoints = 0;
            cout << "****************Congratulations! You've reached level " << level << "****************"<< endl;
        }

        // Adjust computer's winning chances based on level
        int chanceToWin = 50 / level; // Chance of winning in percent
        int randomNumber = rand() % 100 + 1; // Generate a random number between 1 and 100
        if (randomNumber <= chanceToWin)
            computerChoice = playerChoice; // Computer chooses the same as player
    }

    // Display the final winner
    if (playerPoints == 5)
        cout << "Congratulations! You win the game!\n";
    else
        cout << "Computer wins the game. Better luck next time!\n";

    return 0;
}
