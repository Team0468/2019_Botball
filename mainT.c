#include <arm_hand_position.h>
#include <kipr/botball.h>
#include </home/root/Documents/KISS/Default User/tournament_file_Bot_A/include/comp_lib.h>
#include </home/root/Documents/KISS/Default User/tournament_file_Bot_A/include/L_Mechanism.h>
#include <camera_2019.h>
//#include <threads.h>


int main()
{

    //thread slowArmUp;
    //slowArmUp = thread_create(slow_arm_thread(up, slow));
    //int burning_building = 1;   //|defined by camera for which building(now defined in line 22 -RW)
    int target = buffer(ET);
    pre_test();

    //calibration_square();
    //msleep(5000);
    slow_hand(hand_start,fast);
    slow_arm(arm_max,fast);
    slow_hand(hand_max,fast);

    position_camera();
    waitingForLight();//makeshift waitforlight
    burning_building = building;//from waitingForLight
    printf("Burning Building: %d\n",burning_building);


    if(analog(0) || analog(1) < white)
    { //| verifys IR sensor are working
        //int burning_building = position_camera;
        slow_arm(arm_prism,slow);  
        PID_gyro_drive_distance(600*multiplier,2000);                         //|


        move(0,0);                 //| begin grabbing cube

        slow_hand(hand_max,slow);
        slow_arm(arm_max,slow);
        slow_hand(hand_min,fast);
        slow_arm(arm_min,fast);
        msleep(500);
        //slow_arm(up,slow);   
        move(630,600);//|end of cube grab
        //thread_destroy(slowArmup);
        PID_gyro_drive(600*multiplier,1.45/multiplier);//| begin driving to prism
        turn_with_gyro(450 * multiplier,-90);
        square_up(2,250 * multiplier);                                                   
        move(0,0);      
        ao();//| leave starting box
        msleep(300);

        PID_gyro_drive_distance(600*multiplier,1550); 
        msleep(100);
        PID_gyro_drive_distance(600*multiplier,1550);
        msleep(100);
        //| 
        //|----->prism verify for cube drop
        ao();												 //|

        slow_arm(arm_prism,slow);                               //| cube drop
        slow_hand(hand_max,fast);
        ao();
        msleep(250);
        slow_arm(arm_max,slow);                                 //| end of cube drop
        PID_gyro_drive(600 * multiplier,.75 / multiplier);
        slow_hand(hand_prism_close,slow);
        msleep(200);                                         //| both in grasp
        PID_gyro_drive(-300 * multiplier,.50 /multiplier);   //|this is the end of start with firefighter and truck
        if(burning_building == 1)                            //|beginning of cases
        {
            turn_with_gyro(400 * multiplier,45);
            msleep(250);
            move(630,600);
            msleep(3500);                                    //|at first building
            ao();
            slow_hand(hand_prism,fast);
            PID_gyro_drive(-500*multiplier,1/multiplier);
            slow_arm(arm_prism,fast);
            slow_hand(hand_min,fast);
            slow_arm(arm_min,fast);                               //| just cube in hand prism in place
            move(-155,155);
            msleep(1150);
            move(0,0);
            move(600,600);
            msleep(1000);
            move(0,0);
            ao();

            slow_hand(hand_max,fast);                            //|blocks in place for firefighter
            move(0,0);
            msleep(250);
            turn_with_gyro(300*multiplier,45);
            // move(600,-600);
            //msleep(1000);
            slow_arm(arm_valve,fast);
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
            PID_gyro_drive(600*multiplier,3.75/multiplier);
            //msleep(250);
            //move(300,-300);
            //msleep(590);


            move(0,0);                                           //|at second building
            ao();
            slow_hand(hand_prism,fast);
            PID_gyro_drive(-500*multiplier,1/multiplier);
            slow_arm(arm_prism,fast);
            slow_hand(hand_min,fast);
            slow_arm(arm_min,fast);                                   //| just cube in hand prism in place

            move(-155,155);
            msleep(1150);
            ao();
            move(0,0);
            PID_gyro_drive(600*multiplier,1.5/multiplier);


            move(0,0);
            //slow_arm(arm_building,fast);
            slow_hand(hand_max,fast);                                //| blocks in place for firefighter
            PID_gyro_drive(-600*multiplier,.4/multiplier);
            turn_with_gyro(400*multiplier,45);                   //| set up for gas valve


        }                                                        //| end of second case
        valve_verify();

        
        ao();
  /*      while(buffer(ET) != 1465){ //| start of setup for blue linefollow
            if(buffer(2)<1455){   
                move(600,600);    
            }
            else if(buffer(2)>1475){
                move(-600,-600);
            }
            else{
                break;
            }
        }

        move(0,0);                //|
        slow_hand(hand_min-100,fast);//|
        move(0,0);				  //|--->grabs gas valve
        msleep(250);              //|
        slow_arm(arm_min,slow);        //| */
        move(-500,-500);
        msleep(4000);

    }
    return 0;
}