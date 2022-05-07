#include <iostream>
#include<stdlib.h>
#include <time.h>
using namespace std;
/*A5  - Guess the secret number using 3 attempts. Give the user hints for values entered between 1 and 10. If statements, while loops, count attempts, and a random number. Check for valid input within the range. Invalid input counts as an attempt if the user already entered valid input.*/
//Kennedy A. Mays
//February 25, 2021

int main() {
  //alternate code
  cout<<"************************"<<endl;
  cout<<"Guess the secret number!"<<endl;
  cout<<"************************"<<endl;
  cout<<endl;
  //generate a random secret number in the range of 1-10
  srand(time(NULL)); 
  int sn = rand()%10+1;
  //or set the secret numbeer equal to 3
  //int = 3;
  int guess;
  int attempts = 1;
  cout<<"Enter a number between 1 and 10: ";
  cin>>guess;
  //loops through until the user guesses correctly or uses up attempts
  while(guess!=sn && attempts<3){
    //prompts user for a valid number and only adds to the attempts if the user previously entered a valid number
    if(guess<1 || guess>10){
      cout<<"!Invalid Range!"<<endl;
      cout<<endl;
      if(guess<0){
        cout<<"Enter a positive valid number between 1 and 10: ";
      }
      else{
        cout<<"Enter a valid number between 1 and 10: ";
      }
      if(attempts>1){
        attempts++;
      }
    }
    //gives hints after entering a valid number
    else if(guess<sn){
      cout<<"Too low"<<endl;
      cout<<endl;
      attempts++;
      cout<<"Enter a number between 1 and 10: ";
    }
    else{
      cout<<"Too high"<<endl;
      cout<<endl;
      attempts++;
      cout<<"Enter a number between 1 and 10: ";
    }
    //allows the user to guess again
    cin>>guess;
    
  }
  //once the user reaches this point, they either guessed correctly or ran out of attempts
  cout<<endl;
  if(guess==sn){
    cout<<"You guessed the secret number!"<<endl;
  }
  else{
    cout<<"You ran out of attempts. The secret number was "<<sn<<"."<<endl<<"Goodbye!"<<endl;
  }
}