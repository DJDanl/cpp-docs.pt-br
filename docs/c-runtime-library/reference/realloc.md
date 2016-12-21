---
title: "realloc | Microsoft Docs"
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
  - "realloc"
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
  - "_brealloc"
  - "_nrealloc"
  - "realloc"
  - "_frealloc"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _brealloc"
  - "Função realloc"
  - "Função nrealloc"
  - "Função frealloc"
  - "Função _nrealloc"
  - "blocos de memória, realocando"
  - "memória, realocando"
  - "Função _frealloc"
  - "realocar blocos de memória"
ms.assetid: 2b2239de-810b-4b11-9438-32ab0a244185
caps.latest.revision: 20
caps.handback.revision: 18
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# realloc
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Realocar blocos de memória.  
  
## Sintaxe  
  
```  
void *realloc(  
   void *memblock,  
   size_t size   
);  
```  
  
#### Parâmetros  
 `memblock`  
 Ponteiro para o bloco de memória anteriormente atribuído.  
  
 `size`  
 Novo tamanho em bytes.  
  
## Valor de retorno  
 `realloc` retorna um ponteiro de `void` \(movido e possivelmente\) no bloco de memória realocado.  
  
 Se não houver memória suficiente disponível para expandir o bloco ao tamanho especificado, o bloco original permanecerá inalterado, e `NULL` é retornado.  
  
 Se `size` for zero, o bloco apontado por `memblock` será liberado; o valor de retorno é `NULL`, aponte para e `memblock` é deixado em um bloco liberado.  
  
 O valor de retorno para um espaço de armazenamento que é garantia de ser alinhado adequadamente para o armazenamento de qualquer tipo de objeto.  Para obter um ponteiro para um tipo diferente de `void`, use uma conversão de tipos no valor de retorno.  
  
## Comentários  
 A função de `realloc` o tamanho de um bloco de memória alocada.  O argumento de `memblock` ao início do bloco de memória.  Se `memblock` é `NULL`, `realloc` se comporta da mesma maneira que `malloc` e atribui\-se um novo bloco de bytes de `size` .  Se `memblock` não é `NULL`, deve ser um ponteiro retornado por uma chamada a `calloc`anterior, a `malloc`, ou a `realloc`.  
  
 O argumento de `size` do novo tamanho do bloco, em bytes.  O conteúdo do bloco não serão alteradas até o mais curto tamanhos dos novos e antigos, embora o novo pacote pode estar em um local diferente.  Como o novo bloco pode estar em um novo local na memória, o ponteiro retornado por `realloc` não é garantido como o ponteiro passado pelo argumento de `memblock` .  `realloc` não zera a memória alocada recentemente no caso de crescimento do buffer.  
  
 `realloc` define `errno` a `ENOMEM` se a alocação de memória falhar ou se a quantidade de memória solicitada exceder `_HEAP_MAXREQ`.  Para obter mais informações sobre esse e outros códigos de erro, consulte [errno, \_doserrno, \_sys\_errlist e \_sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md).  
  
 chamadas`malloc`de`realloc`para usar a função C\+\+ [\_set\_new\_mode](../../c-runtime-library/reference/set-new-mode.md) para definir o novo modo do manipulador.  O novo modo de manipulador indica se, em caso de falha, `malloc` deve chamar a nova rotina do manipulador conforme definido por [\_set\_new\_handler](../Topic/_set_new_handler.md).  Por padrão, `malloc` não chama a nova rotina do manipulador em caso de falha para alocar memória.  Você pode substituir esse comportamento padrão para que, quando `realloc` não aloca memória, `malloc` chama a nova rotina de manipulador da mesma forma que o operador de `new` faz quando falha pela mesma razão.  Para substituir o padrão, chame  
  
```  
_set_new_mode(1)  
```  
  
 no início de programa, ou link com o NEWMODE.OBJ \(consulte [Opções de link](../Topic/Link%20Options.md)\).  
  
 Quando o aplicativo é vinculado a uma versão de depuração das bibliotecas de tempo de execução C, `realloc` resolve a [\_realloc\_dbg](../../c-runtime-library/reference/realloc-dbg.md).  Para obter mais informações sobre como o heap é gerenciado durante o processo de depuração, consulte [O heap de depuração do CRT](../Topic/CRT%20Debug%20Heap%20Details.md).  
  
 `realloc` é `__declspec(noalias)` marcado e `__declspec(restrict)`, o que significa que a função não é garantida para modificar as variáveis globais, e que o ponteiro retornado não possui alias.  Para obter mais informações, consulte [noalias](../../cpp/noalias.md) e [restrinja](../../cpp/restrict.md).  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`realloc`|\<stdlib.h\> e \<malloc.h\>|  
  
 Para informações adicionais de compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Exemplo  
  
```  
// crt_realloc.c  
// This program allocates a block of memory for  
// buffer and then uses _msize to display the size of that  
// block. Next, it uses realloc to expand the amount of  
// memory used by buffer and then calls _msize again to  
// display the new amount of memory allocated to buffer.  
  
#include <stdio.h>  
#include <malloc.h>  
#include <stdlib.h>  
  
int main( void )  
{  
   long *buffer, *oldbuffer;  
   size_t size;  
  
   if( (buffer = (long *)malloc( 1000 * sizeof( long ) )) == NULL )  
      exit( 1 );  
  
   size = _msize( buffer );  
   printf_s( "Size of block after malloc of 1000 longs: %u\n", size );  
  
   // Reallocate and show new size:  
   oldbuffer = buffer;     // save pointer in case realloc fails  
   if( (buffer = realloc( buffer, size + (1000 * sizeof( long )) ))   
        ==  NULL )  
   {  
      free( oldbuffer );  // free original block  
      exit( 1 );  
   }  
   size = _msize( buffer );  
   printf_s( "Size of block after realloc of 1000 more longs: %u\n",   
            size );  
  
   free( buffer );  
   exit( 0 );  
}  
```  
  
  **O tamanho do bloco depois de um malloc de 1000 longs: 4000**  
**O tamanho do bloco depois de um realloc de 1000 longs mais: 8000**   
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função padrão de C, use `PInvoke`. Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Alocação de memória](../../c-runtime-library/memory-allocation.md)   
 [calloc](../../c-runtime-library/reference/calloc.md)   
 [free](../../c-runtime-library/reference/free.md)   
 [malloc](../../c-runtime-library/reference/malloc.md)