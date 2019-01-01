void limparLCD (){
    ClearScreen ();
    Wait (1000);
}

void calibrou (){
   TextOut (0,40, "Calibrado");  
   Wait (500);
   ClearScreen ();
}

void calibrouZona (){
   TextOut (0,40, "Zona calibrada");  
   Wait (500);
   ClearScreen ();
}

void print (int linha, string texto){
   TextOut (0,linha, texto);
}

void texto (string nome){
   TextOut (0, 50, nome);      
}

void mostra2 (int num1, int num2){
   NumOut (0,20, num1); 
   NumOut (0,10, num2);
}

void mostra3 (int num1, int num2, int num3){
   NumOut (0,30, num3); 
   NumOut (0,20, num2);
   NumOut (0,10, num1); 
}
