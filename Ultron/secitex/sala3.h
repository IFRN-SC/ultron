void zonaDireita (){}
void zonaEsquerda (){}
void zonaBunda (){}

void escolherZona (int zona){
   switch (zona){
      case 1:
         zonaDireita ();
         break;
      case 2:
         zonaEsquerda ();
         break;
      case 3:
         zonaBunda ();
         break;
   }
}

