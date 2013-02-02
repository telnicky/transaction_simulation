/* A Product is a food item in a wherehouse.
 * ie. Oranges, Lettuce, Cereal
 *
 *
 * Dustin Robinson
 * January 29, 2013
 */
#include <iostream>
#include <sstream>
#include <string>
#include "product.h"


namespace cs3505

{

    product::product() {
      this->shelf_life = 0;
      this->UPC = "";
      this->name = "";
    }

    product::product(int _shelf_life, std::string _UPC, std::string _name)     // Constructor
    {
      this->shelf_life = _shelf_life;
      this->UPC = _UPC;
      this->name = _name;
    }

    product::product(const product & other) // Copy constructor
    {
      this->shelf_life = other.shelf_life;
      this->UPC = other.UPC;
    }

    //~product();                      // Destructor

    int product::set_shelf_life(int _exp) {
      shelf_life = _exp;
      return 0;
    }

    int product::get_shelf_life() const
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

    std::string product::get_upc() const
    {
      return UPC;
    }

    std::string product::get_name() const
    {
      return this->name;
    }

    /*
     * Overrides cout <<
     */
    std::ostream& operator<< (std::ostream &out, const product & rhs ) {
      out << "PROD: " << std::endl;
      out << "\tUPC: " << rhs.get_upc() << std::endl;
      out << "\tName: " << rhs.get_name() << std::endl;
      out << "\tShelf Life: " << rhs.get_shelf_life() << std::endl;
      // out << "UPC: " << rhs.UPC << " Name: " << rhs.name << " Shelf Life: " << rhs.shelf_life;
      return out;
    }

}
