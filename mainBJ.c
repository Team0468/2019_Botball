#include <kipr/botball.h>
#include <create_functions.h>
#include <create_comp_lib.h>

int main()
{
    create_connect();
    calibrate_gyro();
 
    /*start_position();
    
    create_stop();
    msleep(7000);
    
    turn_with_gyro_create(50,01);
    square_up_front_create(white,100);
    square_up_back_create(white,100);
    
    PID_gyro_drive_create(300,1.2);
    square_up_front_create(white,100);
    
    PID_gyro_drive_create(150,0.9);
    
    turn_with_gyro_create(50,-90);
    
    slow_arm(up);
    slow_base(front);
    slow_arm(down);
    
    PID_gyro_drive_create(300,1.2);
    
    square_up_back_create(white,100);*/
    
    slow_hand(open);
    slow_arm(1130);
    create_stop();
    msleep(5000);
    slow_hand(closed);
    slow_arm(up);
    
    create_disconnect();
    
    return 0;
}
