---
title: _aligned_offset_recalloc_dbg | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _aligned_offset_recalloc_dbg
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
- aligned_offset_recalloc_dbg
- _aligned_offset_recalloc_dbg
dev_langs:
- C++
helpviewer_keywords:
- aligned_offset_recalloc_dbg function
- _aligned_offset_recalloc_dbg function
ms.assetid: 7ab719c3-77e0-4d2e-934f-01529d062fbf
caps.latest.revision: 9
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: a82768750e6a7837bb81edd8a51847f83c294c20
ms.openlocfilehash: 7c65c73075c282f3a1b0dac83692c0adfe527c58
ms.contentlocale: pt-br
ms.lasthandoff: 04/04/2017

---
# <a name="alignedoffsetrecallocdbg"></a>_aligned_offset_recalloc_dbg
Altera o tamanho de um bloco de memória que foi alocado com [_aligned_malloc](../../c-runtime-library/reference/aligned-malloc.md) ou [_aligned_offset_malloc](../../c-runtime-library/reference/aligned-offset-malloc.md) e inicializa a memória como 0 (somente versão de depuração).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
void * _aligned_offset_recalloc_dbg(  
   void *memblock,   
   size_t num,   
   size_t size,   
   size_t alignment,  
   size_t offset,  
   const char *filename,  
   int linenumber  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 [in] `memblock`  
 O ponteiro do bloco de memória atual.  
  
 [in] `num`  
 Número de elementos.  
  
 [in] `size`  
 O comprimento, em bytes, de cada elemento.  
  
 [in] `alignment`  
 O valor de alinhamento, que deve ser um inteiro elevado à segunda potência.  
  
 [in] `offset`  
 O deslocamento na alocação de memória para forçar o alinhamento.  
  
 [in] `filename`  
 Ponteiro para o nome do arquivo de origem que solicitou a operação `realloc` ou NULL.  
  
 [in] `linenumber`  
 Número da linha do arquivo de origem em que a operação `realloc` foi solicitada ou NULL.  
  
## <a name="return-value"></a>Valor de retorno  
 `_aligned_offset_recalloc_dbg` retorna um ponteiro nulo para o bloco de memória realocado (e possivelmente migrado). O valor retornado é `NULL` se o tamanho for zero e o argumento do buffer não for `NULL`, ou se não houver memória suficiente para expandir o bloco para o tamanho determinado. No primeiro caso, o bloco original é liberado. No segundo caso, ele permanece inalterado. O valor retornado indica um espaço de armazenamento que sempre está sutilmente alinhado para armazenamento de qualquer tipo de objeto. Para obter um ponteiro para um tipo que não seja nulo, digite a conversão no valor retornado.  
  
## <a name="remarks"></a>Comentários  
 `_aligned_offset_realloc_dbg` é uma versão de depuração da função [_aligned_offset_recalloc](../../c-runtime-library/reference/aligned-offset-recalloc.md). Quando [_DEBUG](../../c-runtime-library/debug.md) não está definido, cada chamada para `_aligned_offset_recalloc_dbg` é reduzida a uma chamada para `_aligned_offset_recalloc`. `_aligned_offset_recalloc` e `_aligned_offset_recalloc_dbg` realocam um bloco de memória no heap de base, mas `_aligned_offset_recalloc_dbg` acomoda diversos recursos de depuração: buffers nos dois lados da parte do usuário do bloco para testar se há perdas, um parâmetro de tipo de bloco para rastrear tipos de alocação específicos e informações de `filename`/`linenumber` para determinar a origem das solicitações de alocação.  
  
 `_aligned_offset_realloc_dbg` realoca o bloco de memória especificado com um pouco mais de espaço que o `newSize` solicitado. `newSize` pode ser maior ou menor que o espaço do bloco de memória alocado originalmente. O espaço adicional é usado pelo gerenciador de heaps de depuração para vincular os blocos de memória de depuração e fornecer informações do cabeçalho de depuração ao aplicativo e substituir buffers. A realocação pode resultar no deslocamento do bloco de memória original para outro local do heap e alterar o tamanho do bloco de memória. Se o bloco de memória for movido, o conteúdo do bloco original será substituído.  
  
 Essa função definirá `errno` como `ENOMEM` se a alocação de memória falhar ou se o tamanho solicitado (`num` * `size`) for maior que `_HEAP_MAXREQ`. Para obter mais informações sobre `errno`, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md). Além disso, `_aligned_offset_recalloc_dbg` valida seus parâmetros. Se `alignment` não for um número elevado à segunda potência ou se `offset` for maior ou igual ao tamanho solicitado e diferente de zero, essa função invocará o manipulador de parâmetro inválido, conforme a descrição em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essa função retornará `NULL` e definirá `errno` como `EINVAL`.  
  
 Para obter informações sobre como os blocos de memória são alocados, inicializados e gerenciados na versão de depuração do heap de base, consulte [Detalhes do heap de depuração CRT](/visualstudio/debugger/crt-debug-heap-details). Para obter informações sobre os tipos de blocos de alocação e como eles são usados, consulte [Types of blocks on the debug heap](/visualstudio/debugger/crt-debug-heap-details) (Tipos de blocos no heap de depuração). Para obter informações sobre as diferenças entre chamar uma função de heap padrão e sua versão de depuração em um build de depuração de um aplicativo, consulte [Versões de depuração das funções de alocação de heap](/visualstudio/debugger/debug-versions-of-heap-allocation-functions).  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_aligned_offset_recalloc_dbg`|\<malloc.h>|  
  
## <a name="see-also"></a>Consulte também  
 [Alinhamento de dados](../../c-runtime-library/data-alignment.md)
