#include <iostream>
#include <time.h>
#include <ctime>
#include <cstdlib>
using namespace std;
/*Write a program that mimics a coin toss game where the player wins if they correctly guess the side the coin will land on. Use functions, loops, userInput. When the player selects exit, the game should display the score for wins and losses */
//April 20, 2021
//Kennedy A. Mays

//functions
void menu(){
  //displays menu options
  cout<<"1. Play the Game of Coin Toss"<<endl;
  cout<<"2. Exit"<<endl;
}

int toss(){
  //randomly assigns the coin value
  srand(time(NULL));
  int coinNum=rand()%2;
  string coin;
  if(coinNum==0){coin="Heads";}
  else{coin="Tails";}
  cout<<"Coin: "<<coinNum<<" = "<<coin<<endl;
  return coinNum;
}

int getUserSelection(){
  //user selects (valid) guess
  int playerNum=3;
  string player;
  //loops until the user enters valid input
  while(playerNum!=0 && playerNum!=1){
    cout<<"Enter 0 for heads or 1 for tails: ";
    cin>>playerNum;
  }
  if(playerNum==0){player="Heads";}
  else{player="Tails";}
  cout<<"Player: "<<playerNum<<" = "<<player<<endl;
  return playerNum;
}

int determineWinner(int playerNum, int coinNum){
  //compares results and displays the winner
  //
  int winner;
  if(playerNum==coinNum){
    cout<<"Player wins!"<<endl;winner=1;
  }
  else{
    cout<<"Player loses!"<<endl;winner=0;
  }
  return winner;
}
int main() {
  //variables
  int menuChoice=1;
  int win=0;
  int lose=0;
  int playerNum, coinNum, winner;

  //introduction
  cout<<"********************************"<<endl;
  cout<<"Welcome to the Coin Toss Program"<<endl;
  cout<<"********************************"<<endl;
  cout<<"A coin is flipped to identify heads or tails."<<endl;
  cout<<"Select 0 for heads and 1 for tails."<<endl;
  cout<<endl;

  //loop until the user chooses exit
  while(menuChoice!=2){
    cout<<"Menu Options"<<endl;
    cout<<"************"<<endl;
    menu();
    cout<<"Menu option: ";
    cin>>menuChoice;
    //loop for invalid input
    while(menuChoice!=1 && menuChoice!=2){
      cout<<"Please enter a valid menu option: ";
      cin>>menuChoice;
    }
    cout<<endl;
    if(menuChoice==1){
      //toss the coin, ask for guess, display result, and tally score
      cout<<"Game of Coin Toss"<<endl;
      playerNum=getUserSelection();
      coinNum=toss();
      winner=determineWinner(playerNum, coinNum);
      if(winner==1){
        win++;
      }
      else{
        lose++;
      }
      cout<<endl;
    }
    else{
    //user chooses to leave, display results and message
    cout<<"Exit"<<endl;
      cout<<"Wins: "<<win<<endl;
      cout<<"Losses: "<<lose<<endl;
      cout<<"Good Game!"<<endl;
      break;
    }
  }
  return 0;
}
