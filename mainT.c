#include <kipr/botball.h>
#include </home/root/Documents/KISS/Default User/tournament_file_Bot_A/include/comp_lib.h>
#include </home/root/Documents/KISS/Default User/tournament_file_Bot_A/include/L_Mechanism.h>
//#include </home/root/Documents/KISS/Default User/tournament_file_Bot_A/include/IR.h>
//#include </home/root/Documents/KISS/Default User/tournament_file_Bot_A/include/drive.h>
int main()
{
    int target = 500 + buffer(4);

    if(analog(0) || analog(1) > white){

        slow_arm(up,slow);
        PID_gyro_drive(-600 * multiplier, .35 / multiplier);

        PID_gyro_drive(600 * multiplier, .35 / multiplier);
        while(buffer(4) <= 1600){
            PID_gyro_drive(600 * multiplier, 1 /multiplier);
        }

        slow_hand(open,slow);
        slow_arm(down,slow);
        slow_hand(closed,fast);
        msleep(500);
        slow_arm(up,slow);

        // wait_for_light(3);

        PID_gyro_drive(600 * multiplier,1.60 / multiplier);


        turn_with_gyro(250 * multiplier,-90);
        square_up(black,200 * multiplier);
        //starting box
        move(600,600);
        while(buffer(4) <= 1400){


        }
        ao();
        //firefighter_adjust();
        slow_arm(prism2,slow);       //firefighter drop
        slow_hand(open,fast);
        ao();
        msleep(250);
        slow_arm(down,slow);
        PID_gyro_drive(600 * multiplier,.75 / multiplier);

        slow_hand(prism,slow);
        msleep(200);
        slow_arm(up,slow);                      //firetruck combo
        PID_gyro_drive(500 * multiplier,1.5 /multiplier);
        //square_up(black,600);
        msleep(250);
        turn_with_gyro(500 * multiplier,45);
        msleep(250);
        printf("%d",buffer(4));
        if(buffer(4)<900)
        {
            move(0,200);
            msleep(50);}
        
        move(600,600);
        while (buffer(4)<target)
        {}
        move(0,0);

        //PID_gyro_drive(600 * multiplier,4 / multiplier);
        // msleep(250);
        // turn_with_gyro(500 * multiplier,45);

    }
    else{
        return 0;
    }
}
