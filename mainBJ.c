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

    start_position();

    create_stop();
    msleep(2000);
    
    create_connect();
    //wait_for_light(0);
    
    // MATERIALS AND FIRST WATER

    square_up_back_create(white,-square);  ///
    square_up_front_create(white,-square); //
    short_pause();                         //
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

    PID_gyro_drive_create(PID-50,0.6);   ///                     
    square_up_back_create(black,square); // REACH AND GRAB WATERS
    fast_hand(tight);                    //
    short_pause();                       ///

    thread_start(arm_bucket);            ///
	PID_gyro_drive_create(-(PID+100),2); //
    short_pause();                       // PHYSICAL SQUARE UP AND TURN TO BUCKET
    PID_gyro_drive_create(PID,0.5);      //
    turn_with_gyro_create(turn+10,45);   ///

    fast_hand(closed+700);            ///
    shake_arm_bucket();               //
    fast_hand(open);
    slow_arm(down);                   // DROP WATER IN BUCKET AND WRAP AROUND BUCKET
    thread_start(hand_close);         //
    PID_gyro_drive_create(PID,0.35);  //
    create_stop();                    //
    msleep(1000);                     //
    PID_gyro_drive_create(-PID,0.5);  ///

    turn_with_gyro_create(turn+10,45);  ///
    thread_start(raise_arm);            // MOVE BUCKET TO CORNER AND MOVE OUT OF WAY
    fast_hand(closed+700);              ///
    
    turn_with_gyro_create(turn,-90);
    PID_gyro_drive_create(-(PID),1);
    short_pause();
    PID_gyro_drive_create(PID,0.5);
    turn_with_gyro_create(turn,-90);
    PID_gyro_drive_create(PID,1);
	square_up_front_create(square,black);
    short_pause();
    PID_gyro_drive_create(PID,0.75);
    thread_start(arm_down);
    turn_with_gyro_create(turn,90);
    thread_start(hand_close);
    square_up_front_create(square,black);
    
    /*    turn_with_gyro_create(turn+30,-90);  ///
    PID_gyro_drive_create(PID+125,1.5);  // 
    square_up_back_create(white,square); // PREPARE FOR NEXT MATERIALS
	short_pause();                       //
	PID_gyro_drive_create(PID,0.3);      //   maybe keep this line
    turn_with_gyro_create(turn+30,-90);  ///                               */
    
    
    

    // WORKING ON GRABBING WATERS

    /*slow_base(front);
    slow_arm(up);
    fast_hand(open);
    square_up_back_create(black,square);
    PID_gyro_drive_create(-PID,0.80);
    
	short_pause();
    turn_with_gyro_create(turn,90);        // FIRST WATERS
    short_pause();
    thread_start(arm_down);
	PID_gyro_drive_create(-(PID*2),0.75);
    thread_start(hand_close);
    square_up_front_create(white,square);
    short_pause();
    PID_gyro_drive_create(PID-50,0.475);
    create_stop();
    msleep(900);
    slow_arm(down-300);
    PID_gyro_drive_create(-(PID*2),1);
    square_up_front_create(black,square);
	short_pause();
    turn_with_gyro_create(turn,90);
    short_pause();

    PID_gyro_drive_create(PID,2.3);          // MOVEMENT BETWEEN WATERS
    slow_arm(down-250);
    fast_hand(closed+700);
    shake_arm();
    thread_start(arm_bucket);
    create_stop();
    msleep(650);

    turn_with_gyro_create(turn,-90); // SECOND WATERS
    short_pause();
    thread_start(arm_down);
    fast_hand(open);
    short_pause();
    thread_start(hand_close);
    square_up_front_create(white,square);
    short_pause();
    PID_gyro_drive_create(PID-50,0.475);
    create_stop();
    msleep(900);
    slow_arm(down-250);
    PID_gyro_drive_create(-(PID*2),1);
    square_up_front_create(black,square);
	short_pause();
    turn_with_gyro_create(turn,90);
    short_pause();
    
    fast_hand(closed+700);
    shake_arm();
    fast_hand(open);
    slow_arm(down);
    
    PID_gyro_drive_create(PID,3.0); // BULLDOZE WATERS
    thread_start(arm_bucket);
    PID_gyro_drive_create(-PID,0.7);
    create_stop();
    msleep(650);

    turn_with_gyro_create(turn,-90);
    short_pause();
    thread_start(arm_down);
    fast_hand(open);
    short_pause();
    thread_start(hand_close);
    square_up_front_create(white,square);
    short_pause();
    PID_gyro_drive_create(PID-50,0.475);
    create_stop();
    msleep(900);
    slow_arm(down-250);
    PID_gyro_drive_create(-(PID*2),1);
    square_up_front_create(black,square);
	short_pause();
    turn_with_gyro_create(turn,90);
    short_pause();
    
    fast_hand(closed+700);
    shake_arm();
    fast_hand(open);
    slow_arm(down);
    
    PID_gyro_drive_create(PID,3.0); // BULLDOZE WATERS
    thread_start(arm_bucket);
    PID_gyro_drive_create(-PID,0.7);
    create_stop();
    msleep(650);

    turn_with_gyro_create(turn,-90);
    short_pause();
    thread_start(arm_down);
    fast_hand(open);
    short_pause();
    thread_start(hand_close);
    square_up_front_create(white,square);
    short_pause();
    PID_gyro_drive_create(PID-50,0.475);
    create_stop();
    msleep(900);
    slow_arm(down-250);
    PID_gyro_drive_create(-(PID*2),1);
    square_up_front_create(black,square);
	short_pause();
    turn_with_gyro_create(turn,90);
    short_pause();
    
    fast_hand(closed+800);
    shake_arm();
    fast_hand(open);
    slow_arm(down);
    
    PID_gyro_drive_create(PID*2,1.5);
    short_pause();
    PID_gyro_drive_create(-PID,0.4);
    fast_hand(tightish);
    short_pause();
    
    PID_gyro_drive_create(-(PID*2),1.25);
    short_pause();
    turn_with_gyro_create(turn,-90);
    PID_gyro_drive_create(-(PID*4/3),2);
    PID_gyro_drive_create(PID,0.3);
    short_pause();
    turn_with_gyro_create(turn,90);
    slow_arm(arm_water);
    square_up_front_create(black,square);
    turn_with_gyro_create(turn-50,01);
    fast_hand(open);
    
    PID_gyro_drive_create(-(PID*2),0.5);
    slow_arm(down);
    PID_gyro_drive_create(PID*2,0.35);
    fast_hand(closed);
    PID_gyro_drive_create(-(PID*2),0.35);
    slow_arm(arm_water);
    PID_gyro_drive_create(PID*2,0.5);
    fast_hand(open); */
    
    
    
    // GRAB WATERS LESS LINES

    /*slow_base(front);
    slow_arm(up);
    fast_hand(open);
    
    first_water();
    first_water_down();

    grab_water();
    pile_water(700);
    push_water();

    grab_water();
    pile_water(700);
    push_water();

    grab_water();
    pile_water(800);
    
    all_water();
    all_water_drop();
    
    recover_water();
    */
    
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