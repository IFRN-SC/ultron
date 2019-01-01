char indentificadorZona;
float brancoDir, pretoDir, cinzaDir;
float brancoEsq, pretoEsq, cinzaEsq;



void calibraRobo (){
   bool interromper = false;
   while (!interromper){
   
     limparLCD ();
     while (!(ButtonPressed(BTN2, false))){
       texto("Branco todos");
       HSV sensorDir = SensorDireito();
       HSV sensorEsq = SensorEsquerdo();
       mostra2 (sensorDir.v, sensorEsq.v);
          if (ButtonPressed (BTN4, false)){
             brancoDir = sensorDir.v;
             brancoEsq = sensorEsq.v;
	         calibrou ();
          }
     }
     
   
     limparLCD ();
     while (!(ButtonPressed(BTN2, false))){
       texto("Preto todos");
       HSV sensorDir = SensorDireito();
       HSV sensorEsq = SensorEsquerdo();
       mostra2 (sensorDir.v, sensorEsq.v);
          if (ButtonPressed (BTN4, false)){
             pretoDir = sensorDir.v;
             pretoEsq = sensorEsq.v;
             calibrou ();
          }
     }


             if (true){

                 limparLCD ();
                 while (!(ButtonPressed(BTN2, false))){
                   texto("Direito verde");
   			       RGB sensorDir = lerSensorRGB(SENSOR_DIR );
   	               mostra3(sensorDir.r,sensorDir.g,sensorDir.b);
				     if (ButtonPressed (BTN4, false)){
					    ManipuladorDir = saturacao_cor(sensorDir);
				        calibrou ();
					 }
				 }

                 limparLCD ();
                 while (!(ButtonPressed(BTN2, false))){
                   texto("Esquerdo verde");
       			   RGB sensorEsq = lerSensorRGB(SENSOR_ESQ);
			       mostra3(sensorEsq.r,sensorEsq.g,sensorEsq.b);
				     if (ButtonPressed (BTN4, false)){
				        ManipuladorEsq = saturacao_cor(sensorEsq);
  			            calibrou ();
					 }
				 }
             }


     limparLCD ();
     while (!(ButtonPressed(BTN2, false))){
       texto("Cinza todos");
       HSV sensorDir = SensorDireito();
       HSV sensorEsq = SensorEsquerdo();
       mostra2 (sensorDir.v, sensorEsq.v);
          if (ButtonPressed (BTN4, false)){
             cinzaDir = sensorDir.v;
             cinzaEsq = sensorEsq.v;
             calibrou ();
          }
     }


     limparLCD();
     while (!(ButtonPressed(BTN2, false))){
       texto ("Zona Direita");  
       if (ButtonPressed(BTN4, false)){
            indentificadorZona = 'd';
            calibrouZona ();
       }
     }

     limparLCD();
     while (!(ButtonPressed(BTN2, false))){
       texto ("Zona Esquerda");  
       if (ButtonPressed(BTN4, false)){
            indentificadorZona = 'e';
            calibrouZona ();
       }
     }

     limparLCD();
     while (!(ButtonPressed(BTN2, false))){
       texto ("Zona Bunda");  
       if (ButtonPressed(BTN4, false)){
            indentificadorZona = 'b';
            calibrouZona ();
       }
     }

     limparLCD ();    
     while (!(ButtonPressed(BTN2, false))){
       texto("Quer iniciar? ");
          if (ButtonPressed (BTN4, false)){
             memoria.mediaDir = (pretoDir + brancoDir)/2;
             memoria.mediaEsq = (pretoEsq + brancoEsq)/2;
             memoria.cinzaDir = (cinzaDir + brancoDir)/2;
             memoria.cinzaEsq = (cinzaEsq + brancoEsq)/2;  
             memoria.zona = indentificadorZona;
             interromper = true; break;
          } 
       }  
     }
}



bool preto_direito (){
   HSV sensor = SensorDireito ();
   return (sensor.v < memoria.mediaDir);
}
bool preto_esquerdo (){
   HSV sensor = SensorEsquerdo ();
   return (sensor.v < memoria.mediaEsq);
}

bool branco_direito (){
   HSV sensor = SensorDireito ();
   return (sensor.v > memoria.mediaDir);
}
bool branco_esquerdo (){
   HSV sensor = SensorEsquerdo ();
   return (sensor.v > memoria.mediaEsq);
}

bool cinza_direito (){
   HSV sensor = SensorDireito ();
   return (sensor.v < memoria.cinzaDir);
}
bool cinza_esquerdo (){
   HSV sensor = SensorEsquerdo ();
   return (sensor.v < memoria.cinzaEsq);
}

bool verde_esquerdo (){
   RGB sensorEsq = lerSensorRGB(SENSOR_ESQ);         
   return contains (ManipuladorEsq, sensorEsq);    
}
bool verde_direito (){
   RGB sensorDir = lerSensorRGB(SENSOR_DIR);         
   return contains (ManipuladorDir, sensorDir);    
}



bool obstaculoEncontrado () {
   return (SONAR_FRE < DISTANCIA_OBSTA);
}
bool rampaEncontrada () {
   return (SONAR_LAT < DISTANCIA_RAMPA);
}
bool salaEncontrada () {
   return (cinza_direito() && cinza_esquerdo() && rampaEncontrada());
}

