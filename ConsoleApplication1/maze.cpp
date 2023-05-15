/* Kinan Haj Rashid
* 4 / oktober / 2021
* Betyg: E
*/
#include "maze.h"

int Maze::bringX() {
    return myVec.size(); //retunerar stoleken på vektors längd
}

int Maze::bringY() {
    return myVec[0].size(); // retunerar storleken på vekros bredd
}

Maze::node::node(int x, int y) {// difinerar nods objekter
    this->x = x; 
    this->y = y;
    cell = 'X';
    IsVisited = false; // för besökta noder DEFAULT
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
    int y = rand() % (myVec[0].size() - 2); // range for y - vector size från början -2 (  )

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

std::vector<Maze::node> Maze::possible_neighbour(int x, int y) { // check för vilka möjliga grannar

    std::vector<node>neighbours2;

    if ((Inside_the_maze(x - 2, y)) && !(myVec[x - 2][y].IsVisited )) { //uppåt
        neighbours2.push_back(myVec[x - 2][y]);
    }
    if ((Inside_the_maze(x, y + 2) && !(myVec[x][y + 2].IsVisited ))) {//höger
        neighbours2.push_back(myVec[x][y + 2]);

    }
    if ((Inside_the_maze(x + 2, y) && !(myVec[x + 2][y].IsVisited))) { //neråt
        neighbours2.push_back(myVec[x + 2][y]);
    }
    if ((Inside_the_maze(x, y - 2) && !(myVec[x][y - 2].IsVisited ))) { //vänsteråt
        neighbours2.push_back(myVec[x][y - 2]);
    }

    return neighbours2;
}

Maze::node Maze::randomgranne(std::vector<node>const c) { // random möjlig granne 

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


bool Maze::Inside_the_maze(int x, int y) { // in the maze IsVisited för att inte nå väggarna från alla sidor

    if (x <= 0 || y <= 0 || y >= myVec[0].size() || x >= myVec.size()) {
        return false;
    }
    return true; // om ingen av ovan stämmer då finns noden
}

void Maze::generate() { //DFS 
   
    std::stack<node>stack; 
    std::vector<node>neighbour;
    Start();

    int p = randomX(); //tilldelar random siffra till att byta x kordinater
    int k = randomY(); // y kord
    node current = node(p, k); //startar nod med random kord

    stack.push(current); // pushar första noden till stacken
    myVec[current.x][current.y].IsVisited = true;
    myVec[current.x][current.y].cell = ' ';


    while (!stack.empty())
    {
        current = stack.top(); //använder det elemntet som finns längst upp
        stack.pop(); //poppar den (tabort)

        neighbour = possible_neighbour(current.x, current.y); //tar in alla möjliga grannar till en vektor
        
        if (!neighbour.empty()){

            stack.push(current); 

            node nextCurrent = randomgranne(neighbour); //tilldelar en random nod för att bli som en granne nod

            if (current.y != nextCurrent.y) {
                if (nextCurrent.y > current.y) {//Höger åt
                    myVec[current.x][current.y + 1].cell = ' ';
                }
                if (nextCurrent.y < current.y) {//Vänster åt
                    myVec[current.x][current.y - 1].cell = ' ';
                }
            }
            else{
                if (nextCurrent.x < current.x) { //Uppåt
                    myVec[current.x - 1][current.y].cell = ' ';
                }
                if (nextCurrent.x > current.x) // Neråt 
                {
                    myVec[current.x + 1][current.y].cell = ' ';
                }
            }
            current.IsVisited = true;
            myVec[nextCurrent.x][nextCurrent.y].cell = ' '; // efter IsVisited (check) lämna en 'space' ist för *
            myVec[nextCurrent.x][nextCurrent.y].IsVisited = true;
            stack.push(nextCurrent);
        }
    }
}




