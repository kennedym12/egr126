#include <iostream>
using namespace std;
//x = rand()%(high value -low value +1) + low
/*Write a program that displays 3 destinations and their distances from macon, asks the user to pick 1, asks the user to input their travel speed, and gives travel time */
//Kennedy A. Mays
//March 4, 2021

int main() {
  //introduction and travel options
  cout<<"Welcome to the travel app!"<<endl;
  cout<<endl;
  cout<<"Destination      Miles from Macon"<<endl;
  cout<<"*********************************"<<endl;
  cout<<"Atlanta                83.9 Miles"<<endl;
  cout<<"Tallulah              175.4 Miles"<<endl;
  cout<<"Washington DC         670.2 Miles"<<endl;
  cout<<"*********************************"<<endl;
  cout<<endl;

  //variables include choice, speed, hours and minutes of travel, distance, and the strings for hour/hours
  int choice, speed, hr, min;
  double distance;
  string destination, hrvhrs;
  while(choice!=4){
    //options
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<"Options:"<<endl;
    cout<<"1. Macon to Atlanta, GA"<<endl;
    cout<<"2. Macon to Washington, D.C."<<endl;
    cout<<"3. Macon to Tallulah Falls, GA"<<endl;
    cout<<"4. Exit Program"<<endl;
    cout<<endl;
    //prompt user for choice
    cout<<"Select an option: ";
    cin>>choice;
    if(choice!=4){
      //information for choice
      if(choice==1){destination = "Atlanta, GA"; distance=83.9;}
      else if(choice==2){destination = "Washington, DC"; distance=175.4;}
      else{destination = "Tallulah Falls, GA"; distance=670.2;}
      cout<<"Great choice! You have chosen to travel to "<<destination<<"."<<endl<<"It's a distance of "<<distance<<" miles. "<<endl;
      cout<<endl;
      //prompt user for avg speed
      cout<<"Enter your average travel speed: ";
      cin>>speed;
      hr = distance/speed;
      min = (int)distance%speed;
      if(hr>1){hrvhrs="hours";}
      else{hrvhrs="hour";}
      //travel time information
      cout<<"It will take "<<hr<<" "<<hrvhrs<<" and "<<min<<" minutes to get to "<<destination<<"."<<endl;
      cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
      cout<<endl;
    }
    else{cout<<"Thank you for using the travel app!"<<endl;}
  }
}