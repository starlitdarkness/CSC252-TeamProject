#include <stdio.h>
#include <ostream>
#include "Robot.h"
#include <iostream>
using namespace std;

Robot::Robot() {}
Robot::Robot(int xLocation, int yLocation, bool cargoBed, char load)
{
    this->xLocation = xLocation;
    this->yLocation = yLocation;
    this->cargoBed = cargoBed;
    this->load = load;
}
int Robot::getxLocation() const
{
    return xLocation;
}
void Robot::setxLocation(int xLocation)
{
    this->xLocation = xLocation;
}
int Robot::getyLocation() const
{
    return yLocation;
}
void Robot::setyLocation(int yLocation)
{
    this->yLocation = yLocation;
}
bool Robot::getcargoBed() const
{
    return cargoBed;
}
void Robot::setcargoBed(bool cargoBed)
{
    this->cargoBed = cargoBed;
}
char Robot::getLoad() const
{
    return load;
}
void Robot::setLoad(char load)
{
    this->load = load;
}

//moveto function here//
bool Robot::moveTo(int lx, int ly, char grid[10][10])
{
    cout << "Moving robot from (" << getxLocation() << ", " << getyLocation() << ")" << " to " << " (" << lx << ", " << ly << ") ..." << endl;
    for (int i = 0; i < lx; i++)
    {
        xLocation = xLocation + 1;
        cout << " Robot is at (" << xLocation << ", " << yLocation << ")" << endl;
    }

    for (int j = 0; j < ly; j++)
    {
        yLocation = yLocation + 1;
        cout << " Robot is at (" << xLocation << ", " << yLocation << ")" << endl;

    }


    if ((lx == xLocation) & (ly == yLocation))
        return false;
    else
        return true;

}



//pickup funcion//
bool Robot::pickUp(int lx, int ly, char grid[10][10])
{
    if (grid[lx][ly] != '.' && cargoBed == false && load == '.')
    {
        moveTo(lx, ly, grid);
        load = grid[lx][ly];
        cargoBed = true;
        grid[lx][ly] = '.';
        return true;
    }
    return false;
}


//drop off function here//
bool Robot::dropOff(int lx, int ly, char grid[10][10])
{

}

//print grid function
void print2D()
{

}

ostream& operator<<(ostream& out, Robot& robot)
{
    out << "(" << robot.getxLocation() << ", " << robot.getyLocation() << ") :" << robot.getLoad() << endl;
    return out;
}

//destructor//
Robot::~Robot() {}






int main()
{

    return 0;
}
