#include <iostream>
#include <fstream>
#include <string>
#include"game.h"

using namespace std;
void Creature::getPosition(int& a_row, int& a_col){
    a_row=row;
    a_col=col;
} // get pacman position in maze and store in a_row, a_col
void Creature::showCreaturePosition(){
	cout<<"Pacman at position ("<<row<<","<<col<<")"<<endl;
  }
void Creature::setPosition(int a_row, int a_col){
		row=a_row;
		col=a_col;
	}
void Creature::addPoints(int a_point){
		points+=a_point;
	} // add points collected
void Creature::showCurrentPoints(){
		printf("Your collected points =%d\n",points);
	}// show collected reward points
    
void Maze::showMazeProperty(){
		
        cout<<"Num rows= "<<numRow<<endl;
        cout<<"Num columns= "<<numCol<<endl;
        cout<<endl;
        
        for(int i=0;i<numRow;i++)
		{for(int j=0;j<numCol;j++){
			cout<<mat[i][j];}
        	cout<<endl;
		}
	}
         // display the maze 2D matrix stored in mat
void Maze::readMaze(){
		string myText;

	// Read from the text file
	ifstream MyReadFile("maze.txt");
	int r = 0;
	// Use a while loop together with the getline() function to read the file line by line
	cout << "\n Reading maze and allocate memory for maze array \n\n";
	while (getline(MyReadFile, myText)) {
		// Output the text from the file
		//cout << myText << endl;
		r++;
	}
	numRow = r;
	numCol = myText.length();
	// Close the file
	MyReadFile.close();

	// allocate memory
	mat = new int*[numRow];
	for (int i = 0; i < numRow; i++)
		mat[i] = new int[numCol];

	// Read from the text file to read maze content
	MyReadFile.open("maze.txt");
	r = 0;
	// Use a while loop together with the getline() function to read the file line by line
	while (getline(MyReadFile, myText)) {
		// Output the text from the file
		for (unsigned i = 0; i<myText.length(); ++i)
		{
			mat[r][i] = (int)myText.at(i) - 48;
		}
		r++;
	}

	// Close the file
	MyReadFile.close();



	}// read maze from text file and populate ma    
void Maze::drawMaze(){
		system("cls");
        for(int i=0;i<numRow;i++){
            for(int j=0;j<numCol;j++){
                if(mat[i][j]==1)
                cout<<"|";
                else if(mat[i][j]==0)
                cout<<" ";
                else if(mat[i][j]==2)
                cout<<"*";
                else if(mat[i][j]==3)
                cout<<"P";
            }
            cout<<endl;
        }
    }
void Maze::deleteMaze(){
	for(int i=0;i<numRow;i++){
	delete [] mat [i];
	}

	delete [] mat ;
}
void Maze::updateMaze(Creature p, int row_, int col_){
int a_row,a_col;
p.getPosition(a_row,a_col);
mat[a_row][a_col] = 0;
mat[row_][col_] = 3;
}
bool Maze::isValidMove(int nrow, int ncol){
	if(nrow>6 || ncol>12){
		return false;
	}
	else if(mat[nrow][ncol]==1){
		return false;
	}
	else if(ncol==-1)
	return false;
	else if(ncol==12)
	return false;
	else return true;
	return 1;
}
void Maze::placeCreatureInMaze(Creature p){
		int a_row,a_col;
        p.getPosition(a_row,a_col),mat[a_row][a_col]=3;
        }
int  Maze::getReward(int r, int c){
	if(mat[r][c]==2){
		return 1;
	}
	else return 0;
}
void CGame::checkMove(char move, Maze& a_maze , Creature& a_creature){
	int a_row,a_col;
	a_creature.getPosition(a_row,a_col);
	if(move=='w')
    {
		if(a_maze.isValidMove(a_row-1,a_col)==true)
        {
			a_creature.addPoints(a_maze.getReward(a_row-1,a_col));
			a_maze.updateMaze(a_creature,a_row-1,a_col);
			a_creature.setPosition(a_row-1,a_col);
		}
    }   
    else if (move=='a'){
		if(a_maze.isValidMove(a_row,a_col-1)==true){
			a_creature.addPoints(a_maze.getReward(a_row,a_col-1));
			a_maze.updateMaze(a_creature,a_row,a_col-1);
			a_creature.setPosition(a_row,a_col-1);
	    }
    }
        else if(move=='d'){
            if(a_maze.isValidMove(a_row,a_col+1)==true){
			a_creature.addPoints(a_maze.getReward(a_row,a_col+1));
			a_maze.updateMaze(a_creature,a_row,a_col+1);
			a_creature.setPosition(a_row,a_col+1);
	    }
        }
        else if(move=='z'){
            if(a_maze.isValidMove(a_row+1,a_col)==true){
			a_creature.addPoints(a_maze.getReward(a_row+1,a_col));
			a_maze.updateMaze(a_creature,a_row+1,a_col);
			a_creature.setPosition(a_row+1,a_col);
	    }
        }
}
int main() {
    CGame game1;
    Maze m1; // init and allocate memory
    m1.readMaze();
    m1.showMazeProperty();
    m1.drawMaze();
    Creature p(1, 3, 1); // starting position of pacman in maze at(1,3) where type=1 is pacman
    m1.placeCreatureInMaze(p);
    m1.drawMaze();
    bool status;
    char move='y';
    while (move != 'q')
     {
        m1.drawMaze();
        m1.showMazeProperty();
        p.showCurrentPoints();
        p.showCreaturePosition();
        cout << endl << "enter move >> ";
        cin >> move;
        // check if move is valid in the maze
        game1.checkMove(move, m1, p); // if it is valid, update the pacman position and update maze
        m1.showMazeProperty();
    
    }
    m1.deleteMaze();
    system("pause");
    return 1;
}














