/* Kinan Haj Rashid
* 4 / oktober / 2021
* Betyg: E
*/
#ifndef HEADER_H
#define HEADER_H
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <sstream>

class Maze {

public:   
    Maze(int x, int y);
    Maze(); 
    void print();

private:
    struct node {
        node(int x, int y);
        int x, y;
        char cell; 
        bool IsVisited;
    };

    void add(int x, int y);
    void Start();
    void End();
    void generate();
    bool Inside_the_maze(int x, int y); //in the maze 
    int i, j = 11;
    int bringX();
    int randomX();
    int bringY();
    int randomY();
    node randomgranne(std::vector<node>const s);
    std::vector<Maze::node> possible_neighbour(int x, int y);
    std::vector<std::vector<node>> myVec;
 
};

#endif 