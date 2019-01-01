void indentificaZona (char zona){
  // zona direita
  if (zona == 'd'){ zonaDireita(); break;} else 
  // zona esquerda
  if (zona == 'e'){ zonaEsquerda(); break;} else 
  // zona bunda
  if (zona == 'b'){ zonaBunda(); break;}     
}


void iniciarRobo (){
      // ler os valores que estão escritos
      // no arquivo txt na memoria permanente
      open_for_read ();
      read_media (memoria);
      read_rgb_dir (ManipuladorDir);
      read_rgb_dir (ManipuladorEsq);

          while (true){
                // condição para sala 3 
                if (salaEncontrada ()){
                    entrarSala ();         
                    // objeto memoria que possui os valores da calibração SALVOS!!! 
                    indentificadorZona (memoria.zona);   
                    break;
                }
                // condição para a rampa
                else if (rampaEncontrada ()){
                    // MINI SEGUIR LINHA NA RAMPA
                    subirRampa ();
                }
                // condição para o obstaculo
                else if (obstaculoEncontrado ()) {
                    alinharNoPreto ();      // ROBO ALINHA NO PRETO
                    desviarObstaculo ();    // ROBO DESVIA O OBSTACULO
                    encontrarLinha ();      // ROBO ENCONTRA LINHA APÓS OBSTACULO
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
