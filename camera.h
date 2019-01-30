#define camera 3

void position_camera(){
    // This function was developed and written by Ryan Webb.
	camera_open_black();
    msleep(20);
    camera_update();
    while(get_object_center_x(2,0) != 80){
        camera_update();
        msleep(15);
     	if (get_object_center_x(2,0) > 80){
         	while (get_object_center_x(2,0) > 80){
                camera_update();
             	motor(camera, (get_object_center_x(2,0) - 80));   
            }
        }
        if (get_object_center_x(2,0) < 80){
         	while (get_object_center_x(2,0) < 80){
                camera_update();
             	motor(camera, 80 - get_object_center_x(2,0));   
            }
        }
    }
    camera_close();
}