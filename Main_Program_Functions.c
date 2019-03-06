#include <kipr/botball.h>
#include </home/root/Documents/KISS/Default User/tournament_file_Bot_A/include/comp_lib.h>
#include </home/root/Documents/KISS/Default User/tournament_file_Bot_A/include/L_Mechanism.h>
#include <arm_hand_position.h>

/*void cube_verify()
{
    if(buffer(4)>1600)
    {
        move(-400,-400);
        while(buffer(4)>1400){}
        move(0,0);
    }
    if(buffer(4)<1600)
    {
        move(400,400);
        while(buffer(4)<1400){}
        move(0,0);
    }
}*/

void pvc_backwards_follow(){
    //function developed and written by Ryan P. Webb & Treyton J. Ross
    move(-800, -800);
    msleep(500);
    ao();
    cmpc(1);
    cmpc(2);
    int min_accel_x = 55;
    int max_accel_y = 5;
    while(gmpc(left_motor) > -8000){
        if(accel_x() < min_accel_x){
            min_accel_x = accel_x();
        }
        if(accel_y() > max_accel_y){
            max_accel_y = accel_y();
        }
        if(accel_x() < -30){
            move(800,800);
        }
        else{
            if(digital(0) == 1){
                move(-800, -1000);
            }
            else{
                move(-1000, -800);
            }
        }
    }
    ao();
}
void bookItAcross(){
    calibrate_gyro();
	PID_gyro_drive(1000,1);
    calibrate_gyro();
    turn_with_gyro(800,90);
    square_up(black,-700);
    	move(0,0);
    	calibrate_gyro();
    PID_gyro_drive(1500,2.8);
    square_up(white,700);
    	move(0,0);
    	calibrate_gyro();
    PID_gyro_drive(1500,3);
    square_up(white,700);
    	move(0,0);
    	calibrate_gyro();
    PID_gyro_drive(1500,2.5);
    square_up(black,700);
    	move(0,0);
    	calibrate_gyro();
    		slow_arm(arm_max,fast);  //Put valve drop off here
    slow_hand(hand_max,fast);
    slow_arm(600,fast);
    cmpc(right_motor);
    move(0,600);
    double pi = 3.14159265359;
    while(gmpc(right_motor) < ((((pi)*5)/((2.75)/2*2*pi))*1400)){}
    ao();
    	calibrate_gyro();
    PID_gyro_drive(1500,1.5);
    square_up(white,700);
    calibrate_gyro();
    move(600,600);
    	msleep(1100);
    calibrate_gyro();
    turn_with_gyro(400,90);
}
void bookItAcrossValve(){
    slow_arm(arm_max,fast);
    slow_hand(hand_max,fast);
    slow_hand(hand_min,fast);
    calibrate_gyro();
	PID_gyro_drive(1000,1);
    calibrate_gyro();
    turn_with_gyro(800,90);
    square_up(black,-700);
    	move(0,0);
    	calibrate_gyro();
    PID_gyro_drive(1500,2.8);
    square_up(white,700);
    	move(0,0);
    	calibrate_gyro();
    PID_gyro_drive(1500,3);
    square_up(white,700);
    	move(0,0);
    	calibrate_gyro();
    PID_gyro_drive(1500,2.5);
    	  /*slow_arm(0,slow);
    		msleep(100);
    	slow_hand(hand_min-175,fast);
    		msleep(100);*/
        square_up(black,700);
    		turn_with_gyro(600,-45);
    		move(0,0);
    		calibrate_gyro();
    		slow_arm(arm_max,slow);
    			msleep(100);
    		turn_with_gyro(600,90);
    			msleep(100);
    		turn_with_gyro(600,-45);
    		slow_hand(hand_min+175,fast);
    			msleep(100);
    		slow_arm(1450,fast);
    			msleep(100);
    		slow_hand(hand_min-175,fast);
    			msleep(100);
    		slow_arm(0,slow);
    			msleep(100);
    	square_up(black,700);
    		move(0,0);
    		calibrate_gyro();
    	cmpc(right_motor);
    	move(-600,-600);
    while(gmpc(right_motor)>-800);{}
    	turn_with_gyro(600,90);
    		ao();
    if(analog(ET)<2000){
        move(-600,-600);
        	msleep(1000);
    }
    PID_gyro_drive_distance(600,1900);
    slow_arm(350,slow);
    PID_gyro_drive_distance(600,1100);
    slow_arm(700,slow);
    }
int electricLines()
{
    enable_servo(arm);
    enable_servo(hand);
    slow_arm(600,fast);
    set_servo_position(hand,0);
    	msleep(100);
    calibrate_gyro();
    PID_gyro_drive_distance(600,2800);
    
    slow_arm(300,fast);
    turn_with_gyro(600,-45);
    while(analog(right_IR)<analog_black){
        move(-300,-300);
    }
    slow_arm(600,fast);
    
    PID_gyro_drive(-600,4);
    	//msleep(100);
    turn_with_gyro(300,45);
    
    while(analog(ET)<2400){
        move(600,600);
    }
    
    slow_arm(300,fast);
    turn_with_gyro(300,45);
    PID_gyro_drive(-300,1);
    return 0;
    
}
