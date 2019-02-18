#include <kipr/botball.h>
#include </home/root/Documents/KISS/Default User/tournament_file_Bot_A/include/comp_lib.h>
#include </home/root/Documents/KISS/Default User/tournament_file_Bot_A/include/L_Mechanism.h>
#include <camera_2019.h>
//#include <threads.h>


int main()
{
	//thread slowArmUp;
    //slowArmUp = thread_create(slow_arm_thread(up, slow));
    int burning_building = position_camera();   //|defined by camera for which building
    int target = buffer(ET);
    slow_hand(hand_start,fast);
    slow_arm(down,fast);
    slow_hand(open,fast);
    
    msleep(2000);
    if(analog(0) || analog(1) < white)
    { //| verifys IR sensor are working
        int burning_building = position_camera;
        slow_arm(prism2,slow);  
        move(625,600);                                       //| verify firefighter is in reach
        while(buffer(ET) <= 1900){}                           //|


        move(0,0);                 //| begin grabbing cube
       
        slow_hand(open,slow);
        slow_arm(down,slow);
        slow_hand(closed,fast);
        slow_arm(up,fast);
        msleep(500);
        //slow_arm(up,slow);   
        move(630,600);//|end of cube grab
        //thread_destroy(slowArmup);
        PID_gyro_drive(600*multiplier,1.6/multiplier);//| begin driving to prism
        turn_with_gyro(450 * multiplier,-90);
        square_up(2,250 * multiplier);                                                   
        move(0,0);                                           //| leave starting box
        msleep(150);
        cmpc(right_motor);
        cmpc(left_motor);
        PID_gyro_drive_distance(500*multiplier,1350);                            //| 
       										 //|----->prism verify for cube drop
        ao();												 //|

        slow_arm(prism2,slow);                               //| cube drop
        slow_hand(hand_prism_open,fast);
        ao();
        msleep(250);
        slow_arm(down,slow);                                 //| end of cube drop
        PID_gyro_drive(600 * multiplier,.75 / multiplier);
        slow_hand(prism,slow);
        msleep(200);                                         //| both in grasp
        PID_gyro_drive(-300 * multiplier,.30 /multiplier);   //|this is the end of start with firefighter and truck
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
            PID_gyro_drive(600*multiplier,2/multiplier);    //|stopped right before linefollow




        }
        else
        {

            turn_with_gyro(400 * multiplier,90);
            move(0,0);
            msleep(100);
            square_up(2,600*multiplier);
            move(0,0);
            msleep(100);
            turn_with_gyro(400*multiplier,-45);
            move(0,0);
            msleep(100);
            PID_gyro_drive(600*multiplier,3/multiplier);
            //msleep(250);
            //move(300,-300);
            //msleep(590);
            
            
            move(0,0);                                           //|at second building
            ao();
            slow_hand(hand_prism_open,fast);
            PID_gyro_drive(-500*multiplier,1/multiplier);
            slow_arm(prism2,fast);
            slow_hand(closed,fast);
            slow_arm(up,fast);                                   //| just cube in hand prism in place
            
            
            
            move(0,0);
            slow_arm(arm_fire,fast);
            slow_hand(open,fast);                                //| blocks in place for firefighter
            PID_gyro_drive(-600*multiplier,.4/multiplier);
            turn_with_gyro(400*multiplier,45);                   //| set up for gas valve


        }                                                        //| end of second case
        while(buffer(ET)<1440){//| verify                         //| setting up for gas valve
            mav(left_motor,.35*(analog(3)));
            mav(right_motor,.35*(3400-analog(3)));

        }
        move(0,0);
        slow_arm(prism2,fast);
        PID_gyro_drive(-600*multiplier,1/multiplier);
        while(buffer(ET)<1440){   //valve 2nd verify
            mav(left_motor,.35*(analog(3)));
            mav(right_motor,.35*(3400-analog(3)));

        }
        while(buffer(ET) != 1465){ //| start of setup for blue linefollow
            if(buffer(ET)<1475){   
                move(600,600);    
            }
            else if(buffer(ET)>1455){
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

        /*while(buffer(ET) != 2900){ //| start of setup for blue linefollow
            if(buffer(4)<2850){   
                move(600,600);    
            }
            else if(buffer(ET)>2950){
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

       /* move(-725,-600);                 //| 
        while(digital(0)!= 1){           //| this is arc until physical is on
            //| and exits to physical linefollow
        }                                //|
        
       
            pvc_backwards_follow(); //| physical linefollow*/
        
    }
	printf("x_Accel: %d", min_accel_x);
    printf("y_Accel: %d", max_accel_y);
    return 0;
}