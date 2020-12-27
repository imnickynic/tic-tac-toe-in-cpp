#include<iostream>            //for io
#include<cstdlib>             //for random function
#include<stdlib.h>            //for abort() 
#include<ctime>               //for random number
#include<windows.h>           //for sleep() function
using namespace std; 
char ind[] = {'1','2','3','4','5','6','7','8','9'};         //creating index array for tic toc toe board
int temp;

//function to show tictoctoe board
void showBoard(){
    cout<< " "<<ind[0]<<" | "<<ind[1]<<" | "<<ind[2]<<endl;
    cout<< "-----------"<<endl;
    cout<< " "<<ind[3]<<" | "<<ind[4]<<" | "<<ind[5]<<endl;
    cout<< "-----------"<<endl;
    cout<< " "<<ind[6]<<" | "<<ind[7]<<" | "<<ind[8]<<endl<<endl;
}

// getting index input from user
void getInput(){  
    cout<< "Enter Position: ";
    cin >>temp;
    cout<< endl;
    if (ind[temp-1] != 'X' && ind[temp-1] != 'O'){
        ind[temp-1] = 'X';
        showBoard(); 
    }
    else{
        cout<< "Position is Already filled. Enter Blank Position.."<<endl<<endl;
        getInput();
    }    
}

// function to create random index for computer
void compTurn(){
    int random_number = (rand()%8);
    if (ind[random_number] != 'X' && ind[random_number] != 'O'){
        ind[random_number] = 'O';
        cout<< "Computer Turn..."<<endl;
        Sleep(1500);
        cout<< "Comupter : "<<random_number+1<<endl<<endl;
        Sleep(1000);
        showBoard(); 
    }
    else{
        compTurn();
    }
}

// function to checking matching
void check(){
    if((ind[0]=='X'&&ind[3]=='X'&&ind[6]=='X')|| (ind[1]=='X'&&ind[4]=='X'&&ind[7]=='X')||( ind[2]=='X'&&ind[5]=='X'&&ind[8]=='X')||
       (ind[0]=='X'&&ind[1]=='X'&&ind[2]=='X')|| (ind[3]=='X'&&ind[4]=='X'&&ind[5]=='X')|| (ind[6]=='X'&&ind[7]=='X'&&ind[8]=='X')||
       (ind[0]=='X'&&ind[4]=='X'&&ind[8]=='X')|| (ind[2]=='X'&&ind[4]=='X'&&ind[6]=='X') ){
            cout<<("-----------------|| You Win ||---------------")<<endl<<endl;
            abort();
    }
    else if((ind[0]=='O'&&ind[3]=='O'&&ind[6]=='O') || (ind[1]=='O'&&ind[4]=='O'&&ind[7]=='O') || (ind[2]=='O'&&ind[5]=='O'&&ind[8]=='O')||
            (ind[0]=='O'&&ind[1]=='O'&&ind[2]=='O') || (ind[3]=='O'&&ind[4]=='O'&&ind[5]=='O') || (ind[6]=='O'&&ind[7]=='O'&&ind[8]=='O')||
            (ind[0]=='O'&&ind[4]=='O'&&ind[8]=='O') || (ind[2]=='O'&&ind[4]=='O'&&ind[6]=='O')){
           cout<<("----------------|| Computer Win ||---------------")<<endl<<endl;
           abort();
    }
}

// run function for all operation
void runFunction(){ 
    getInput();
    check();
    compTurn();
    check();
}

// main cpp function
int main(){
    srand((int)time(0)); 
    system("cls");     
    showBoard();
    for(int i=0; i<5; i++){        
        runFunction();
    }
    return 0;
}
