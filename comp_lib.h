#define right_motor 0
#define left_motor 1
#define target_theta_45 225000 //numbers for wallaby-4188
#define target_theta_90 507500
#define target_theta_180 1061500
#define target_theta_360 2175000
#define target_theta_m45 225000
#define target_theta_m90 507500
#define target_theta_m180 1061500
#define target_theta_m360 2175000
void move(int lsp,int rsp) {
    mav(right_motor,rsp);
    mav(left_motor,lsp);
}

double bias = 0.0;

double calibrate_gyro(){
    int i = 0;
    double avg = 0;
    while( i < 50){
        avg += gyro_z();
        msleep(1);
        i++;
        printf("Gyro Z: %d\n",gyro_z());
    }
    bias = avg / 50.0;
    printf("New Bias: %f\n", bias);
    return bias;
}

void drive_with_gyro(int speed, double time){
    double startTime = seconds();
    double theta = 0;
    while(seconds() - startTime < time){
        if (theta < 1000 && theta > -1000){
            mav(right_motor, speed);
            mav(left_motor, speed);
        }
        else if (theta < 1000){
            mav(right_motor, speed + 100);
            mav(left_motor, speed - 100);
        }
        else{
            mav(right_motor, speed - 100);
            mav(left_motor, speed + 100);
        }
        msleep(10);
        theta += (gyro_z() - bias) * 10;
        printf("%f",theta);
    }
}

void PID_gyro_drive(int speed, double time){
    double startTime = seconds();
    double theta = 0;
    while((seconds() - startTime) < time){
        if(speed > 0){
            mav(right_motor, (speed - (speed * (theta/100000))));            
            mav(left_motor, (speed + (speed * theta/100000)));
        }

        else{
            mav(left_motor, (speed + (speed * theta/100000)));            
            mav(right_motor, (speed - (speed * (theta/100000))));
        }
        msleep(10);
        theta += (gyro_z() - bias) * 10;
    }
}

void turn_with_gyro_create(int speed, int deg){
    double theta = 0;
    int targetTheta; 
    switch(deg){
        case 45:
            targetTheta = target_theta_45;
            create_drive_direct(speed,speed*-1);
            break;
        case 90:
            targetTheta = target_theta_90; //507500
            create_drive_direct(speed,speed*-1);
            break;
        case 180:
            targetTheta = target_theta_180;
           create_drive_direct(speed,speed*-1);
            break;
        case 360:
            targetTheta = target_theta_360;
            create_drive_direct(speed,speed*-1);
            break;
        case -45:
            targetTheta = target_theta_m45;
            create_drive_direct(speed*-1,speed);
            break;
        case -90:
            targetTheta = target_theta_m90;
            create_drive_direct(speed*-1,speed);
            break;
        case -180:
            targetTheta = target_theta_m180;
            create_drive_direct(speed*-1,speed);
            break;
        case -360:
            targetTheta = target_theta_m360;
            create_drive_direct(speed*-1,speed);
            break;
        default:
            targetTheta = 0;
            break;
    }  
    while(theta < targetTheta){
        msleep(10);
        theta += abs(gyro_z() - bias) * 10;
        printf("Turn Gyro Z: %d\n",gyro_z());
    }
    create_drive_direct(0,0);
}


void turn_with_gyro(int speed, int deg){
    double theta = 0;
    int targetTheta; 
    switch(deg){
        case 45:
            targetTheta = target_theta_45;
            move(speed,speed*-1);
            break;
        case 90:
            targetTheta = target_theta_90;
            move(speed,speed*-1);
            break;
        case 180:
            targetTheta = target_theta_180;
            move(speed,speed*-1);
            break;
        case 360:
            targetTheta = target_theta_360;
            move(speed,speed*-1);
            break;
        case -45:
            targetTheta = target_theta_m45;
            move(speed*-1,speed);
            break;
        case -90:
            targetTheta = target_theta_m90;
            move(speed*-1,speed);
            break;
        case -180:
            targetTheta = target_theta_m180;
            move(speed*-1,speed);
            break;
        case -360:
            targetTheta = target_theta_m360;
            move(speed*-1,speed);
            break;
        default:
            targetTheta = 0;
            break;
    }  
    while(theta < targetTheta){
        msleep(10);
        theta += abs(gyro_z() - bias) * 10;
        printf("Turn Gyro Z: %d\n",gyro_z());
    }
    mav(right_motor, 0);
    mav(right_motor, 0);
}

