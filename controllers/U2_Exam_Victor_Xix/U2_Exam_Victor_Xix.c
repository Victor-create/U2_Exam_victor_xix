/*
 * File:          U2_Exam_Victor_Xix.c
 * Date:
 * Description:
 * Author:
 * Modifications:
 */

/*
 * You may need to add include files like <webots/distance_sensor.h> or
 * <webots/differential_wheels.h>, etc.
 */
#include <stdio.h>
#include <webots/robot.h>
#include <webots/distance_sensor.h>
#include <webots/position_sensor.h>
//#include <webots/keyboard.h>
#include <webots/motor.h>

/*
 * You may want to add macros here.
 */
#define TIME_STEP 64
#define PI 3.1416

double b1=0;  //posicion inicial en 0
double b2=0; // Posicion incial en 0
double b3=0;
//double pos_final;
//double ObsSen_Pos;

/*
 * This is the main program.
 * The arguments of the main function can be specified by the
 * "controllerArgs" field of the Robot node
 */
int main(int argc, char **argv)
{
  /* necessary to initialize webots stuff */
  wb_robot_init();
  //wb_keyboard_enable(TIME_STEP);
 
  
  /*
   * You should declare here WbDeviceTag variables for storing
   * robot devices like this:
   *  WbDeviceTag my_sensor = wb_robot_get_device("my_sensor");
   *  WbDeviceTag my_actuator = wb_robot_get_device("my_actuator");
   */
   WbDeviceTag wheel_1 = wb_robot_get_device("motor_1");
   WbDeviceTag wheel_2 = wb_robot_get_device("motor_2");
   WbDeviceTag wheel_3 = wb_robot_get_device("motor_3");
   WbDeviceTag ps_1 = wb_robot_get_device("position_1");
   WbDeviceTag ps_2 = wb_robot_get_device("position_2");
   WbDeviceTag ps_3 = wb_robot_get_device("position_3");
   
   wb_position_sensor_enable(ps_1, TIME_STEP);
   wb_position_sensor_enable(ps_2, TIME_STEP);
   wb_position_sensor_enable(ps_3, TIME_STEP);
   
   ///////////distance sensor/////////7
   WbDeviceTag ds_r1 = wb_robot_get_device("distance_sensor1");
   WbDeviceTag ds_r2 = wb_robot_get_device("distance_sensor2");
   
   wb_distance_sensor_enable(ds_r1, TIME_STEP);
   wb_distance_sensor_enable(ds_r2, TIME_STEP);
  
  /* main loop
   * Perform simulation steps of TIME_STEP milliseconds
   * and leave the loop when the simulation is over
   */
  while (wb_robot_step(TIME_STEP) != -1) {
  
  double pos_final1, pos_final2,pos_final3;
  double a1, a2,a3;//posiciones actuales
  double RPM_1, RPM_2, RPM_3;
  
  ////rueda 1//////////////
  a1 = wb_position_sensor_get_value(ps_1);
          pos_final1 = ((a1 - b1)*1)/0.064;  //0-064 es el time step en segundos
          RPM_1= (pos_final1*60)/(2*PI);
          b1 = a1;
          
  //////rueda 2////////////
  a2 = wb_position_sensor_get_value(ps_2);
          pos_final2 = ((a2 - b2)*1)/0.064;
          RPM_2= (pos_final2*60)/(2*PI);
          b2 = a2;
          
  //////rueda 3////////////
  a3 = wb_position_sensor_get_value(ps_3);
          pos_final3 = ((a3 - b3)*1)/0.064;
          RPM_3= (pos_final3*60)/(2*PI);
          b3 = a3;
          
          
  /////////velocidad lineal del robot///////
  float radio=0.06; //radio de la llanta
  double linvel1, linvel2, linvel3;//velocidad lineal por llanta
  double linvel_rob; //velocidad lineal del robot
  
  linvel1=pos_final1*radio;
  linvel2=pos_final2*radio;
  linvel3=pos_final3*radio;
  linvel_rob=(linvel1+linvel2+linvel3)/3;
  
   
  //int key=wb_keyboard_get_key();
    
    //if (key==WB_KEYBOARD_UP){
    //double speed = -1;
    wb_motor_set_position(wheel_1, INFINITY);
    wb_motor_set_velocity(wheel_1, -1);
    wb_motor_set_position(wheel_2, INFINITY);
    wb_motor_set_velocity(wheel_2, 1);
    wb_motor_set_position(wheel_3, INFINITY);
    wb_motor_set_velocity(wheel_3, 0);
    
     /*
    if(key==WB_KEYBOARD_DOWN){
    //double speed = -1;
    wb_motor_set_position(wheel_1, INFINITY);
    wb_motor_set_velocity(wheel_1, -1.33);
    wb_motor_set_position(wheel_2, INFINITY);
    wb_motor_set_velocity(wheel_2, -1.33);
    wb_motor_set_position(wheel_3, INFINITY);
    wb_motor_set_velocity(wheel_3, -1.33);
    }
    
    else if(key==WB_KEYBOARD_LEFT){
    wb_motor_set_position(wheel_1, INFINITY);
    wb_motor_set_velocity(wheel_1, 15);
    wb_motor_set_position(wheel_2, INFINITY);
    wb_motor_set_velocity(wheel_2, 0);
    wb_motor_set_position(wheel_3, INFINITY);
    wb_motor_set_velocity(wheel_3, 0);
    }
   
    if(key==WB_KEYBOARD_RIGHT){
    wb_motor_set_position(wheel_1, INFINITY);
    wb_motor_set_velocity(wheel_1, 0);
    wb_motor_set_position(wheel_2, INFINITY);
    wb_motor_set_velocity(wheel_2, 15);
    wb_motor_set_position(wheel_3, INFINITY);
    wb_motor_set_velocity(wheel_3, 15);
    }
    
    if(key==WB_KEYBOARD_END){
    wb_motor_set_position(wheel_1, INFINITY);
    wb_motor_set_velocity(wheel_1, 0);
    wb_motor_set_position(wheel_2, INFINITY);
    wb_motor_set_velocity(wheel_2, 0);
    wb_motor_set_position(wheel_3, INFINITY);
    wb_motor_set_velocity(wheel_3, 0);
    }
    */
    
     //printf("Left velocity: %f RPM\n",pos_final);
     //printf("SLW_RPM= %f RPM\LW_RPM= %f RPM\tRW_RPM= %f RPM\t\tlinear velocity= %f\n",RPM_1,RPM_2,RPM_3,vel_rob);
     printf("Wheel1:RW_RPM %f RPM\tWheel2:RW_RPM %f RPM\tWheel3:RW_RPM %f RPM\tlinear_velocity %f \n",RPM_1,RPM_2,RPM_3,linvel_rob);
     //printf("Linear:RW_RPM %f RPM\n",);
     //fflush(stdout);
    

    /*
     * Read the sensors :
     * Enter here functions to read sensor data, like:
     *  double val = wb_distance_sensor_get_value(my_sensor);
     */

    /* Process sensor data here */

    /*
     * Enter here functions to send actuator commands, like:
     * wb_differential_wheels_set_speed(100.0,100.0);
     */
  };

  /* Enter your cleanup code here */

  /* This is necessary to cleanup webots resources */
  wb_robot_cleanup();

  return 0;
}