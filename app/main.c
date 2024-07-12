/*
 * A (not so basic) 'Connect 4 Game' implementation.
 *
 * Author: Tommaso Bocchietti
 * Email: tommaso.bocchietti@gmail.com
 * Date: 2023-03-30
 *
 * This program let two players play the 'Connect 4 Game' on the same computer.
 * The game is played on a 6x7 board, and the first player to get four of his/her symbols in a row (horizontally, vertically or diagonally) wins.
 * The players take turns inserting their symbols into the board, and the game ends when one of the players wins, or when the board is full.
 * No graphics are provided, this is just a console application.
 * It is possible to play personalized versions of the game by passing parameters to the program.
 *
 * License: MIT
 *
 */

#include <stdio.h>
#include <stdlib.h>

#include "src/definitions.h"
#include "src/setup/setup.h"
#include "src/loop.h"

// int main(int argc, char *argv[])
// {
// 	game_t *game = (game_t *)malloc(sizeof(game_t));
// 	game->gameBoard = (board_t *)malloc(sizeof(board_t));
// 	game->currentMove = (board_index_t *)malloc(sizeof(board_index_t));

// 	C4G_Setup(game, argc, argv);
// 	C4G_Loop(game);

// 	return EXIT_SUCCESS;
// }

#include <glad/glad.h>
#include <GLFW/glfw3.h>

int main(void)
{
	GLFWwindow *window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}