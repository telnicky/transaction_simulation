/* A Product is a food item in a wherehouse.
 * ie. Oranges, Lettuce, Cereal
 *
 *
 * Dustin Robinson
 * January 29, 2013
 */
 

#ifndef PRODUCT
#define PRODUCT

#include <string>

namespace cs3505

{

  class product
  {
  public:
    product(int shelf_life, std::string UPC, std::string name);     // Constructor
    product(const product & other);               // Copy constructor
    //~product();                                 // Destructor

    int get_shelf_life();
    void decrement_shelf_life();
    std::string get_upc();
    std::string get_name();
   
     
  private:
    int shelf_life;       //The length of time a product is good for
    std::string UPC;      //Prodoct UPC code
    std::string name;          //Name of the product
    
  };

 
}

#endif