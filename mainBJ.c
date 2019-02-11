#include <kipr/botball.h>
#include <create_functions.h>
#include <create_comp_lib.h>
#include <threads.h>

thread baseback;
//thread startpos;
thread pre_valve;
thread ready_valve;
thread drop_valve;
thread hand_open;
thread small_open;
thread arm_down;

int main()
{
    calibrate_gyro();

    baseback = thread_create(slow_base_valve);
    //startpos = thread_create(slow_start);
    pre_valve = thread_create(slow_arm_up2);
    ready_valve = thread_create(slow_arm_pre_valve);
    drop_valve = thread_create(slow_base_front);
    hand_open = thread_create(slow_hand_open);
    small_open = thread_create(slow_hand_small_open);
    arm_down = thread_create(slow_arm_down);

    //thread_startpos();
    //slow_start();

    start_position();

    create_connect();

    printf("Capacity Battery: %d\n",get_create_battery_capacity());
    printf("Charge Battery: %d\n",get_create_battery_charge());
    printf("Current Battery: %d\n",get_create_battery_current());
    printf("Temp Battery: %d\n",get_create_battery_temp());
    
    create_stop();
    msleep(4000);

    // TEST FOR MATERIALS
    
	turn_with_gyro_create(50,01);
    square_up_front_create(white,100);
    thread_start(drop_valve);
    square_up_back_create(white,100); 
    msleep(250);
    PID_gyro_drive_create(250,1.12);
    thread_start(arm_down);
    turn_with_gyro_create(50,-90);
    
    create_drive_direct(-45,-45);
    msleep(2000);
    
    create_drive_direct(0,0);
    msleep(250);
    
    PID_gyro_drive_create(150,0.905);
    slow_hand(closed);
    /*create_drive_direct(0,0);
    msleep(500);
    slow_arm(down-200);
    
    turn_with_gyro_create(50,-90);
   
    create_drive_direct(0,0);
    msleep(250);
    
    slow_hand(open);
    slow_arm(up);*/


    // LEAVE BASE

    /*square_up_front_create(white,100); ///
    square_up_back_create(white,100);  // |
    msleep(250);                       // |
                                       // |=> Leave base to corner
    PID_gyro_drive_create(300,1.2);    // | 
                                       // |
    square_up_front_create(black,100); ///      */

    // GRAB FOOD MATERIALS

    /*thread_start(drop_valve);
	create_drive_direct(-100,-100);
    thread_start(arm_down);
    turn_with_gyro_create(60,-90);
    create_drive_direct(0,0);
    msleep(250);*/


    // GRAB 3 WATERS

    /*create_drive_direct(0,0);
    msleep(250);

    create_drive_direct(50,50);
    msleep(350);
    thread_start(drop_valve);
    turn_with_gyro_create(60,-90);

    slow_arm(down);

    PID_gyro_drive_create(250,1.5);
    square_up_back_create(black,100);
    create_drive_direct(0,0);
    msleep(250);

    slow_hand(closed);*/

    create_disconnect();

    thread_destroy(baseback);
    thread_destroy(pre_valve);
    thread_destroy(ready_valve);
    //thread_destroy(startpos);
    thread_destroy(drop_valve);
    thread_destroy(hand_open);
    thread_destroy(small_open);
    thread_destroy(arm_down);

    return 0;
}
