---
title: _expand_dbg | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: reference
apiname:
- _expand_dbg
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
- expand_dbg
- _expand_dbg
dev_langs:
- C++
helpviewer_keywords:
- memory blocks, changing size
- expand_dbg function
- _expand_dbg function
ms.assetid: dc58c91f-72a8-48c6-b643-fe130fb6c1fd
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 41f3d59cec6ec4a064143e0211ebd956f30e16e5
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="expanddbg"></a>_expand_dbg
Redimensiona um bloco especificado de memória no heap pela expansão ou contração do bloco (somente versão de depuração).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
void *_expand_dbg(   
   void *userData,  
   size_t newSize,  
   int blockType,  
   const char *filename,  
   int linenumber   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `userData`  
 Ponteiro para o bloco de memória alocado anteriormente.  
  
 `newSize`  
 Solicitou o novo tamanho do bloco (em bytes).  
  
 `blockType`  
 Tipo de bloco redimensionado solicitado: `_CLIENT_BLOCK` ou `_NORMAL_BLOCK`.  
  
 `filename`  
 Ponteiro para o nome do arquivo de origem que solicitou a operação de expansão ou `NULL`.  
  
 `linenumber`  
 Número de linha do arquivo de origem em que a operação de expansão foi solicitada ou `NULL`.  
  
 Os parâmetros `filename` e `linenumber` estarão disponíveis apenas quando `_expand_dbg` tiver sido chamado explicitamente ou quando a constante do pré-processador [_CRTDBG_MAP_ALLOC](../../c-runtime-library/crtdbg-map-alloc.md) tiver sido definida.  
  
## <a name="return-value"></a>Valor de retorno  
 Após a conclusão bem-sucedida, `_expand_dbg` retorna um ponteiro para o bloco de memória redimensionado. Como a memória não é movida, o endereço é o mesmo que userData. Se ocorreu um erro ou o bloco não pôde ser expandido para o tamanho solicitado, ele retornará `NULL`. Se ocorrer uma falha, `errno` terá informações do sistema operacional sobre a natureza da falha. Para obter mais informações sobre `errno`, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).  
  
## <a name="remarks"></a>Comentários  
 A função `_expand_dbg` é uma versão de depuração da função _[expand](../../c-runtime-library/reference/expand.md). Quando [_DEBUG](../../c-runtime-library/debug.md) não está definido, cada chamada para `_expand_dbg` é reduzida a uma chamada para `_expand`. Tanto `_expand` quanto `_expand_dbg` redimensionam um bloco de memória no heap de base, mas `_expand_dbg` acomoda diversos recursos de depuração: buffers dos dois lados da porção do usuário do bloco para verificar se há perdas, um parâmetro de tipo de bloco para acompanhar tipos específicos de alocação e informações `filename`/`linenumber` para determinar a origem das solicitações de alocação.  
  
 `_expand_dbg` realoca o bloco de memória especificado com um pouco mais de espaço que o `newSize` solicitado. `newSize` pode ser maior ou menor que o espaço do bloco de memória alocado originalmente. O espaço adicional é usado pelo gerenciador de heaps de depuração para vincular os blocos de memória de depuração e fornecer informações do cabeçalho de depuração ao aplicativo e substituir buffers. O redimensionamento é realizado pela expansão ou contração do bloco de memória original. `_expand_dbg` não move o bloco de memória, como faz a função [_realloc_dbg](../../c-runtime-library/reference/realloc-dbg.md).  
  
 Quando `newSize` for maior do que o tamanho do bloco original, o bloco de memória será expandido. Durante uma expansão, se o bloco de memória não puder ser expandido para acomodar o tamanho solicitado, `NULL` será retornado. Quando `newSize` for menor do que o tamanho do bloco original, o bloco de memória será contraído até que o novo tamanho seja obtido.  
  
 Para obter informações sobre como os blocos de memória são alocados, inicializados e gerenciados na versão de depuração do heap de base, consulte [Detalhes do heap de depuração CRT](/visualstudio/debugger/crt-debug-heap-details). Para obter informações sobre os tipos de blocos de alocação e como eles são usados, consulte [Types of blocks on the debug heap](/visualstudio/debugger/crt-debug-heap-details) (Tipos de blocos no heap de depuração). Para obter informações sobre as diferenças entre chamar uma função de heap padrão e sua versão de depuração em um build de depuração de um aplicativo, consulte [Versões de depuração das funções de alocação de heap](/visualstudio/debugger/debug-versions-of-heap-allocation-functions).  
  
 Essa função valida seus parâmetros. Se `memblock` for um ponteiro nulo ou se a função for maior que `_HEAP_MAXREQ`, essa função invocará um manipulador de parâmetro inválido, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução tiver permissão para continuar, `errno` será definido como `EINVAL` e a função retornará `NULL`.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_expand_dbg`|\<crtdbg.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="libraries"></a>Libraries  
 Somente versões de depuração de [bibliotecas de tempo de execução C](../../c-runtime-library/crt-library-features.md).  
  
## <a name="example"></a>Exemplo  
  
```  
// crt_expand_dbg.c  
//  
// This program allocates a block of memory using _malloc_dbg  
// and then calls _msize_dbg to display the size of that block.  
// Next, it uses _expand_dbg to expand the amount of  
// memory used by the buffer and then calls _msize_dbg again to  
// display the new amount of memory allocated to the buffer.  
//  
  
#include <stdio.h>  
#include <malloc.h>  
#include <stdlib.h>  
#include <crtdbg.h>  
  
int main( void )  
{  
   long *buffer;  
   size_t size;  
  
   // Call _malloc_dbg to include the filename and line number  
   // of our allocation request in the header  
   buffer = (long *)_malloc_dbg( 40 * sizeof(long),  
                                 _NORMAL_BLOCK, __FILE__, __LINE__ );  
   if( buffer == NULL )  
      exit( 1 );  
  
   // Get the size of the buffer by calling _msize_dbg  
   size = _msize_dbg( buffer, _NORMAL_BLOCK );  
   printf( "Size of block after _malloc_dbg of 40 longs: %u\n", size );  
  
   // Expand the buffer using _expand_dbg and show the new size  
   buffer = (long *)_expand_dbg( buffer, size + sizeof(long),  
                                 _NORMAL_BLOCK, __FILE__, __LINE__ );  
  
   if( buffer == NULL )  
      exit( 1 );  
   size = _msize_dbg( buffer, _NORMAL_BLOCK );  
   printf( "Size of block after _expand_dbg of 1 more long: %u\n",  
           size );  
  
   free( buffer );  
   exit( 0 );  
}  
```  
  
```Output  
Size of block after _malloc_dbg of 40 longs: 160  
Size of block after _expand_dbg of 1 more long: 164  
```  
  
## <a name="comment"></a>Comentário  
 A saída desse programa depende da capacidade do seu computador de expandir todas as seções. Se todas as seções estiverem expandidas, a saída será refletida na seção de saída.  
  
## <a name="see-also"></a>Consulte também  
 [Rotinas de depuração](../../c-runtime-library/debug-routines.md)   
 [_malloc_dbg](../../c-runtime-library/reference/malloc-dbg.md)