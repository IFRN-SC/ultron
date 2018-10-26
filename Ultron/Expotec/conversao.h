#define SENSOR_DIREITO S1
#define SENSOR_ESQUERDO S4 


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



// métodos importantes para calcular os valores
float calcularMaior (float num1, float num2, float num3)
{
    if ((num1 >= num2) && (num1 >= num3)){return num1;} else 
    if ((num2 >= num1) && (num2 >= num3)){return num2;} else 
    if ((num3 >= num1) && (num3 >= num2)){return num3;}
}  

float calcularMenor (float num1, float num2,float num3)
{
    if ((num1 <= num2) && (num1 <= num3)){return num1;} else 
    if ((num2 <= num1) && (num2 <= num3)){return num2;} else 
    if ((num3 <= num1) && (num3 <= num2)){return num3;}
}

float calculeH (float maximo, float minimo, float red, float green, float blue)
{
    if ((maximo == red) && (green >= blue)){return (60 * (green - blue)/(maximo - minimo) + 0);} else 
    if ((maximo == red) && (green <  blue)){return (60 * (green - blue)/(maximo - minimo) + 360);} else 
    if (maximo == green){return (60 * (blue - red)/(maximo - minimo) + 120);} else 
    if (maximo == blue){return (60 * (red - green)/(maximo - minimo) + 240);}
}
  




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
   RGB valRGB = lerSensorRGB (SENSOR_DIREITO);
   valRetorno = converter (valRGB);
   return valRetorno;
}

HSV SensorEsquerdo (){
   HSV valRetorno ;
   RGB valRGB = lerSensorRGB (SENSOR_ESQUERDO);
   valRetorno = converter (valRGB);
   return valRetorno;
}

