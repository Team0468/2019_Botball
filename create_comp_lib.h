/*#define right_motor 0
#define left_motor 1
#define target_theta_45 265000
#define target_theta_90 532500 // WORKING ON NUMBERS FOR 4184
#define target_theta_180 1095000 // ALL NUMBERS SHOULD BE GOOD
#define target_theta_01 50000
int target_theta_m45 = target_theta_45;
int target_theta_m90 = target_theta_90;
int target_theta_m180 = target_theta_180; */

/*#define analog_white 300
#define analog_black 3500
#define digital_right 0
#define digital_left 1
#define left_IR 1
#define right_IR 0
#define stop 0
#define cliff 1700*/

void move(int l_speed,int r_speed);
int white;
int black;
int physical;
int black_speed;
void square_up(int ending,int speed);
double bias;
double calibrate_gyro();
void drive_with_gyro(int speed, double time);
void PID_gyro_drive(int speed, double time);
void turn_with_gyro_create(int speed, int deg);
void turn_with_gyro(int speed, int deg);
void PID_gyro_drive_create(int speed, double time);
void square_up_front_create(int ending,int speed);
//switch(ending);
void linefollow_create(int speed);
void square_up_back_create(int ending,int speed);