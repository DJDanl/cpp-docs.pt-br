---
title: "_msize_dbg | Microsoft Docs"
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
  - "_msize_dbg"
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
apitype: "DLLExport"
f1_keywords: 
  - "_msize_dbg"
  - "msize_dbg"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "blocos de memória"
  - "Função _msize_dbg"
  - "Função msize_dbg"
ms.assetid: a333f4b6-f8a2-4e61-bb69-cb34063b8cef
caps.latest.revision: 15
caps.handback.revision: 15
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _msize_dbg
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Calcula o tamanho de um bloco de memória no heap \(versão de depuração somente\).  
  
## Sintaxe  
  
```  
  
      size_t _msize_dbg(  
   void *userData,  
   int blockType   
);  
```  
  
#### Parâmetros  
 `userData`  
 Ponteiro para o bloco de memória para a qual determinar o tamanho.  
  
 *em blocos*  
 Tipo do bloco de memória especificado: `_CLIENT_BLOCK` ou **\_NORMAL\_BLOCK**.  
  
## Valor de retorno  
 Na conclusão bem\-sucedida, `_msize_dbg` retorna o tamanho \(em bytes\) do bloco de memória especificado; se não retorna NULL.  
  
## Comentários  
 `_msize_dbg` é uma versão de depuração da função de[msize](../Topic/_msize.md) \_.  Quando [\_DEBUG](../Topic/_DEBUG.md) não for definido, cada chamada a `_msize_dbg` será reduzido para uma chamada a `_msize`.  `_msize` e `_msize_dbg` calcular o tamanho de um bloco de memória heap de base, mas `_msize_dbg` adiciona dois recursos de depuração: Inclui os buffers em ambos os lados da parte do usuário do bloco de memória em tamanho retornado e permite cálculos de tamanho para tipos específicos do bloco.  
  
 Para obter informações sobre como os blocos de memória são atribuídos, inicializados, e gerenciados na versão de depuração da heap de base, consulte [Detalhes da pilha de depuração CRT](../Topic/CRT%20Debug%20Heap%20Details.md).  Para obter informações sobre o bloco de alocação digitar e como elas são usadas, consulte [Tipos de blocos na heap de depuração](../Topic/CRT%20Debug%20Heap%20Details.md#BKMK_Types_of_blocks_on_the_debug_heap).  Para obter informações sobre as diferenças entre chamar uma função padrão do heap e sua versão de depuração em uma compilação de depuração de um aplicativo, consulte [Versões de depuração das funções de alocação da pilha](../Topic/Debug%20Versions%20of%20Heap%20Allocation%20Functions.md).  
  
 Essa função valida seu parâmetro.  Se `memblock` for um ponteiro nulo, `_msize` invoca um manipulador inválido do parâmetro, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se o erro é tratado, a função `errno` define a `EINVAL` e retorna \-1.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_msize_dbg`|\<crtdbg.h\>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Bibliotecas  
 Versões de depuração das [Bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md) somente.  
  
## Exemplo  
  
```  
// crt_msize_dbg.c  
// compile with: /MTd  
/*  
 * This program allocates a block of memory using _malloc_dbg  
 * and then calls _msize_dbg to display the size of that block.  
 * Next, it uses _realloc_dbg to expand the amount of  
 * memory used by the buffer and then calls _msize_dbg again to  
 * display the new amount of memory allocated to the buffer.  
 */  
  
#include <stdio.h>  
#include <malloc.h>  
#include <stdlib.h>  
#include <crtdbg.h>  
  
int main( void )  
{  
        long *buffer, *newbuffer;  
        size_t size;  
  
        /*   
         * Call _malloc_dbg to include the filename and line number  
         * of our allocation request in the header  
         */  
        buffer = (long *)_malloc_dbg( 40 * sizeof(long), _NORMAL_BLOCK, __FILE__, __LINE__ );  
        if( buffer == NULL )  
               exit( 1 );  
  
        /*   
         * Get the size of the buffer by calling _msize_dbg  
         */  
        size = _msize_dbg( buffer, _NORMAL_BLOCK );  
        printf( "Size of block after _malloc_dbg of 40 longs: %u\n", size );  
  
        /*   
         * Reallocate the buffer using _realloc_dbg and show the new size  
         */  
        newbuffer = _realloc_dbg( buffer, size + (40 * sizeof(long)), _NORMAL_BLOCK, __FILE__, __LINE__ );  
        if( newbuffer == NULL )  
               exit( 1 );  
        buffer = newbuffer;  
        size = _msize_dbg( buffer, _NORMAL_BLOCK );  
        printf( "Size of block after _realloc_dbg of 40 more longs: %u\n", size );  
  
        free( buffer );  
        exit( 0 );  
}  
```  
  
## Saída  
  
```  
Size of block after _malloc_dbg of 40 longs: 160  
Size of block after _realloc_dbg of 40 more longs: 320  
```  
  
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função padrão de C, use `PInvoke`. Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Rotinas de depuração](../../c-runtime-library/debug-routines.md)   
 [\_malloc\_dbg](../../c-runtime-library/reference/malloc-dbg.md)