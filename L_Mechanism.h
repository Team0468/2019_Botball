#define arm 0
#define hand 1
#define arm_max 1800
#define arm_min 675
#define hand_max 1350
#define hand_min 500
#define hand_prism 600
#define arm_prism 1500

int down = arm_max;
int up = arm_min;
int open = hand_max;
int closed = hand_min;
int block = hand_min;
int prism = hand_prism;
int prism2 = arm_prism;

int slow = 2
    int fast = 1
    int hand_fully_closed = hand_min;
int hand_bulldoze = hand_max;
int arm_fully_up = arm_min;
int arm_bulldoze = arm_max;
int arbitrary_arm_position = arm_max - 100;

void slow_arm (int x,int speed )//this funtion slows 
{ 

    enable_servo (arm);
    int desired_position;
    int current_position = get_servo_position(arm);
    if (x > arm_max) {desired_position = arm_max;}
    else if(x < arm_min) {desired_position = arm_min;}
    else {desired_position = x;}
    switch(speed){

        case 1:
            {
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

                     msleep(1)
                    }
                }
            }
        case 2:
            {
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

                     msleep(2)
                    }
                }
            }

            set_servo_position (arm, x);
            if(analog(0)<50){return 0;}
            else{return 1;}
            disable_servo (arm);
    }
    void slow_hand ( int z, int speed )//this funtion slows 
    { 

        enable_servo (hand);
        int desired_position;
        int current_position = get_servo_position(hand);
        if (z > hand_max) {desired_position = hand_max;}
        else if(z < hand_min) {desired_position = hand_min;}
        else {desired_position = z;}

        switch(speed){

        case 1:
            {
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
            }
        
                 case 2:
            {
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
            }
        }

            
          
             
             
        }

        set_servo_position (hand, z);
        if(analog(0)<50){return 0;}
        else{return 1;}
        disable_servo (hand);
    }
    /*void start_position(){
    slow_arm(arm_bulldoze);
	slow_hand(hand_min);


}*/
