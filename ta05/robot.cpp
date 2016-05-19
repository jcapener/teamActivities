#include "robot.h"
#include <iostream>
using namespace std;

/************************************
 * Function: Display
 * Purpose: Displays the robot.
 ************************************/
void Robot :: display() const
{
   position.display();
   cout << " - Energy: " << getEnergy();
}

void Robot :: moveUp()
{
   if (energyIsValid(10))
   {
      position.setY(position.getY() + 1);
      if (positionIsSafe())
         setEnergy(getEnergy() - 10);
      else
         setEnergy(0);
   }
   else
      cout << "ERROR: Not enough energy!\n"
           << "       Action was aborted!\n";
}

void Robot :: moveDown()
{
   if (energyIsValid(10))
   {
      position.setY(position.getY() - 1);
      if (positionIsSafe())
         setEnergy(getEnergy() - 10);
      else
         setEnergy(0);
   }
   else
      cout << "ERROR: Not enough energy!\n"
           << "       Action was aborted!\n";
}

void Robot :: moveLeft()
{
   if (energyIsValid(10))
   {
      position.setX(position.getX() - 1);
      if (positionIsSafe())
         setEnergy(getEnergy() - 10);
      else
      {
         cout << "ENERGY DEPLETED: Land Mine Hit!\n";
         setEnergy(0);
      }
   }
   else
      cout << "ERROR: Not enough energy!\n"
           << "       Action was aborted!\n";
}

void Robot :: moveRight()
{
   if (energyIsValid(10))
   {
      position.setX(position.getX() + 1);
      if (positionIsSafe())
         setEnergy(getEnergy() - 10);
      else
         setEnergy(0);
   }
   else
      cout << "ERROR: Not enough energy!\n"
           << "       Action aborted!\n";
}

void Robot :: fireLaser()
{
   if (energyIsValid(25))
   {
      setEnergy(getEnergy() - 25);
      cout << "Pew! Pew!\n";
   }
   else
      cout << "ERROR: Not enough energy!\n"
           << "       Action was aborted!\n";
}

bool Robot :: energyIsValid(int moveEnergy)
{
   if (energy > moveEnergy)
      return true;
   else
      return false;
}

bool Robot :: positionIsSafe()
{
   if (position.getX() == 3 && position.getY() == 3)
      return false;

   if (position.getX() == 4 && position.getY() == 4)
      return false;

   if (position.getX() == 6 && position.getY() == 6)
      return false;

   else
      return true;
}
