---
title: _aligned_recalloc_dbg | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: reference
apiname:
- _aligned_recalloc_dbg
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
- _aligned_recalloc_dbg
- aligned_recalloc_dbg
dev_langs:
- C++
helpviewer_keywords:
- aligned_recalloc_dbg function
- _aligned_recalloc_dbg function
ms.assetid: 55c3c27e-561c-4d6b-9bf9-1e34cc556e4b
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: dfa1d87d363fb0c306e3befb3d2fd7fd6a0d3bf0
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="alignedrecallocdbg"></a>_aligned_recalloc_dbg
Altera o tamanho de um bloco de memória que foi alocado com [_aligned_malloc](../../c-runtime-library/reference/aligned-malloc.md) ou [_aligned_offset_malloc](../../c-runtime-library/reference/aligned-offset-malloc.md) e inicializa a memória como 0 (somente versão de depuração).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
void * _aligned_recalloc_dbg(  
   void * memblock,   
   size_t num,  
   size_t size,   
   size_t alignment,  
   const char *filename,  
   int linenumber  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 [in] `memblock`  
 O ponteiro do bloco de memória atual.  
  
 [in] `num`  
 O número de elementos.  
  
 [in] `size`  
 O tamanho, em bytes, de cada elemento.  
  
 [in] `alignment`  
 O valor de alinhamento, que deve ser um inteiro elevado à segunda potência.  
  
 [in] `filename`  
 Ponteiro para o nome do arquivo de origem que solicitou a operação de alocação ou `NULL`.  
  
 [in] `linenumber`  
 Número da linha no arquivo de origem em que a operação de alocação foi solicitada ou `NULL`.  
  
## <a name="return-value"></a>Valor de retorno  
 `_aligned_recalloc_dbg` retorna um ponteiro nulo para o bloco de memória realocado (e possivelmente migrado). O valor retornado é `NULL` se o tamanho for zero e o argumento do buffer não for `NULL`, ou se não houver memória suficiente para expandir o bloco para o tamanho determinado. No primeiro caso, o bloco original é liberado. No segundo caso, ele permanece inalterado. O valor retornado indica um espaço de armazenamento que sempre está sutilmente alinhado para armazenamento de qualquer tipo de objeto. Para obter um ponteiro para um tipo que não seja nulo, digite a conversão no valor retornado.  
  
 Realocar a memória e alterar o alinhamento de um bloco é um erro.  
  
## <a name="remarks"></a>Comentários  
 `_aligned_recalloc_dbg` é uma versão de depuração da função [_aligned_recalloc](../../c-runtime-library/reference/aligned-recalloc.md). Quando [_DEBUG](../../c-runtime-library/debug.md) não está definido, cada chamada para `_aligned_recalloc_dbg` é reduzida a uma chamada para `_aligned_recalloc`. `_aligned_recalloc` e `_aligned_recalloc_dbg` realocam um bloco de memória no heap de base, mas `_aligned_recalloc_dbg` acomoda diversos recursos de depuração: buffers nos dois lados da parte do usuário do bloco para testar se há perdas, um parâmetro de tipo de bloco para rastrear tipos de alocação específicos e informações de `filename`/`linenumber` para determinar a origem das solicitações de alocação.  
  
 `_aligned_recalloc_dbg` realoca o bloco de memória especificado com um pouco mais de espaço do que o tamanho solicitado (`num` * `size`), que pode ser maior ou menor que o tamanho do bloco de memória alocado originalmente. O espaço adicional é usado pelo gerenciador de heaps de depuração para vincular os blocos de memória de depuração e fornecer informações do cabeçalho de depuração ao aplicativo e substituir buffers. A realocação pode resultar no deslocamento do bloco de memória original para outro local do heap e alterar o tamanho do bloco de memória. A parte do usuário do bloco é preenchida com o valor 0xCD e os buffers de substituição são preenchidos com 0xFD.  
  
 `_aligned_recalloc_dbg` definirá `errno` como `ENOMEM` se uma alocação de memória falhar; `EINVAL` será retornado se uma quantidade de memória necessária (incluindo a sobrecarga mencionada anteriormente) exceder `_HEAP_MAXREQ`. Para obter informações sobre esse e outros códigos de erro, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).  
  
 Além disso, `_aligned_recalloc_dbg` valida seus parâmetros. Se `alignment` não for um número elevado à segunda potência, essa função invocará o manipulador de parâmetro inválido, conforme a descrição em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essa função retornará `NULL` e definirá `errno` como `EINVAL`.  
  
 Para obter informações sobre como os blocos de memória são alocados, inicializados e gerenciados na versão de depuração do heap de base, consulte [Detalhes do heap de depuração CRT](/visualstudio/debugger/crt-debug-heap-details). Para obter informações sobre os tipos de blocos de alocação e como eles são usados, consulte [Types of blocks on the debug heap](/visualstudio/debugger/crt-debug-heap-details) (Tipos de blocos no heap de depuração). Para obter informações sobre as diferenças entre chamar uma função de heap padrão e sua versão de depuração em um build de depuração de um aplicativo, consulte [Versões de depuração das funções de alocação de heap](/visualstudio/debugger/debug-versions-of-heap-allocation-functions).  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_aligned_recalloc_dbg`|\<crtdbg.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="libraries"></a>Libraries  
 Somente versões de depuração de [bibliotecas de tempo de execução C](../../c-runtime-library/crt-library-features.md).  
  
## <a name="see-also"></a>Consulte também  
 [Rotinas de depuração](../../c-runtime-library/debug-routines.md)