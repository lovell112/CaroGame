#include "include\Game.h"

void gotoXY(int x, int y, HANDLE& h) {
    CONSOLE_CURSOR_INFO cur;
    // GetConsoleCursorInfo(h, &cur);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(h, pos);
}

void run(Board board, Player player_1, Player player_2) {
    // construct Game with twice player and a board
    Game caro = Game(player_1, player_2, board);
    // Default current player is player 1
    caro.setCurrentPlayer(player_1);

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);

    FlushConsoleInputBuffer(hInput);

    CONSOLE_CURSOR_INFO cur;
    GetConsoleCursorInfo(hConsole, &cur);
    cur.dwSize = 100;
    // cur.bVisible = false;
    SetConsoleCursorInfo(hConsole, &cur);

    COORD curPos = {1, 1};
    COORD oldPos = curPos;

    Sleep(200);
    while (GetAsyncKeyState(VK_UP) & 0x8000) Sleep(10);
    while (GetAsyncKeyState(VK_DOWN) & 0x8000) Sleep(10);
    while (GetAsyncKeyState(VK_LEFT) & 0x8000) Sleep(10);
    while (GetAsyncKeyState(VK_RIGHT) & 0x8000) Sleep(10);
    while (GetAsyncKeyState('W') & 0x8000) Sleep(10);
    while (GetAsyncKeyState('A') & 0x8000) Sleep(10);
    while (GetAsyncKeyState('S') & 0x8000) Sleep(10);
    while (GetAsyncKeyState('D') & 0x8000) Sleep(10);
    while (GetAsyncKeyState(VK_RETURN) & 0x8000) Sleep(10);

    bool hadWon = false;
    board.draw();

    while (!(GetAsyncKeyState(VK_ESCAPE)&0x0001)) {
        // display current cursor
        gotoXY(curPos.X, curPos.Y, hConsole);
        SetConsoleTextAttribute(hConsole, 0x02);
        cout << (board.isFull(curPos.X, curPos.Y) ? board[curPos.Y][curPos.X] : caro.getCurrentPlayer()->getSymbol());
        SetConsoleTextAttribute(hConsole, 0x07);

        // delete old position
        if (oldPos.X != curPos.X || oldPos.Y != curPos.Y) {
            gotoXY(oldPos.X, oldPos.Y, hConsole);
            if (!board.isFull(oldPos.X, oldPos.Y))
                cout << ' ';
            else {
                // display original color
                if (board[oldPos.Y][oldPos.X] == player_1.getSymbol())
                    SetConsoleTextAttribute(hConsole, 0x09);
                else
                    SetConsoleTextAttribute(hConsole, 0x0C);
                cout << board[oldPos.Y][oldPos.X];
                SetConsoleTextAttribute(hConsole, 0x07);
            }
            oldPos = curPos;
        }

        if (GetAsyncKeyState(VK_UP) & 0x0001 || GetAsyncKeyState('W') & 0x0001)
            curPos.Y--;
        else if (GetAsyncKeyState(VK_LEFT) & 0x0001 || GetAsyncKeyState('A') & 0x0001)
            curPos.X--;
        else if (GetAsyncKeyState(VK_DOWN) & 0x0001 || GetAsyncKeyState('S') & 0x0001)
            curPos.Y++;
        else if (GetAsyncKeyState(VK_RIGHT) & 0x0001 || GetAsyncKeyState('D') & 0x0001)
            curPos.X++;

        // Check limit space
        if (curPos.X <= 0)
            curPos.X = board.getCol() - 2;
        else if (curPos.X >= board.getCol() - 1)
            curPos.X = 1;
        if (curPos.Y <= 0)
            curPos.Y = board.getRow() - 2;
        else if (curPos.Y >= board.getRow() - 1)
            curPos.Y = 1;

        // Press ENTER to fill
        if ((GetAsyncKeyState(VK_RETURN) & 0x0001) && !board.isFull(curPos.X, curPos.Y)) {
            caro.getCurrentPlayer()->press(curPos.X, curPos.Y, board);

            gotoXY(curPos.X, curPos.Y, hConsole);
            if (board[curPos.Y][curPos.X] == player_1.getSymbol())
                SetConsoleTextAttribute(hConsole, 0x09);
            else
                SetConsoleTextAttribute(hConsole, 0x0C);
            cout << board[curPos.Y][curPos.X];
            SetConsoleTextAttribute(hConsole, 0x07);

            // Check win condition
            hadWon = caro.checkWin(caro.getCurrentPlayer()->getSymbol(), curPos.X, curPos.Y, board);

            if (hadWon) {
                break;
            }
            caro.switchPlayer();
        }

        Sleep(50);
    }

    // Display winner
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    SHORT newCol = csbi.dwSize.X + 10;
    SHORT newRow = csbi.dwSize.Y + 10;
    SetConsoleScreenBufferSize(hConsole, {newCol, newRow});
    SHORT bottom = csbi.dwSize.Y - 1;
    SetConsoleCursorPosition(hConsole, {0, bottom});
    cout << "=====================================\n";
    cout << "Winner is : " << caro.getCurrentPlayer()->getName() << endl;
    cout << "=====================================\n";
}
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    int width, height;
    string p1_name, p2_name;
    char p1_symbol, p2_symbol;

    // the size of board
    cout << "=====================================\n";
    cout << "Enter size of BOARD:\n";
    cout << "Width = "; cin >> width;
    cout << "Height = "; cin >> height;
    cout << "=====================================\n";
    Board board(height, width);
    Sleep(1000);
    system("cls");

    // the first player
    cout << "=====================================\n";
    cout << "The first player:\n";
    cout << "Enter Player's name: "; cin >> p1_name;
    cout << "Enter Player's symbol: "; cin >> p1_symbol;
    cout << "=====================================\n";
    Player player_1(p1_name, p1_symbol);
    Sleep(1000);
    system("cls");

    // the second player
    cout << "=====================================\n";
    cout << "The second player:\n";
    cout << "Enter Player's name: "; cin >> p2_name;
    cout << "Enter Player's symbol: "; cin >> p2_symbol;
    cout << "=====================================\n";
    Player player_2(p2_name, p2_symbol);
    Sleep(1000);
    system("cls");

    cin.ignore();

    // playing
    run(board, player_1, player_2);


    // press any key to quit
    system("pause");
    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.