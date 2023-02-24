#include <iostream>
#include <vector>

using namespace std;

// Initialize the game board
vector<char> board(9, ' ');

// Print the game board
void print_board() {
    cout << " " << board[0] << " | " << board[1] << " | " << board[2] << " \n";
    cout << "---+---+---\n";
    cout << " " << board[3] << " | " << board[4] << " | " << board[5] << " \n";
    cout << "---+---+---\n";
    cout << " " << board[6] << " | " << board[7] << " | " << board[8] << " \n";
}

// Check if the game is over
bool game_over() {
    // Check for horizontal wins
    if ((board[0] != ' ' && board[0] == board[1] && board[1] == board[2]) ||
        (board[3] != ' ' && board[3] == board[4] && board[4] == board[5]) ||
        (board[6] != ' ' && board[6] == board[7] && board[7] == board[8])) {
        return true;
    }
    // Check for vertical wins
    if ((board[0] != ' ' && board[0] == board[3] && board[3] == board[6]) ||
        (board[1] != ' ' && board[1] == board[4] && board[4] == board[7]) ||
        (board[2] != ' ' && board[2] == board[5] && board[5] == board[8])) {
        return true;
    }
    // Check for diagonal wins
    if ((board[0] != ' ' && board[0] == board[4] && board[4] == board[8]) ||
        (board[2] != ' ' && board[2] == board[4] && board[4] == board[6])) {
        return true;
    }
    // Check for tie game
    for (int i = 0; i < 9; i++) {
        if (board[i] == ' ') {
            return false;
        }
    }
    return true;
}

int main() {
    // Initialize variables
    int player = 1;
    char mark;
    string choice_str;
    bool replay = true;
    

    cout << "Welcome to Tic Tac Toe!\n\n";
	while (replay) {
	    // Clear the screen
	    #ifdef _WIN32
	        system("cls");
	    #else
	        system("clear");
	    #endif
	
	    // Initialize the game board
	    board = vector<char>(9, ' ');
	
	    do {
	    	#ifdef _WIN32
	        	system("cls");
	    	#else
	        	system("clear");
	    	#endif
	        // Print the game board
	        print_board();
	        player = (player % 2) ? 1 : 2;
	
	        // Get the player's mark
	        mark = (player == 1) ? 'X' : 'O';
	
	        // Get the player's choice for where to place their mark
	        cout << "Player " << player << ", please enter a number from 1-9: ";
	        cin >> choice_str;
	
	        // Check if the chosen position is valid
	        try {
	            int choice = stoi(choice_str);
	            if (choice < 1 || choice > 9) {
	                cout << "Invalid choice. Please choose a number from 1-9.\n";
	                continue;
	            }
	            if (board[choice-1] != ' ') {
	                cout << "That position is already taken. Please choose another.\n";
	                continue;
	            }
	
	            // Place the mark on the board
	            board[choice-1] = mark;
	
	            // Switch to the other player
	            player++;
	
	            // Check if the game is over
	            if (game_over()) {
	                break;
	            }
	        } catch (const std::invalid_argument&) {
	            cout << "Invalid input. Please enter a valid integer.\n";
	        }
	    } while (true);
	
	    // Print the final game board
	    print_board();
	
	    // Print the winner
	    if (mark == 'X') {
	        cout << "Player 1 (X) wins!\n";
	    } else {
	        cout << "Player 2 (O) wins!\n";
	    }
	
	    // Prompt the user to replay
	    char response;
	    cout << "Do you want to play again? (y/n): ";
	    cin >> response;
	    replay = (response == 'y' || response == 'Y');
	    player = 1;
	}
	return 0;
}
