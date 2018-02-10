#include "credits.h" // including credits header file 


credits::credits()  // a constructor which do nothing just formality
{
}
void credits::showcredit(ALLEGRO_DISPLAY *display) // member function which shows credits 
{

	al_init_primitives_addon(); // allegro initializer for graphic primitives
	al_init_font_addon();	// allegro initializer for font 
	al_init_ttf_addon(); // allegro initializer for ttf files
	al_clear_to_color(al_map_rgb(0,0,0)); // change all color to black 
	al_init_image_addon(); // allegro initializer for bitmap image
	ALLEGRO_BITMAP *C1;	// image bitmap pointer
	ALLEGRO_BITMAP *C2;	// image bitmap pointer
	ALLEGRO_BITMAP *C3;	// image bitmap pointer

	C1 = al_load_bitmap("t.jpg");  // load image through its pointer
	C2 = al_load_bitmap("s.jpg");  // load image through its pointer
	C3 = al_load_bitmap("h.jpg");  // load image through its pointer

	int imageWidth = al_get_bitmap_width(C1);  //get image width
	int imageHeight = al_get_bitmap_height(C1); //get image height
	int imageWidth2 = al_get_bitmap_width(C2); //get image width
	int imageHeight2 = al_get_bitmap_height(C2); //get image height
	int imageWidth3 = al_get_bitmap_width(C3); //get image width
	int imageHeight3 = al_get_bitmap_height(C3); //get image height

	ALLEGRO_FONT *credits = al_load_font("BRITANIC.ttf", 60, 0); // intialize font pointer and giving its size along with ttf font
	ALLEGRO_FONT *talha = al_load_font("BRITANIC.ttf", 24, 0); // intialize font pointer and giving its size along with ttf font
	ALLEGRO_FONT *sohaib = al_load_font("BRITANIC.ttf", 24, 0); // intialize font pointer and giving its size along with ttf font
	ALLEGRO_FONT *hamza = al_load_font("BRITANIC.ttf", 24, 0); // intialize font pointer and giving its size along with ttf font
	
	al_draw_text(credits, al_map_rgb(110, 200, 18), 400, 20, 0, "  CREDITS  "); // it draws the font gives it color and set position and flags
	al_draw_text(talha, al_map_rgb(110, 10, 180), 50, 150, 0, "TALHA ASIF (14k-2246) "); // it draws the font gives it color and set position and flags
	al_draw_text(sohaib, al_map_rgb(110, 10, 180), 50, 300, 0, "SOHAIB HASHMI (14k-2121) "); // it draws the font gives it color and set position and flags
	al_draw_text(hamza, al_map_rgb(110, 10, 180), 50, 450, 0, "HAMZA MASOOD (14k-2198) "); // it draws the font gives it color and set position and flags
	al_draw_bitmap(C1,450,100,0); //draw the bitmap image
	al_draw_bitmap(C2,450,260,0); //draw the bitmap image
	al_draw_bitmap(C3,450,420,0); //draw the bitmap image

	ALLEGRO_EVENT_QUEUE *event_queue = NULL; // intialize event queue pointer to NULL
	event_queue = al_create_event_queue();   // creating a new event queue

	al_register_event_source(event_queue, al_get_display_event_source(display)); // register event queue source and gives display
	
	al_flip_display(); // brings back buffer to front buffer and gives output
	al_rest(5.0); //rest for 5 seconds to show credits
	al_destroy_font(talha); //destroys font
	al_destroy_font(sohaib); //destroys font
	al_destroy_font(hamza); //destroys font
} //end 