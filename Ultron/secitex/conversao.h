struct RGB {
  float red;
  float green;
  float blue;
};

struct HSV { 
  float h;
  float s;
  float v;
};

RGB lerSensorRGB (int porta){
   RGB valRetorno ;
   
   valRetorno.red = ColorSensorValue (porta, INPUT_RED);
   valRetorno.green = ColorSensorValue (porta, INPUT_GREEN);
   valRetorno.blue = ColorSensorValue (porta, INPUT_BLUE);
   
   return valRetorno ; 
}

HSV converter (RGB value){
   HSV valRetorno ; 
   
   float maximo = calcularMaior (value.red, value.green, value.blue);
   float minimo = calcularMenor (value.red, value.green, value.blue);
   
   valRetorno.h = calculeH (maximo, minimo, value.red, value.green, value.blue);
   valRetorno.s = ((maximo - minimo)/maximo) * 100 ;
   valRetorno.v = maximo;
 
   return valRetorno ;
}

HSV SensorDireito (){
   HSV valRetorno ;
   RGB valRGB = lerSensorRGB (SENSOR_DIR);
   valRetorno = converter (valRGB);
   return valRetorno;
}

HSV SensorEsquerdo (){
   HSV valRetorno ;
   RGB valRGB = lerSensorRGB (SENSOR_ESQ);
   valRetorno = converter (valRGB);
   return valRetorno;
}

