void calibrarRobo ()
{
  while (true)
  {
    ClearScreen ();Wait(500);
    while (!(ButtonPressed(BTN2, false))){
      TextOut ( 0, 50, "todos branco");
      TextOut (20, 20, " [OK]  passa >");
      if (ButtonPressed (BTN4, false)){
        HSV sensorDir = SensorDireito();
        HSV sensorEsq = SensorEsquerdo();
        branco_direito = sensorDir.v;
        branco_esquerdo = sensorEsq.v;
        TextOut (0,40,"calibrado");
        Wait (500); ClearScreen ();     
      }
    }
       
   
    
    ClearScreen ();Wait(500);
    while (!(ButtonPressed(BTN2, false))){
      TextOut ( 0, 50, "todos cinza");
      TextOut (20, 20, " [OK]  passa >");
      if (ButtonPressed (BTN4, false)){
        HSV sensorDir = SensorDireito();
   	    HSV sensorEsq = SensorEsquerdo();
        cinza_direito = sensorDir.v;
        cinza_esquerdo = sensorEsq.v;
        TextOut (0,40,"calibrado");
        Wait (500); ClearScreen ();     
      }
    }

    
    ClearScreen ();Wait(500); 
    while (!(ButtonPressed(BTN2, false))){
       TextOut ( 0, 50, "deseja iniciar?");
       TextOut (20, 20, " [OK]  passa >");
       if (ButtonPressed (BTN4, false)){
         interromper = true; break;
       }   
    }
       if (interromper) interromper = false; break;     
  }
}

 #define VERDE 3
 #define PRETO 1

 #define BRANCO_CINZA_DIR calcularMedia (branco_direito, cinza_direito)
 #define BRANCO_CINZA_ESQ calcularMedia (branco_esquerdo, cinza_esquerdo)
  


void atualizarSensores ()
{
  HSV sensorDir = SensorDireito();
  HSV sensorEsq = SensorEsquerdo();

  sensor_direito_branco = (sensorDir.v > BRANCO_CINZA_DIR);
  sensor_esquerdo_branco = (sensorEsq.v > BRANCO_CINZA_ESQ);

  sensor_direito_cinza = ((sensorDir.v > VERDE_CINZA_DIR) && (!sensor_direito_branco));
  sensor_esquerdo_cinza = ((sensorEsq.v > VERDE_CINZA_ESQ) && (!sensor_esquerdo_branco));

  sensor_direito_verde = (Sensor(S1) == VERDE);
  sensor_esquerdo_verde = (Sensor(S4) == VERDE);

 
  sensor_direito_preto = (Sensor(S1) == PRETO);
  sensor_esquerdo_preto = (Sensor(S4) == PRETO);

 



}
