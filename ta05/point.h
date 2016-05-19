#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <cassert>
using namespace std;

class Point
{
   private:
      int x;
      int y;

   public:

      //DEFAULT CONSTRUCTOR : default location of the robot is at (5, 5)
      Point() : x(5), y(5)
      {
         assert(x == 5);
         assert(y == 5);
      }

      //NON-DEFAULT CONSTRUCTOR : set the default values
      Point (int x, int y)
      {
         setX(x);
         setY(y);
      }

      //POINT :: SET X :
      void setX(int x)
      {
         if (x < 1)
            this->x = 1;
         else if (x > 10)
            this->x = 10;
         else
            this->x = x;
      }

      //POINT :: SET Y :
      void setY(int y)
      {
         if (y < 1)
            this->y = 1;
         else if (y > 10)
            this->y = 10;
         else
            this->y = y;
      }

      //POINT :: GET X :
      int getX() const {return x;}

      //POINT :: GET Y :
      int getY() const {return y;}

      void display() const;

      ~Point() {;}

};

#endif
