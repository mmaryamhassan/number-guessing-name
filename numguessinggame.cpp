#include <iostream>
#include <random>

int main() {
    std::random_device rd;       // it creates a random device
    std::mt19937 gen(rd());      // Use the random device to seed the random number generator
    std::uniform_int_distribution<> dis(1, 100);     // generates a random number between 1 and 100
    int guessno = dis(gen);
    int your_num;

    do {
        std::cout << "Guess a number between 1 and 100: ";
        std::cin >> your_num;

        if (your_num < guessno) {
            std::cout << your_num << " is too low. Try again.\n";
        } else if (your_num > guessno) {
            std::cout << your_num << " is too high. Try again.\n";
        } else {
            std::cout << "WOW!! You guessed it!\n";
            std::cout << "Do you want to play again? (y/n): ";
            char replay;
            std::cin >> replay;
            if (replay == 'y' || replay == 'Y') {
                guessno = dis(gen);
            }
        }
    } while (guessno != your_num);

    return 0;
}
