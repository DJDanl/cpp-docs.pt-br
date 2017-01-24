---
title: "fread_s | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "fread_s"
apilocation: 
  - "msvcrt.dll"
  - "msvcr80.dll"
  - "msvcr90.dll"
  - "msvcr100.dll"
  - "msvcr100_clr0400.dll"
  - "msvcr110.dll"
  - "msvcr110_clr0400.dll"
  - "msvcr120.dll"
  - "msvcr120_clr0400.dll"
  - "ucrtbase.dll"
  - "api-ms-win-crt-stdio-l1-1-0.dll"
apitype: "DLLExport"
f1_keywords: 
  - "fread_s"
  - "stdio/fread_s"
dev_langs: 
  - "C++"
ms.assetid: ce735de0-f005-435d-a8f2-6f4b80ac775e
caps.latest.revision: 7
caps.handback.revision: 5
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# fread_s
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Ler dados de um fluxo.  Esta versão de [fread](../../c-runtime-library/reference/fread.md) tem aprimoramentos de segurança, conforme descrito em [Recursos de segurança no CRT](../Topic/Security%20Features%20in%20the%20CRT.md).  
  
## Sintaxe  
  
```  
size_t fread_s(   
   void *buffer,  
   size_t bufferSize,  
   size_t elementSize,  
   size_t count,  
   FILE *stream   
);  
```  
  
#### Parâmetros  
 `buffer`  
 Local para armazenamento de dados.  
  
 `bufferSize`  
 Tamanho do buffer de destino em bytes.  
  
 `elementSize`  
 Tamanho do item para ler em bytes.  
  
 `count`  
 Número máximo de itens a serem lidos.  
  
 `stream`  
 Ponteiro a estrutura de `FILE` .  
  
## Valor de retorno  
 `fread_s` retorna o número de itens \(inteiros\) que foram lidas no buffer, que pode ser menor do que `count` se um erro de leitura ou ao final do arquivo é encontrado antes que `count` seja atingido.  Use a função de `feof` ou de `ferror` para diferenciar um erro de uma condição de participante de Arquivo.  Se `size` ou `count` são 0, 0 e `fread_s` retorna o conteúdo do buffer são iguais.  Se `stream` ou `buffer` for um ponteiro nulo, `fread_s` invoca o manipulador inválido do parâmetro, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução for permitida continuar, conjuntos `errno` dessa função a `EINVAL` e retorna 0.  
  
 Para obter mais informações sobre códigos de erro, consulte [\_doserrno, errno, \_sys\_errlist, e \_sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md).  
  
## Comentários  
 A função de `fread_s` ler até `count` itens de bytes de `elementSize` de entrada `stream` e armazená\-los em `buffer`.  O ponteiro de arquivo que está associado a `stream` \(se houver\) é gerado pelo número de bytes lidos de fato.  Se o fluxo fornecido é aberto no modo de texto, os pares de retorno\- avanço de linha de carro são substituídos pelos únicos caracteres de alimentação de linha.  Reprovação não tem nenhum efeito no ponteiro de arquivo ou no valor de retorno.  A posição do arquivo ponteiro é indeterminada se ocorrer um erro.  O valor parcialmente de um item de leitura não puder ser determinado.  
  
 Essa função bloqueia out outros threads.  Se você precisar de uma versão sem\-bloqueio, use `_fread_nolock`.  
  
## Requisitos  
  
|Função|Cabeçalho necessário|  
|------------|--------------------------|  
|`fread_s`|\<stdio.h\>|  
  
 Para informações adicionais de compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Exemplo  
  
```cpp  
  
// crt_fread_s.c  
// Command line: cl /EHsc /nologo /W4 crt_fread_s.c  
//  
// This program opens a file that's named FREAD.OUT and  
// writes characters to the file. It then tries to open  
// FREAD.OUT and read in characters by using fread_s. If the attempt succeeds,  
// the program displays the number of actual items read.  
  
#include <stdio.h>  
  
#define BUFFERSIZE 30  
#define DATASIZE 22  
#define ELEMENTCOUNT 2  
#define ELEMENTSIZE (DATASIZE/ELEMENTCOUNT)  
#define FILENAME "FREAD.OUT"  
  
int main( void )  
{  
   FILE *stream;  
   char list[30];  
   int  i, numread, numwritten;  
  
   for ( i = 0; i < DATASIZE; i++ )  
      list[i] = (char)('z' - i);  
   list[DATASIZE] = '\0'; // terminal null so we can print it  
  
   // Open file in text mode:  
   if( fopen_s( &stream, FILENAME, "w+t" ) == 0 )  
   {  
      // Write DATASIZE characters to stream   
      printf( "Contents of buffer before write/read:\n\t%s\n\n", list );  
      numwritten = fwrite( list, sizeof( char ), DATASIZE, stream );  
      printf( "Wrote %d items\n\n", numwritten );  
      fclose( stream );  
   } else {  
      printf( "Problem opening the file\n" );  
      return -1;  
   }  
  
   if( fopen_s( &stream, FILENAME, "r+t" ) == 0 )   {  
      // Attempt to read in characters in 2 blocks of 11  
      numread = fread_s( list, BUFFERSIZE, ELEMENTSIZE, ELEMENTCOUNT, stream );  
      printf( "Number of %d-byte elements read = %d\n\n", ELEMENTSIZE, numread );  
      printf( "Contents of buffer after write/read:\n\t%s\n", list );  
      fclose( stream );  
   } else {  
      printf( "File could not be opened\n" );  
      return -1;  
   }  
}  
```  
  
  **Conteúdo do buffer antes da gravação\/leitura:**   
 **zyxwvutsrqponmlkjihgfe**  
 **Gravou 22 itens**   
 **O número de elementos de 11 bytes lidos \= 2**   
 **Conteúdo do buffer após a leitura\/gravação:**   
 **zyxwvutsrqponmlkjihgfe**    
## Consulte também  
 [E\/S de fluxo](../../c-runtime-library/stream-i-o.md)   
 [fwrite](../Topic/fwrite.md)   
 [\_read](../Topic/_read.md)