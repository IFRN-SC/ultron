#ifndef MATEMATICA_H
#define MATEMATICA_H

float media (float num1, float num2){
    return (num1+num2)/2;
}

float maximo (float num1, float num2, float num3){
    if ((num1 > num2)&&(num1 > num3)) return num1; else
    if ((num2 > num1)&&(num2 > num3)) return num2; else 
    if ((num3 > num1)&&(num3 > num2)) return num3;
}

float minimo (float num1, float num2, float num3){
    if ((num1 < num2)&&(num1 < num3)) return num1; else
    if ((num2 < num1)&&(num2 < num3)) return num2; else 
    if ((num3 < num1)&&(num3 < num2)) return num3;
}


float calculeH (float maximo, float minimo, float red, float green, float blue){
    if ((maximo == red) && (green >= blue)){return (60 * (green - blue)/(maximo - minimo) + 0);} else 
    if ((maximo == red) && (green <  blue)){return (60 * (green - blue)/(maximo - minimo) + 360);} else 
    if (maximo == green){return (60 * (blue - red)/(maximo - minimo) + 120);} else 
    if (maximo == blue){return (60 * (red - green)/(maximo - minimo) + 240);}
}
  
#endif
