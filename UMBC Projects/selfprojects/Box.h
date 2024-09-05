/ File: Box.h
	//
	//   Class declaration for the Box class
	//

#ifndef BOX_H
#define BOX_H


class Box {

  friend int compare(Box &, Box &) ;

  public:
  Box() ;                      // default constructor
  Box(float, float, float) ;   // alternate constructor
  ~Box() ;                     // destructor

  void identify() ;            // prints out vital stats
  static void report() ;       // prints out static members
   
  float volume() ;             // volume of the box
  void grow() ;                // double box dimensions
  void shrink() ;              // halve box dimensions

  protected:      // semi-private
  float length ;               // box length
  float height ;               // box height
  float width ;                // box width

  inline int serial() { return serial_number ; } 

  private:        // really private
  int serial_number ;          // serial number of this box
  static int count ;           // number of boxes in existence
  static int sequence ;        // number of boxes ever made

  };


// Returns -1 if first box fits in second
//          1 if second box fits in first
//          0 if neither

int compare(Box&, Box&) ;

#endif
