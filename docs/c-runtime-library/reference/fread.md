---
title: "fread | Microsoft Docs"
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
  - "fread"
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
  - "fread"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "dados [C++], lendo de fluxo de entrada"
  - "Função fread"
  - "lendo dados [C++], de fluxos de entrada"
  - "fluxos [C++], lendo dados de"
ms.assetid: 9a3c1538-93dd-455e-ae48-77c1e23c53f0
caps.latest.revision: 17
caps.handback.revision: 15
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# fread
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Ler dados de um fluxo.  
  
## Sintaxe  
  
```  
size_t fread(   
   void *buffer,  
   size_t size,  
   size_t count,  
   FILE *stream   
);  
```  
  
#### Parâmetros  
 `buffer`  
 Local para armazenamento de dados.  
  
 `size`  
 Tamanho do item em bytes.  
  
 `count`  
 Número máximo de itens a serem lidos.  
  
 `stream`  
 Ponteiro a estrutura de `FILE` .  
  
## Valor de retorno  
 `fread` retorna o número de itens completo ler a verdade, que pode ser menor do que `count` se ocorrer um erro ou se ao final do arquivo for encontrada antes de `count`do intervalo*.* Use a função de `feof` ou de `ferror` para diferenciar um erro de leitura de uma condição de participante de Arquivo.  Se `size` ou `count` são 0, 0 e `fread` retorna o conteúdo do buffer são iguais.  Se `stream` ou `buffer` for um ponteiro nulo, `fread` invoca o manipulador inválido do parâmetro, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução for permitida continuar, conjuntos `errno` dessa função a `EINVAL` e retorna 0.  
  
 Para obter mais informações sobre esses e outros códigos de erro, consulte [\_doserrno, errno, \_sys\_errlist, and \_sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md).  
  
## Comentários  
 A função de `fread` ler até `count` itens de bytes de `size` de entrada `stream` e armazená\-los em `buffer`*.* O ponteiro de arquivo associado com `stream` \(se houver\) é gerado pelo número de bytes lidos de fato.  Se o fluxo fornecido é aberto no modo de texto, os pares de retorno\- avanço de linha de carro são substituídos pelos únicos caracteres de alimentação de linha.  Reprovação não tem nenhum efeito no ponteiro de arquivo ou no valor de retorno.  A posição do arquivo ponteiro é indeterminada se ocorrer um erro.  O valor parcialmente de um item de leitura não puder ser determinado.  
  
 Essa função bloqueia out outros threads.  Se você precisar de uma versão sem\-bloqueio, use `_fread_nolock`.  
  
## Requisitos  
  
|Função|Cabeçalho necessário|  
|------------|--------------------------|  
|`fread`|\<stdio.h\>|  
  
 Para informações adicionais de compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Exemplo  
  
```  
// crt_fread.c  
// This program opens a file named FREAD.OUT and  
// writes 25 characters to the file. It then tries to open  
// FREAD.OUT and read in 25 characters. If the attempt succeeds,  
// the program displays the number of actual items read.  
  
#include <stdio.h>  
  
int main( void )  
{  
   FILE *stream;  
   char list[30];  
   int  i, numread, numwritten;  
  
   // Open file in text mode:  
   if( fopen_s( &stream, "fread.out", "w+t" ) == 0 )  
   {  
      for ( i = 0; i < 25; i++ )  
         list[i] = (char)('z' - i);  
      // Write 25 characters to stream   
      numwritten = fwrite( list, sizeof( char ), 25, stream );  
      printf( "Wrote %d items\n", numwritten );  
      fclose( stream );  
  
   }  
   else  
      printf( "Problem opening the file\n" );  
  
   if( fopen_s( &stream, "fread.out", "r+t" ) == 0 )  
   {  
      // Attempt to read in 25 characters   
      numread = fread( list, sizeof( char ), 25, stream );  
      printf( "Number of items read = %d\n", numread );  
      printf( "Contents of buffer = %.25s\n", list );  
      fclose( stream );  
   }  
   else  
      printf( "File could not be opened\n" );  
}  
```  
  
  **Gravou 25 itens**  
**Número de itens lidos \= 25**  
**Conteúdo do buffer de zyxwvutsrqponmlkjihgfedcb \=**   
## Equivalência do .NET Framework  
 [System::IO::FileStream::Read](https://msdn.microsoft.com/en-us/library/system.io.filestream.read.aspx)  
  
## Consulte também  
 [E\/S de fluxo](../../c-runtime-library/stream-i-o.md)   
 [fwrite](../Topic/fwrite.md)   
 [\_read](../Topic/_read.md)