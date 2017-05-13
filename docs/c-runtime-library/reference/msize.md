---
title: _msize | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _msize
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
- api-ms-win-crt-heap-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- msize
- _msize
dev_langs:
- C++
helpviewer_keywords:
- memory blocks
- msize function
- _msize function
ms.assetid: 02b1f89e-d0d7-4f12-938a-9eeba48a0f88
caps.latest.revision: 12
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
ms.sourcegitcommit: e257f037a05c45f5b98e64ea55bd125af443b0be
ms.openlocfilehash: f669b35ab67ff08835e3335f702027d61581b868
ms.contentlocale: pt-br
ms.lasthandoff: 03/30/2017

---
# <a name="msize"></a>_msize
Retorna o tamanho de um bloco de memória alocado no heap.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      size_t _msize(  
   void *memblock   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `memblock`  
 Ponteiro para o bloco de memória.  
  
## <a name="return-value"></a>Valor de retorno  
 `_msize` retorna o tamanho (em bytes) como um inteiro sem sinal.  
  
## <a name="remarks"></a>Comentários  
 A função `_msize` retorna o tamanho, em bytes, do bloco de memória alocado por uma chamada para `calloc`, `malloc` ou `realloc`.  
  
 Quando o aplicativo estiver vinculado a uma versão de depuração das bibliotecas de tempo de execução C, `_msize` será resolvido como [_msize_dbg](../../c-runtime-library/reference/msize-dbg.md). Para obter mais informações sobre como o heap é gerenciado durante o processo de depuração, consulte [The CRT Debug Heap](/visualstudio/debugger/crt-debug-heap-details) (O heap de depuração do CRT).  
  
 Esta função valida seu parâmetro. Se `memblock` for um ponteiro nulo, `_msize` invocará o manipulador de parâmetro inválido, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se o erro for tratado, a função definirá `errno` como `EINVAL` e retornará –1.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_msize`|\<malloc.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="libraries"></a>Libraries  
 Todas as versões das [bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md).  
  
## <a name="example"></a>Exemplo  
 Veja o exemplo de [realloc](../../c-runtime-library/reference/realloc.md).  
  
## <a name="see-also"></a>Consulte também  
 [Alocação de Memória](../../c-runtime-library/memory-allocation.md)   
 [calloc](../../c-runtime-library/reference/calloc.md)   
 [_expand](../../c-runtime-library/reference/expand.md)   
 [malloc](../../c-runtime-library/reference/malloc.md)   
 [realloc](../../c-runtime-library/reference/realloc.md)
