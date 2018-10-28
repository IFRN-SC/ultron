#define SONAR_FRE SensorUS (IN_2)
#define SONAR_LAT SensorUS (IN_3)

#define DISTANCIA_RAMPA 15
#define DISTANCIA_OBST 7

void Executar (){

   while (!ButtonPressed(BTN4, false))
   {
       // atualiza os valores dos sensores         
       atualizar(); 
       verBateria();

       if (SONAR_LAT <= DISTANCIA_RAMPA){
          subirRampa ();  
       }
       else if (SONAR_FRE <= DISTANCIA_OBST){
          alinharRobo ();
          desviarObstaculo ();
	  encontrarLinha ();
       }

       // condições para o verde  
       else if (sensor_verde_dir && sensor_verde_esq){
           acionarMotores (-45, 45);
           Wait (1800);
       }
       else if (sensor_verde_dir && sensor_branco_esq){      
           acionarMotores (35, 35);
     	   Wait (700);
           acionarMotores (45, -45);
           Wait (900);
       }
       else if (sensor_branco_dir && sensor_preto_esq){      
           acionarMotores (35, 35);
     	   Wait (700);
           acionarMotores (-45, 45);
           Wait (900);  
       }
         
       // condições para o preto
       else if (sensor_preto_dir && sensor_preto_esq){
           while (!(sensor_branco_dir && sensor_branco_esq)){
               atualizar();
               acionarMotores (30, 30);
           }
       }
       else if (sensor_preto_dir && sensor_branco_esq){      
           acionarMotores (50, -50);  
       }
       else if (sensor_branco_dir && sensor_preto_esq){      
           acionarMotores (-50, 50);  
       }
       else {
           acionarMotores (25, 25);  
       }
   }
}
