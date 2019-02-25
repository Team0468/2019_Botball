#include <kipr/botball.h>
#include <camera_2019.h>
#define camera 0
void takeBuildingPic();
int building1 = 0;
int building2 = 0;
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

    //thread building;
    /*building = thread_create(takeBuildingPic);
    thread_start(building);
    wait_for_light(3);
    thread_destroy(building);*/
    /*if (building1 > building2){
        camera_close();
        return 1;
    }else{
        camera_close();
        return 2;   
    }*/

    camera_close();
    //printf("Building: %d\n", burning_building);
    return 0;
}
void takeBuildingPic(){
    // This function was written and developed by Ryan P. Webb
    camera_open_black();
    int i = 0;
    building1 = 0;
    building2 = 0;
    while(1){
        while(i < 50){
            camera_update();
            if(get_object_center_x(0,0) < 90){
                building1 += 1;
            }else if(get_object_center_x(0,0) > 90){
                building2 += 2;   
            }
            i++;
        }
        if (building1 > building2){
            building = 1;
        }else{
            building = 2;   
        }
        printf("Building: %d\n",building);
        msleep(5000);
    }
    camera_close();
}
void waitingForLight(){
    //This function was written and developed by Ryan P. Webb
    thread building;
    building = thread_create(takeBuildingPic);
    thread_start(building);
    wait_for_light(3);
    thread_destroy(building);
    camera_close();
}