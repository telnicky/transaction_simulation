/* A Product is a food item in a wherehouse.
 * ie. Oranges, Lettuce, Cereal
 *
 *
 * Dustin Robinson
 * Travis Elnicky
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
    product();
    product(int _shelf_life, std::string _UPC, std::string _name);     // Constructor
    product(const product & other);               // Copy constructor
    //~product();                                 // Destructor

    void decrement_shelf_life();
    bool expired(int date);
    int set_shelf_life(int _exp);
    int get_shelf_life() const;
    std::string get_upc() const;
    std::string get_name() const;

   
    friend std:: ostream& operator<< (std::ostream &out, const product & rhs ); 
  private:
    int shelf_life;       //The length of time a product is good for
    std::string UPC;      //Prodoct UPC code
    std::string name;          //Name of the product
    
  };

 
}

#endif