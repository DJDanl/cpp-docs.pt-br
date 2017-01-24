---
title: "_heapset | Microsoft Docs"
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
  - "_heapset"
apilocation: 
  - "msvcr90.dll"
  - "msvcr80.dll"
  - "msvcr110.dll"
  - "msvcr110_clr0400.dll"
  - "msvcrt.dll"
  - "msvcr120.dll"
  - "msvcr100.dll"
apitype: "DLLExport"
f1_keywords: 
  - "_heapset"
  - "heapset"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "verificando heap"
  - "Função heapset"
  - "verificação de pilhas,"
  - "depuração [CRT], problemas relacionados a heap"
  - "Função _heapset"
ms.assetid: 9667eeb0-55bc-4c19-af5f-d1fd0a142b3c
caps.latest.revision: 14
caps.handback.revision: 14
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _heapset
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Verifica pilhas consistência mínima e define as entradas livres para um valor especificado.  
  
> [!IMPORTANT]
>  Essa função é obsoleta. A partir do Visual Studio 2015, ele não está disponível no CRT.  
  
## Sintaxe  
  
```  
int _heapset(   
   unsigned int fill   
);  
```  
  
#### Parâmetros  
 `fill`  
 Caractere de preenchimento.  
  
## Valor de retorno  
 `_heapset` Retorna uma das seguintes constantes de manifesto de inteiro definidas no malloc.  
  
 `_HEAPBADBEGIN`  
 Informações de cabeçalho inicial inválidas ou não foi encontradas.  
  
 `_HEAPBADNODE`  
 Heap danificado ou nó inválido encontrado.  
  
 `_HEAPEMPTY`  
 Heap não inicializado.  
  
 `_HEAPOK`  
 Heap parece estar consistente.  
  
 Além disso, se ocorrer um erro, `_heapset` define `errno` para `ENOSYS`.  
  
## Comentários  
 O `_heapset` função mostra os locais de memória livre ou nós que foram substituídas acidentalmente.  
  
 `_heapset` verifica a consistência mínima na pilha e define cada byte de entradas livres da heap de `fill` valor. Esse valor conhecido mostra quais locais de memória do heap contêm nós livres e que contêm dados que foram gravados acidentalmente memória liberada. Se o sistema operacional não suportar `_heapset`\(por exemplo, Windows 98\), a função retorna `_HEAPOK` e define `errno` para `ENOSYS`.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|Cabeçalho opcional|  
|------------|--------------------------|------------------------|  
|`_heapset`|\< malloc \>|\< errno. h \>|  
  
 Para obter informações de compatibilidade, consulte [compatibilidade](../c-runtime-library/compatibility.md) na introdução.  
  
## Exemplo  
  
```  
// crt_heapset.c  
// This program checks the heap and  
// fills in free entries with the character 'Z'.  
  
#include <malloc.h>  
#include <stdio.h>  
#include <stdlib.h>  
  
int main( void )  
{  
   int heapstatus;  
   char *buffer;  
  
   if( (buffer = malloc( 1 )) == NULL ) // Make sure heap is   
      exit( 0 );                        //    initialized       
   heapstatus = _heapset( 'Z' );        // Fill in free entries   
   switch( heapstatus )  
   {  
   case _HEAPOK:  
      printf( "OK - heap is fine\n" );  
      break;  
   case _HEAPEMPTY:  
      printf( "OK - heap is empty\n" );  
      break;  
   case _HEAPBADBEGIN:  
      printf( "ERROR - bad start of heap\n" );  
      break;  
   case _HEAPBADNODE:  
      printf( "ERROR - bad node in heap\n" );  
      break;  
   }  
   free( buffer );  
}  
```  
  
```Output  
OK - heap é bem  
```  
  
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Alocação de memória](../c-runtime-library/memory-allocation.md)   
 [\_heapadd](../c-runtime-library/heapadd.md)   
 [\_heapchk](../c-runtime-library/reference/heapchk.md)   
 [\_heapmin](../c-runtime-library/reference/heapmin.md)   
 [\_heapwalk](../Topic/_heapwalk.md)