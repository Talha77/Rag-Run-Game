/*
****************************************************************************************************************************************************
--------------------------------------------------------------------RAG RUN GAME -------------------------------------------------------------------
-----------------------FINAL PROJECT COMPUTER PROGRAMMING ------------------------------------------------------------------------------------------
---------------MISCROSOFT VISUAL STUDIO----------------------ALLEGRO 5------------------------------------------------------------------------------
--------TALHA ASIF ---------------k142246-----------------------------------------------------------------------------------------------------------
--------SOHAIB HASHMI ------------k142121-----------------------------------------------------------------------------------------------------------
--------HAMZA MASOOD -------------k142198-----------------------------------------------------------------------------------------------------------
--------------Submitted on 1-MAY-2015 -----------------------to Ms Fareeha Sheikh ------------------------------------------------------------------
*/
#include <allegro5\allegro.h>				 // to include allegro5 file
#include <allegro5\allegro_image.h>			 // to include allegro image file
#include <allegro5\allegro_font.h>			 // for fonts to work on allegro
#include <allegro5\allegro_ttf.h>			 // ttf files true type fonts 
#include <allegro5\allegro_primitives.h>	 // graphics primitives which are used in game
#include <allegro5\allegro_audio.h>			 // for sound audio in the game
#include <allegro5\allegro_acodec.h>		 // for audio in game
#include <math.h>							 // for all the manipulations in math for scoring and couting distance
#include "credits.h"						 //including CREDITS.h file in the main 
#include "background.h"						 //including BACKGROUND.h file in the main
#include "mainpage.h"						 // including MAINPAGE.h file in the main 
#include "dimension.h"

enum IDS{ENEMY};				//enemy is refering to hurdles in the game
const int WIDTH = 1000;			//its the constant width of screen while playing the game
const int HEIGHT = 600;			//its the constant heights of screen while playing the game
const int NUM_COMETS = 8;		// number of comets in a loop or array
enum Keys{ESP,SPACE};			// these are the buttons we will be using in the game
ALLEGRO_SAMPLE *song = NULL;	// song implementation in the game
ALLEGRO_SAMPLE_INSTANCE *songInstance = NULL;	 // intializing son pointer to NULL


class Comet: public Dimension  // comet or hurdles class 
{
public:  // public member variables 
	int ID;
	int x;
	int y;
	bool live;
	int speed;
	int boundx;
	int boundy;

	// puclic member functions 
	Comet();  // default constructor 
	void InitComet(Comet comets[], int size); // comet initializer 
	void DrawComet(Comet comets[], int size);	// this function draws comet
	void StartComet(Comet comets[], int size);	// this dunction starts the comet movement
	void UpdateComet(Comet comets[], int size);	// it updates the comet evry timer

};
Comet::Comet() // constructor 
{

}
void Comet::InitComet(Comet comets[], int size)  
{
	for(int i = 0; i < size; i++) //loop for initializing comet
	{
		comets[i].ID = ENEMY; // id emeny as its the only enemy which can disturb a user playing
		comets[i].live = false;	// comet coming live 
		comets[i].speed = 6;	// speed of comet
		comets[i].boundx = 18;	//position on x axis 
		comets[i].boundy = 200; //position on y axis
	}
}


void Comet::DrawComet(Comet comets[], int size)
{
		for(int i = 0; i < size; i++)  //loop to draw comet
	{
		if(comets[i].live)  // if condition if comet is false
		{
			al_draw_rectangle(comets[i].x,comets[i].y,comets[i].x+50,comets[i].y+50,al_map_rgb(210,105,30),4); //draws the  comet
			al_draw_filled_rectangle(comets[i].x+3,comets[i].y+3,comets[i].x+47,comets[i].y+47,al_map_rgb(139,69,19)); // drws the comet
		}
	}
}
void Comet::StartComet(Comet comets[], int size)
{
		int diff = 1000; // to set when the comets will come 
	for(int i = 0; i < size; i++) //loop to control poisiton of comets
	{
		diff = diff - 20; // difference will decrease as score will increase in the game , to make difficulty level
		if(!comets[i].live) // if comets live is false
		{
			if(rand() % diff == 0) // randly creates comets
			{
				comets[i].live = true; // comets will bool true
				comets[i].x = WIDTH;  // changes width
				comets[i].y = HEIGHT-110; // chandes height 

			
				break; //break the function
			}
		}
	}
}

void Comet::UpdateComet(Comet comets[], int size)
{
		for(int i = 0; i < size; i++) //loop to update the comet
	{
		if(comets[i].live)
		{
			comets[i].x -= comets[i].speed;  //comet speed and x axis realtion as the timer comet will update positon amd come closer to user

			if(comets[i].x < 0)
				comets[i].live = false; // if comets is less then zero it becomes false means no comet will be shown then
		}
	}
}
class Collide   //class to collide user to comet
{
public:   //public 
	int x;  //position x member variable
	int y;	//position y member variable
	Collide(int ,int);		//constructor 
	void CollideImage(Comet comets[],int cSize,ALLEGRO_BITMAP *image2[],int count,ALLEGRO_DISPLAY *display);  //member function
};
Collide::Collide(int X,int Y) // initialize the position x and y
{
x = X;
y = Y;
}
void Collide::CollideImage(Comet comets[],int cSize,ALLEGRO_BITMAP *image2[],int count,ALLEGRO_DISPLAY *display)  //  collide member function
{

	for(int i = 0; i < cSize; i++) //loop to csize 
	{
		if(comets[i].live)  //if comets is shown 
		{
			if(((comets[i].x-comets[i].boundx < 195 && comets[i].x-comets[i].boundx > 180) && HEIGHT - y < 250 ) ||  (comets[i].x-comets[i].boundx < 195 && comets[i].x-comets[i].boundx > 180) && y > 440) // for collidng position of user and comet
			{
				
				comets[i].live = false;  // comets bool become false
				al_rest(2.0); // if collide we need rest of 2 seconds
				al_clear_to_color(al_map_rgb(0,0,0));  // change color to black 
				al_init_font_addon();  // font allegro
				al_init_ttf_addon();  // ttf allegro true type font
				ALLEGRO_FONT *fontover = al_load_font("mypager.ttf", 80, 0);   // allegro font pointer and its ttf font
				ALLEGRO_FONT *fontclose = al_load_font("mypager.ttf", 30, 0);  // allegro font pointer and its ttf font
				ALLEGRO_FONT *fontragged = al_load_font("mypager.ttf", 40, 0);  // allegro font pointer and its ttf font
				al_draw_textf(fontragged, al_map_rgb(255, 0, 255), WIDTH/7 ,200 , 0, "YOU HAVE BEEN RAGGED BY SENIOR"); //draw font color and its position
				al_draw_textf(fontover, al_map_rgb(255, 0, 255), WIDTH/4 , 270, 0, "GAME OVER"); //draw font color and its position
				al_draw_textf(fontclose, al_map_rgb(255, 0, 255), WIDTH/3 , 380, 0, "YOUR SCORE : %i ", (count/6)-1); //draw font color and its position
				al_flip_display();  // flip our back display to front
				al_rest(3.0); // rest for 3 seconds
				al_clear_to_color(al_map_rgb(0,0,0));  // color to black
				credits end;	 // credit class object created 
				end.showcredit(display); // credit class member function call
				al_rest(2.0); // rest of 2 seconds 
				exit(0); // exit the game
			}
			
		}
	}
}

int main(void)   //here the main body started
{
	int width = 1000;  // thats the width of screen
	int height = 600;  // thats the height of screen
	
	ALLEGRO_DISPLAY *display = NULL; // allegro display pointer which is equal to NULL
	
	if(!al_init())										 // chectk if allegro is working or not
		return -1;
	display = al_create_display(width, height);		     // we created a dislpay and given it width and height	
	if(!display)										 // check for display if its working 																
		return -1;	

	Mainpage MP(width,height); //mainpage object + constuctor 
	MP.page(display);          // here we displayinh a mainpage of the game



	bool render = false;	// bool value for keyboard
	bool done = false;      // game done loop bool value
	const int maxFrame = 3; // for senior running max frames of comp
	const int maxFrame2 = 4;//for freshie running max frames of user
	int curFrame = 0;  // frames of comp
	int curFrame2 = 0; //frames of user
	int frameCount = 0; // count frame of comp
	int frameDelay = 5;	// delays the frame to convert form one to other
	int frameCount2 = 0; // count frame for user
	int frameDelay2 = 5; // delays the frame to convert form one to other
	int count = 0;  // count for scoring + distance 
	bool redraw = true;  // to re draw comets
	int diff = 800;  // diff of comets done 
	Comet comets[NUM_COMETS];  // comets class object 
    static int  X  = 150, Y = 415;  // X and Y values which helps in jumping user and setting its position
	float jumpspeed = 18; // jumspeed is directly relational to jump high or low
	bool keys[2] = {false,false};  // keys bool foe escape and space
	float velx,vely;	// jumping velocity at x and y
	velx = vely = 0; // initalizes both to zero 
	bool jump = false;  // jump bool vlaue 
	bool active = false;  // active bool value 
	bool draw = false;   // draw bool value 
	
	const float gravity = 1;   //gravity that brings user down after jumping 

	ALLEGRO_EVENT_QUEUE *event_queue = NULL;   //event queue which initializes to NULL
	ALLEGRO_TIMER *timer;  // allegro time for game
	ALLEGRO_BITMAP *bgImage = NULL;  //background imge 


	ALLEGRO_BITMAP *image[maxFrame];  // pointer array of comp images 
	ALLEGRO_BITMAP *image2[maxFrame+1];  //pointer array of user images
	al_init_font_addon(); // allegro fonts
	al_init_ttf_addon();  // allegro ttf
	ALLEGRO_FONT *font18 = al_load_font("stocky.ttf", 18, 0); // font pointer and font ttf file + size
	ALLEGRO_FONT *font19 = al_load_font("stocky.ttf", 18, 0); // font pointer and font ttf file + size

	al_install_keyboard();   //install  allegro keyboard
	al_init_image_addon();  // allegro image initiazlie
	al_init_primitives_addon();   // graphics of allegro 
	al_install_audio();  // install allegro audio
	al_init_acodec_addon(); // acodec for audio

	bgImage = al_load_bitmap("backwa.jpg");    //background image of allegro 
	ALLEGRO_KEYBOARD_STATE keystate;   // for keyborard state

	Background BG;    //object for background
	BG.InitBackground(BG, 0, 0, 3, 0, 964, 600, -6 ,0 , bgImage);   // intialize and move background 
	
	image[0] = al_load_bitmap("r1.png");   //load image to array of comp
	image[1] = al_load_bitmap("r2.png");   //load image to array of comp
	image[2] = al_load_bitmap("r3.png");   //load image to array of comp

	image2[0] = al_load_bitmap("a1.png");   //load image to array of user
	image2[1] = al_load_bitmap("a2.png");   //load image to array of user
	image2[2] = al_load_bitmap("a3.png");   //load image to array of user
	image2[3] = al_load_bitmap("a4.png");   //load image to array of user

	for(int i = 0; i < maxFrame; i++)  //loop to convert background of images to transparent
		{
			al_convert_mask_to_alpha(image[i], al_map_rgb(255, 255, 255));   // mask transparent color white
			al_convert_mask_to_alpha(image2[i], al_map_rgb(0, 0, 0));        // mask transparent color black   
			
		}


	event_queue = al_create_event_queue();    //event queue initializer
	timer = al_create_timer(1.5 / 60);        // timer created for 1.5 / 60 seconds
	Collide col(X,Y);   // collide class object along with constructor parameters
	srand(time(NULL));  // rand time which is currently equal to NULL
	
	comets[NUM_COMETS].setDimension(1000,600);    // set dimension through comets class "INHERITANCE"
	comets[NUM_COMETS].InitComet(comets, NUM_COMETS);  //call for member function of comet class
	
	al_reserve_samples(1);   // samples for audio 
	song = al_load_sample("song.mp3");   //load song of audio

	al_register_event_source(event_queue, al_get_timer_event_source(timer));  //register timer in loop of program
	al_register_event_source(event_queue, al_get_display_event_source(display));  // registers display in loop of program 
	al_register_event_source(event_queue, al_get_keyboard_event_source());    // registers keyboard in loop of program

	al_start_timer(timer);   // the timer started

	while(!done)  // while it is not done 
	{
		ALLEGRO_EVENT ev;    // new event created for keyboard input
		al_wait_for_event(event_queue, &ev);  // waiting fro event
		al_get_keyboard_state(&keystate);  //keystates check the state of keyboaed and its keys in current position
		count = count + 1;   // increment in count
			BG.DrawBackground(BG);   //background member function with its object in argument
			BG.UpdateBackground(BG); //background member function with its object in argument

		al_draw_textf(font18, al_map_rgb(0, 0, 255), width-160 , 30, 0, "SCORE : %i ", count/6);   //to update score of game
		al_draw_textf(font19, al_map_rgb(0, 0, 255), 20 , 30, 0, "DISTANCE : %i m", count/10);	   //to update distance of game 

		if(ev.type == ALLEGRO_EVENT_TIMER)  // loop for event type timer i.e if timer is on 
		{

			redraw = true;  //redraw true means all will be redraw
			render = true; //for input
			comets[NUM_COMETS].StartComet(comets, NUM_COMETS);   //comets class member function along with its object as argument
			comets[NUM_COMETS].UpdateComet(comets, NUM_COMETS);  //comets class member function along with its object as argument
			
			
			if(++frameCount > frameDelay)   //loop to change images of comp to make him display run
			{
				if(++curFrame >= maxFrame)  // here curframe is zero and get pre increment
					curFrame = 0;  //if greater then again comes to zero

				frameCount = 0;  //frame count in the end of loop equals to zero
			}
			if(++frameCount2 > frameDelay2)  //loop to change images of user to make him display run
			{
				if(++curFrame2 >= maxFrame2)  // here curframe is zero and get pre increment
					curFrame2 = 0;  //if greater then again comes to zero

				frameCount2 = 0;   //frame count in the end of loop equals to zero
			}
			
				if(al_key_down(&keystate, ALLEGRO_KEY_SPACE) && jump)   // if user press space bar (JUMP)
				{
				vely = -jumpspeed;  // velocity decreases and user went UP
				jump = false; // jump rmains false
				}
		

				if(!jump)   // if jump false 
				vely += gravity;   // vely with gravitiy with help the user to come back again to ground slowly as it jump
				
				else
				vely = 0;  // else vely == 0
				
				X += velx;  //X is the position of user at X axis which changes with jump 
				Y += vely;  //Y is the position of user at Y axis which changes with jump
				Collide col(X,Y);  // collison class object + constructor arguments
				col.CollideImage(comets,NUM_COMETS,image2,count,display); //  member function of class collide
				 
				jump = (Y >= 415 );  // in jump y is always greater than or equal to 415(place where user runs)

				if(jump)
					Y = 415 ;  //user comes back to 415 after jump
		}

	
		if(al_key_down(&keystate, ALLEGRO_KEY_ESCAPE))   // if ESCAPE PRESSED game will be closed
				{
				done = true;  //done is the game loop it will become true and game will be closes
				break;
				}
		else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)   // if crossed on titile bar pressed game will be closed
		{
			done = true;
		}
		
		if(redraw && al_is_event_queue_empty(event_queue))    //redraw for comets 
		{
			redraw = false; 
			comets[NUM_COMETS].DrawComet(comets, NUM_COMETS);   // comets class to draw new comets
		}
		
		al_draw_bitmap(image[curFrame],20,height-180,0);   // position of computer (SENIOR)
		al_draw_bitmap(image2[curFrame],X,Y,0);			   //position of user(FRESHIE)	
		al_flip_display();								//changes back buffer to front buffer
		al_clear_to_color(al_map_rgb(0,0,0));			//clear all back ground to black
	
	}
	
	al_destroy_sample(song);    // destroy song
	al_destroy_sample_instance(songInstance);  // destroy song instance with game loop
	al_destroy_bitmap(bgImage);  // destroy pointer of image
	al_destroy_event_queue(event_queue);  // destroys eent queue
	al_destroy_timer(timer);   // destroys timer 
	for(int i = 0; i < maxFrame; i++)   // destorys all comp images used in motion
	{	
		al_destroy_bitmap(image[i]);
		
	}
	for(int j = 0; j < maxFrame2; j++)   // destroys all user images used in motiom
	{	
		al_destroy_bitmap(image2[j]);
		
	}

	al_destroy_display(display);					 // destroys the display final one

	return 0;  // return 0 to main function for int main()
		
	}   // end of the GAME //