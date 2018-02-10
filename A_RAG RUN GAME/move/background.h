#define BACKGROUND_H						 // defining background header file
#include <allegro5\allegro.h>				 // to include allegro5 file
#include <allegro5\allegro_image.h>			 // to include allegro image file
#include <allegro5\allegro_font.h>			 // for fonts to work on allegro
#include <allegro5\allegro_ttf.h>			 // ttf files true type fonts 
#include <allegro5\allegro_primitives.h>	 // graphics primitives which are used in game

class Background  // class of background
{

	public:			// public mamber variables
		float x;   // position stats x
		float y;	// position starts y
		float velX;	// start of speed x
		float velY;	//start of speed y
		int dirX;	// end of speed x
		int dirY;	// end of speed y
		int width;	//position end x
		int height;	//position end y

	ALLEGRO_BITMAP *image; // bitmap image pointer

	
		void InitBackground(Background &back, float x, float y, float velx, float vely, int width, int height, int dirX, int dirY, ALLEGRO_BITMAP *image); //member functions public
		void UpdateBackground(Background &back); //member functions public
		void DrawBackground(Background &back); //member functions public
}; //end