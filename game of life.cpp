/*
Name::mohamed Tarek Abdelsattar
ID::20210343
Q5::Game_Of_Life
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
using namespace std;

class Universe
{
    bool game[20][20];
public:
    int rows = 20;
    Universe(bool GOF[20][20])
    {
        for (int i = 0; i < rows; i++)
        {
            for(int j = 0; j < rows; j++)
            {
                game[i][j] = GOF[i][j];
            }
        }
    }
    Universe(){}
    void initialize(); //generates a starting layout
    void reset(); //sets all the cells as dead.
    int count_neighbors(); //returns the number of alive neighbors.
    void next_generation(); //produces a new state of the game based on the transition rules.
    void display(); //shows the game status on the console (It is better to erase screen and rewrite, and NO it is console, no graphics is needed)
    void run(); //to start the game for a certain number of runs

};

int main()
{
    Universe o1;
    o1.run();
}
int Universe :: count_neighbors(){
    int counter = 0;
    for(int i = 0;i < rows;i++){
        for(int j = 0;j < rows;j++){
            if(game[i][j] == true)
                counter++;
        }
    }
    return counter;
}
void Universe :: reset(){
    int counter = 0;
    for(int i = 0;i < rows;i++){
        for(int j = 0;j < rows;j++){
            game[i][j] = false;
        }
    }
}
void Universe :: display(){

    cout<<"\t";
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < rows; j++)
        {
            if(game[i][j] == true)
                cout<<"$ ";
            else
                cout<<". ";
        }
        cout<<endl<<"\t";
    }

}
void Universe :: next_generation(){
    bool temp_arr[rows][rows];
    for (int i = 0; i < rows; i++)
    {
        for(int j = 0; j < rows; j++)
        {
            temp_arr[i][j] = game[i][j];
        }
    }
    for(int i = 0;i < rows;i++){
        for(int j = 0;j < rows;j++){
            int counter = 0;
            //first row
            if(i == 0 && j != 0 && j != rows-1){
                if(game[i][j-1] == true)
                    counter++;
                if(game[i][j+1] == true)
                    counter++;
                if(game[i+1][j-1] == true)
                    counter++;
                if(game[i+1][j] == true)
                    counter++;
                if(game[i+1][j+1] == true)
                    counter++;
            }
            //first colm
            else if(j == 0 && i != 0 && i != rows-1){
                if(game[i][j+1] == true)
                    counter++;
                if(game[i-1][j] == true)
                    counter++;
                if(game[i+1][j] == true)
                    counter++;
                if(game[i-1][j+1] == true)
                    counter++;
                if(game[i+1][j+1] == true)
                    counter++;
            }
            //last row
            else if(i == rows-1 && j != 0 && j != rows-1){
                if(game[i][j+1] == true)
                    counter++;
                if(game[i][j-1] == true)
                    counter++;
                if(game[i-1][j] == true)
                    counter++;
                if(game[i-1][j+1] == true)
                    counter++;
                if(game[i-1][j-1] == true)
                    counter++;
            }
            //last colm
            else if(j == rows-1 && i != 0 && i != rows-1){
                if(game[i][j-1] == true)
                    counter++;
                if(game[i-1][j] == true)
                    counter++;
                if(game[i-1][j-1] == true)
                    counter++;
                if(game[i+1][j+1] == true)
                    counter++;
                if(game[i+1][j-1] == true)
                    counter++;
            }
            /*
            boundres
            */
            else if(i == 0 && j == 0){
                if(game[i][j+1] == true)counter++;
                if(game[i+1][j] == true)counter++;
                if(game[i+1][j+1] == true)counter++;
            }
            else if(i == rows-1 && j == 0){
                if(game[i-1][j])counter++;
                if(game[i-1][j+1])counter++;
                if(game[i][j+1])counter++;
            }
            else if(i == 0 && j == rows-1){
                if(game[i][j-1] == true)counter++;
                if(game[i+1][j] == true)counter++;
                if(game[i+1][j-1] == true)counter++;
            }
            else if(i == rows-1 && j == rows-1){
                if(game[i][j-1] == true)counter++;
                if(game[i-1][j] == true)counter++;
                if(game[i-1][j-1] == true)counter++;
            }
            //the middle of table
            else {
                if(game[i-1][j-1] == true)
                    counter++;
                if(game[i-1][j] == true)
                    counter++;
                if(game[i-1][j+1] == true)
                    counter++;
                if(game[i][j-1] == true)
                    counter++;
                if(game[i][j+1] == true)
                    counter++;
                if(game[i+1][j-1] == true)
                    counter++;
                if(game[i+1][j] == true)
                    counter++;
                if(game[i+1][j+1] == true)
                    counter++;

            }
            if(game[i][j] == true && (counter == 2 || counter == 3)){
                    temp_arr[i][j] = true;
            }
            else if(game[i][j] == false && counter == 3){
                    temp_arr[i][j] = true;
            }
            else
                temp_arr[i][j] = false;


        }
    }


    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < rows; j++)
        {
            game[i][j] = temp_arr[i][j];
        }
    }


}
void Universe :: initialize(){
    //to make random choice between true or false
    //using time() that change every second
    srand(time(0));
    for (int i = 0; i < rows; i++)
    {
        for(int j = 0; j < rows; j++)
        {
            game[i][j] = rand()%2;
        }
    }
}
void Universe :: run(){
    int counter,n;
    cout<<"how many generations do you want : ";
    cin>>counter;
    cout<<"press space\n";
    for(int i = 1; i < counter+1 ; i++){
        if(i == 0){
            initialize();
        }
        else{
            next_generation();
        }
        string buttom;
        //cin for buttom but it doesn't show what is the output
        buttom = getch();
        if(i == 0){
            cout<<"\npress space to continue";
            cout<<"if you want to Quit press q\n";
        }
        if(buttom == " "){
            //to clear the screen
            system("cls");
            cout<<"this is generation "<<i<<" / "<<counter<<"\n";
            cout<<"neighbors = "<<count_neighbors()<<endl<<endl;
            display();
            cout<<"\npress space to continue";
            cout<<"\npress r to reset the table\n";
            cout<<"press q to Quit\n";

        }
        else if(buttom == "r"){
            //to clear the screen
            system("cls");
            reset();
            cout<<"this is generation "<<i<<" / "<<counter;
            cout<<"\n\nneighbors = "<<count_neighbors()<<endl<<endl;
            display();
            cout<<"\npress space to continue";
            cout<<"\npress r to reset the table\n";
            cout<<"press q to Quit\n";

            initialize();
        }
        else if (buttom == "q")
            exit(0);
        cout<<endl;
    }

}
