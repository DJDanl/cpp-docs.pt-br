---
title: "calloc | Microsoft Docs"
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
  - "calloc"
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
  - "api-ms-win-crt-heap-l1-1-0.dll"
apitype: "DLLExport"
f1_keywords: 
  - "calloc"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "alocação de memória e matrizes"
  - "Função calloc"
ms.assetid: 17bb79a1-98cf-4096-90cb-1f9365cd6829
caps.latest.revision: 17
caps.handback.revision: 15
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# calloc
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Atribui uma matriz na memória com os elementos inicializados como 0.  
  
## Sintaxe  
  
```  
void *calloc(   
   size_t num,  
   size_t size   
);  
```  
  
#### Parâmetros  
 `num`  
 Número de elementos.  
  
 `size`  
 Comprimento em bytes de cada elemento.  
  
## Valor de retorno  
 `calloc` retorna um ponteiro para o espaço alocado.  O espaço de armazenamento apontado pelo valor de retorno tem a garantia de ser alinhado adequadamente para o armazenamento de qualquer tipo de objeto.  Para obter um ponteiro para um tipo diferente de `void`, use uma conversão de tipos no valor de retorno.  
  
## Comentários  
 A função de `calloc` atribui o espaço de armazenamento para uma matriz de elementos de `num` , cada um de `size` de bytes de comprimento.  Cada elemento é inicializado como 0.  
  
 `calloc` define `errno` a `ENOMEM` se uma alocação de memória falhar ou se a quantidade de memória solicitada exceder `_HEAP_MAXREQ`.  Para obter mais informações sobre esse e outros códigos de erro, consulte [errno, \_doserrno, \_sys\_errlist e \_sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md).  
  
 chamadas `malloc` de`calloc` para usar a função C\+\+ [\_set\_new\_mode](../../c-runtime-library/reference/set-new-mode.md) para definir o novo modo do manipulador.  O novo modo de manipulador indica se, em caso de falha, `malloc` deve chamar a nova rotina do manipulador conforme definido por [\_set\_new\_handler](../Topic/_set_new_handler.md).  Por padrão, `malloc` não chama a nova rotina do manipulador em caso de falha para alocar memória.  Você pode substituir esse comportamento padrão para que, quando `calloc` não aloca memória, `malloc` chama a nova rotina de manipulador da mesma forma que o operador de `new` faz quando falha pela mesma razão.  Para substituir o padrão, chame  
  
```  
_set_new_mode(1)  
```  
  
 no início do seu programa, ou no link com NEWMODE.OBJ \(consulte [Opções de link](../Topic/Link%20Options.md)\).  
  
 Quando o aplicativo é vinculado a uma versão de depuração das bibliotecas de tempo de execução C, `calloc` resolve a [\_calloc\_dbg](../../c-runtime-library/reference/calloc-dbg.md).  Para obter mais informações sobre como o heap é gerenciado durante o processo de depuração, consulte [O heap de depuração do CRT](../Topic/CRT%20Debug%20Heap%20Details.md).  
  
 `calloc` é `__declspec(noalias)` marcado e `__declspec(restrict)`, o que significa que a função não é garantida para modificar as variáveis globais, e que o ponteiro retornado não possui alias.  Para obter mais informações, consulte [noalias](../../cpp/noalias.md) e [restrinja](../../cpp/restrict.md).  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`calloc`|\<stdlib.h\> e \<malloc.h\>|  
  
 Para informações adicionais de compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Exemplo  
  
```  
// crt_calloc.c  
// This program uses calloc to allocate space for  
// 40 long integers. It initializes each element to zero.  
  
#include <stdio.h>  
#include <malloc.h>  
  
int main( void )  
{  
   long *buffer;  
  
   buffer = (long *)calloc( 40, sizeof( long ) );  
   if( buffer != NULL )  
      printf( "Allocated 40 long integers\n" );  
   else  
      printf( "Can't allocate memory\n" );  
   free( buffer );  
}  
```  
  
  **Alocado 40 inteiros longos**   
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função padrão de C, use `PInvoke`. Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Alocação de memória](../../c-runtime-library/memory-allocation.md)   
 [free](../../c-runtime-library/reference/free.md)   
 [malloc](../../c-runtime-library/reference/malloc.md)   
 [realloc](../../c-runtime-library/reference/realloc.md)