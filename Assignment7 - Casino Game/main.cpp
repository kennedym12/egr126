#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
/*simulates a casino slot machine */
//March 22, 2021
//Arthur Campomanes and Kennedy Mays
int main() {
  //introduction
  cout<<"*******************"<<endl;
  cout<<"Welcome to Casino 7"<<endl;
  cout<<"*******************"<<endl;
  cout<<endl;
  //more information
  double deposit;
  cout<<"The minimum cost to play is $50.00."<<endl;
  cout<<"The goal is to get 3 of the same values in a row between 1 and 10 to double your balance."<<endl;
  cout<<"Each spin costs $1.00."<<endl;
  cout<<"The game ends when your balance reaches $0 or you roll 3 of the exact same value."<<endl;
  //prompt user to deposit at least $50.00 until the min amount is deposited
  cout<<"Please enter amount of bet: $";
  cin>>deposit;
  while(deposit<50){
    cout<<"The minimum cost to play is $50.00."<<endl;
    cout<<"Please enter amount of bet: $";
    cin>>deposit;
  }
  cout<<endl;
  //lever is pulled, numbers are generated and deposit changes
  bool sameNum;
  int a,b,c;
  srand (time(NULL));
  while(deposit>0){
    //deduct $1 to pull lever
    deposit-=1;
    //pull lever (generate 3 random numbers)
    a = rand()%9+1;
    b = rand()%9+1;
    c = rand()%9+1;
    cout<<"Pull: "<<a<<", "<<b<<", "<<c<<endl;
    //check if they're the same
    if(a==b and b==c){sameNum=true;}
    //apply winning multiplier to bet if applicable
    if(sameNum && a!=7){
      deposit*=2;
      cout<<"You Win!"<<endl;
      break;
      }
    else if(sameNum && a==7){
      deposit*=100;
      cout<<"You Win!"<<endl;
      break;
      }
    }
    //display the final balance
    cout<<"Your balance is $"<<deposit<<"."<<endl;
    if(!sameNum){
      cout<<"Game Over!"<<endl;
  }
}