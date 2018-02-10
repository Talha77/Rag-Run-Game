#include "background.h" // including background header file

void Background::InitBackground(Background &back, float x, float y, float velx, float vely, int width, int height, int dirX, int dirY, ALLEGRO_BITMAP *image) //member function which initiaizes all values
{
	back.x = x; // first width
	back.y = y; // first height 
	back.velX = velx; // speed negative
	back.velY = vely; //speed positive
	back.width = width;	// total width
	back.height = height;// total height
	back.dirX = dirX;	//speed
	back.dirY = dirY;	//speed
	back.image = image;	// background image
}

void Background::UpdateBackground(Background &back) // member function with background object argument
{
	back.x += back.velX * back.dirX;	// back.x i.e background width change accouring to spees that is given 
	if(back.x + back.width <= 0)	//condtion that if background is gone less than zero make it zero so parallax backgroun can work
		back.x = 0; //
}

void Background::DrawBackground(Background &back) // member function with background object argument
{
	al_draw_bitmap(back.image, back.x, back.y, 0); // draw background image
	
	if(back.x + back.width < 1000)	// condition of if its less than 1000 
		al_draw_bitmap(back.image, back.x + back.width, back.y, 0); // draw again else not 
} //end