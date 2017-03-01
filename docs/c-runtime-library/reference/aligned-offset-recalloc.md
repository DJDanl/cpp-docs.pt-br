---
title: _aligned_offset_recalloc | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _aligned_offset_recalloc
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
- aligned_offset_recalloc
- _aligned_offset_recalloc
dev_langs:
- C++
helpviewer_keywords:
- aligned_offset_recalloc function
- _aligned_offset_recalloc function
ms.assetid: a258f54e-eeb4-4853-96fc-007d710f98e9
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
translationtype: Machine Translation
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: 29b1ec185542bdec1fdb70c4c11842367e7ebf50
ms.lasthandoff: 02/25/2017

---
# <a name="alignedoffsetrecalloc"></a>_aligned_offset_recalloc
Altera o tamanho de um bloco de memória que foi alocado com [_aligned_malloc](../../c-runtime-library/reference/aligned-malloc.md) ou [_aligned_offset_malloc](../../c-runtime-library/reference/aligned-offset-malloc.md) e inicializa a memória como 0.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
void * _aligned_offset_recalloc(  
   void *memblock,   
   size_t num,   
   size_t size,   
   size_t alignment,  
   size_t offset  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `memblock`  
 O ponteiro do bloco de memória atual.  
  
 `num`  
 Número de elementos.  
  
 `size`  
 O comprimento, em bytes, de cada elemento.  
  
 `alignment`  
 O valor de alinhamento, que deve ser um inteiro elevado à segunda potência.  
  
 `offset`  
 O deslocamento na alocação de memória para forçar o alinhamento.  
  
## <a name="return-value"></a>Valor de retorno  
 `_aligned_offset_recalloc` retorna um ponteiro nulo para o bloco de memória realocado (e possivelmente migrado). O valor retornado é `NULL` se o tamanho for zero e o argumento do buffer não for `NULL`, ou se não houver memória suficiente para expandir o bloco para o tamanho determinado. No primeiro caso, o bloco original é liberado. No segundo caso, ele permanece inalterado. O valor retornado indica um espaço de armazenamento que sempre está sutilmente alinhado para armazenamento de qualquer tipo de objeto. Para obter um ponteiro para um tipo que não seja nulo, digite a conversão no valor retornado.  
  
 `_aligned_offset_recalloc` é marcado como `__declspec(noalias)` e `__declspec(restrict)`, o que representa a garantia de que a função não modifica variáveis globais e que o ponteiro retornado não é um alias. Para obter mais informações, consulte [noalias](../../cpp/noalias.md) e [restrict](../../cpp/restrict.md).  
  
## <a name="remarks"></a>Comentários  
 Assim como [_aligned_offset_malloc](../../c-runtime-library/reference/aligned-offset-malloc.md), `_aligned_offset_recalloc` permite que uma estrutura seja alinhada em um deslocamento dentro da estrutura.  
  
 `_aligned_offset_recalloc` baseia-se em `malloc`. Para obter mais informações sobre como usar `_aligned_offset_malloc`, consulte [malloc](../../c-runtime-library/reference/malloc.md). Se `memblock` é `NULL`, a função chama `_aligned_offset_malloc` internamente.  
  
 Essa função definirá `errno` como `ENOMEM` se a alocação de memória falhar ou se o tamanho solicitado (`num` * `size`) for maior que `_HEAP_MAXREQ`. Para obter mais informações sobre `errno`, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md). Além disso, `_aligned_offset_recalloc` valida seus parâmetros. Se `alignment` não for um número elevado à segunda potência ou se `offset` for maior ou igual ao tamanho solicitado e diferente de zero, essa função invocará o manipulador de parâmetro inválido, conforme a descrição em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essa função retornará `NULL` e definirá `errno` como `EINVAL`.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_aligned_offset_recalloc`|\<malloc.h>|  
  
## <a name="net-framework-equivalent"></a>Equivalente ao .NET Framework  
 Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [Exemplos de invocação de plataforma](http://msdn.microsoft.com/Library/15926806-f0b7-487e-93a6-4e9367ec689f).  
  
## <a name="see-also"></a>Consulte também  
 [Alinhamento de dados](../../c-runtime-library/data-alignment.md)   
 [_recalloc](../../c-runtime-library/reference/recalloc.md)   
 [_aligned_recalloc](../../c-runtime-library/reference/aligned-recalloc.md)
