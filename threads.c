#include <kipr/botball.h>
#include <threads.h>
#include <create_functions.h>
#include <create_comp_lib.h>

void thread_valve(){
    thread baseback;
    baseback = thread_create(slow_base_valve);
    thread_start(baseback);
    slow_arm(up);
    thread_destroy(baseback);
}

void thread_startpos(){
    thread startpos;
    startpos = thread_create(slow_start);
    slow_arm(down-100);
    thread_start(startpos);
    slow_base(back);
    thread_destroy(startpos);
}

void thread_pre_valve(){
    thread pre_valve;
    pre_valve = thread_create(slow_arm_up);
    thread_start(pre_valve);
    slow_base_front();
    thread_destroy(pre_valve);
}

void thread_ready_valve(){
    thread ready_valve;
    ready_valve = thread_create(slow_arm_pre_valve);
    thread_start(ready_valve);
    PID_gyro_drive_create(100,0.7);
    thread_destroy(ready_valve);
}



    /*square_up_front_create(white,100); // GAS VALVE RUN

    create_drive_direct(0,0);
    msleep(250);

    PID_gyro_drive_create(150,0.85);

    turn_with_gyro_create(70,-90); // TURN AT CORNER

    create_drive_direct(0,0);
    msleep(250);

    thread_start(pre_valve);
    //slow_base_front();
    PID_gyro_drive_create(300,1.2);

    square_up_back_create(white,75); // SQUARE AT BLACK TAPE IN FRONT OF VALVE
    create_drive_direct(0,0);
    msleep(250);
    
    create_drive_direct(25,25);
    msleep(250);
    
    thread_start(small_open);
    square_up_back_create(black,-75);

    create_drive_direct(0,0);
    msleep(250);

    thread_start(ready_valve);
    PID_gyro_drive_create(100,0.79); // roughly 0.7 is good value

    create_drive_direct(0,0);
    msleep(250);
    slow_hand(hand_valve);
    msleep(250);

    thread_start(baseback);
    slow_arm(up);

    create_drive_direct(-75,-75);
    msleep(1500);
    create_drive_direct(0,0);
    turn_with_gyro_create(100,02);

    PID_gyro_drive_create(100,0.75);
    create_drive_direct(0,0);


    thread_start(drop_valve);
    slow_arm(down);
    thread_start(hand_open);
    slow_arm(up);*/