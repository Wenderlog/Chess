//  main.cpp
//  Chess
//
//  Created by Кирилл Грибанов on 05.10.2024.
//

#include <iostream>
#include <map>
#include <string>

#include "Game.h"
#include "Manager.h"
#include "Table.h"
#include "Run.h"

/*!
 * \brief Entry point for the Chess application.
 * \details The `main` function serves as the entry point for the Chess game application.
 * It initializes the `RunningGame` object, which manages the game loop, user input,
 * and game logic. The `RunningGame::Run()` method is called to start the game and
 * handle the main loop, including player moves, game state updates, and termination
 * conditions. In case of an error, an exception is caught, and an error message is printed.
 *
 * \return 0 if the game runs successfully, or 1 if an error occurs.
 */

int main() {
    try {
        RunningGame runningGame; ///< Creates an instance of the `RunningGame` class to manage the game.
        return runningGame.Run(); ///< Starts the game loop and returns the exit code.
        
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl; ///< Prints the error message if an exception is thrown.
        return 1; ///< Returns 1 to indicate an error occurred.
    }
}
