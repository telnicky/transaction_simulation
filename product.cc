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

    product::product() {
      this->shelf_life = 0;
      this->UPC = "";
      this->name = "";
    }

    product::product(int shelf_life, std::string UPC ,std::string name)     // Constructor
    {
      this->shelf_life = shelf_life;
      this->UPC = UPC;
      this->name = name;
    }

    product::product(const product & other) // Copy constructor
    {
      this->shelf_life = other.shelf_life;
      this->UPC = other.UPC;
    }

    //~product();                      // Destructor

    int product::get_shelf_life()
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

    std::string product::get_upc()
    {
      return UPC;
    }

    std::string product::get_name()
    {
      return name;
    }

}
