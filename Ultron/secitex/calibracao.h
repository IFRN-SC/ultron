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
      TextOut ( 0, 50, "todos preto");
      TextOut (20, 20, " [OK]  passa >");
      if (ButtonPressed (BTN4, false)){
        HSV sensorDir = SensorDireito();
        HSV sensorEsq = SensorEsquerdo();
        preto_direito = sensorDir.v;
        preto_esquerdo = sensorEsq.v;
        S_direito_preto = sensorDir.s;
        S_esquerdo_preto = sensorEsq.s;
        TextOut (0,40,"calibrado");
        Wait (500); ClearScreen ();     
      }
    }
    
    
    ClearScreen ();Wait(500);
    while (!(ButtonPressed(BTN2, false))){
      TextOut ( 0, 50, "direito verde");
      TextOut (20, 20, " [OK]  passa >");
      if (ButtonPressed (BTN4, false)){
        HSV sensorDir = SensorDireito();
        H_direito_verde = sensorDir.h;
        S_direito_verde = sensorDir.s;
    	verde_direito = sensorDir.v;
        TextOut (0,40,"calibrado");
        Wait (500); ClearScreen ();     
      }
    }
    
    
    ClearScreen ();Wait(500);
    while (!(ButtonPressed(BTN2, false))){
      TextOut ( 0, 50, "esquerdo verde");
      TextOut (20, 20, " [OK]  passa >");
      if (ButtonPressed (BTN4, false)){ 
 	    HSV sensorEsq = SensorEsquerdo();     
     	H_esquerdo_verde = sensorEsq.h;
        S_esquerdo_verde = sensorEsq.s;
        verde_esquerdo = sensorEsq.v ;
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



 #define BRANCO_CINZA_DIR calcularMedia (branco_direito, cinza_direito)
 #define BRANCO_CINZA_ESQ calcularMedia (branco_esquerdo, cinza_esquerdo)
  
 #define PRETO_VERDE_DIR calcularMedia (preto_direito, verde_direito)
 #define PRETO_VERDE_ESQ calcularMedia (preto_esquerdo, verde_esquerdo)  

 #define VERDE_CINZA_DIR  calcularMedia (verde_direito, cinza_direito)
 #define VERDE_CINZA_ESQ  calcularMedia (verde_esquerdo, cinza_esquerdo)
 
 #define S_PRETO_VERDE_DIR calcularMedia (S_direito_verde, S_direito_preto)
 #define S_PRETO_VERDE_ESQ calcularMedia (S_esquerdo_verde, S_esquerdo_preto)




void atualizarSensores ()
{
  HSV sensorDir = SensorDireito();
  HSV sensorEsq = SensorEsquerdo();

  sensor_direito_branco = (sensorDir.v > BRANCO_CINZA_DIR);
  sensor_esquerdo_branco = (sensorEsq.v > BRANCO_CINZA_ESQ);

  sensor_direito_preto = ((sensorDir.v < PRETO_VERDE_DIR) && (sensorDir.s < S_PRETO_VERDE_DIR));
  sensor_esquerdo_preto = ((sensorEsq.v < PRETO_VERDE_ESQ) && (sensorEsq.s < S_PRETO_VERDE_ESQ));

  sensor_direito_verde = ((sensorDir.v > PRETO_VERDE_DIR) && (sensorDir.v < VERDE_CINZA_DIR)
  && (sensorDir.s > S_PRETO_VERDE_DIR) && (sensorDir.h > H_direito_verde));

  sensor_esquerdo_verde = ((sensorEsq.v > PRETO_VERDE_ESQ) && (sensorEsq.v < VERDE_CINZA_ESQ)
  && (sensorEsq.s > S_PRETO_VERDE_ESQ) && (sensorEsq.h > H_esquerdo_verde));

  sensor_direito_cinza = ((sensorDir.v > VERDE_CINZA_DIR) && (!sensor_direito_branco));
  sensor_esquerdo_cinza = ((sensorEsq.v > VERDE_CINZA_ESQ) && (!sensor_esquerdo_branco));
}