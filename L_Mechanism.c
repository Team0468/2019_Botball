#include <kipr/botball.h> 
#include <L_Mechanism.h>
#include <arm_hand_position.h>
#include <comp_lib.h>





int total;
int i;
int buffer(int sensor)
{total = 0;
 i = 0;
 while(i<5){
     i = i+1;
     total = total + analog(sensor);
     msleep(1);}
 return(total/5);
}


int slow_arm (int x,int speed)//this funtion slows 
{ 

    enable_servo (arm);
    int desired_position;
    int current_position = get_servo_position(arm);
    if (x > arm_max) {desired_position = arm_max;}
    else if(x < arm_min) {desired_position = arm_min;}
    else {desired_position = x;}
    switch(speed){
        case 1:
            while(current_position <= desired_position-2 || current_position >= desired_position+2)
            {
                if(current_position < desired_position)
                { current_position=current_position +2;
                 set_servo_position(arm, current_position);
                 msleep(1);
                }
                if(current_position > desired_position)
                { current_position=current_position -2;
                 set_servo_position(arm, current_position);

                 msleep(1);
                }
            }
            break;
        case 2:
            while(current_position != desired_position)
            {
                if(current_position < desired_position)
                { current_position=current_position +1;
                 set_servo_position(arm, current_position);
                 msleep(2);
                }
                if(current_position > desired_position)
                { current_position=current_position -1;
                 set_servo_position(arm, current_position);

                 msleep(2);
                }
            }
            break;
    }

    set_servo_position (arm, x);
    msleep(15);
    disable_servo (arm);
    if(analog(0)<50){return 0;}
    else{return 1;}

}

int slow_hand ( int z, int speed )//this funtion slows 
{ 

    enable_servo (hand);
    int desired_position;
    int current_position = get_servo_position(hand);
    if (z > hand_max) {desired_position = hand_max;}
    else if(z < hand_min) {desired_position = hand_min;}
    else {desired_position = z;}
    switch(speed){
        case 1:
            while(current_position <= desired_position-2 || current_position >= desired_position+2)
            {
                if(current_position < desired_position)
                { current_position=current_position +2;
                 set_servo_position(hand, current_position);
                 msleep(1);
                }
                if(current_position > desired_position)
                { current_position=current_position -2;
                 set_servo_position(hand, current_position);
                 msleep(1);
                }
            }
            break;
        case 2:

            while(current_position != desired_position)
            {
                if(current_position < desired_position)
                { current_position=current_position +1;
                 set_servo_position(hand, current_position);
                 msleep(2);
                }
                if(current_position > desired_position)
                { current_position=current_position -1;
                 set_servo_position(hand, current_position);

                 msleep(2);
                }
            }
            break;
    }
    set_servo_position (hand, z);
    if(analog(0)<50){return 0;}
    else{return 1;}
    disable_servo (hand);
}