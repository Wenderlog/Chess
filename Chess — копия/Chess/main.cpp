//
//  main.cpp
//  Chess
//
//  Created by Кирилл Грибанов  on 05.10.2024.
//

#include <iostream>
#include <string>

#include "Game.h"
#include "Manager.h"
#include "Table.h"

int main() {
    try {
        Table chessTable;
        Game game(chessTable);

        game.StartGame();

        std::string input;
        Manager manager;

        while (true) {
            // Генерация состояния доски и вывод на экран
            std::string boardState = chessTable.GenerateBoardState();
            
            // Выводим состояние доски
            std::cout << "Current board state:\n";
            std::cout << boardState << std::endl;

            std::cout << "Enter your move (e.g., e2 e4 or O-O): ";
            std::getline(std::cin, input);

            // Выход из игры
            if (input == "exit") {
                std::cout << "Game ended by the player." << std::endl;
                break;
            }

            // Отладочный вывод для проверки ввода
            std::cout << "Input move: " << input << std::endl;

            // Преобразуем ход в координаты
            auto coords = manager.WordToCoord(chessTable.getBoard(), input);
            std::cout << coords.first.col << coords.first.row << coords.second.col << coords.second.row;

            // Проверка на пустую пару координат
            if (coords.first.row == 8 || coords.second.row == 8) {
                std::cout << "Invalid move. Try again." << std::endl;
                continue;
            }

            // Отладочный вывод для проверки координат
            std::cout << "From: (" << coords.first.row << ", " << coords.first.col << "), To: ("
                      << coords.second.row << ", " << coords.second.col << ")" << std::endl;

            // Проверка хода
            auto turnVerdict = chessTable.CheckTurn(coords.first, coords.second);
            switch (turnVerdict) {
                case Table::TurnVerdict::correct:
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
                default:
                    std::cout << "Invalid move or special condition. Try again." << std::endl;
                    continue;
            }

            // Проверка на повторение ходов и 50 ходов без захвата
            game.CheckForRepetition();
            game.CheckFor50MovesWithoutCapture();
        }

        // Завершение игры
        game.EndGame();
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }

    return 0;
}

