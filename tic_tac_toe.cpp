#include<iostream>
#include<fstream>
#include<conio.h>
using namespace std;
const int gridSize = 3;
int countt = 0;
char board[gridSize][gridSize] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}};
void header()
{
    cout << "__________________________________________________________________________" << endl<<endl;
    cout << "    ####### #    ###   #######    #        ###   #######   ###   #####    " << endl;
    cout << "       #    #  ##         #      # #     ##         #     #####  #        " << endl;
    cout << "       #    #  #     *    #     #   #    #     *    #     #####  #####    " << endl;
    cout << "       #    #  ##         #    #######   ##         #     #####  #        " << endl;
    cout << "       #    #    ###      #   #       #    ###      #      ###   #####    " << endl;
    cout << "__________________________________________________________________________" << endl;
    cout<<endl;
}
void show_array()
{
    cout<<endl;
    cout<<"-------------------------------------------------"<<endl;
    for(int x =0 ; x< gridSize ;x++)
    {
        cout<<"|\t\t||\t\t||\t\t|"<<endl;
        for(int m=0 ; m < gridSize ; m++)
        {
            cout<<"|\t"<<board[x][m]<<"\t|";
        }
        cout<<endl<<"|\t\t||\t\t||\t\t|";
        cout<<endl<<"-------------------------------------------------"<<endl;
    }
}
void place(char symbol)
{
    int rows=4,colm=4;
    string str;
    while(1)
    {
        system("cls");
        header();
        show_array();
        cout <<"\t(Player "<<symbol<<" turn)"<<endl;
        cout <<"Enter Input : ";
        cin>> str;
        if(str[0] == '1') rows=0;
        if(str[0] == '2') rows=1;
        if(str[0] == '3') rows=2;
        if(str[1] == 'A' || str[1] == 'a') colm=0;
        if(str[1] == 'B' || str[1] == 'b') colm=1;
        if(str[1] == 'C' || str[1] == 'c') colm=2;
        if(board[rows][colm] == ' ')
        {
            board[rows][colm] = symbol;
            countt++;
            break;
        }
        else
        {
            cout<<"Wrong Input (This place is already taken)."<<endl<<"Press any key to enter again....."<<endl<<endl;
            getch();
        }
    }
}
void back_to_game()
{
    countt=0;
    for(int x =0 ; x< gridSize ;x++)
    {
        for(int m=0 ; m < gridSize ; m++)
        {
            board[x][m]=' ';
        }
    }
}
bool checkRows(char symbol)
{
    int count = 0;
    for (int row = 0; row < gridSize; row = row + 1)
    {
        count = 0;
        for (int col = 0; col < gridSize; col = col + 1)
        {
            if (board[row][col] == symbol)
            {
                count = count + 1;
            }
        }
        if (count == gridSize)
        {
            return 1;
        }
    }
    return 0;
}
bool checkColumns(char symbol)
{
    int count = 0;
    for (int col = 0; col < gridSize; col = col + 1)
    {
        count = 0;
        for (int row = 0; row < gridSize; row = row + 1)
        {
            if (board[row][col] == symbol)
            {
                count = count + 1;
            }
        }
        if (count == gridSize)
        {
            return 1;
        }
    }
    return 0;
}
bool checkDiagonals(char symbol)
{
    int count = 0;
    for (int idx = 0; idx < gridSize; idx = idx + 1)
    {
        if (board[idx][idx] == symbol)
        {
            count = count + 1;
        }
    }
    if (count == gridSize)
    {
        return 1;
    }
    count = 0;
    for (int row = 0, col = 2; row < gridSize; row++, col--)
    {
        if (board[row][col] == symbol)
        {
            count = count + 1;
        }
    }
    if (count == gridSize)
    {
        return 1;
    }
    return 0;
}
bool isWinner(char symbol)
{
    if (checkRows(symbol) || checkColumns(symbol) || checkDiagonals(symbol))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void menu()
{
    cout<<"Main Menu >"<<endl<<endl;
    cout<<"1) Press 1 to play the game"<<endl;
    cout<<"2) Press 2 to view Records"<<endl;
    cout<<"3) Press 3 to exit"<<endl;
}
main()
{
    int choose=0;
    while(choose != 3)
    {
        system("cls");
        header();
        menu();
        cin >> choose;
        if (choose == 1)
        {
            char again = 9;
            while (again != '0')
            {
                system("cls");
                header();
                back_to_game();
                string str;
                bool yt = 0;
                char symbol = 'O';
                char symbol1 = 'X';
                while (countt != 9)
                {
                    place(symbol);
                    yt = isWinner(symbol);
                    if (yt == 1)
                    {
                        string store="Player 1 won !!!!!!!!";
                        system("cls");
                        header();
                        show_array();
                        cout <<store << endl;
                        fstream file;
                        file.open("1.txt" , ios::app);
                        file << store<<endl;
                        file.close();
                        break;
                    }
                    else if (countt == 9)
                    {
                        break;
                    }
                    place(symbol1);
                    yt = isWinner(symbol1);
                    if (yt == 1)
                    {
                        string store="Player 2 won !!!!!!!!";
                        system("cls");
                        header();
                        show_array();
                        cout <<store<< endl;
                        fstream file;
                        file.open("1.txt" , ios::app);
                        file << store<<endl;
                        file.close();
                        break;
                    }
                    else if (countt == 9)
                    {
                        header();
                        show_array();
                        
                        break;
                    }
                }
                if (countt == 9)
                {
                    string store= "Its a Draw !!!!!!!!";
                    cout << store<< endl;
                    fstream file;
                    file.open("1.txt", ios::app);
                    file << store << endl;
                    file.close();
                }
                cout << "Enter any key to play again( Press 0 to Exit) :";
                cin >> again;
            }
        }
        else if (choose == 2)
        {
            system("cls");
            header();
            cout<<"Main Menu > Records >"<<endl<<endl;
            string str;
            fstream file;
            file.open("1.txt" , ios::in);
            while(!file.eof())
            {
                getline(file, str);
                cout << "   " << str << endl;
            }
            cout<<"Enter any key to continue.....";
            getch();
        }
        else if( choose ==3)
        {
            system("cls");
            header();
            cout<<"Main Menu > Exit >"<<endl<<endl;
            cout<<"Thanks for playing the game"<<endl<<"Hope you loved the experience"<<endl;
        }
    }
}