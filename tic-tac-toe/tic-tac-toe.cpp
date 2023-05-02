#include <iostream>

using namespace std;

char boardData[10] = { '0','1','2','3','4','5','6','7','8','9' };
int checkWin();
void boardDrawing();

int main()
{
    setlocale(LC_ALL, "ru");

    int player = 1, i, choice;
    char mark;

    do {

        boardDrawing();
        player = (player % 2) ? 1 : 2;
        cout << "Игрок-" << player << ", выберите число: ";
        cin >> choice;
        mark = (player == 1) ? 'X' : 'O';
        if (choice == 1 && boardData[1] == '1')
            boardData[1] = mark;
        else if (choice == 2 && boardData[2] == '2')
            boardData[2] = mark;
        else if (choice == 3 && boardData[3] == '3')
            boardData[3] = mark;
        else if (choice == 4 && boardData[4] == '4')
            boardData[4] = mark;
        else if (choice == 5 && boardData[5] == '5')
            boardData[5] = mark;
        else if (choice == 6 && boardData[6] == '6')
            boardData[6] = mark;
        else if (choice == 7 && boardData[7] == '7')
            boardData[7] = mark;
        else if (choice == 8 && boardData[8] == '8')
            boardData[8] = mark;
        else if (choice == 9 && boardData[9] == '9')
            boardData[9] = mark;

        else {
            cout << "Невозможно совершить ход, повторите: ";
            player--;
            cin.ignore();
            cin.get();
        }

        i = checkWin();
        player++;


    } while (i == -1);
    boardDrawing();
    if (i == 1) cout << "*** Игрок-" << --player << " победил ***";
    else cout << "*** Ничья";
    cin.ignore();
    cin.get();

    return 0;
}



void boardDrawing() {
    //system("cls"); // очистка консоли
    cout << "\t\t\t\t ИГРА \n";
    cout << "Игрок-1 (X) | Игрок-2 (O)" << endl << endl;

    cout << " _________________ " << endl;
    cout << "|     |     |     |" << endl;
    cout << "|  " << boardData[1] << "  |  " << boardData[2] << "  |  " << boardData[3] << "  |" << endl;
    cout << "|_____|_____|_____|" << endl;
    cout << "|     |     |     |" << endl;
    cout << "|  " << boardData[4] << "  |  " << boardData[5] << "  |  " << boardData[6] << "  |" << endl;
    cout << "|_____|_____|_____|" << endl;
    cout << "|     |     |     |" << endl;
    cout << "|  " << boardData[7] << "  |  " << boardData[8] << "  |  " << boardData[9] << "  |" << endl;
    cout << "|_____|_____|_____|" << endl << endl;

}

int checkWin() {
    if (boardData[1] == boardData[2] && boardData[2] == boardData[3])
        return 1;
    else if (boardData[4] == boardData[5] && boardData[5] == boardData[6])
        return 1;
    else if (boardData[7] == boardData[8] && boardData[8] == boardData[9])
        return 1;
    else if (boardData[1] == boardData[4] && boardData[4] == boardData[7])
        return 1;
    else if (boardData[2] == boardData[5] && boardData[5] == boardData[8])
        return 1;
    else if (boardData[3] == boardData[6] && boardData[6] == boardData[9])
        return 1;
    else if (boardData[1] == boardData[5] && boardData[5] == boardData[9])
        return 1;
    else if (boardData[3] == boardData[5] && boardData[5] == boardData[7])
        return 1;
    else if (boardData[1] != '1' && boardData[2] != '2' && boardData[3] != '3' && boardData[4] != '4'
        && boardData[5] != '5' && boardData[6] != '6' &&
        boardData[7] != '7' && boardData[8] != '8' && boardData[9] != '9')
        return 0;
    else
        return -1;
}