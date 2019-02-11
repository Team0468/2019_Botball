#include <kipr/botball.h>
#include <camera_2019.h>
#define camera 0

int position_camera(){
    // This function was developed and written by Ryan P. Webb
    camera_open_black();
    msleep(150);
    camera_update();camera_update();camera_update();camera_update();camera_update();camera_update();
    //while(1)
    while(get_object_center_x(2,0) != 80){
        camera_update();

        if (get_object_count(2) < 1){
            off(camera);
        }
        else{
            motor(camera,(80 - get_object_center_x(2,0)));   
        }
    }
    cmpc(camera);
    while(gmpc(camera) > -240){
        motor(camera, -10);
    }
    freeze(camera);
    int i = 0;
    int building1 = 0;
    int building2 = 0;
    while(i < 50){
        camera_update();
        if(get_object_center_x(0,0) < 90){
            building1 += 1;
        }else if(get_object_center_x(0,0) > 90){
            building2 += 2;   
        }
        i++;
    }
    if (building2 > building1){
        camera_close();
        return 2;
    }else{
        camera_close();
     	return 1;   
    }

    camera_close();
    printf("Building: %d\n", burning_building);
    return 0;
}