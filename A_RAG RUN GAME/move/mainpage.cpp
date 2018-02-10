#include "mainpage.h"			// inlcuding header fie of mainpage

Mainpage::Mainpage(int width,int height) // constructor of main page
{
w = width;  // width initialization
h = height;	// height initializaion
}
void Mainpage::page(ALLEGRO_DISPLAY *display)
{

	al_init_primitives_addon();  // for all shapes and grpahics which is being added 
	
	al_init_font_addon();	// for fonts to do one or more
	al_init_ttf_addon();	// ttf true type font files simply to display anything we need font.ttf file
	ALLEGRO_BITMAP *MP1;	// MP1 is a pointer to a bitmap image 	
	
	al_init_image_addon();	// image adon helps to output the image
	
	MP1 = al_load_bitmap("running.png");	// here we include our image file to be displayed


	al_convert_mask_to_alpha(MP1, al_map_rgb(255, 255, 255));  // converting some colors to transparent here we are converting white color to transparent
	

	al_draw_bitmap(MP1,175,130,0);  // adjusting position and flags of an image
	

	ALLEGRO_FONT *title = al_load_font("stocky.ttf", 66, 0); // font pointer and its ttf file which font it will display
	ALLEGRO_FONT *play = al_load_font("mypager.ttf", 24, 0); // font pointer and its ttf file which font it will display
	ALLEGRO_FONT *high = al_load_font("mypager.ttf", 24, 0); // font pointer and its ttf file which font it will display


	for(int i = 5 ; i  >=0 ; i--) // Loop for count dowm
	{	
	al_draw_bitmap(MP1,175,130,0);	// image in loop
	al_draw_text(title, al_map_rgb(15, 240, 18), 500, 250, ALLEGRO_ALIGN_CENTRE, "RAG-RUN GAME : "); //writing on font pointer and adjusting its position and color
	al_draw_text(play, al_map_rgb(15, 240, 18), 480, 380, ALLEGRO_ALIGN_CENTRE, " # TAP SPACE TO JUMP ");//writing on font pointer and adjusting its position and color
	al_draw_textf(high, al_map_rgb(15, 240, 18), 480, 420, ALLEGRO_ALIGN_CENTRE, " GAME BEGINS IN %i" ,i);//writing on font pointer and adjusting its position and color and also using loop i here
	al_rest(1.0); // after every loop it rest for 1 second
	al_flip_display();//its simply brings back buffer to front buffer
	al_clear_to_color(al_map_rgb(0,0,0));// it clears all color to black after evry loop 
	}



	bool done = false;	// done bool
	bool draw = true;	// draw bool
	int pos_x = w / 2;	//position set
	int pos_y = h / 2;  //position set

	ALLEGRO_EVENT_QUEUE *event_queue = NULL;  //waits for the event queue
	event_queue = al_create_event_queue();	  // initialize event queue

	
	al_register_event_source(event_queue, al_get_display_event_source(display));  //event is display means event done and display shown
	
	al_flip_display(); // again brings back buffer to fornt buffer
	
	al_destroy_font(high); // destroys font pointer
	al_destroy_font(play); // destroys font pointer
	al_destroy_font(title); // destroys font pointer
	al_destroy_bitmap(MP1); // destroys image pointer

} // end 