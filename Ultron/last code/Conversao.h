struct RGB {
  float r;
  float g;
  float b;
};

struct HSV { 
  float s;
  float v;
  float h;
};

// CRIEI ESSE MÉTODO PARA COMPARAR A SATURAÇÃO DOS VALORES CALIBRADOS (RGB)
// ONDE, CALCULO 20% DE SATURAÇÃO E VERIFICO SE O VALOR QUE TA DANDO ESTÁ ENTRE 
// ESSA SATURAÇÃO DE 20% DA COR

Manipulador saturacao_cor (RGB &cor){
   Manipulador valor;
   valor.redMax   = cor.r + (cor.r * 0.20); 
   valor.redMin   = cor.r - (cor.r * 0.20); 

   valor.greenMax = cor.g + (cor.g * 0.20); 
   valor.greenMin = cor.g - (cor.g * 0.20); 

   valor.blueMax  = cor.b + (cor.b * 0.20); 
   valor.blueMin  = cor.b - (cor.b * 0.20); 
   return valor;
}

// CRIEI UM MÉTODO PARA COMPARAR SE OS VALORE LIDOS ESTÃO 
// DENTRO DOS 20% DE SATURAÇÃO
bool contains (Manipulador &limite, RGB &cores){
   return 
   (cores.r > limite.redMin && cores.r < limite.redMax)     &&
   (cores.g > limite.greenMin && cores.g < limite.greenMax) &&
   (cores.b > limite.blueMin && cores.b < limite.blueMax) ;
}

// LER OS VALORES EM RGB
RGB lerSensorRGB (int porta){
   RGB valRetorno ;   
   valRetorno.r = ColorSensorValue (porta, INPUT_RED);
   valRetorno.g = ColorSensorValue (porta, INPUT_GREEN);
   valRetorno.b = ColorSensorValue (porta, INPUT_BLUE);
   return valRetorno ; 
}

// MÉTODO PARA CONVERTER EM HSV
HSV converter (RGB value){
   HSV valRetorno ; 
   float max = maximo (value.r, value.g, value.b);
   float min = minimo (value.r, value.g, value.b);
   valRetorno.h = calculeH (max, min, value.r, value.g, value.b);
   valRetorno.s = ((max - min)/max) * 100 ;
   valRetorno.v = max;
   return valRetorno ;
}

HSV SensorDireito (){
   RGB valRGB = lerSensorRGB (SENSOR_DIR);
   HSV valRetorno = converter (valRGB);
   return valRetorno;
}

HSV SensorEsquerdo (){
   RGB valRGB = lerSensorRGB (SENSOR_ESQ);
   HSV valRetorno = converter (valRGB);
   return valRetorno;
}
