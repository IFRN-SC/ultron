#define MOTOR_D OUT_A
#define MOTOR_E OUT_C

void acionarMotores (int motor1, int motor2){
    OnFwdReg (MOTOR_E, motor1, OUT_REGMODE_SPEED);
    OnFwdReg (MOTOR_D, motor2, OUT_REGMODE_SPEED);
}  

void subirRampa () {
    atualizar ();
    if (sensor_preto_dir && sensor_branco_esq){
       acionarMotores (55, -55);
    }
    else if (sensor_branco_dir && sensor_preto_esq){
       acionarMotores (-55, 55);
    }
    else {
       acionarMotores (40, 40);
    }
} 

void encontrarLinha (){
   while (!(sensor_branco_dir && sensor_preto_esq)){
     atualizar ();
     acionarMotores (15, -15);  
   }
}
  
void desviarObstaculo (){
   acionarMotores (45, 45);
   Wait (1750);   
   acionarMotores (-45, 45);
   Wait(1200);
   acionarMotores (0, 0);
   Wait (2000);
   acionarMotores (45, 45);
   Wait (2800);   
   acionarMotores (-45, 45);
   Wait(1200);
   acionarMotores (0, 0);
   Wait (2000);
   acionarMotores (45, 45);
   Wait (1500);   
}
 
void alinharRobo () {
   acionarMotores (-25, -25);  Wait (300); 
   acionarMotores ( 45, -45);  Wait (1000);
      
   while (!(sensor_preto_dir && sensor_preto_esq))
   {
      atualizar();
      if (sensor_preto_dir && sensor_branco_esq)
      { 
         acionarMotores (-20, 20);
      }
      else if (sensor_branco_dir && sensor_preto_esq)
      { 
         acionarMotores (20, -20);
      }
      else {
         acionarMotores (-10, -10);
      }   
   }
}
