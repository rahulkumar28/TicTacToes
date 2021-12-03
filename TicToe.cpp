#include <iostream>
using namespace std;

const int ROWS = 3;
const int COLS = 3;

void initializeGame(char arr[][COLS]);
bool getUserInput(char arr[][COLS], char & whoseTurn);
void runGame(char arr[][COLS]);
bool isValidInput(char arr[][COLS],int row, int column);
void printCurrentBoard(char arr[][COLS]);
bool checkCondition(char arr[][COLS],char& winner);

int main() {

    char ticTacToe[ROWS][COLS];
    //initialize game
    initializeGame(ticTacToe);

    //run the game 
    runGame(ticTacToe);
    
    cout<<"Game Over."<<endl;

    return 0;
}

void initializeGame(char arr[][COLS]) {
    
    for(int i=0;i<ROWS;i++) {
        for(int j=0;j<COLS;j++) {
            arr[i][j] = ' ';
        }
    }

    cout<<"-----------------------------"<<endl;
    cout<<"       Tic Tac Toe           "<<endl;
    cout<<"-----------------------------"<<endl<<endl;

    //first time print
    printCurrentBoard(arr);
}

void runGame(char arr[][COLS]){
  
    char whoseTurn = 'X';
    bool isGameOver = false;
    char winner = 'Y';

    while(!isGameOver)
    {
        if(!getUserInput(arr, whoseTurn))
            continue;
        
        //print array
        printCurrentBoard(arr);

        //check condition
        isGameOver=checkCondition(arr,winner);
       
        if(whoseTurn == 'X')
            whoseTurn = 'O';
        else
            whoseTurn = 'X';
    }

    if(winner != 'X' && winner !='O')
    {
        cout<<"No One Wins..Its Draw!!"<<endl;
    }
    else{
        cout<<"Hurray..We have a Winner : "<<winner<<endl;
    }

}
bool getUserInput(char arr[][COLS], char & whoseTurn){
    
    int row=0;
    int column=0;
    
    cout<<"It is "<<whoseTurn<<"'s Turn"<<endl;
    cout<<"Please enter the row THEN the column, each from 0, 1 or 2 separated by a space"<<endl;
    cin>>row>>column;
    
    if(isValidInput(arr,row,column)) {
        arr[row][column] = whoseTurn;
        return true;
    }

    return false;
}

bool isValidInput(char arr[][COLS], int row, int column)
{
    if((row<0 || row>(ROWS-1)) || (column<0 && column>(COLS-1)))
    {
        cout<<"Wrong Row and Column value"<<endl;
        return false;
    }
    if((arr[row][column]=='X') || (arr[row][column]=='O'))
    {
        cout<<"Slot Already occupied..Try Again"<<endl;
        return false;
    }
    return true;
}

void printCurrentBoard(char arr[][COLS])
{
    for(int i=0; i<ROWS; i++)
    {
        for(int j=0; j<COLS; j++)
        {
            cout<<arr[i][j];
            if(j<=(COLS-2))
            {
                cout<<" | ";
            }
        }
        cout<<endl;
        if(i<=(ROWS-2)){
            for(int i=0;i<(2*COLS-1);i++)
                cout<<"- ";
        }
            
        
        cout<<endl;
        
    }
}

bool checkCondition(char arr[][COLS],char& winner)
{
    static int counter=0;

    bool isRowValEqual=true;
    bool isColValEqual=true;

    if(++counter >= (ROWS*COLS))
    {
        winner = 'N';
        return true;
    }
    // if(counter <= 3)
    // {
    //     return false;
    // }
    //rows check
    for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLS;j++)
        {
           if(arr[i][0] != arr[i][j])
           {
                isRowValEqual = false;
                break; 
           }
           isRowValEqual = true;
        }
        if(isRowValEqual){
            
            if(arr[i][0]!=' ')
            {
                winner = arr[i][0];
                return true;
            }
        }
    }
    //column check
    for(int i=0;i<COLS;i++){
        if(arr[0][i] == arr[1][i] && arr[1][i]==arr[2][i]){
            
            if(arr[0][i] != ' ')
            {
                winner = arr[0][i];
                return true;
            }
        }
    }

    //diagonal check
    if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2])
    {
        winner = arr[0][0];
        return true;    
    }
    if (arr[2][0] == arr[1][1] && arr[1][1] == arr[0][0])
    {
        winner = arr[0][0];
        return true;    
    } 
    return false;
}
