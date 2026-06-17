#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

void drawHangman(int stage) {
	switch (stage) {
	case 0:
		cout << " +---+\n"
			<< " |   |\n"
			<< "     |\n"
			<< "     |\n"
			<< "     |\n"
			<< "     |\n"
			<< "=======\n";
		break;
	case 1:
		cout << " +---+\n"
			<< " |   |\n"
			<< " O   |\n"
			<< "     |\n"
			<< "     |\n"
			<< "     |\n"
			<< "=======\n";
		break;
	case 2:
		cout << " +---+\n"
			<< " |   |\n"
			<< " O   |\n"
			<< " |   |\n"
			<< "     |\n"
			<< "     |\n"
			<< "=======\n";
		break;
	case 3:
		cout << " +---+\n"
			<< " |   |\n"
			<< " O   |\n"
			<< "/|   |\n"
			<< "     |\n"
			<< "     |\n"
			<< "=======\n";
		break;
	case 4:
		cout << " +---+\n"
			<< " |   |\n"
			<< " O   |\n"
			<< "/|\\  |\n"
			<< "     |\n"
			<< "     |\n"
			<< "=======\n";
		break;
	case 5:
		cout << " +---+\n"
			<< " |   |\n"
			<< " O   |\n"
			<< "/|\\  |\n"
			<< "/    |\n"
			<< "     |\n"
			<< "=======\n";
		break;
	case 6:
		cout << " +---+\n"
			<< " |   |\n"
			<< " O   |\n"
			<< "/|\\  |\n"
			<< "/ \\  |\n"
			<< "     |\n"
			<< "=======\n";
		cout << "GAME OVER!\n";
		break;
	}
}

int main() {

	cout << "Welcome to Hangman!\n\n";
	cout << "Press ENTER to continue...\n";
	cin.get();

	vector<string> words = {
		"apple", "banana", "cherry", "grape", "orange"
	};

	srand(time(0));

	string word = words[rand() % words.size()];

	int chances = 6;
	string guess;
	bool won = false;

	do {
		cout << "\nPlease enter a " << word.length() << " letter word: ";
		cin >> guess;

		// FIX 1: only validate, don't re-input
		if (guess.length() != word.length()) {
			cout << "Wrong length! Try again.\n";
			continue;
		}

		// correct guess
		if (guess == word) {
			cout << "Congratulations! You won!\n";
			won = true;
		}
		else {
			chances--;
			cout << "Wrong guess! You have " << chances << " left.\n";
			drawHangman(6 - chances);
		}

	} while (!won && chances > 0);

	if (!won) {
		cout << "\nYou lost! The word was: " << word << "\n";
	}

	cout << "Press ENTER to exit...";
	cin.ignore(10000, '\n');
	cin.get();

	return 0;
}