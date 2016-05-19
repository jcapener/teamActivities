#ifndef ROBOT_H
#define ROBOT_H

#include "point.h"

#include <iostream>
#include <cassert>
using namespace std;

class Robot
{
   private:
      Point position;
      int energy;

   public:

      ////DEFAULT CONSTRUCTOR : default energy amount is 100.
      Robot() : energy(100) {assert(energy == 100);}

      //NON DEFAULT CONSTRUCTOR : take an integer energy amount
      Robot(int energy) {setEnergy(energy);}

      //NON DEFAULT CONSTRUCTOR :
      Robot(Point position, int energy)
      {
         setPosition(position);
         setEnergy(energy);
      }

      //ROBOT :: SET POSITION :
      void setPosition(Point position) {this->position = position;}

      //ROBOT :: SET ENERGY :
      void setEnergy(int energy)
      {
         if (energy > 0)
            this->energy = energy;
         else
            this->energy = 0;
      }

      //ROBOT :: GET POSITION :
      Point getPosition() const {return position;}

      //ROBOT :: GET ENERGY :
      int   getEnergy()   const {return energy;}

      void moveUp   ();
      void moveDown ();
      void moveLeft ();
      void moveRight();
      void fireLaser();

      bool energyIsValid(int moveEnergy);

      bool positionIsSafe();

      void display() const;

      ~Robot() {;}

};

#endif
