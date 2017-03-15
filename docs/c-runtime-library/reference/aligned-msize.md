---
title: _aligned_msize | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _aligned_msize
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
- _aligned_msize
- aligned_msize
dev_langs:
- C++
helpviewer_keywords:
- aligned_msize function
- _aligned_msize function
ms.assetid: 10995edc-2110-4212-9ca9-5e0220a464f4
caps.latest.revision: 6
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
translationtype: Machine Translation
ms.sourcegitcommit: 84964b0a49b236bae056125de8155b18880eb378
ms.openlocfilehash: 375eb2921ac47be819eeb050fa87643c50a52289
ms.lasthandoff: 02/25/2017

---
# <a name="alignedmsize"></a>_aligned_msize
Retorna o tamanho de um bloco de memória alocado no heap.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
size_t _msize(  
   void *memblock,  
   size_t alignment,  
   size_t offset  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 [in] `memblock`  
 Ponteiro para o bloco de memória.  
  
 [in] `alignment`  
 O valor de alinhamento, que deve ser um inteiro elevado à segunda potência.  
  
 [in] `offset`  
 O deslocamento na alocação de memória para forçar o alinhamento.  
  
## <a name="return-value"></a>Valor de retorno  
 Retorna o tamanho (em bytes) como um inteiro sem sinal.  
  
## <a name="remarks"></a>Comentários  
 A função `_aligned_msize` retorna o tamanho, em bytes, do bloco de memória alocado por uma chamada para [_aligned_malloc](../../c-runtime-library/reference/aligned-malloc.md) ou [_aligned_realloc](../../c-runtime-library/reference/aligned-realloc.md). Os valores `alignment` e `offset` devem ser os mesmos que os valores passados para a função que alocou o bloco.  
  
 Quando o aplicativo estiver vinculado a uma versão de depuração das bibliotecas em tempo de execução do C, `_aligned_msize` será resolvido como [_aligned_msize_dbg](../../c-runtime-library/reference/aligned-msize-dbg.md). Para obter mais informações sobre como o heap é gerenciado durante o processo de depuração, consulte [The CRT Debug Heap](/visualstudio/debugger/crt-debug-heap-details) (O heap de depuração do CRT).  
  
 Esta função valida seu parâmetro. Se `memblock` for um ponteiro nulo ou se `alignment` não for um número elevado à segunda potência, `_msize` invocará um manipulador de parâmetro inválido, conforme a descrição em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se o erro for tratado, a função definirá `errno` como `EINVAL` e retornará –1.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_msize`|\<malloc.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="libraries"></a>Libraries  
 Todas as versões das [bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md).  
  
## <a name="net-framework-equivalent"></a>Equivalente ao .NET Framework  
 Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [Exemplos de invocação de plataforma](http://msdn.microsoft.com/Library/15926806-f0b7-487e-93a6-4e9367ec689f).  
  
## <a name="see-also"></a>Consulte também  
 [Alocação de Memória](../../c-runtime-library/memory-allocation.md)
