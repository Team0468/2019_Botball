#include <kipr/botball.h>
#include <create_functions.h>
#include <create_comp_lib.h>
#define hand 3
#define arm 2
#define base 0
#define arm_max 1200
#define arm_min 300
#define arm_mid 600
#define hand_max 2047 //also start
#define hand_min 600
#define hand_close 330
#define base_max 1300
#define base_min 0
#define base_start 150
#define left 2
#define right 1


/* If you change one of the defines above that matches one below, you must change the other as well */

//#define down 1200
//int down = down;
int up = down - 900;
int mid = down - 600;
int arm_water = down - 400;

//#define front 1300
//int front = front;
int back = front - 1300;

//#define closed 600
//int closed = closed;
int open = closed + 1447;
int tight = closed - 270;
int small_open = closed + 1000;
int tightish = closed - 75;

void slow_arm (int x )//this funtion slows 
{ 

    enable_servo(arm);
    int desired_position;
    int current_position = get_servo_position(arm);
    if (x > arm_max) {desired_position = arm_max;}
    else if(x < arm_min) {desired_position = arm_min;}
    else {desired_position = x;}

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

    set_servo_position (arm, x);
    disable_servo (arm);
}

void slow_hand (int x )//this funtion slows 
{ 

    enable_servo(hand);
    int desired_position;
    int current_position = get_servo_position(hand);
    if (x > hand_max) {desired_position = hand_max;}
    else if(x < hand_min) {desired_position = hand_min;}
    else {desired_position = x;}

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

    set_servo_position (hand, x);
    disable_servo (hand);
}

void slow_base (int x )//this funtion slows 
{ 

    enable_servo(base);
    int desired_position;
    int current_position = get_servo_position(base);
    if (x > base_max) {desired_position = base_max;}
    else if(x < base_min) {desired_position = base_min;}
    else {desired_position = x;}

    while(current_position != desired_position)
    {
        if(current_position < desired_position)
        { current_position=current_position +1;
         set_servo_position(base, current_position);
         msleep(2);
        }
        if(current_position > desired_position)
        { current_position=current_position -1;
         set_servo_position(base, current_position);
         msleep(2);
        }
    }

    set_servo_position (base, x);
    disable_servo (base);
}

void start_position(){
    slow_arm(up);
    slow_base(back);
    slow_arm(mid);
    slow_hand(open);
}

void arm_out(){
    slow_base(front);
    slow_arm(down);
}

void slow_base_valve()//this function slows 
{ 

    enable_servo(base);
    int desired_position;
    int current_position = get_servo_position(base);
    if (front-750 > base_max) {desired_position = base_max;}
    else if(front-750 < base_min) {desired_position = base_min;}
    else {desired_position = front-750;}

    while(current_position != desired_position)
    {
        if(current_position < desired_position)
        { current_position=current_position +1;
         set_servo_position(base, current_position);
         msleep(2);
        }
        if(current_position > desired_position)
        { current_position=current_position -1;
         set_servo_position(base, current_position);
         msleep(2);
        }
    }

    set_servo_position (base, front-750);
    disable_servo (base);
}

void slow_start() 
{ 	
    enable_servo(arm);
    enable_servo(hand);
    enable_servo(base);
    int d = mid;
    int dd = open;
    int ddd = back;
    int c = get_servo_position(arm);
    int cc = get_servo_position(hand);
    int ccc = get_servo_position(base);

    while((c != d) || (cc != dd) || (ccc != ddd)) // this loop is being exited instantly. need to fix.
    {
        if(c < d)
        { c=c+1;
         set_servo_position(arm, c);
         msleep(2);
        }
        if(c > d)
        { c=c-1;
         set_servo_position(arm, c);
         msleep(2);
        }
        if(cc < dd)
        { cc=cc+1;
         set_servo_position(hand, cc);
         msleep(2);
        }
        if(cc > dd)
        { cc=cc-1;
         set_servo_position(hand, cc);
         msleep(2);
        }
        if(ccc < ddd)
        { ccc=ccc+1;
         set_servo_position(base, ccc);
         msleep(2);
        }
        if(ccc > ddd)
        { ccc=ccc-1;
         set_servo_position(base, ccc);
         msleep(2);
        }
        msleep(2);
    }
    set_servo_position(arm, mid);
    set_servo_position(hand,open);
    set_servo_position(base,back);
    disable_servo(arm);
    disable_servo(hand);
    disable_servo(base);
}

void slow_arm_pre_valve()//this funtion slows 
{ 
    enable_servo(arm);
    int desired_position;
    int current_position = get_servo_position(arm);
    if ((up+625) > arm_max) {desired_position = arm_max;}
    else if((up+625) < arm_min) {desired_position = arm_min;}
    else {desired_position = (up+625);}

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

    set_servo_position (arm, (up+625));
    disable_servo (arm);
}

void slow_base_front()//this funtion slows 
{ 
    enable_servo(base);
    int desired_position;
    int current_position = get_servo_position(base);
    if (front > base_max) {desired_position = base_max;}
    else if(front < base_min) {desired_position = base_min;}
    else {desired_position = front;}

    while(current_position != desired_position)
    {
        if(current_position < desired_position)
        { current_position=current_position +1;
         set_servo_position(base, current_position);
         msleep(2);
        }
        if(current_position > desired_position)
        { current_position=current_position -1;
         set_servo_position(base, current_position);
         msleep(2);
        }
    }

    set_servo_position (base, front);
    disable_servo (base);
}

void slow_arm_up()//this funtion slows 
{ 
    enable_servo(arm);
    int desired_position;
    int current_position = get_servo_position(arm);
    if (up > arm_max) {desired_position = arm_max;}
    else if(up < arm_min) {desired_position = arm_min;}
    else {desired_position = up;}

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

    set_servo_position (arm, up);
    disable_servo (arm);
}

void slow_arm_up2()//this funtion slows 
{ 
    enable_servo(arm);
    int desired_position;
    int current_position = get_servo_position(arm);
    if (up > arm_max) {desired_position = arm_max;}
    else if(up < arm_min) {desired_position = arm_min;}
    else {desired_position = up;}

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

    set_servo_position (arm, up);
    disable_servo (arm);
    
    enable_servo(base);
    int desired_position2;
    int current_position2 = get_servo_position(base);
    if (front > base_max) {desired_position2 = base_max;}
    else if(front < base_min) {desired_position2 = base_min;}
    else {desired_position2 = front;}

    while(current_position2 != desired_position2)
    {
        if(current_position2 < desired_position2)
        { current_position2=current_position2 +1;
         set_servo_position(base, current_position2);
         msleep(2);
        }
        if(current_position2 > desired_position2)
        { current_position2=current_position2 -1;
         set_servo_position(base, current_position2);
         msleep(2);
        }
    }

    set_servo_position (base, front);
    disable_servo (base);
}

void slow_hand_open()//this funtion slows 
{ 
    enable_servo(hand);
    int desired_position;
    int current_position = get_servo_position(hand);
    if (small_open > hand_max) {desired_position = hand_max;}
    else if(small_open < hand_min) {desired_position = hand_min;}
    else {desired_position = small_open;}

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

    set_servo_position (hand, small_open);
    disable_servo (hand);
}

void slow_hand_small_open()//this funtion slows 
{ 
    enable_servo(hand);
    int desired_position;
    int current_position = get_servo_position(hand);
    if (closed-50 > hand_max) {desired_position = hand_max;}
    else if(closed-50 < hand_min) {desired_position = hand_min;}
    else {desired_position = closed-50;}

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

    set_servo_position (hand, closed-50);
    disable_servo (hand);
}

void slow_arm_down()//this funtion slows 
{ 
    enable_servo(arm);
    int desired_position;
    int current_position = get_servo_position(arm);
    if (down > arm_max) {desired_position = arm_max;}
    else if(down < arm_min) {desired_position = arm_min;}
    else {desired_position = down;}

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

    set_servo_position (arm, down);
    disable_servo (arm);
}

void slow_hand_close()//this funtion slows 
{ 
    enable_servo(hand);
    int desired_position;
    int current_position = get_servo_position(hand);
    if (tight > hand_max) {desired_position = hand_max;}
    else if(tight < hand_min) {desired_position = hand_min;}
    else {desired_position = tight;}

    while(current_position != desired_position)
    {
        if(current_position < desired_position)
        { current_position=current_position +1;
         set_servo_position(hand, current_position);
         msleep(1);
        }
        if(current_position > desired_position)
        { current_position=current_position -1;
         set_servo_position(hand, current_position);
         msleep(1);
        }
    }

    set_servo_position (hand, tight);
    disable_servo (hand);
}

void short_pause(){
    create_stop();
    msleep(250);
}

void slow_arm_bucket()//this funtion slows 
{ 
    enable_servo(arm);
    int desired_position;
    int current_position = get_servo_position(arm);
    if (down-500 > arm_max) {desired_position = arm_max;}
    else if(down-500 < arm_min) {desired_position = arm_min;}
    else {desired_position = down-500;}

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

    set_servo_position (arm, down-500);
    disable_servo (arm);
}

void shake_arm(){
    enable_servos(arm);
    int i = 0;
    while(i < 30){
        set_servo_position(arm,down-325);
        msleep(30);
        set_servo_position(arm,down-250);
        msleep(30);
        i=i+1;
    }
}

void fast_hand (int x )//this funtion slows 
{ 

    enable_servo(hand);
    int desired_position;
    int current_position = get_servo_position(hand);
    if (x > hand_max) {desired_position = hand_max;}
    else if(x < hand_min) {desired_position = hand_min;}
    else {desired_position = x;}

    while(current_position >= desired_position+2 || current_position <= desired_position-2)
    {
        if(current_position < desired_position)
        { current_position=current_position +2;
         set_servo_position(hand, current_position);
         msleep(2);
        }
        if(current_position > desired_position)
        { current_position=current_position -2;
         set_servo_position(hand, current_position);
         msleep(2);
        }
    }

    set_servo_position (hand, x);
    disable_servo (hand);
}

void grab_water(){
    
    thread ad;
    thread hc;
    
    ad = thread_create(slow_arm_down);
    hc = thread_create(slow_hand_close);
    
    turn_with_gyro_create(turn,-90);
    short_pause();
    thread_start(ad);
    fast_hand(open);
    short_pause();
    thread_start(hc);
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
    
    thread_destroy(ad);
    thread_destroy(hc);
}

void pile_water(int x){
    fast_hand(closed+x);
    shake_arm();
    fast_hand(open);
    slow_arm(down);
}

void push_water(){
    
    thread ab;
    
    ab = thread_create(slow_arm_bucket);
    
    PID_gyro_drive_create(PID,3.0);
    thread_start(ab);
    PID_gyro_drive_create(-PID,0.7);
    create_stop();
    msleep(650);
    
    thread_destroy(ab);
}

void recover_water(){
    PID_gyro_drive_create(-(PID*2),0.5);
    slow_arm(down);
    PID_gyro_drive_create(PID*2,0.35);
    fast_hand(closed);
    PID_gyro_drive_create(-(PID*2),0.35);
    slow_arm(arm_water);
    PID_gyro_drive_create(PID*2,0.5);
    fast_hand(open);
}

void first_water(){
    
    thread ad2;
    thread hc2;
    
    ad2 = thread_create(slow_arm_down);
    hc2 = thread_create(slow_hand_close);
    
    square_up_back_create(black,square);
    PID_gyro_drive_create(-PID,0.80);
	short_pause();
    turn_with_gyro_create(turn,90);
    short_pause();
    thread_start(ad2);
	PID_gyro_drive_create(-(PID*2),0.75);
    thread_start(hc2);
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
    
    thread_destroy(ad2);
    thread_destroy(hc2);
}

void all_water(){
    PID_gyro_drive_create(PID*2,1.5);
    short_pause();
    PID_gyro_drive_create(-PID,0.4);
    fast_hand(tightish);
    short_pause();
}

void first_water_down(){
    
    thread ab2;
    
    ab2 = thread_create(slow_arm_bucket);
    
    PID_gyro_drive_create(PID,2.3);
    slow_arm(down-250);
    fast_hand(closed+700);
    shake_arm();
    thread_start(ab2);
    create_stop();
    msleep(650);
    
    thread_destroy(ab2);
}

void all_water_drop(){
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
}

void shake_arm_bucket(){
    enable_servos(arm);
    int i = 0;
    while(i < 30){
        set_servo_position(arm,down-400);
        msleep(30);
        set_servo_position(arm,down-475);
        msleep(30);
        i=i+1;
    }
}