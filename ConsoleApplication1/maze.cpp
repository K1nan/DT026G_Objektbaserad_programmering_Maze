/* Kinan Haj Rashid
* 4 / oktober / 2021
* Betyg: E
*/
#include "maze.h"

int Maze::bringX() {
    return myVec.size(); //retunerar stoleken p� vektors l�ngd
}

int Maze::bringY() {
    return myVec[0].size(); // retunerar storleken p� vekros bredd
}

Maze::node::node(int x, int y) {// difinerar nods objekter
    this->x = x; 
    this->y = y;
    cell = 'X';
    IsVisited = false; // f�r bes�kta noder DEFAULT
}

Maze::Maze(int x, int y) { 

    this->i = x;
    this->j = y;
    add(i, j);
    generate();
}

Maze::Maze() { 
    add(11, 11);
    generate();
}

void Maze::print() {

    for (int x = 0; x < bringX(); x++) {
        for (int c = 0; c < bringY(); c++) {
            std::cout << myVec[x][c].cell;
        }
        std::cout << std::endl;
    }
}

void Maze::add(int x, int y) {

    for (int i = 0; i < x; i++) {
        std::vector<node> Vec;
        for (int c = 0; c < y; c++) {
            Vec.push_back(node(i, c));
        }
        myVec.push_back(Vec);
    }
    End();
}

void Maze::Start() {

    int x = 0;
    int y = rand() % (myVec[0].size() - 2); // range for y - vector size fr�n b�rjan -2 (  )

    while (y % 2 == 0) { 
        y = rand() % (myVec[0].size() - 2);
    }
    myVec[x][y].IsVisited = true;
    myVec[x][y].cell = 'S';
}

void Maze::End() {

    int x = myVec.size() - 1;
    int y = rand() % (myVec[0].size() - 2);

    while (y % 2 == 0) {
        y = rand() % (myVec[0].size() - 2);
    }
    myVec[x][y].cell = 'E';
    myVec[x][y].IsVisited = true;
}

std::vector<Maze::node> Maze::possible_neighbour(int x, int y) { // check f�r vilka m�jliga grannar

    std::vector<node>neighbours2;

    if ((Inside_the_maze(x - 2, y)) && !(myVec[x - 2][y].IsVisited )) { //upp�t
        neighbours2.push_back(myVec[x - 2][y]);
    }
    if ((Inside_the_maze(x, y + 2) && !(myVec[x][y + 2].IsVisited ))) {//h�ger
        neighbours2.push_back(myVec[x][y + 2]);

    }
    if ((Inside_the_maze(x + 2, y) && !(myVec[x + 2][y].IsVisited))) { //ner�t
        neighbours2.push_back(myVec[x + 2][y]);
    }
    if ((Inside_the_maze(x, y - 2) && !(myVec[x][y - 2].IsVisited ))) { //v�nster�t
        neighbours2.push_back(myVec[x][y - 2]);
    }

    return neighbours2;
}

Maze::node Maze::randomgranne(std::vector<node>const c) { // random m�jlig granne 

    int i = rand() % c.size();

    return c.at(i);
}

int Maze::randomX() {

    int x;

    x = rand() % (myVec.size() - 2);

    while (x % 2 == 0)
    {
        x = rand() % (myVec[0].size() - 2);
    }
    return x;
}

int Maze::randomY() {

    int y;
    y = rand() % (myVec[0].size() - 2);

    while (y % 2 == 0)
    {
        y = rand() % (myVec[0].size() - 2);
    }
    return y;
}


bool Maze::Inside_the_maze(int x, int y) { // in the maze IsVisited f�r att inte n� v�ggarna fr�n alla sidor

    if (x <= 0 || y <= 0 || y >= myVec[0].size() || x >= myVec.size()) {
        return false;
    }
    return true; // om ingen av ovan st�mmer d� finns noden
}

void Maze::generate() { //DFS 
   
    std::stack<node>stack; 
    std::vector<node>neighbour;
    Start();

    int p = randomX(); //tilldelar random siffra till att byta x kordinater
    int k = randomY(); // y kord
    node current = node(p, k); //startar nod med random kord

    stack.push(current); // pushar f�rsta noden till stacken
    myVec[current.x][current.y].IsVisited = true;
    myVec[current.x][current.y].cell = ' ';


    while (!stack.empty())
    {
        current = stack.top(); //anv�nder det elemntet som finns l�ngst upp
        stack.pop(); //poppar den (tabort)

        neighbour = possible_neighbour(current.x, current.y); //tar in alla m�jliga grannar till en vektor
        
        if (!neighbour.empty()){

            stack.push(current); 

            node nextCurrent = randomgranne(neighbour); //tilldelar en random nod f�r att bli som en granne nod

            if (current.y != nextCurrent.y) {
                if (nextCurrent.y > current.y) {//H�ger �t
                    myVec[current.x][current.y + 1].cell = ' ';
                }
                if (nextCurrent.y < current.y) {//V�nster �t
                    myVec[current.x][current.y - 1].cell = ' ';
                }
            }
            else{
                if (nextCurrent.x < current.x) { //Upp�t
                    myVec[current.x - 1][current.y].cell = ' ';
                }
                if (nextCurrent.x > current.x) // Ner�t 
                {
                    myVec[current.x + 1][current.y].cell = ' ';
                }
            }
            current.IsVisited = true;
            myVec[nextCurrent.x][nextCurrent.y].cell = ' '; // efter IsVisited (check) l�mna en 'space' ist f�r *
            myVec[nextCurrent.x][nextCurrent.y].IsVisited = true;
            stack.push(nextCurrent);
        }
    }
}




