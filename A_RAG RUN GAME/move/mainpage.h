#define MAINPAGE_H							 // defining a header file of Mainpage
#include <allegro5\allegro.h>				 // to include allegro5 file
#include <allegro5\allegro_image.h>			 // to include allegro image file
#include <allegro5\allegro_font.h>			 // for fonts to work on allegro
#include <allegro5\allegro_ttf.h>			 // ttf files true type fonts 
#include <allegro5\allegro_primitives.h>	 // graphics primitives which are used in game


class Mainpage  // class of mainpage
{
private:		// initializing width and height in private data members
	int w;
	int h;

public:				
	Mainpage(int,int);	    // constructor 
	void page(ALLEGRO_DISPLAY *display);		// member function for dislplaying mainpage , display pointer is being passed here

}; //end