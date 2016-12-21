---
title: "clearerr | Microsoft Docs"
ms.custom: ""
ms.date: "12/14/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "clearerr"
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
  - "clearerr"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função clearerr"
  - "indicador de erro de fluxos"
  - "redefinindo indicador de erro de fluxo"
ms.assetid: a9711cd4-3335-43d4-a018-87bbac5b3bac
caps.latest.revision: 21
caps.handback.revision: 19
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# clearerr
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Redefine o indicador de erro de um fluxo.  Uma versão mais segura dessa função está disponível; consulte [clearerr\_s](../../c-runtime-library/reference/clearerr-s.md).  
  
## Sintaxe  
  
```  
void clearerr(  
   FILE *stream   
);  
```  
  
#### Parâmetros  
 `stream`  
 Ponteiro a estrutura de `FILE` .  
  
## Comentários  
 A função de `clearerr` redefine o indicador de erro e o indicador de participante de Arquivo para `stream`.  Os indicadores de erro não estejam desmarcados automaticamente; o indicador de erro para um fluxo especificado é definido uma vez, as operações naquele fluxo continuam retornar um valor de erro até `clearerr`, `fseek`, `fsetpos`, ou `rewind` é chamado.  
  
 Se `stream` é `NULL`, o parâmetro de manipulador inválido é invocado, como descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução for permitida continuar, conjuntos `errno` dessa função a `EINVAL` e retorna.  Para obter mais informações sobre como `errno` e os códigos de erro, consulte [constantes de errno](../../c-runtime-library/errno-constants.md).  
  
 Uma versão mais segura dessa função está disponível; consulte [clearerr\_s](../../c-runtime-library/reference/clearerr-s.md).  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`clearerr`|\<stdio.h\>|  
  
 Para informações adicionais de compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Exemplo  
  
```  
// crt_clearerr.c  
// This program creates an error  
// on the standard input stream, then clears  
// it so that future reads won't fail.  
  
#include <stdio.h>  
  
int main( void )  
{  
   int c;  
   // Create an error by writing to standard input.  
   putc( 'c', stdin );  
   if( ferror( stdin ) )  
   {  
      perror( "Write error" );  
      clearerr( stdin );  
   }  
  
   // See if read causes an error.  
   printf( "Will input cause an error? " );  
   c = getc( stdin );  
   if( ferror( stdin ) )  
   {  
      perror( "Read error" );  
      clearerr( stdin );  
   }  
   else  
      printf( "No read error\n" );  
}  
```  
  
  **`erro` de nnWrite: Nenhum erro**  
**A entrada causará um erro? n**  
**Nenhum erro de leitura**   
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função padrão de C, use `PInvoke`. Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Tratamento de erros](../../c-runtime-library/error-handling-crt.md)   
 [E\/S de fluxo](../../c-runtime-library/stream-i-o.md)   
 [\_eof](../../c-runtime-library/reference/eof.md)   
 [feof](../../c-runtime-library/reference/feof.md)   
 [ferror](../../c-runtime-library/reference/ferror.md)   
 [perror, \_wperror](../../c-runtime-library/reference/perror-wperror.md)