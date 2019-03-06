#include <kipr/botball.h>
#include <arm_hand_position.h>
#include <comp_lib.h>
#include <L_Mechanism.h>

//int arm_max = 1700;
int arm_prism = arm_max - 380;
int arm_min = arm_max - 1075;
int arm_valve = arm_max - 290;
int arm_building = arm_max - 550;

//int hand_max = 1050
int hand_min = hand_max - 705;
int hand_prism = hand_max - 400;
int hand_prism_close = hand_max - 555;
int hand_start = hand_max - 163;