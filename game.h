class Creature {
	int row; // position of creature object (Pacman) in maze
	int col;
	int type; // 1 indicate pacman
	int points=0;
public:
	Creature() {}
	Creature(int a_row, int a_col , int a_type) {
		row = a_row;
		col = a_col;
		type = a_type;
	}
	void getPosition(int& a_row, int& a_col); // get pacman position in maze and store in a_row, a_col
	void showCreaturePosition();
	void setPosition(int a_row, int a_col);
	// update based on new position nrow, ncol
	void addPoints(int a_point); // add points collected
	void showCurrentPoints(); // show collected reward points
};

//Maze
class Maze {
	int numRow;
	int numCol;
	int** mat; // 2D matrix that stores the maze

    public:
	Maze() {}
	void showMazeProperty(); // display the maze 2D matrix stored in mat
	void readMaze(); // read maze from text file and populate mat
	void drawMaze();
	void deleteMaze(); // release memory
	// update maze based on location of pacman object p and its previous location
	void updateMaze(Creature p, int row_, int col_);
	bool isValidMove(int nrow, int ncol); // Check if the move to new location (nrow,ncol) is valid
	void placeCreatureInMaze(Creature p); // Position pacman object p into the maze
	// return points as reward if move into food at location (r,c)
	int getReward(int r, int c);
};
//Game
class CGame {
public:
	// check if the move by creature (pacman) is valid or not. if valid update // location of pacman and maze property
	void checkMove(char move, Maze& a_maze , Creature& a_creature);

};

