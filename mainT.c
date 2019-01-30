#include <kipr/botball.h>
#include </home/root/Documents/KISS/Default User/tournament_file_Bot_A/include/comp_lib.h>
#include </home/root/Documents/KISS/Default User/tournament_file_Bot_A/include/L_Mechanism.h>
//#include </home/root/Documents/KISS/Default User/tournament_file_Bot_A/include/IR.h>
//#include </home/root/Documents/KISS/Default User/tournament_file_Bot_A/include/drive.h>
int burning_building = 1; //
int main()
{
    int target = buffer(4);

    if(analog(0) || analog(1) > white){

        slow_arm(up,slow);
        PID_gyro_drive(-600 * multiplier, .35 / multiplier);

        PID_gyro_drive(600 * multiplier, .35 / multiplier);
        move(600,600);
        while(buffer(4) <= 1900){


        }

        move(0,0);
        slow_hand(open,slow);
        slow_arm(down,slow);
        slow_hand(closed,fast);
        msleep(500);
        slow_arm(up,slow);

        // wait_for_light(3);

        PID_gyro_drive(600 * multiplier,1.90 / multiplier);


        turn_with_gyro(450 * multiplier,-90);
        square_up(black,200 * multiplier);
        //starting box
        move(600,600);
        while(buffer(4) <= 1400){}
        cube_verify();
        ao();

        slow_arm(prism2,slow);       //firefighter drop
        slow_hand(open,fast);
        ao();
        msleep(250);
        slow_arm(down,slow);
        PID_gyro_drive(600 * multiplier,.75 / multiplier);

        slow_hand(prism,slow);
        msleep(200);
        //slow_arm(up,slow);//firetruck combo
        //square_up(black,600);
        //PID_gyro_drive(-500 * multiplier,.30 /multiplier);
        //square_up(black,600);

        turn_with_gyro(500 * multiplier,45);
        msleep(250);
        move(600,600);
        msleep(3000);
        ao();
        //square_up(black,500); //this is the end of start with firefighter and truck
        if(burning_building == 1)
        {
            slow_arm(down,fast);
            slow_hand(open,fast);
            slow_arm(prism2,fast);
            PID_gyro_drive(-500*multiplier,1/multiplier);
            slow_hand(closed,fast);
            slow_arm(up,fast);
            move(300,600);
            msleep(350);
            move(300,600);
            while(buffer(4)>=1400){  
            }
            move(0,0);
            ao();
            move(600,600);
            while(buffer(4)<=1500){
            }
            move(0,0);
            ao();
            slow_arm(arm_fire,fast);
            slow_hand(open,fast);


        }
    }
    return 0;
}
