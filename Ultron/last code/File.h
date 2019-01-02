#define FILE_NAME "banco.txt"   //nome do arquivo salvo na mémoria
#define FILE_SIZE 1024          //tamanho do arquivo em bytes
byte handle = 0;                // indentificador do arquivo

//método responsável por para 
//o código assim que necessário
void shutdown(const int delay){
   if (handle) CloseFile(handle);
   Wait(delay);
   Stop(true);
}

// método onde deve ser retornado um número em byte 
// onde é uma determinada resposta em bytes
// Ex::    unsigned int rtn_code = CreateFile(FILE_NAME, file_size, handle);
// o método retornará um determinado número em caso o arquivo sej criado com sucesso
// caso contrario terá outro indentificador retornado

// retorna o numero do indeniicador na tela
void rtn_code_out(const unsigned int code){
   TextOut(0, LCD_LINE2, "code ");
   NumOut(50, LCD_LINE2, code);
}


// método construido para abrir o nosso aquivo da memoria 
// com a intenção de escrever no mesmo, logo no mesmo irá 
// mostrar na tela as diversas excessões que possam ser possiveis 
void open_for_write(){
   unsigned int file_size = FILE_SIZE;
   handle = 0;
   unsigned int rtn_code = CreateFile(FILE_NAME, file_size, handle);
   if (rtn_code == LDR_FILEEXISTS)
      rtn_code = OpenFileAppend(FILE_NAME, file_size, handle);
   switch (rtn_code)
   {
   case LDR_SUCCESS:
      return;
   case LDR_FILEISFULL:
      TextOut(0, LCD_LINE1, "arquivo cheio!");
      break;
   default:
      TextOut(0, LCD_LINE1, "pode escrever!");
      rtn_code_out(rtn_code);
      break;
   }
   shutdown(SEC_2);
}

// método construido para abrir o nosso aquivo da memoria 
// com a intenção de verificar se o nosso arquivo existe na memoria
void open_for_read(){
   unsigned int file_size = FILE_SIZE;
   handle = 0;
   unsigned int rtn_code = OpenFileRead(FILE_NAME, file_size, handle);

   if (rtn_code != LDR_SUCCESS){
      TextOut(0, LCD_LINE1, "pode ler!");
      rtn_code_out(rtn_code);
      shutdown(SEC_2);
   }
}

// método feito para escrever (salvar) os valores de rgb de uma strutuc  
void write_rgb (const Manipulador &recd){
    unsigned int rtn_code = Write (handle, recd);
    if (rtn_code != LDR_SUCCESS){
        switch (rtn_code){
           case LDR_EOFEXPECTED:
             TextOut(0, LCD_LINE1, "sem espaço!");
             break;
           default:
             TextOut(0, LCD_LINE1, "escrever falho!");
             rtn_code_out(rtn_code);
             break;
        }
           shutdown(SEC_2);    
    }
}

// método feito para escrever (salvar) os valores de HSV de uma strutuc  
void write_recd(const armazenar recd){
   unsigned int rtn_code = Write(handle, recd);
   if (rtn_code != LDR_SUCCESS){
      switch (rtn_code)
      {
      case LDR_EOFEXPECTED:
         TextOut(0, LCD_LINE1, "sem espaço!");
         break;
      default:
         TextOut(0, LCD_LINE1, "escrever falho!");
         rtn_code_out(rtn_code);
         break;
      }
      shutdown(SEC_2);
   }
}

// método feito para ler (carregar) os valores da média do V 
// (HSV) no branco e preto, onde uma vez foram salvos na mémoria
void read_media (armazenar &recd){
  unsigned int rtn_code = Read(handle, recd);
  switch (rtn_code){
      case LDR_SUCCESS:  
           memoria.mediaDir = recd.mediaDir;
           memoria.mediaEsq = recd.mediaEsq;
           break;
      default:
         TextOut(0, LCD_LINE1, "ler falhou!");
         rtn_code_out(rtn_code);
  }
}

// método feito para ler (carregar) os valores de saturação do rgb 
// do sensor de cor direito
void read_rgb_dir (Manipulador &mDir){
  unsigned int rtn_code = Read(handle, mDir);
  switch (rtn_code){
      case LDR_SUCCESS:  
           ManipuladorDir = mDir;
           break;
      default:
         TextOut(0, LCD_LINE1, "ler falhou!");
         rtn_code_out(rtn_code);
  }
}

// método feito para ler (carregar) os valores de saturação do rgb 
// do sensor de cor esquerdo
void read_rgb_esq (Manipulador &mEsq){
  unsigned int rtn_code = Read(handle, mEsq);
  switch (rtn_code){
      case LDR_SUCCESS:  
           ManipuladorDir = mEsq;
           break;
      default:
         TextOut(0, LCD_LINE1, "ler falhou!");
         rtn_code_out(rtn_code);
  }
}
