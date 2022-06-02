#include<iostream>
#include<cmath>
using namespace std;
char num[6][7] = { {' ' , ' ', ' ' ,' ',' ',' ',' '},
{' ' , ' ', ' ' ,' ',' ',' ',' '},
{' ' , ' ', ' ' ,' ',' ',' ',' '},
{' ' , ' ', ' ' ,' ',' ',' ',' '},
{' ' , ' ', ' ' ,' ',' ',' ',' '},
{' ' , ' ', ' ' ,' ',' ',' ',' '} }; 
char symbols[4],symbol , answer;
int players ,winner =0 , P1_win = 0 ,P2_win = 0 ,P3_win = 0 , P4_win = 0;
void ifdraw();
void ifwon();
void interface();
void Player4_turn();
void Player3_turn();
void Player2_turn();
void Player1_turn();
void Playagain();
void score();
int main()
{ 
    cout <<"How many players? (minimum 2 - maximum 4): "; 
    while(true){
    cin >> players;
    if (players<2 || players >4 ){
    cout <<"Please select a number of players from 2 to 4: ";}
    else{
    for (int i = 0 ; i < players ;i++)
    {
        cout <<"Player " <<(i+1) <<" please enter your 1-character symbol: ";
        while (true)
        {
            int symbol_taken = 0;
            cin >> symbol;
            for (int j = 0 ; j<4 ;j++)
            {
                if (symbol == symbols[j])
                {
                    cout <<"symbol is already taken! try another: ";
                    symbol_taken++;
                    break;
                }
            }
            if (symbol_taken == 0){
            symbols[i] = symbol;
            break;}
        }
    }
    break;}
    }
    cout <<"------------------------------------------------------\n";
    cout <<"C   O   N   N   E   C   T   F   O   U   R \n";
    score();
    interface();
    while (true){
    Player1_turn();}
}
void ifdraw()
{
    if ((num[0][0] != ' ') && (num[0][1] != ' ') && (num[0][2] != ' ') && (num[0][3] != ' ') && (num[0][4] != ' ') && (num[0][5] != ' ') && (num[0][6] != ' ') && (winner == 0))
    {
        cout <<"It's a draw! ";
        if (players >2)
            cout <<"All of you are on the same level of skill! wow\n";
        else if (players == 2)
            cout <<"Both of you are on the same level of skill! wow\n";
        Playagain();
    }
}
void ifwon()
{
    for (int i = 0 ; i < 6 ; i++)
    {
        for (int j = 0 ; j < 7 ; j++)
        {
            if (num[i][j] != ' ')
            {
                if ( ((num[i][j] == num[i][(j+1)]) && (num[i][j] == num[i][(j+2)]) && (num[i][j] == num[i][(j+3)])) )
                {
                    if (((j+1) != 7) && ((j+2) != 7) && ((j+3) !=7))
                    {
                    if (num[i][j] == symbols[0]){
                    cout <<"Player 1 is the winner!\n"; P1_win++;}
                    else if (num[i][j] == symbols[1]){
                    cout <<"Player 2 is the winner!\n"; P2_win++;}
                    else if (num[i][j] == symbols[2]){
                    cout <<"Player 3 is the winner!\n"; P3_win++;}
                    else if (num[i][j] == symbols[3]){
                    cout <<"Player 4 is the winner!\n"; P4_win++;}
                    winner++;
                    Playagain();
                    }
                }
                if (((num[i][j] == num[(i+1)][j]) && (num[i][j] == num[(i+2)][j]) && (num[i][j] == num[(i+3)][j])))
                {
                    if (num[i][j] == symbols[0]){
                    cout <<"Player 1 is the winner!\n"; P1_win++;}
                    else if (num[i][j] == symbols[1]){
                    cout <<"Player 2 is the winner!\n"; P2_win++;}
                    else if (num[i][j] == symbols[2]){
                    cout <<"Player 3 is the winner!\n"; P3_win++;}
                    else if (num[i][j] == symbols[3]){
                    cout <<"Player 4 is the winner!\n"; P4_win++;}
                    winner++;
                    Playagain();
                }
                if (((num[i][j] == num[(i+1)][(j+1)]) && (num[i][j] == num[(i+2)][(j+2)]) && (num[i][j] == num[(i+3)][(j+3)])))
                {
                    if ( (((j+1) != 7) || ((i+1) !=6)) && (((j+2) != 7) || ((i+2) !=6)) && (((j+3) != 7) || ((i+3) !=6)))
                    {
                    if (num[i][j] == symbols[0]){
                    cout <<"Player 1 is the winner!\n"; P1_win++;}
                    else if (num[i][j] == symbols[1]){
                    cout <<"Player 2 is the winner!\n"; P2_win++;}
                    else if (num[i][j] == symbols[2]){
                    cout <<"Player 3 is the winner!\n"; P3_win++;}
                    else if (num[i][j] == symbols[3]){
                    cout <<"Player 4 is the winner!\n"; P4_win++;}
                    winner++;
                    Playagain();
                    }
                }
                if(((num[i][j] == num[(i+1)][(j-1)]) && (num[i][j] == num[(i+2)][(j-2)]) && (num[i][j] == num[(i+3)][(j-3)])))
                {
                    if ( (((j-1) >= 0) || ((i+1) !=6)) && (((j-2) >= 0) || ((i+2) !=6)) && (((j-3) >= 0) || ((i+3) !=6)))
                    {
                    if (num[i][j] == symbols[0]){
                    cout <<"Player 1 is the winner!\n"; P1_win++;}
                    else if (num[i][j] == symbols[1]){
                    cout <<"Player 2 is the winner!\n"; P2_win++;}
                    else if (num[i][j] == symbols[2]){
                    cout <<"Player 3 is the winner!\n"; P3_win++;}
                    else if (num[i][j] == symbols[3]){
                    cout <<"Player 4 is the winner!\n"; P4_win++;}
                    winner++;
                    Playagain();
                    }
                }
            }
        }
    }
}
void interface()
{
    cout <<"_____________________________________\n";
    for (int i = 0 ; i < 6 ; i++)
    {
        cout <<"|";
        for (int j = 0 ; j<7 ; j++)
        {
            cout <<"| " <<num[i][j] <<" |" ;
        }
        cout <<"|\n";
        cout <<"||---||---||---||---||---||---||---||\n";
    }
            cout <<"   1    2    3    4    5    6    7\n";
}
void Player4_turn()
{
    ifwon();
    ifdraw();
    int line;
    cout <<"Player 4 - Enter a line: ";
    while(true){
    cin >> line;
    if (line <1 || line > 7)
    cout <<"Please enter a line from 1 to 7: ";
    else if (num[0][(line-1)] != ' ')
    {
    cout <<"line is completed! go for another play: ";
    }
    else if (line >=1 && line <=7)
    {
        for (int i = 5 ; i>=0 ; i-=1)
        {
            if (num[i][(line-1)] == ' ')
            {
                num[i][(line-1)] = symbols[3];
                interface();
                break;
            }
        }
        break;
    }
    }
}
void Player3_turn()
{
    ifwon();
    ifdraw();
    int line;
    cout <<"Player 3 - Enter a line: ";
    while(true){
    cin >> line;
    if (line <1 || line > 7)
    cout <<"Please enter a line from 1 to 7: ";
    else if (num[0][(line-1)] != ' ')
    {
    cout <<"line is completed! go for another play: ";
    }
    else if (line >=1 && line <=7)
    {
        for (int i = 5 ; i>=0 ; i-=1)
        {
            if (num[i][(line-1)] == ' ')
            {
                num[i][(line-1)] = symbols[2];
                interface();
                break;
            }
        }
        break;
    }
    }
    if (players>3)
    Player4_turn();
}
void Player2_turn()
{
    ifwon();
    ifdraw();
    int line;
    cout <<"Player 2 - Enter a line: ";
    while(true){
    cin >> line;
    if (line <1 || line > 7)
    cout <<"Please enter a line from 1 to 7: ";
    else if (num[0][(line-1)] != ' ')
    {
    cout <<"line is completed! go for another play: ";
    }
    else if (line >=1 && line <=7)
    {
        for (int i = 5 ; i>=0 ; i-=1)
        {
            if (num[i][(line-1)] == ' ')
            {
                num[i][(line-1)] = symbols[1];
                interface();
                break;
            }
        }
        break;
    }
    }
    if (players>2)
    Player3_turn();
}
void Player1_turn()
{
    ifwon();
    ifdraw();
    int line;
    cout <<"Player 1 - Enter a line: ";
    while(true){
    cin >> line;
    if (line <1 || line > 7 )
    cout <<"Please enter a line from 1 to 7: ";
    else if (num[0][(line-1)] != ' ')
    {
    cout <<"line is completed! go for another play: ";
    }
    else if (line >=1 && line <=7 )
    {
        for (int i = 5 ; i>=0 ; i-=1)
        {
            if (num[i][(line-1)] == ' ')
            {
                num[i][(line-1)] = symbols[0];
                interface();
                break;
            }
        }
        break;
    }
    }
    Player2_turn();
}
void Playagain()
{
    cout <<"Do you want to play again? (Y/N): "; cin >> answer;
    if (answer == 'Y' || answer == 'y')
    {
        for (int i = 0 ; i < 6 ; i++)
        {
            for (int j = 0 ; j<7 ; j++)
            {
                num[i][j] = ' ';
            }
        }
        for (int i = 0 ; i <4 ; i++)
        {
            symbols[i] = 0;
        }
main();
    }
}
void score()
{
    cout <<"Player 1: " <<P1_win << " || Player 2: " <<P2_win;
    if (players == 3)
    cout <<" || Player 3: " <<P3_win <<endl;
    else if (players == 4)
    cout <<" || Player 3: " <<P3_win <<" || Player 4: " <<P4_win <<endl;
    else cout <<endl;
}