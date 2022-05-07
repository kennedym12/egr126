#include <iostream>
using namespace std;
//program will simulate the functions of a cash register
//February 18, 2021
//Kennedy A. Mays

int main() {
  //needed variables (item quantity, item price, total cost, payment, & change)
  int ffq, bq, dq, mmq;
  double ff=0.99, b=2.25, d=0.99, mm=3.99;
  double tc,p,c;

  //Order prompt
  cout<<"************************"<<endl;
  cout<<"*Welcome to Burger Cafe*"<<endl;
  cout<<"************************"<<endl;
  cout<<endl;
  cout<<"Menu"<<endl;
  cout<<"French Fries: $.99 | Burgers: $2.25 | Drinks: $.99 | Mighty Meal $3.99 (Includes 1 French Fry, 1 Burger, 1 drink)"<<endl;
  cout<<"Enter your order:"<<endl;
  cout<<endl;

  //user inputs their order
  cout<<"Enter french fry quantity: ";
  cin>>ffq;
  cout<<"Enter burger quantity: ";
  cin>>bq;
  cout<<"Enter drink quantity: ";
  cin>>dq;
  cout<<"Enter mighty meal quantity: ";
  cin>>mmq;
  cout<<endl;

  //receipt prompt (gives price break down and money back)
  cout<<"**************"<<endl;
  cout<<"*Your Receipt*"<<endl;
  cout<<"**************"<<endl;
  cout<<"French Fry Quantity: "<<ffq<<" = $"<<ffq*ff<<endl;
  cout<<"Burger Quantity: "<<bq<<" = $"<<bq*b<<endl;
  cout<<"Drink Quantity: "<<dq<<" = $"<<dq*d<<endl;
  cout<<"Mighty Meal Quantity: "<<mmq<<" = $"<<mmq*mm<<endl;
  tc=(ffq*ff)+(bq*b)+(dq*d)+(mmq*mm);
  cout<<endl;
  cout<<"Your total cost: $"<<tc<<endl;
  cout<<"Your payment: $";
  cin>>p;
  cout<<"Your change: $"<<p-tc<<endl;
  cout<<"Thank you! Come again."<<endl;
  return 0;
}