#define hand 3
#define arm 2
#define base 0
#define arm_max 1375
#define arm_min 650
#define arm_start 1125
#define hand_max 2047 //also start
#define hand_min 0
#define base_max 1500
#define base_min 0
#define base_start 150
#define left 2
#define right 1

int up = arm_min;
int down = arm_max;
int mid = arm_start;
int front = base_max;
int back = base_min;
int open = hand_max;
int closed = hand_min;

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