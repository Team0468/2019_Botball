#define arm 0
#define hand 1
#define arm_max 1700
#define arm_min 675
#define hand_max 1250
#define hand_prism_open 800
#define hand_min 400
#define hand_valve 459
#define hand_prism 500
#define arm_prism 1445
#define arm_fire 1150
#define hand_start 912

int down;
int up ;
int open;
int closed;
int block;
int prism;
int prism2;

//int arm_building == up + 200;

int slow;
int fast;
int hand_fully_closed;
int hand_bulldoze;
int arm_fully_up;
int arm_bulldoze;
int arbitrary_arm_position;

int slow_arm (int x,int speed);//this funtion slows 
/*{ 

    enable_servo (arm);
    int desired_position;
    int current_position = get_servo_position(arm);
    if (x > arm_max) {desired_position = arm_max;}
    else if(x < arm_min) {desired_position = arm_min;}
    else {desired_position = x;}
    switch(speed){
        case 1:
            while(current_position != desired_position)
            {
                if(current_position < desired_position)
                { current_position=current_position +1;
                 set_servo_position(arm, current_position);
                 msleep(1);
                }
                if(current_position > desired_position)
                { current_position=current_position -1;
                 set_servo_position(arm, current_position);

                 msleep(1);
                }
            }
            break;
        case 2:
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
            break;
    }

    set_servo_position (arm, x);
    msleep(15);
    disable_servo (arm);
    if(analog(0)<50){return 0;}
    else{return 1;}

}*/

int slow_hand ( int z, int speed );//this funtion slows 
int total;
int i;
int buffer(int sensor);



