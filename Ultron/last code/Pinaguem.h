#ifndef PINAGUEM_H
#define PINAGUEM_H

#define MOTOR_D OUT_A
#define MOTOR_E OUT_C
#define MOTOR_G OUT_B

#define SENSOR_DIR S1
#define SENSOR_ESQ S4

#define SONAR_FRE SensorUS (IN_2)
#define SONAR_LAT SensorUS (IN_3)

#define DISTANCIA_OBSTA 7
#define DISTANCIA_RAMPA 15

void initComponents (){
   SetSensorColorFull (S1);
   SetSensorColorFull (S4);
   SetSensorLowspeed (IN_2);
   SetSensorLowspeed (IN_3);
   CloseFile(handle); 
}
#endif
