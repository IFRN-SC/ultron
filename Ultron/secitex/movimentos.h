
 void acionarMotores (int motor1, int motor2)
 {
    OnFwdReg (MOTOR_E, motor1, OUT_REGMODE_SPEED);
    OnFwdReg (MOTOR_D, motor2, OUT_REGMODE_SPEED);
 }  

 void resetRobo ()
 { 
    Off (OUT_ABC);
    Wait (2000); 
 }
  
 void subirRampa ()
 {
    atualizarSensores ();
    if (sensor_direito_preto && sensor_esquerdo_branco){
       acionarMotores (55, -55);
    }
    else if (sensor_direito_branco && sensor_esquerdo_preto) {
       acionarMotores (-55, 55);
    }
    else {
       acionarMotores (40, 40);
    }
 } 

 void encontrarLinha ()
 {
     while (!(sensor_direito_branco && sensor_esquerdo_preto))
     {
        atualizarSensores ();
        acionarMotores ( 15, -15);  
     }
 }
  
 void desviarObstaculo ()
 {
      acionarMotores (45, 45);
      Wait (1750);   
      acionarMotores (-45, 45);
      Wait(1000);
      acionarMotores (0, 0);
      Wait (2000);
      acionarMotores (45, 45);
      Wait (2800);   
      acionarMotores (-45, 45);
      Wait(1000);
      acionarMotores (0, 0);
      Wait (2000);
      acionarMotores (45, 45);
      Wait (1750);   
  }
 
 void alinharRobo ()
 {
     acionarMotores (-25, -25);  Wait (500); 
     acionarMotores ( 45, -45);  Wait (1000);
      
      while (!(sensor_direito_preto && sensor_esquerdo_preto))
      {
          atualizarSensores ();
          if (sensor_direito_preto && sensor_esquerdo_branco)
          { 
              acionarMotores (-20, 20);
          }
          else if (sensor_direito_branco && sensor_esquerdo_preto)
          { 
              acionarMotores (20, -20);
          }
          else {
              acionarMotores (-10, -10);
          }   
      }
 }
