#include <iostream>
using namespace std;
/*Stone Game, Start 10 -20 stones; In the two players alternate turns;Each turn, a player may take 1-3 stones from the pile;  Validate the appropriate amount of stones is taken (between 1-3 or the remaining stones less than three); The player forced to take the last stone loses. The game should be played a maximum of 5 times. After five games, determine the winner (player with the most wins) and end the game. Display the player with the most wins.*/
//April 22, 2021
//Arthur Campomanes, Kennedy Mays, Christian McGrath

int choice=1;
int stone, takeAway, count=0,p1Count=0, p2Count=0;
string p1,p2, check;
//functions

void menu()
{
    cout<<"\nMenu\n1. Play against another person to see who avoids taking the last stone\n2. Play against the computer\n3. Exit"<<endl;
    cin>>choice;
}

void switchPlayer()
{
    string temp = p2;
    p2 = p1;
    p1 = temp;
}
//player v player
void playGame()
{
    int stone;
    if(count == 0)
    {
        //prompt players for names and initial stone amount
        cout<<"Enter Name for player #1:  ";
        cin>>p1;
        check=p1;

        if(choice == 1)
        {
            cout<<"Enter Name for player #2:  ";
            cin>>p2;
        }
        else
        {
            p2 = "Computer";
        }
    }
    //initiates
    cout<<"Enter the number of stones (10 to 20):  ";
    cin>>stone;

    //loops until user enters acceptable amount
    while(stone<10||stone >20)
    {
        cout<<"Choose a number between 10 and 20: ";
        cin>>stone;
    }


    //users taking turns removing stones
    while(stone >0)
    {
        cout<<"\nHow many stones do you want to take?(1-3)\n"<<p1<<": ";
        cin>>takeAway;

        //loops until player enters valid input
        while(takeAway >3 || takeAway <1)
        {
            cout<<"invalid input, try a number between 1-3: ";
            cin>>takeAway;
        }

        //loops to make sure the player only takes available stones
        while(takeAway>stone)
        {
            cout<<"You cant take that many stones, there's only " << stone << " stone(s) left.";
            cin>>takeAway;
        }

        //takes away stones
        stone -= takeAway;
        cout<<"Number of stones: "<< stone<<endl;
        switchPlayer();
    }
    cout<<endl;
}
//player v computer
void playGame(string computer)
{
    int stone;
    if(count == 0)
    {
        //prompt players for names and initial stone amount
        cout<<"Enter Name for player #1:  ";
        cin>>p1;
        check=p1;
        p2 = "Computer";
        cout<<"Enter the number of stones (10 to 20):  ";
        cin>>stone;
    }
    //loops until user enters acceptable amount
    while(stone<10||stone >20)
    {
        cout<<"Choose a number between 10 and 20: ";
        cin>>stone;
    }


    //user and computer take turns removing stones
    while(stone >0)
    {
        cout<<"\nHow many stones do you want to take?(1-3)\n"<<p1<<": ";
        cin>>takeAway;

        //loops until player enters valid input
        while(takeAway >3 || takeAway <0)
        {
            cout<<"invalid input, try a number between 1-3";
            cin>>takeAway;
        }

        //loops to make sure the player only takes available stones
        while(takeAway>stone)
        {
            cout<<"You cant take that many stones, there's only " << stone << " stone(s) left.";
            cin>>takeAway;
        }

        //takes away stones
        stone -= takeAway;
        cout<<"Number of stones: "<< stone<<endl;
        if(stone>3 || stone <0)
        {
            int comp = rand()%3+1;
            cout<<"\nComputer: "<<comp<<endl;
            stone-=comp;
        }
        else if(stone>0)
        {
            int comp=rand()%stone+1;
            cout<<"\nComputer: "<<comp<<endl;
            stone-=comp;
        }
        else
        {
            switchPlayer();
            break;
        }
        cout<<"Number of stones: "<< stone<<endl;
    }
    cout<<endl;
}

void determineWinner()
{
    if(check==p1)
    {
        p1Count++;
    }
    else
    {
        p2Count++;
    }
    cout<<p1+ " wins the game!" << endl;
    count++;
}

int main()
{
    int stone;
    //introduction
    cout<<"Welcome to the Last Stone Game!\n*******************************"<<endl;
    cout<<endl;
    //initial menu display
    srand(time(NULL));
    //loops until player exits the game
    while(choice<3 && choice >0 && count<5)
    {
        menu();
        switch(choice)
        {
        //loops player v. player version
        case 1:
            cout<<"Player 1 v Player 2"<<endl;
            playGame();
            determineWinner();
            break;
        //loops through player v. computer
        case 2:
            cout<<"Player 1 v Computer"<<endl;
            playGame("computer");
            determineWinner();
            if(p1!=check)
            {
                switchPlayer();
            }
            break;
        }
    }
    if(p1!=check)
    {
        switchPlayer();
    }
    if(p1Count>p2Count)
    {
        cout<<p1 << " has the most wins of " << p1Count << " wins"<<endl;
    }
    else
    {
        cout<<p2 << " has the most wins of " << p2Count << " wins"<<endl;
    }
    cout<<"Goodbye!"<<endl;
    return 0;
}