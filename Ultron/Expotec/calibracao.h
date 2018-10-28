//variaveis globais importantes
bool sensor_preto_dir, sensor_preto_esq;
bool sensor_verde_dir, sensor_verde_esq;
bool sensor_branco_dir, sensor_branco_esq;
bool interromper = false;


void calibrarRobo ()
{
  while (true)
  {
    ClearScreen ();Wait(500);
 
    while (!(ButtonPressed(BTN2, false))){
      TextOut ( 0, 50, "todos branco");
      if (ButtonPressed (BTN4, false)){
        HSV sensorDir = SensorDireito();
        HSV sensorEsq = SensorEsquerdo();
        c.branco_direito = sensorDir.v;
        c.branco_esquerdo = sensorEsq.v;
        TextOut (0,40,"calibrado");
        Wait (500); ClearScreen ();     
      }
    }

    ClearScreen ();Wait(500);

    while (!(ButtonPressed(BTN2, false))){
      TextOut ( 0, 50, "todos preto");
      if (ButtonPressed (BTN4, false)){
        HSV sensorDir = SensorDireito();
        HSV sensorEsq = SensorEsquerdo();
        c.preto_direito = sensorDir.v;
        c.preto_esquerdo = sensorEsq.v;
        TextOut (0,40,"calibrado");
        Wait (500); ClearScreen ();     
      }
    }

    ClearScreen ();Wait(500); 

    while (!(ButtonPressed(BTN2, false))){
       TextOut ( 0, 50, "deseja iniciar?");
       if (ButtonPressed (BTN4, false)){
         interromper = true; break;
       }   
    }

    c.BRANCO_PRETO_DIR = (c.preto_direito + c.branco_direito)/ 2;
    c.BRANCO_PRETO_ESQ = (c.preto_esquerdo + c.branco_esquerdo)/ 2; 
     
    if (interromper == true) {break;}  
  }
}

void atualizar ()
{  
  HSV sensorDir = SensorDireito();
  HSV sensorEsq = SensorEsquerdo();
  
  // métodos importantes para destinguir as cores

  sensor_preto_dir = (sensorDir.v < c.BRANCO_PRETO_DIR);
  sensor_preto_esq = (sensorEsq.v < c.BRANCO_PRETO_ESQ);

  sensor_branco_dir = (sensorDir.v > c.BRANCO_PRETO_DIR);
  sensor_branco_esq = (sensorEsq.v > c.BRANCO_PRETO_ESQ);

  sensor_verde_dir = (Sensor (SENSOR_DIREITO) == VERDE);
  sensor_verde_esq = (Sensor (SENSOR_ESQUERDO) == VERDE);
}