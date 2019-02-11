#include <kipr/botball.h>
#include </home/root/Documents/KISS/Default User/tournament_file_Bot_A/include/comp_lib.h>
#include </home/root/Documents/KISS/Default User/tournament_file_Bot_A/include/L_Mechanism.h>
#include <camera_2019.h>


int main()
{

    int burning_building = 2;   //|defined by camera for which building
    int target = buffer(4);
    slow_hand(hand_start,fast);
    if(analog(0) || analog(1) < white)
    { //| verifys IR sensor are working

        slow_arm(prism2,slow);
        PID_gyro_drive(-600 * multiplier, .35 / multiplier); //|physical square up
        PID_gyro_drive(600 * multiplier, .35 / multiplier);  
        move(600,625);                                       //| verify firefighter is in reach
        while(buffer(4) <= 2000){}                           //|


        move(0,0);                 //| begin grabbing cube
        slow_hand(open,slow);
        slow_arm(down,slow);
        slow_hand(closed,fast);
        msleep(500);
        slow_arm(up,slow);         //|end of cube grab
        PID_gyro_drive(600 * multiplier,1.65/ multiplier);  //| begin driving to prism
        turn_with_gyro(450 * multiplier,-90);
        square_up(black,200 * multiplier);                                                   
        move(0,0);                                           //| leave starting box
        msleep(150);
        move(633,600);
        while(buffer(4)<1425){}                              //| 
        cube_verify();										 //|----->prism verify for cube drop
        ao();												 //|

        slow_arm(prism2,slow);                               //| cube drop
        slow_hand(hand_prism_open,fast);
        ao();
        msleep(250);
        slow_arm(down,slow);                                 //| end of cube drop
        PID_gyro_drive(600 * multiplier,.75 / multiplier);
        slow_hand(prism,slow);
        msleep(200);                                         //| both in grasp
        PID_gyro_drive(-500 * multiplier,.30 /multiplier);   //|this is the end of start with firefighter and truck
        if(burning_building == 1)                            //|beginning of cases
        {
            turn_with_gyro(400 * multiplier,45);
            msleep(250);
            move(630,600);
            msleep(3500);                                    //|at first building
            ao();
            slow_hand(hand_prism_open,fast);
            PID_gyro_drive(-500*multiplier,1/multiplier);
            slow_arm(prism2,fast);
            slow_hand(closed,fast);
            slow_arm(up,fast);                               //| just cube in hand prism in place
            move(-155,155);
            msleep(1150);
            move(0,0);
            move(600,600);
            msleep(1000);
            move(0,0);
            ao();
            slow_arm(arm_fire,fast);
            slow_hand(open,fast);                            //|blocks in place for firefighter
            move(0,0);
            msleep(250);
            move(600,-600);
            msleep(1000);
            move(0,0);
            msleep(500);
            PID_gyro_drive(600*multiplier,2/multiplier);     //|stopped right before linefollow




        }
        else if(burning_building==2)
        {

            turn_with_gyro(400 * multiplier,80);
            //msleep(250);
            //move(300,-300);
            //msleep(590);
            move(0,0);
            msleep(100);
            move(630,600);
            msleep(7500);
            move(0,0);                                           //|at second building
            ao();
            slow_hand(hand_prism_open,fast);
            PID_gyro_drive(-500*multiplier,1/multiplier);
            slow_arm(prism2,fast);
            slow_hand(closed,fast);
            slow_arm(up,fast);                                   //| just cube in hand prism in place
            move(-155,155);
            msleep(1350);
            move(0,0);
            move(600,600);
            msleep(500);
            move(0,0);
            slow_arm(arm_fire,fast);
            slow_hand(open,fast);                                //| blocks in place for firefighter
            PID_gyro_drive(-600*multiplier,.4/multiplier);
            turn_with_gyro(400*multiplier,45);                   //| set up for gas valve


        }                                                        //| end of second case
        while(buffer(4)<1450){//| verify                         //| setting up for gas valve
            mav(left_motor,.35*(analog(3)));
            mav(right_motor,.35*(3400-analog(3)));

        }
        move(0,0);
        slow_arm(prism2,fast);
        PID_gyro_drive(-600*multiplier,1/multiplier);
        while(buffer(4)<1450){   //valve 2nd verify
            mav(left_motor,.35*(analog(3)));
            mav(right_motor,.35*(3400-analog(3)));

        }
        while(buffer(4) != 1475){ //| start of setup for blue linefollow
            if(buffer(4)<1475){   
                move(600,600);    
            }
            else if(buffer(4)>1475){
                move(-600,-600);
            }
            else{
                break;
            }
        }

        move(0,0);                //|
        slow_hand(closed-100,fast);//|
        move(0,0);				  //|--->grabs gas valve
        msleep(250);              //|
        slow_arm(up,slow);        //|

        while(buffer(4) != 2900){ //| start of setup for blue linefollow
            if(buffer(4)<2850){   
                move(600,600);    
            }
            else if(buffer(4)>2950){
                move(-600,-600);
            }
            else{
                break;
            }
        }						  
        PID_gyro_drive(600*multiplier,.25/multiplier);
        turn_with_gyro(300*multiplier,-90);
        PID_gyro_drive(-600*multiplier,.35/multiplier);
        square_up(white,300*multiplier); //| end of setup

        move(-725,-600);                 //| 
        while(digital(0)!= 1){           //| this is arc until physical is on
            //| and exits to physical linefollow
        }                                //|
        cmpc(1);
        cmpc(2);
        pvc_backwards_follow(); //| physical linefollow

    }
    
    return 0;
}