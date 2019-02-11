#include <kipr/botball.h>
#include <create_functions.h>
#define hand 3
#define arm 2
#define base 0
#define arm_max 1200
#define arm_min 400
#define arm_mid 790
#define hand_max 2047 //also start
#define hand_min 50
#define base_max 1300
#define base_min 0
#define base_start 150
#define left 2
#define right 1

int up = arm_min;
int down = arm_max;
int mid = arm_mid;
int front = base_max;
int back = base_min;
int open = hand_max;
int closed = hand_min;
int hand_valve = 0;

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
    slow_hand(closed);
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
    if (open > hand_max) {desired_position = hand_max;}
    else if(open < hand_min) {desired_position = hand_min;}
    else {desired_position = open;}

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

    set_servo_position (hand, open);
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