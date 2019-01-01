void acionarMotores (int esquerdo, int direito){
   OnFwdReg (MOTOR_D, direito, OUT_REGMODE_SPEED);
   OnFwdReg (MOTOR_E, esquerdo, OUT_REGMODE_SPEED);
}

void super_verde(){
   while (!(branco_direito() && preto_esquerdo())){
     acionarMotores (50, -50);  
   }
   acionarMotores (50, -50);  
   Wait (1000);
   while (!(branco_direito() && preto_esquerdo())){
     acionarMotores (50, -50);  
   }
} 
      
void entrarSala (){
   acionarMotores (45,45);
   Wait (1000);
   acionarMotores (45,-45);
   Wait (1200);    
}
      
void moverGarra(int velocidade, int tempo){
    OnFwdReg (MOTOR_G, velocidade,OUT_REGMODE_SPEED);
    Wait (tempo);
}

void parar (){
   Off (OUT_AC);
   Wait (700);
}


void subirRampa (){
   if (preto_esquerdo() && branco_direito()){
      acionarMotores (-30, 30);
   }
   else if (branco_esquerdo() && preto_direito()){
      acionarMotores (30, -30);
   }
   else {
      acionarMotores (50,50);
   }       
}

void alinharNoPreto (){
    acionarMotores (45,-45);
    Wait (1200);
    while (!(preto_esquerdo() && preto_direito())){    
      if (preto_esquerdo() && branco_direito()) acionarMotores (40, -40); 
      if (branco_esquerdo() && preto_direito()) acionarMotores (-40, 40);
      else acionarMotores (-10, -10);
    }
}

void fazer_verde_esquerdo(){
   acionarMotores (20, 20);
   Wait (800);
   acionarMotores (-45, 45);
   Wait(1200);
   acionarMotores (20, 20);
   Wait (200);
   while (!(branco_direito() && preto_esquerdo())){
     acionarMotores (50, -50);  
   }
   acionarMotores (20, 20);
   Wait (100);
} 
 
void fazer_verde_direito(){
   acionarMotores (20, 20);
   Wait (800);
   acionarMotores (45, -45);
   Wait(1200);
   acionarMotores (20, 20);
   Wait (200);
   while (!(preto_direito() && branco_esquerdo())){
     acionarMotores (-50, 50);  
   }
   acionarMotores (20, 20);
   Wait (100);
} 
 


void desviarObstaculo (){
   acionarMotores (45, 45);
   Wait (2000);   
   acionarMotores (-45, 45);
   Wait(1250);
   acionarMotores (0, 0);
   Wait (2000);
   acionarMotores (45, 45);
   Wait (2900);   
   acionarMotores (-45, 45);
   Wait(1250);
   acionarMotores (0, 0);
   Wait (2000);
}

void fazerPretoPreto (){
  while (!(branco_direito() && branco_esquerdo())){
      acionarMotores (20, 20);  
  }
}

void encontrarLinha (){
   while (!(preto_direito() && preto_esquerdo())){
     acionarMotores (45, 45);
   }
   Off(OUT_ABC); Wait (1500);

   while (!(branco_direito() && preto_esquerdo())){
     acionarMotores (20, -20);  
   }
}
