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
    product(int shelf_life, std::string UPC);     // Constructor
    product(const product & other);               // Copy constructor
    //~product();                                 // Destructor

    int getShelf_life();
    void decrement_shelf_life();
    std::string getUPC();
   
     
  private:
    int shelf_life;  //The length of time a product is good for
    std::string UPC;      //Prodoct UPC code
    
  };

 
}

#endif