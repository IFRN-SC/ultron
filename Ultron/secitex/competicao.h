void iniciarCompeticao ()
{
   ClearScreen ();
   TextOut(20,30, " [OK] reset cod");
    
    
    while (!(ButtonPressed(BTN4, false)))
    {  
        atualizarSensores ();
    
        // condições para o cinza e rampa
        if (SONAR_LAT < DISTANCIA_RAMPA){
              if (sensor_direito_cinza && sensor_esquerdo_cinza)
              {
 		          SetSensorColorBlue (S1);
 	              SetSensorColorBlue (S4);
                  acionarMotores (30, 30); Wait (5000);
                  acionarMotores ( 0, 80); Wait (2000);
                  escolherZona (posicaoZona);
              }
	          else {
                  subirRampa (); 
              }
        }

        // condição para o obstaculo
        else if (SONAR_FRE < DISTANCIA_OBSTACULO)
        {
           alinharRobo ();
           desviarObstaculo ();
           encontrarLinha ();
        }

        // condição para o verde     
        else if (sensor_direito_verde || sensor_esquerdo_verde)
    	{        
            if (sensor_direito_verde && sensor_esquerdo_verde){
               acionarMotores (-45, 45);
               Wait (1800);
            }
            else if (sensor_direito_verde && sensor_esquerdo_branco){
               acionarMotores (35, 35);
     	       Wait (700);
               acionarMotores (45, -45);
               Wait (900);
            }
            else if (sensor_direito_branco && sensor_esquerdo_verde) {
               acionarMotores (35, 35);
     	       Wait (700);
     	       acionarMotores (-45, 45);
               Wait (900);
            }
        } 
    
        else if (sensor_direito_preto && sensor_esquerdo_preto){
            while (!(sensor_direito_branco && sensor_esquerdo_branco))
	    {
               atualizarSensores ();
               acionarMotores (25, 25);
            }
        }
        else if (sensor_direito_preto && sensor_esquerdo_branco){
            acionarMotores (50, -50);
        }
        else if (sensor_direito_branco && sensor_esquerdo_preto) {
            acionarMotores (-50, 50);
        }
          
        else {
            acionarMotores (20, 20);
     	}
    }
            ClearScreen ();
            resetRobo (); 
}
