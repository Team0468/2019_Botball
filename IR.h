#define analog_white 300
#define analog_black 3500
#define digital_right 0
#define digital_left 1
#define left_IR 1
#define right_IR 0
#define stop 0
#define left 1
#define right 0

void move(l_speed,r_speed){
    mav(right,r_speed);
    mav(left,l_speed);
}

int white = 1;
int black = 2;
int physical = 3;
int black_speed;
void square_up(int ending,int speed){
    if(speed > 0 && speed < 600){
        black_speed = 0.5*speed;
    }
    else{black_speed = 0.25*speed;}
    if(ending == 1 || ending == 2){
        while(1){
            if(analog(left_IR)<analog_white && analog(right_IR)<analog_white){
                move(speed,speed);
            }
            if(analog(right_IR)>analog_white){
                move(speed,stop);
            }
            if(analog(left_IR)>analog_white){
                move(stop,speed);
            }
            if(analog(left_IR)>analog_white && analog(right_IR)>analog_white) {
                move(stop,stop);
                break;
            }
        }
    }
    if(ending == 3){
        ao();
    }
    switch(ending){
        case 3:
            {
                while(1){
                    if(digital(digital_right)==0 && digital(digital_left)==0){
                        move(speed,speed);
                    }
                    if(digital(digital_right)==1){
                        move(speed,stop);
                    }
                    if(digital(digital_left)==1){
                        move(stop,speed);
                    }
                    if(digital(digital_right)==1 && digital(digital_left)==1){
                        move(stop,stop);
                        break;
                    }
                }
            }
        case 1:
            {
                while(1){
                    if(analog(left_IR)>analog_white && analog(right_IR)>analog_white){
                        move(black_speed,black_speed);
                    }
                    if(analog(left_IR)<analog_white){
                        move(stop,black_speed);
                    }
                    if(analog(right_IR)<analog_white){
                        move(black_speed,stop);
                    }
                    if(analog(left_IR)<analog_white && analog(right_IR)<analog_white){
                        move(stop,stop);
                        break;
                    }
                }
            }
        case 2:
            {
                while(1){
                    if(analog(left_IR)>analog_white && analog(right_IR)>analog_white){
                        move(-1*black_speed,-1*black_speed);
                    }
                    if(analog(left_IR)<analog_white){
                        move(stop,-1*black_speed);
                    }
                    if(analog(right_IR)<analog_white){
                        move(-1*black_speed,stop);
                    }
                    if(analog(left_IR)<analog_white && analog(right_IR)<analog_white){
                        move(stop,stop);
                        break;
                    }
                }
            }
    }
}