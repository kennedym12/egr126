#include <iostream>
#include <ctime>
#include <time.h>
using namespace std;
/*Write a multiplication program with three levels of difficulty. There should be functions for each level, the menu, avgScore, and the letter grade*/
//May 4, 2021
//Kennedy A. Mays

//universal variables
int x,y,problems,answer,points;
int choice=0;
double avg;
char letter;

//functions
void menu(){
  cout<<"Menu"<<endl;
  cout<<"1. Beginner"<<endl;
  cout<<"2. Intermediate"<<endl;
  cout<<"3. Advanced"<<endl;
  cout<<"4. Exit"<<endl;
  cout<<"Choice: ";
}

void beginnerQuiz(int num){
  //loop for the requested num of problems
  for(int i=0; i<num; i++){
    //generate numbers
    x=rand()%10+1;
    y=rand()%5+1;
    //display problem and get input
    cout<<x<<" x "<<y<<endl;
    cout<<"Anwer: ";
    cin>>answer;
    //update points
    if(answer==x*y){
      cout<<"Your answer is correct. \n+1pt"<<endl;
      points++;
    }
    else{
      cout<<"Your answer is incorrect. \n+0pts"<<endl;
    }
    cout<<endl;
  }
}

void intermediateQuiz(int num){
  //loop for the requested num of problems
  for(int i=0; i<num; i++){
    //generate numbers
    x=rand()%11+10;
    y=rand()%10+1;
    //display problem and get input
    cout<<x<<" x "<<y<<endl;
    cout<<"Anwer: ";
    cin>>answer;
    //update points
    if(answer==x*y){
      cout<<"Your answer is correct. \n+1pt"<<endl;
      points++;
    }
    else{
      cout<<"Your answer is incorrect. \n+0pts"<<endl;
    }
    cout<<endl;
  }
}

void advancedQuiz(int num){
  //loop for the requested num of problems
  for(int i=0; i<num; i++){
    //generate numbers
    x=rand()%11+20;
    y=rand()%11+10;
    //display problem and get input
    cout<<x<<" x "<<y<<endl;
    cout<<"Anwer: ";
    cin>>answer;
    //update points
    if(answer==x*y){
      cout<<"Your answer is correct. \n+1pt"<<endl;
      points++;
    }
    else{
      cout<<"Your answer is incorrect. \n+0pts"<<endl;
    }
    cout<<endl;
  }
}

void solveAvg(){
  avg=(points*100)/problems;
}

void getLetterGrade(){
  if(avg>89){
    letter='A';
  }
  else if(avg>79){
    letter='B';
  }
  else if(avg>69){
    letter='C';
  }
  else if(avg>59){
    letter='D';
  }
  else{
    letter='F';
  }
}

int main() {
  srand(time(NULL));
  //inital introduction
  cout<<"**************************************"<<endl;
  cout<<"Welcome to the Multiplication Program!"<<endl;
  cout<<"**************************************"<<endl;
  cout<<"There's 3 levels of difficulty to choose from. From there pick the number of problems. Enter the correct answer to earn a point. Accuracy information will be displayed at the end of each set."<<endl;
  cout<<endl;
  //loop until the user selects exit
  while(choice!=4){
    //prompt for 
    menu();
    cin>>choice;
    if(choice!=4){
      cout<<"How many problems would you like to complete?"<<endl;
      cin>>problems;
      cout<<endl;
    }
    //reset points
    points=0;
    //switch statement for quizzes
    switch (choice){
      case 1:
      beginnerQuiz(problems);
      break;
      case 2:
      intermediateQuiz(problems);
      break;
      case 3:
      advancedQuiz(problems);
      break;
      case 4:
      break;
    }
    //display stats
    if(choice!=4){
      cout<<endl;
      solveAvg();
      getLetterGrade();
      cout<<"**********"<<endl;
      cout<<"Your Stats"<<endl;
      cout<<"**********"<<endl;
      cout<<"You got "<<points<<" points out of "<<problems<<" possible."<<endl;
      cout<<"Your score percentage is: "<<avg<<"%"<<endl;
      cout<<"Your letter grade is: "<<letter<<endl;
      cout<<endl;
    }
  }
  //outro
  cout<<endl;
  cout<<"Thank you for using the Multiplication Program!\nHave a nice day!"<<endl;
}