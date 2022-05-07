#include <iostream>
using namespace std;
/*Grade average program receive input on the number of grades to be entered and the points earned*/
//March 18, 2021
//Kennedy A. Mays

int main() {
  //declaration of variables
  int grades, points, maxpts, totalpts;
  double avg, percent;
  char letter;
  string avan;
  //intro
  cout<<"*************************************"<<endl;
  cout<<"Welcome to the Grade Average Program!"<<endl;
  cout<<"*************************************"<<endl;
  cout<<endl;
  cout<<"Enter the number of grades you want to enter: ";
  cin>>grades;
  maxpts = grades*20;
  cout<<"Now enter the points earned for each grade, 1-20: "<<endl;
  //loop through entering (valid) points for each grade
  for(int i=1; i<=grades; i++){
    cin>>points;
    if(points>20 || points<1){//checks for invalid range
      bool valid=false;//records that it's invalid
      while(valid==false){//loops until a valid number is entered
        cout<<"Please enter points within the valid range, 1-20"<<endl;
        cin>>points;
        if(points<=20 && points>=1){valid=true;}
      }
    }
      totalpts+=points;
  }
  cout<<endl;
  //avg points earned on assignments
  avg = (double)totalpts/grades;
  cout<<"Your average grade is: "<<avg<<"/20 points"<<endl;
  //percent grade in class
  percent = (totalpts*100 / maxpts);
  cout<<"Your percent grade is: "<<percent<<"%"<<endl;
  //letter grade in the class
  if(percent>=90){letter='A';avan="an";} 
  else if(percent>=80){letter='B';avan="a";}
  else if(percent>=70){letter='C';avan="a";}
  else if(percent>=60){letter='D';avan="a";}
  else{letter='F';avan="a";}
  cout<<"Your letter grade is "<<avan<<" "<<letter<<endl;
}