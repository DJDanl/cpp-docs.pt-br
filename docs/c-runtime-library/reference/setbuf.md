---
title: "setbuf | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "setbuf"
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
  - "setbuf"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função setbuf"
  - "buffer de fluxo"
ms.assetid: 13beda22-7b56-455d-8a6c-f2eb636885b9
caps.latest.revision: 16
caps.handback.revision: 14
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# setbuf
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Proteção de fluxo de controle.  Esta função é substituída; use [setvbuf](../../c-runtime-library/reference/setvbuf.md) em vez disso.  
  
## Sintaxe  
  
```  
void setbuf(  
   FILE *stream,  
   char *buffer   
);  
```  
  
#### Parâmetros  
 `stream`  
 Ponteiro a estrutura de `FILE` .  
  
 `buffer`  
 Buffer usuário atribuído.  
  
## Comentários  
 A função de `setbuf` controla a proteção para `stream`.  O argumento de `stream` deve recorrer a um arquivo aberto que não seja lido ou não é gravado.  Se o argumento de `buffer` é `NULL`, o fluxo não está armazenado no buffer.  Caso contrário, o buffer deve apontar para uma matriz de caractere de comprimento `BUFSIZ`, onde `BUFSIZ` é o tamanho do buffer conforme definido em. STDIO.H.  O buffer especificado pelo usuário, em vez de buffer atribuído por padrão para o fluxo fornecido, é usado para armazenar em buffer de E\/S.  O fluxo de `stderr` não é armazenado em buffer por padrão, mas você pode usar `setbuf` buffers para atribuir a `stderr`.  
  
 `setbuf` foi substituído por [setvbuf](../../c-runtime-library/reference/setvbuf.md), que é a rotina preferida para o novo código.  `setbuf` é mantido para compatibilidade com o código existente.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`setbuf`|\<stdio.h\>|  
  
 Para informações adicionais de compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Exemplo  
  
```  
// crt_setbuf.c  
// compile with: /W3  
// This program first opens files named DATA1 and  
// DATA2. Then it uses setbuf to give DATA1 a user-assigned  
// buffer and to change DATA2 so that it has no buffer.  
  
#include <stdio.h>  
  
int main( void )  
{  
   char buf[BUFSIZ];  
   FILE *stream1, *stream2;  
  
   fopen_s( &stream1, "data1", "a" );  
   fopen_s( &stream2, "data2", "w" );  
  
   if( (stream1 != NULL) && (stream2 != NULL) )  
   {  
      // "stream1" uses user-assigned buffer:  
      setbuf( stream1, buf ); // C4996  
      // Note: setbuf is deprecated; consider using setvbuf instead  
      printf( "stream1 set to user-defined buffer at: %Fp\n", buf );  
  
      // "stream2" is unbuffered  
      setbuf( stream2, NULL ); // C4996  
      printf( "stream2 buffering disabled\n" );  
      _fcloseall();  
   }  
}  
```  
  
  **stream1 definido como o buffer definido pelo usuário no: 0012FCDC**  
**proteção stream2 desabilitada**   
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função padrão de C, use `PInvoke`. Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [E\/S de fluxo](../../c-runtime-library/stream-i-o.md)   
 [fclose, \_fcloseall](../../c-runtime-library/reference/fclose-fcloseall.md)   
 [fflush](../Topic/fflush.md)   
 [fopen, \_wfopen](../../c-runtime-library/reference/fopen-wfopen.md)   
 [setvbuf](../../c-runtime-library/reference/setvbuf.md)