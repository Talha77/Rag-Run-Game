#define CREDITS_H							 // defining credits header file
#include <allegro5\allegro.h>				 // to include allegro5 file
#include <allegro5\allegro_image.h>			 // to include allegro image file
#include <allegro5\allegro_font.h>			 // for fonts to work on allegro
#include <allegro5\allegro_ttf.h>			 // ttf files true type fonts 
#include <allegro5\allegro_primitives.h>	 // graphics primitives which are used in game

class credits  // class of credits
{
public: // puclic
credits(); // constructor 
void showcredit(ALLEGRO_DISPLAY *display);  //it displays the credits

}; //end
