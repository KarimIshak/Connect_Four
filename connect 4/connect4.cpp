#include<iostream> // I made a slight edit on the game rules which allows user to choose the number of players in the same game .. capped at 4 and minimized at 2
#include<cmath>
using namespace std;
char num[6][7] = { {' ' , ' ', ' ' ,' ',' ',' ',' '}, //6 rows and 7 colomns.. represented as a 2d array of characters
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
    cout <<"Please select a number of players from 2 to 4: ";} //capping number of players
    else{
    for (int i = 0 ; i < players ;i++)
    {
        cout <<"Player " <<(i+1) <<" please enter your 1-character symbol: ";
        while (true)
        {
            int symbol_taken = 0; // making every player has his unique symbol 
            cin >> symbol;
            for (int j = 0 ; j<4 ;j++)
            {
                if (symbol == symbols[j])
                {
                    cout <<"symbol is already taken! try another: ";
                    symbol_taken++; // flag if symbol is taken which allows user to enter another symbol
                    break;
                }
            }
            if (symbol_taken == 0){
            symbols[i] = symbol;
            break;}
        }
    }
    break;} // to the next step
    }
    cout <<"------------------------------------------------------\n";
    cout <<"C   O   N   N   E   C   T   F   O   U   R \n"; //main interface of the game
    score();
    interface();
    while (true){ //making an infinity loop so that the game doesn't end after the first round *player 4 if existed play*
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
            if (num[i][j] != ' ')//trying to avoid logical errors as much as possible
            {
                if ( ((num[i][j] == num[i][(j+1)]) && (num[i][j] == num[i][(j+2)]) && (num[i][j] == num[i][(j+3)])) ) // 4 numbers in one row
                {
                    if (((j+1) != 7) && ((j+2) != 7) && ((j+3) !=7))
                    {
                    if (num[i][j] == symbols[0]){
                    cout <<"Player 1 is the winner!\n"; P1_win++;} //the p1 , p2 , p3 and p4 thing is just a counter to add some compitition
                    else if (num[i][j] == symbols[1]){
                    cout <<"Player 2 is the winner!\n"; P2_win++;}
                    else if (num[i][j] == symbols[2]){
                    cout <<"Player 3 is the winner!\n"; P3_win++;}
                    else if (num[i][j] == symbols[3]){
                    cout <<"Player 4 is the winner!\n"; P4_win++;}
                    winner++; //flag so the game ends
                    Playagain();
                    }
                }
                if (((num[i][j] == num[(i+1)][j]) && (num[i][j] == num[(i+2)][j]) && (num[i][j] == num[(i+3)][j]))) // 4 numbers in one coloumn
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
                if (((num[i][j] == num[(i+1)][(j+1)]) && (num[i][j] == num[(i+2)][(j+2)]) && (num[i][j] == num[(i+3)][(j+3)]))) //right diagonal
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
                if(((num[i][j] == num[(i+1)][(j-1)]) && (num[i][j] == num[(i+2)][(j-2)]) && (num[i][j] == num[(i+3)][(j-3)]))) //left diagonal
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
        cout <<"||---||---||---||---||---||---||---||\n"; //tried to make it look nice as much as possible
    }
            cout <<"   1    2    3    4    5    6    7\n"; //help users to define the targeted line
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
    else if (num[0][(line-1)] != ' ') //giving another chance when input is in a fully occubied line
    {
    cout <<"line is completed! go for another play: ";
    }
    else if (line >=1 && line <=7)
    {
        for (int i = 5 ; i>=0 ; i-=1) //starting from below -- if the index is busy it goes up
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
    if (players>3) // giving a chance for a 4th player
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
    if (players>2) //it's a two-people based game but i decided to make it up to 4
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
void Playagain() //an option to re-match if users had enough fun to do so
{
    cout <<"Do you want to play again? (Y/N): "; cin >> answer; 
    if (answer == 'Y' || answer == 'y')
    {
        for (int i = 0 ; i < 6 ; i++)
        {
            for (int j = 0 ; j<7 ; j++)
            {
                num[i][j] = ' '; //resetting our connect 4
            }
        }
        for (int i = 0 ; i <4 ; i++)
        {
            symbols[i] = 0; //ressetting symbols so users can take the same symbol every time
        }
main();
    }
}
void score() //i like compititional games .. but how can i do this after only learning basics? let me try
{
    cout <<"Player 1: " <<P1_win << " || Player 2: " <<P2_win; //no way it can be less than 2 players
    if (players == 3) //giving chance for 3rd player to join the compitition
    cout <<" || Player 3: " <<P3_win <<endl;
    else if (players == 4) //4th guy for more fun
    cout <<" || Player 3: " <<P3_win <<" || Player 4: " <<P4_win <<endl;
    else cout <<endl;
}
