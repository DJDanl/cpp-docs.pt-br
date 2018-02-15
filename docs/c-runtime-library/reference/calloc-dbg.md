---
title: _calloc_dbg | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: reference
apiname:
- _calloc_dbg
apilocation:
- msvcrt.dll
- msvcr80.dll
- msvcr90.dll
- msvcr100.dll
- msvcr100_clr0400.dll
- msvcr110.dll
- msvcr110_clr0400.dll
- msvcr120.dll
- msvcr120_clr0400.dll
- ucrtbase.dll
apitype: DLLExport
f1_keywords:
- _calloc_dbg
- calloc_dbg
dev_langs:
- C++
helpviewer_keywords:
- _calloc_dbg function
- calloc_dbg function
ms.assetid: 7f62c42b-eb9f-4de5-87d0-df57036c87de
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 634838c5a29b0a356ea8c7c3d3a49ea86263f45e
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="callocdbg"></a>_calloc_dbg
Aloca vários blocos de memória no heap com espaço adicional para um cabeçalho de depuração e buffers de substituição (apenas versão de depuração).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
void *_calloc_dbg(   
   size_t num,  
   size_t size,  
   int blockType,  
   const char *filename,  
   int linenumber   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `num`  
 Número necessário de blocos de memória.  
  
 `size`  
 Tamanho necessário de cada bloco de memória (bytes).  
  
 `blockType`  
 Tipo solicitado de bloco de memória: `_CLIENT_BLOCK` ou `_NORMAL_BLOCK`.  
  
 Para obter informações sobre os tipos de bloco de alocação e como eles são usados, consulte [Tipos de blocos no heap de depuração](/visualstudio/debugger/crt-debug-heap-details).  
  
 `filename`  
 Ponteiro para o nome do arquivo de origem que solicitou a operação de alocação ou `NULL`.  
  
 `linenumber`  
 Número da linha no arquivo de origem em que a operação de alocação foi solicitada ou `NULL`.  
  
 Os parâmetros `filename` e `linenumber` estarão disponíveis apenas quando `_calloc_dbg` tiver sido chamado explicitamente ou quando a constante do pré-processador [_CRTDBG_MAP_ALLOC](../../c-runtime-library/crtdbg-map-alloc.md) tiver sido definida.  
  
## <a name="return-value"></a>Valor de retorno  
 Mediante a conclusão bem-sucedida, essa função retornará um ponteiro para a parte do usuário do último bloco de memória alocado, chamará a nova função do manipulador ou retornará `NULL`. Para obter uma descrição completa do comportamento de retorno, consulte a seção Comentários. Para obter mais informações sobre como a nova função do manipulador é usada, consulte a função [calloc](../../c-runtime-library/reference/calloc.md).  
  
## <a name="remarks"></a>Comentários  
 `_calloc_dbg` é uma versão de depuração da função [calloc](../../c-runtime-library/reference/calloc.md). Quando [_DEBUG](../../c-runtime-library/debug.md) não está definido, cada chamada para `_calloc_dbg` é reduzida a uma chamada para `calloc`. Tanto `calloc` quanto `_calloc_dbg` alocam `num` blocos de memória no heap de base, mas `_calloc_dbg` oferece vários recursos de depuração:  
  
-   Buffers em ambos os lados da parte do usuário do bloco a testar quanto a vazamentos.  
  
-   Um parâmetro de tipo de bloco para controlar os tipos de alocação específicos.  
  
-   Informações `filename`/`linenumber` para determinar a origem das solicitações de alocação.  
  
 `_calloc_dbg` aloca cada bloco de memória com um pouco mais de espaço que o `size` solicitado. O espaço adicional é usado pelo gerenciador de heaps de depuração para vincular os blocos de memória de depuração e fornecer informações do cabeçalho de depuração ao aplicativo e substituir buffers. Quando um bloco é alocado, a parte do usuário do bloco é preenchida com o valor 0xCD e cada um dos buffers de substituição é preenchido com 0xFD.  
  
 `_calloc_dbg` definirá `errno` como `ENOMEM` se uma alocação de memória falhar; `EINVAL` será retornado se uma quantidade de memória necessária (incluindo a sobrecarga mencionada anteriormente) exceder `_HEAP_MAXREQ`. Para obter informações sobre esse e outros códigos de erro, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).  
  
 Para obter informações sobre como os blocos de memória são alocados, inicializados e gerenciados na versão de depuração do heap de base, consulte [Detalhes do heap de depuração CRT](/visualstudio/debugger/crt-debug-heap-details). Para obter informações sobre as diferenças entre chamar uma função de heap padrão e sua versão de depuração em um build de depuração de um aplicativo, consulte [Versões de depuração das funções de alocação de heap](/visualstudio/debugger/debug-versions-of-heap-allocation-functions).  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_calloc_dbg`|\<crtdbg.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="example"></a>Exemplo  
  
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
  
```Output  
Allocated memory successfully  
```  
  
## <a name="see-also"></a>Consulte também  
 [Rotinas de depuração](../../c-runtime-library/debug-routines.md)   
 [calloc](../../c-runtime-library/reference/calloc.md)   
 [_malloc_dbg](../../c-runtime-library/reference/malloc-dbg.md)   
 [_DEBUG](../../c-runtime-library/debug.md)