//
//  main.cpp
//  Chess
//
//  Created by Кирилл Грибанов on 05.10.2024.
//

#include <iostream>
#include <string>

#include "Game.h"
#include "Manager.h"
#include "Table.h"

/*!
 * \brief Entry point for the Chess application.
 * \details Initializes the chessboard, starts the game, and manages the main game loop.
 * Handles user input, validates moves, and interacts with the game logic.
 * \return 0 on successful execution.
 */

int main() {
    try {
        Table chessTable;
        Game game(chessTable);
        Manager manager;

        // Start the game
        game.StartGame();

        std::string input;

        while (true) {
            // Display the current board state
            std::string boardState = chessTable.GenerateBoardState();
            std::cout << "Current board state:\n";
            std::cout << boardState << std::endl;

            // Prompt the player for input
            std::cout << "Enter your move (e.g., e2 e4 or O-O): ";
            std::getline(std::cin, input);

            // Exit the game if the player types "exit"
            if (input == "exit") {
                std::cout << "Game ended by the player." << std::endl;
                break;
            }

            // Debugging output to verify input
            std::cout << "Input move: " << input << std::endl;

            // Convert the move to coordinates
            auto coords = manager.WordToCoord(chessTable.getBoard(), input);
            std::cout << "From: (" << coords.first.col << ", " << coords.first.row
                      << "), To: (" << coords.second.col << ", " << coords.second.row << ")" << std::endl;

            // Check for invalid coordinates
            if (coords.first.row == 8 || coords.second.row == 8) {
                std::cout << "Invalid move. Try again." << std::endl;
                continue;
            }

            // Validate and process the move
            auto turnVerdict = chessTable.CheckTurn(coords.first, coords.second);
            switch (turnVerdict) {
                case Table::TurnVerdict::correct:
                    // Execute the move if it is valid
                    chessTable.DoTurn(coords.first, coords.second);
                    break;

                case Table::TurnVerdict::white_mate:
                    std::cout << "Checkmate! White wins!" << std::endl;
                    return 0;

                case Table::TurnVerdict::black_mate:
                    std::cout << "Checkmate! Black wins!" << std::endl;
                    return 0;

                case Table::TurnVerdict::white_stalemate:
                case Table::TurnVerdict::black_stalemate:
                    std::cout << "Stalemate! It's a draw." << std::endl;
                    return 0;

                case Table::TurnVerdict::unnatural_move:
                    std::cout << "Unnatural move! Please try again." << std::endl;
                    break;

                case Table::TurnVerdict::check:
                    std::cout << "Check! Be careful, your king is in danger." << std::endl;
                    break;

                case Table::TurnVerdict::invalid_rotate:
                    std::cout << "Invalid castling! The move is not allowed." << std::endl;
                    break;

                case Table::TurnVerdict::transformation:
                    std::cout << "Pawn promoted! Choose your new piece." << std::endl;
                    break;

                case Table::TurnVerdict::white_turn:
                    std::cout << "It's not your turn, white player!" << std::endl;
                    break;

                case Table::TurnVerdict::black_turn:
                    std::cout << "It's not your turn, black player!" << std::endl;
                    break;
            }

            // Check for draw conditions
            game.CheckForRepetition();
            game.CheckFor50MovesWithoutCapture();
        }

        // End the game
        game.EndGame();
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }

    return 0;
}
