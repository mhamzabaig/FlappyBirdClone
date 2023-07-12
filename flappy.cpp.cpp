
#include<windows.h>
#include<graphics.h>
#include<time.h>
#include<iostream>
#include<conio.h>

using namespace std;

#define SCREEN_HEIGHT 1200
#define SCREEN_WIDTH 1200

bool COLLISION_DETECTION=false;
bool Move(int &Key_pressed)
{
	if(GetAsyncKeyState(VK_UP))
		return true;
	
}

game()
{
	//CREATING WINDOW.....................
	initwindow(SCREEN_HEIGHT,SCREEN_WIDTH,"sample");
	
		//BIrd SECTION.....
	int Key_pressed;
	int Bird_Ypos = 100;
	int Bird_Xpos = 700;
	int Bird_Width = 60;
	// HURDLE SECTIONS...
			
	struct HURDLE_SECTION
	{	
    	int move_hurdle,left,top,right,bottom,out_screen_range;	
	};
	
	outtextxy(600,500,"To Start THE GAME PRESS ANY KEY ");
	getch();
	
	if(COLLISION_DETECTION==false)
	{
			//BIrd SECTION.....
		int Key_pressed;
		int Bird_Ypos = 100;
		int Bird_Xpos = 700;
		int Bird_Width = 60;
	
	
	}
		while(1)
		{
			if(COLLISION_DETECTION==false)
				{
						//Drawig Bird
				if(Move(Key_pressed)==true)
				{
					Bird_Ypos-=20;
					outtextxy(Bird_Xpos,Bird_Ypos,  "<\\\\\\\==Q");
					outtextxy(Bird_Xpos,Bird_Ypos+15, "\\\\\\");
				}
				else
				{
					Bird_Ypos+=20 ;
			
					outtextxy(Bird_Xpos,Bird_Ypos,  " \\\\\\\\");
					outtextxy(Bird_Xpos,Bird_Ypos+15,"<\\\\\\\\==Q");
				}
				
				//Drawing Hurdles 
					   
			    HURDLE_SECTION hurdles[4];
		    
			 
		    	for(int i=0; i<4; i++)
		   	    {
		            switch(i)
		            {
		            	case 0:
		                hurdles[i].left=1250-hurdles[i].move_hurdle; hurdles[i].top=0; hurdles[i].right=1300-hurdles[i].move_hurdle; hurdles[i].bottom = 200; hurdles[i].out_screen_range = 1100;
						break;
		                
		                case 1:
		                hurdles[i].left=1500-hurdles[i].move_hurdle; hurdles[i].top=0; hurdles[i].right=1550-hurdles[i].move_hurdle; hurdles[i].bottom = 500; hurdles[i].out_screen_range = 1400;
		                break;
		                
		                case 2:
		                hurdles[i].left=1850-hurdles[i].move_hurdle; hurdles[i].top=0; hurdles[i].right=1900-hurdles[i].move_hurdle; hurdles[i].bottom = 350; hurdles[i].out_screen_range = 1500;
		                break;
		                
		               case 3:
		                hurdles[i].left=2100-hurdles[i].move_hurdle; hurdles[i].top=0; hurdles[i].right=2150-hurdles[i].move_hurdle; hurdles[i].bottom = 550; hurdles[i].out_screen_range = 1600;
		                break;
		            }
					
					//RENDERING HURDLE SECTIONS............
					if(hurdles[i].right-hurdles[i].move_hurdle<=-hurdles[i].out_screen_range)
					{
						hurdles[i].move_hurdle=0;
						hurdles[i].bottom=50;
					}
					
					//Upper HURDLE........
					rectangle(hurdles[i].left,hurdles[i].top,hurdles[i].right,hurdles[i].bottom);setcolor(BLUE);
					
					//LOWER HURDLE.......
					rectangle(hurdles[i].left,hurdles[i].bottom+250,hurdles[i].right,SCREEN_HEIGHT);
					
					hurdles[i].move_hurdle+=7;
					
					//COLLISION DETECTION.....
					if(Bird_Ypos>=1000 || Bird_Ypos<10 ||( (Bird_Xpos +60>=hurdles[i].left && Bird_Xpos +60<=hurdles[i].left+50) &&!(Bird_Ypos>=hurdles[i].bottom && Bird_Ypos<=hurdles[i].bottom+250)))
					{
						COLLISION_DETECTION = true;	
					}
					
				}
					
			}
			else 
			{
				setcolor(GREEN);
				outtextxy(500,400,"GAME OVERRRRRRR :)");
				outtextxy(500,420,"PRESS ANY KEY TO EXIT");
				char EXIT;
			    getch();	
				exit(0);	
			}
			delay(50);
			cleardevice();	
		}
	
}



 int main()
{
	game();
}

