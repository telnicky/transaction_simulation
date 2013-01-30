/* A Product is a food item in a wherehouse.
 * ie. Oranges, Lettuce, Cereal
 *
 *
 * Dustin Robinson
 * January 29, 2013
 */
#include <iostream>
#include <sstream>
#include "product.h"
#include <string>


namespace cs3505

{

    product::product(int shelf_life, std::string UPC)     // Constructor
    {
      this->shelf_life = shelf_life;
      this->UPC = UPC;
    }

    product::product(const product & other) // Copy constructor
    {
      this->shelf_life = other.shelf_life;
      this->UPC = other.UPC;
    }

    //~product();                      // Destructor

    int product::getShelf_life()
    {
      return shelf_life;
    }

    void product::decrement_shelf_life()
    {
      if(shelf_life == 0)
          ;
      else
        shelf_life--;

    }

    std::string product::getUPC()
    {
      return UPC;
    }

}
