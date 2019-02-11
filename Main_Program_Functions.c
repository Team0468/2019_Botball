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
    //function developed and written by Ryan P. Webb
    move(-800, -800);
    msleep(500);
    ao();
    cmpc(1);
    cmpc(2);
    while(gmpc(left_motor) < 4000){
        if(digital(0) == 1){
            move(-800, -1000);
        }else{
            move(-1000, -800);
        }
    }
    ao();
}