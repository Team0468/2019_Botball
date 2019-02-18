#include <kipr/botball.h>
#include </home/root/Documents/KISS/Default User/tournament_file_Bot_A/include/comp_lib.h>
#include </home/root/Documents/KISS/Default User/tournament_file_Bot_A/include/L_Mechanism.h>

/*void cube_verify()
{
    if(buffer(4)>1600)
    {
        move(-400,-400);
        while(buffer(4)>1400){}
        move(0,0);
    }
    if(buffer(4)<1600)
    {
        move(400,400);
        while(buffer(4)<1400){}
        move(0,0);
    }
}*/

void pvc_backwards_follow(){
    //function developed and written by Ryan P. Webb & Treyton J. Ross
    move(-800, -800);
    msleep(500);
    ao();
    cmpc(1);
    cmpc(2);
    int min_accel_x = 55;
    int max_accel_y = 5;
    while(gmpc(left_motor) > -8000){
        if(accel_x() < min_accel_x){
            min_accel_x = accel_x();
        }
        if(accel_y() > max_accel_y){
            max_accel_y = accel_y();
        }
        if(accel_x() < -30){
            move(800,800);
        }
        else{
        	if(digital(0) == 1){
            	move(-800, -1000);
        	}
            else{
            	move(-1000, -800);
        	}
        }
    }
    ao();
}