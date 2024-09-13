#include <iostream>
#include <conio.h> 


int main() {

    int size;
    std::cout << "Enter size of maze (max:50): ";
    std::cin >> size;

    const int MAZE_SIZE = 50;
    char maze[MAZE_SIZE][MAZE_SIZE];

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            maze[i][j] = (i == 0 || j == 0 || i == size - 1 || j == size - 1) ? '#' : ' ';
        }
    }


    int x = 1, y = 1;
    maze[x][y] = 'X';

    int tempX, tempY;

    std::cout << "Drawing started!\n";
    std::cout << "Move up - W\nMove down - S\nMove right - D\nMove left - A\nFinish drawing - F\n";
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout << maze[i][j] << ' ';
        }
        std::cout << std::endl;
    }

    bool check = true;
    while (check) {
        if (_kbhit()) {
            std::cout << "Move up - W\nMove down - S\nMove right - D\nMove left - A\nFinish drawing or use eraser - F\n";
            char move = _getch();
            switch (move) {
            case 'w':
                if (x > 1 && maze[x - 1][y] != '#') {
                    maze[x][y] = '#';
                    x--;
                    maze[x][y] = 'X';
                }
                else {
                    std::cout << "You can't move up. Try again!\n";
                }
                break;
            case 's':
                if (x < size - 2 && maze[x + 1][y] != '#') {
                    maze[x][y] = '#';
                    x++;
                    maze[x][y] = 'X';
                }
                else {
                    std::cout << "You can't move down. Try again!\n";
                }
                break;
            case 'd':
                if (y < size - 2 && maze[x][y + 1] != '#') {
                    maze[x][y] = '#';
                    y++;
                    maze[x][y] = 'X';
                }
                else {
                    std::cout << "You can't move right. Try again!\n";
                }
                break;
            case 'a':
                if (y > 1 && maze[x][y - 1] != '#') {
                    maze[x][y] = '#';
                    y--;
                    maze[x][y] = 'X';
                }
                else {
                    std::cout << "You can't move left. Try again!\n";
                }
                break;
            case 'f':
                std::cout << "Drawing finished." << std::endl;
                char eraser;

                std::cout << "Do you want to use eraser: Yes - y|No - n" << std::endl;
                std::cin >> eraser;
                if (eraser == 'y') {
                    for (int i = 0; i < size; ++i) {
                        for (int j = 0; j < size; ++j) {
                            std::cout << maze[i][j] << ' ';
                        }
                        std::cout << std::endl;
                    }
                    bool eraserChecker = true;
                    while (eraserChecker) {
                        if (_kbhit()) {
                            std::cout << "Move up - W\nMove down - S\nMove right - D\nMove left - A\nFinish deleting - F\n";

                            char eraserMove = _getch();
                            switch (eraserMove) {
                            case 'w':
                                if (x > 1) {
                                    maze[x][y] = ' ';
                                    x--;
                                    maze[x][y] = 'X';
                                }
                                else {
                                    std::cout << "You can't move up. Try again!\n";
                                }
                                break;
                            case 's':
                                if (x < size - 2) {
                                    maze[x][y] = ' ';
                                    x++;
                                    maze[x][y] = 'X';
                                }
                                else {
                                    std::cout << "You can't move down. Try again!\n";
                                }
                                break;
                            case 'd':
                                if (y < size - 2) {
                                    maze[x][y] = ' ';
                                    y++;
                                    maze[x][y] = 'X';
                                }
                                else {
                                    std::cout << "You can't move right. Try again!\n";
                                }
                                break;
                            case 'a':
                                if (y > 1) {
                                    maze[x][y] = ' ';
                                    y--;
                                    maze[x][y] = 'X';
                                }
                                else {
                                    std::cout << "You can't move left. Try again!\n";
                                }
                                break;
                            case 'f':
                                eraserChecker = false;
                                for (int i = 0; i < size; ++i) {
                                    for (int j = 0; j < size; ++j) {
                                        std::cout << maze[i][j] << ' ';
                                    }
                                    std::cout << std::endl;
                                }

                                std::cout << "Deleting finished. Do you want to draw again? y(Yes)|n(No): ";
                                char offerDraw;
                                std::cin >> offerDraw;
                                if (offerDraw == 'y') {
                                    std::cout << "Drawing started!\n";
                                    break;
                                }
                                else if (offerDraw == 'n') {
                                    check = false;
                                }

                            default:
                                std::cout << "Invalid move. Try again!" << std::endl;
                            }

                            for (int i = 0; i < size; ++i) {
                                for (int j = 0; j < size; ++j) {
                                    std::cout << maze[i][j] << ' ';
                                }
                                std::cout << std::endl;
                            }
                        }
                    }
                }
                else if (eraser == 'n') {
                    check = false;
                }
            }
            for (int i = 0; i < size; ++i) {
                for (int j = 0; j < size; ++j) {
                    std::cout << maze[i][j] << ' ';
                }
                std::cout << std::endl;
            }
        }   
    }

    maze[x][y] = ' ';

    std::cout << "Starting point marker started.\n";
    bool startPoint = true;
    char tempMove;
 
    while (startPoint) {
        if (_kbhit) {
            std::cout << "Move up - W\nMove down - S\nMove right - D\nMove left - A\nMark starting point - F\n";


            char startMove = _getch();

            switch (startMove) {
            case 'w':
                if (x > 1) {
                    tempMove = maze[x - 1][y];
                    x--;
                    maze[x][y] = 'X';
                    for (int i = 0; i < size; ++i) {
                        for (int j = 0; j < size; ++j) {
                            std::cout << maze[i][j] << ' ';
                        }
                        std::cout << std::endl;
                    }
                    maze[x][y] = tempMove;
                }
                else {
                    std::cout << "\n\n\nYou can't move up. Try again!\n\n\n";

                }
                break;
            case 's':
                if (x < size - 2) {
                    tempMove = maze[x + 1][y];
                    x++;
                    maze[x][y] = 'X';
                    for (int i = 0; i < size; ++i) {
                        for (int j = 0; j < size; ++j) {
                            std::cout << maze[i][j] << ' ';
                        }
                        std::cout << std::endl;
                    }
                    maze[x][y] = tempMove;
                }
                else {
                    std::cout << "\n\n\nYou can't move down. Try again!\n\n\n";
                }
                break;
            case 'd':
                if (y < size - 2) {
                    tempMove = maze[x][y + 1];
                    y++;
                    maze[x][y] = 'X';
                    for (int i = 0; i < size; ++i) {
                        for (int j = 0; j < size; ++j) {
                            std::cout << maze[i][j] << ' ';
                        }
                        std::cout << std::endl;
                    }
                    maze[x][y] = tempMove;
                }
                else {
                    std::cout << "\n\n\nYou can't move right. Try again!\n\n\n";
                }
                break;
            case 'a':
                if (y > 1) {
                    tempMove = maze[x][y - 1];
                    y--;
                    maze[x][y] = 'X';
                    for (int i = 0; i < size; ++i) {
                        for (int j = 0; j < size; ++j) {
                            std::cout << maze[i][j] << ' ';
                        }
                        std::cout << std::endl;
                    }
                    maze[x][y] = tempMove;
                }
                else {
                    std::cout << "\n\n\nYou can't move left. Try again!\n\n\n";
                }
                break;
            case 'f':
                startPoint = false;
                maze[x][y] = 'S';
                tempX = x;
                tempY = y;
                std::cout << "Start point chosed!";
            default:
                std::cout << "Invalid move. Try again.!" << std::endl;
            }
        }
    }


    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout << maze[i][j] << ' ';
        }
        std::cout << std::endl;
    }


    std::cout << "Final point marker started.\n";
    bool finalPoint = true;
    char tempMove1;

    while (finalPoint) {
        if (_kbhit) {
            std::cout << "Move up - W\nMove down - S\nMove right - D\nMove left - A\nMark final point - F\n";

            char startMove = _getch();

            switch (startMove) {
            case 'w':
                if (x > 1) {
                    tempMove1 = maze[x - 1][y];
                    x--;
                    maze[x][y] = 'X';
                    for (int i = 0; i < size; ++i) {
                        for (int j = 0; j < size; ++j) {
                            std::cout << maze[i][j] << ' ';
                        }
                        std::cout << std::endl;
                    }
                    maze[x][y] = tempMove1;
                }
                else {
                    std::cout << "\n\n\nYou can't move up. Try again!\n\n\n";

                }
                break;
            case 's':
                if (x < size - 2) {
                    tempMove1 = maze[x + 1][y];
                    x++;
                    maze[x][y] = 'X';
                    for (int i = 0; i < size; ++i) {
                        for (int j = 0; j < size; ++j) {
                            std::cout << maze[i][j] << ' ';
                        }
                        std::cout << std::endl;
                    }
                    maze[x][y] = tempMove1;
                }
                else {
                    std::cout << "\n\n\nYou can't move down. Try again!\n\n\n";
                }
                break;
            case 'd':
                if (y < size - 2) {
                    tempMove1 = maze[x][y + 1];
                    y++;
                    maze[x][y] = 'X';
                    for (int i = 0; i < size; ++i) {
                        for (int j = 0; j < size; ++j) {
                            std::cout << maze[i][j] << ' ';
                        }
                        std::cout << std::endl;
                    }
                    maze[x][y] = tempMove1;
                }
                else {
                    std::cout << "\n\n\nYou can't move right. Try again!\n\n\n";
                }
                break;
            case 'a':
                if (y > 1) {
                    tempMove1 = maze[x][y - 1];
                    y--;
                    maze[x][y] = 'X';
                    for (int i = 0; i < size; ++i) {
                        for (int j = 0; j < size; ++j) {
                            std::cout << maze[i][j] << ' ';
                        }
                        std::cout << std::endl;
                    }
                    maze[x][y] = tempMove1;
                }
                else {
                    std::cout << "\n\n\nYou can't move left. Try again!\n\n\n";
                }
                break;
            case 'f':
                if (maze[x][y] != 'S') {
                    maze[x][y] = 'F';
                    std::cout << "Final point chosed!\n\n";
                    finalPoint = false;
                }
                else {
                    std::cout << "\n\n\nYou can't place final point on starting point! Try again.\n\n\n";
                }
                
            default:
                std::cout << "Invalid move. Try again.!" << std::endl;
            }
        }
    }


    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout << maze[i][j] << ' ';
        }
        std::cout << std::endl;
    }

    x = tempX;
    y = tempY;

    maze[x][y] = 'X';
    bool mazeFinish = true;
    int chances;

    std::cout << "How many chances do you want: ";
    std::cin >> chances;

    std::cout << "\n\nMaze game started!!!\n\n";

    while (mazeFinish && chances!=0) {
        if (_kbhit()) {
            std::cout << "Move up - W\nMove down - S\nMove right - D\nMove left - A\n";

            char startMove = _getch();

            switch (startMove) {
            case 'w':
                if (x > 1 && maze[x-1][y] != '*' && maze[x-1][y] != '#' && maze[x-1][y] != 'F') {
                    maze[x][y] = '*';
                    x--;
                    maze[x][y] = 'X';
                }
                else if (maze[x-1][y] == 'F') {
                    std::cout << "You finished maze successfully!!!\n";
                    mazeFinish = false;
                }
                else {
                    std::cout << "You can't move up. Try again!\n";
                    chances--;
                }
                break;
            case 's':
                if (x < size - 2 && maze[x+1][y] != '*' && maze[x+1][y] != '#' && maze[x - 1][y] != 'F') {
                    maze[x][y] = '*';
                    x++;
                    maze[x][y] = 'X';
                }
                else if (maze[x][y] == 'F') {
                    std::cout << "You finished maze successfully!!!\n";
                    mazeFinish = false;
                }
                else {
                    std::cout << "You can't move down. Try again!\n";
                    chances--;
                }
                break;
            case 'd':
                if (y < size - 2 && maze[x][y+1] != '*' && maze[x][y+1] != '#' && maze[x - 1][y] != 'F') {
                    maze[x][y] = '*';
                    y++;
                    maze[x][y] = 'X';
                }
                else if (maze[x][y] == 'F') {
                    std::cout << "You finished maze successfully!!!\n";
                    mazeFinish = false;
                }
                else {
                    std::cout << "You can't move right. Try again!\n";
                    chances--;
                }
                break;
            case 'a':
                if (y > 1 && maze[x][y-1] != '*' && maze[x][y-1] != '#' && maze[x - 1][y] != 'F') {
                    maze[x][y] = '*';
                    y--;
                    maze[x][y] = 'X';
                }
                else if (maze[x][y] == 'F') {
                    mazeFinish = false;
                }
                else {
                    std::cout << "You can't move left. Try again!\n";
                    chances--;
                }
                break;
            default:
                std::cout << "Invalid move. Try again.!" << std::endl;
            }
            for (int i = 0; i < size; ++i) {
                for (int j = 0; j < size; ++j) {
                    std::cout << maze[i][j] << ' ';
                }
                std::cout << std::endl;
            }
        }
        
    }

    
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout << maze[i][j] << ' ';
        }
        std::cout << std::endl;
    }

    if (chances == 0) {
        std::cout << "\n\n\nGame over!!! You don't have enough chances!\n\n\n";
    }
    else {
        std::cout << "Congratulations!!! Congratulations!!! Congratulations!!!\n\nYou finished maze successfully!!!\n\n";
    }

    return 0;
}