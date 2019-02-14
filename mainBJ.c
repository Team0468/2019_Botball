#include <kipr/botball.h>
#include <create_functions.h>
#include <create_comp_lib.h>
#include <threads.h>

// WORKING ON MAKING ALL NUMBERS RELATIVE TO ONE

thread baseback;
//thread startpos;
thread pre_valve;
thread ready_valve;
thread drop_valve;
thread hand_open;
thread small_open;
thread arm_down;
thread hand_close;
thread raise_arm;
thread arm_bucket;

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
    hand_close = thread_create(slow_hand_close);
    raise_arm = thread_create(slow_arm_up);
    arm_bucket = thread_create(slow_arm_bucket);

/*    start_position();

    create_connect();
    //wait_for_light(0);
    
    create_stop();
    msleep(4000);

    // MATERIALS AND FIRST WATER
    
    square_up_back_create(white,-square);  ///
    square_up_front_create(white,-square); //
    thread_start(drop_valve);              // LEAVE BASE AND TURN
    PID_gyro_drive_create(-(PID-75),0.65); //
    turn_with_gyro_create(turn+10,90);     //
    short_pause();                         ///
    
    thread_start(arm_down);              ///
    PID_gyro_drive_create(-PID,0.6);     // SQUARE UP
    short_pause();                       // 
    thread_start(hand_close);            // GRAB MATERIALS
    PID_gyro_drive_create(PID-40,1.175); //
    create_stop();                       // 
    msleep(1500);                        /// 
    
    turn_with_gyro_create(turn+10,-90); ///
    fast_hand(open);                    /// DROP OFF MATERIALS IN BASE 
    
    thread_start(raise_arm);            ///
    PID_gyro_drive_create(-PID,1);      //
    turn_with_gyro_create(turn-20,90);  //
    thread_start(arm_down);             //
    PID_gyro_drive_create(-PID,0.9);    // PHYSICAL SQUARE UP
    thread_start(hand_open);            //
    PID_gyro_drive_create(PID-50,0.25); //
    PID_gyro_drive_create(-PID,0.4);    //
    short_pause();                      ///
    
    PID_gyro_drive_create(PID+100,1.25);  ///
    square_up_front_create(black,square); /// MOVE UP TO WATERS
    
    PID_gyro_drive_create(PID-50,0.5);   ///                     
    square_up_back_create(black,square); // REACH AND GRAB WATERS
    fast_hand(tight);                    //
    short_pause();                       ///
    
    thread_start(arm_bucket);            ///
	PID_gyro_drive_create(-(PID+100),2); //
    short_pause();                       // PHYSICAL SQUARE UP AND TURN TO BUCKET
    PID_gyro_drive_create(PID,0.5);      //
    turn_with_gyro_create(turn+10,45);   ///
                    
    fast_hand(open);                  /// 
    slow_arm(down);                   // DROP WATER IN BUCKET AND WRAP AROUND BUCKET
    thread_start(hand_close);         //
    PID_gyro_drive_create(PID,0.35);  //
    create_stop();                    //
    msleep(1000);                     //
    PID_gyro_drive_create(-PID,0.5);  ///
    
    turn_with_gyro_create(turn+10,45);  ///
    thread_start(raise_arm);            // MOVE BUCKET TO CORNER AND MOVE OUT OF WAY
    fast_hand(closed+700);              ///
    
    turn_with_gyro_create(turn+30,-90);  ///
    PID_gyro_drive_create(PID+125,1.5);  // 
    square_up_back_create(white,square); // PREPARE FOR NEXT MATERIALS
	short_pause();                       //
    turn_with_gyro_create(turn+30,-90);  ///
    */
    
    create_connect();
    reach_material();
	thread_start(arm_down);
	line_follow_reverse();
    create_disconnect();

    thread_destroy(baseback);
    thread_destroy(pre_valve);
    thread_destroy(ready_valve);
    //thread_destroy(startpos);
    thread_destroy(drop_valve);
    thread_destroy(hand_open);
    thread_destroy(small_open);
    thread_destroy(arm_down);
    thread_destroy(hand_close);
    thread_destroy(raise_arm);
    thread_destroy(arm_bucket);
    
    return 0;
}
