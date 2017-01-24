---
title: "_calloc_dbg | Microsoft Docs"
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
  - "_calloc_dbg"
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
  - "_calloc_dbg"
  - "calloc_dbg"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _calloc_dbg"
  - "Função calloc_dbg"
ms.assetid: 7f62c42b-eb9f-4de5-87d0-df57036c87de
caps.latest.revision: 18
caps.handback.revision: 16
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _calloc_dbg
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Atribui um número de blocos de memória heap com espaço adicional para um cabeçalho de depuração e substituem buffers \(versão de depuração somente\).  
  
## Sintaxe  
  
```  
void *_calloc_dbg(   
   size_t num,  
   size_t size,  
   int blockType,  
   const char *filename,  
   int linenumber   
);  
```  
  
#### Parâmetros  
 `num`  
 Número solicitado de blocos de memória.  
  
 `size`  
 Tamanho pedido de cada bloco de memória \(bytes\).  
  
 `blockType`  
 O tipo solicitado do bloco de memória: `_CLIENT_BLOCK` ou `_NORMAL_BLOCK`.  
  
 Para obter informações sobre o bloco de alocação digitar e como elas são usadas, consulte[Tipos de blocos na heap de depuração](../Topic/CRT%20Debug%20Heap%20Details.md#BKMK_Types_of_blocks_on_the_debug_heap).  
  
 `filename`  
 Ponteiro para o nome do arquivo de origem que solicitou a operação ou o `NULL`de alocação.  
  
 `linenumber`  
 Número de linha no arquivo de origem em que a operação de alocação foi solicitada ou `NULL`.  
  
 Os parâmetros de `filename` e de `linenumber` só estão disponíveis quando `_calloc_dbg` esteve chamado explicitamente ou a constante de pré\-processador de [\_CRTDBG\_MAP\_ALLOC](../../c-runtime-library/crtdbg-map-alloc.md) esteve definida.  
  
## Valor de retorno  
 Na conclusão com êxito, a função retorna um ponteiro para a parte do usuário do bloco de memória alocado a última vez, chama a nova função de manipulador, ou retornará `NULL`.  Para obter uma descrição completa de comportamento de retorno, consulte a seção comentários.  Para obter mais informações sobre como a nova função de manipulador é usada, consulte a função de [calloc](../../c-runtime-library/reference/calloc.md) .  
  
## Comentários  
 `_calloc_dbg` é uma versão de depuração da função de [calloc](../../c-runtime-library/reference/calloc.md) .  Quando [\_DEBUG](../Topic/_DEBUG.md) não for definido, cada chamada a `_calloc_dbg` será reduzido para uma chamada a `calloc`.  `calloc` e `_calloc_dbg` atribuem blocos de memória de `num` no heap de base, mas ofertas de `_calloc_dbg` vários recursos de depuração:  
  
-   Buffers em ambos os lados da parte do usuário do bloco para testar possíveis vazamentos.  
  
-   Um parâmetro em blocos para controlar tipos específicos de alocação.  
  
-   `filename`\/informações de`linenumber` para determinar a origem de solicitações de alocação.  
  
 `_calloc_dbg` atribui cada bloco de memória com um pouco mais espaço do que `size`solicitado.  O espaço adicional é usado pelo gerenciador de heap de depuração para vincular os blocos de memória de depuração e fornecer o aplicativo com informações de cabeçalho de depuração e para substituir os buffers.  Quando o pacote é atribuído, a parte do usuário do bloco é preenchida com o valor 0xCD e cada um dos buffers substituir for preenchido com 0xFD.  
  
 `_calloc_dbg` define `errno` a `ENOMEM` se uma alocação de memória falha; `EINVAL` será retornado se a quantidade de memória necessária \(incluindo a sobrecarga mencionada anteriormente\) excede `_HEAP_MAXREQ`.  Para obter informações sobre esse e outros códigos de erro, consulte [errno, \_doserrno, \_sys\_errlist e \_sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md).  
  
 Para obter informações sobre como os blocos de memória são atribuídos, inicializados, e gerenciados na versão de depuração da heap de base, consulte [Detalhes da pilha de depuração CRT](../Topic/CRT%20Debug%20Heap%20Details.md).  Para obter informações sobre as diferenças entre chamar uma função padrão do heap na versão de depuração em uma compilação de depuração de um aplicativo, consulte [Versões de depuração das funções de alocação da pilha](../Topic/Debug%20Versions%20of%20Heap%20Allocation%20Functions.md).  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_calloc_dbg`|\<crtdbg.h\>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Exemplo  
  
```  
// crt_callocd.c  
/*  
 * This program uses _calloc_dbg to allocate space for  
 * 40 long integers. It initializes each element to zero.  
 */  
#include <stdio.h>  
#include <malloc.h>  
#include <crtdbg.h>  
  
int main( void )  
{  
        long *bufferN, *bufferC;  
  
        /*   
         * Call _calloc_dbg to include the filename and line number  
         * of our allocation request in the header and also so we can  
         * allocate CLIENT type blocks specifically  
         */  
        bufferN = (long *)_calloc_dbg( 40, sizeof(long), _NORMAL_BLOCK, __FILE__, __LINE__ );  
        bufferC = (long *)_calloc_dbg( 40, sizeof(long), _CLIENT_BLOCK, __FILE__, __LINE__ );  
        if( bufferN != NULL && bufferC != NULL )  
              printf( "Allocated memory successfully\n" );  
        else  
              printf( "Problem allocating memory\n" );  
  
        /*   
         * _free_dbg must be called to free CLIENT type blocks  
         */  
        free( bufferN );  
        _free_dbg( bufferC, _CLIENT_BLOCK );  
}  
```  
  
  **Memória alocada com êxito**   
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função padrão de C, use `PInvoke`. Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Rotinas de depuração](../../c-runtime-library/debug-routines.md)   
 [calloc](../../c-runtime-library/reference/calloc.md)   
 [\_malloc\_dbg](../../c-runtime-library/reference/malloc-dbg.md)   
 [\_DEBUG](../Topic/_DEBUG.md)