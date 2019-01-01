void iniciarRobo (){

      open_for_read ();
      read_media (memoria);
      read_rgb_dir (ManipuladorDir);
      read_rgb_dir (ManipuladorEsq);

          while (true){

                // condição para sala 3 
                if (salaEncontrada ()){
                    entrarSala ();         
                    switch (memoria.zona){
                      case 'd':
                         zonaDireita ();
                         break;
                      case 'e':
                         zonaEsquerda ();
                         break; 
                     default :
                         zonaBunda ();   
                    }
                        break;
                }
                // condição para a rampa
                else if (rampaEncontrada ()){
                    subirRampa ();
                }
                // condição para o obstaculo
                else if (obstaculoEncontrado ()) {
                    alinharNoPreto ();
                    desviarObstaculo ();
                    encontrarLinha ();
                }
                // condições para o verde 
                else if (verde_esquerdo()){
                    fazer_verde_esquerdo();
                }
                else if (verde_direito()){
                    fazer_verde_direito();
                }
                // condições para o preto
                else if (preto_esquerdo() && branco_direito()){
                	acionarMotores (-60,60);
                } 
                else if (branco_esquerdo() && preto_direito()){
                	acionarMotores (60,-60);
                } 
                // para qualquer outra cor
                else {
                    acionarMotores(20,20);
                }
          }
}
