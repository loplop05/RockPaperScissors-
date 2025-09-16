#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

short number_of_rounds() {
    short rounds;
    cout << "\n============================\n";
    cout << "   ROCK-PAPER-SCISSORS\n";
    cout << "============================\n";
    cout << "Enter number of rounds (1 - 10): ";
    cin >> rounds;
    return rounds;
}

int ComputerAnswer() {
    return rand() % 3 + 1;
}

int personAnswer() {
    int n;
    cout << "\nYour choice (1 = Rock, 2 = Paper, 3 = Scissors): ";
    do {
        cin >> n;
        if (n < 1 || n > 3) cout << "Invalid! Enter 1, 2, or 3: ";
    } while (n < 1 || n > 3);
    return n;
}

struct gameResults {
    string win = "WIN!";
    string lost = "LOST!";
    string draw = "DRAW!";
};

enum operations { rock = 1, paper = 2, scissors = 3 };

string getChoiceName(operations op) {
    switch (op) {
    case rock: return "Rock";
    case paper: return "Paper";
    case scissors: return "Scissors";
    default: return "Unknown";
    }
}

void printRoundHeader(int round) {
    cout << "\n----------------------------------------\n";
    cout << "               ROUND " << round << "\n";
    cout << "----------------------------------------\n";
}

void printResultTable(int round, string personChoice, string compChoice, string result) {
    cout << left << setw(10) << "Round" << setw(15) << "Player" << setw(15) << "Computer" << "Result\n";
    cout << left << setw(10) << round << setw(15) << personChoice << setw(15) << compChoice << result << "\n";
}

void roundStart(gameResults results, int& playerScore, int& computerScore) {
    short rounds = number_of_rounds();

    for (int i = 1; i <= rounds; i++) {
        printRoundHeader(i);

        int person = personAnswer();
        operations personOp = (operations)person;
        cout << "Player chose: " << getChoiceName(personOp) << "\n";

        int computer = ComputerAnswer();
        operations computerOp = (operations)computer;
        cout << "Computer chose: " << getChoiceName(computerOp) << "\n";

        string roundResult;
        if (person == computer) {
            roundResult = results.draw;
            system("color 6F");
        }
        else if ((personOp == rock && computerOp == scissors) ||
            (personOp == paper && computerOp == rock) ||
            (personOp == scissors && computerOp == paper)) {
            roundResult = results.win;
            playerScore++;
            system("color 2F");
        }
        else {
            roundResult = results.lost;
            computerScore++;
            system("color 4F");
        }

        cout << "\nResult of this round:\n";
        printResultTable(i, getChoiceName(personOp), getChoiceName(computerOp), roundResult);
    }
}

void askAgain() {
    gameResults results;
    int answer = 1;

    while (answer == 1) {
        system("cls");
        int playerScore = 0, computerScore = 0;

        roundStart(results, playerScore, computerScore);

        cout << "\n====================================\n";
        cout << "FINAL RESULT: Player [" << playerScore << "] - Computer [" << computerScore << "]\n";
        cout << (playerScore > computerScore ? "YOU WON THE GAME!" :
            (playerScore == computerScore ? "IT'S A DRAW!" : "COMPUTER WON THE GAME!")) << "\n";
        cout << "====================================\n";

        cout << "\nPlay again? (YES = 1, NO = 0): ";
        cin >> answer;
    }

    cout << "\nThank you for playing!\n";
}

int main() {
    srand((unsigned)time(NULL));
    askAgain();
    return 0;
}

