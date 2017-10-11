---
title: _aligned_offset_realloc | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _aligned_offset_realloc
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
- aligned_offset_realloc
- _aligned_offset_realloc
dev_langs:
- C++
helpviewer_keywords:
- aligned_offset_realloc function
- _aligned_offset_realloc function
ms.assetid: e0263533-991e-41b0-acc9-1b8a51ab9ecd
caps.latest.revision: 18
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 9b90b8b2ff057e42425825ae7d02b8d0901a5e45
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="alignedoffsetrealloc"></a>_aligned_offset_realloc
Altera o tamanho de um bloco de memória que foi alocado com [_aligned_malloc](../../c-runtime-library/reference/aligned-malloc.md) ou [_aligned_offset_malloc](../../c-runtime-library/reference/aligned-offset-malloc.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
void * _aligned_offset_realloc(  
   void *memblock,   
   size_t size,   
   size_t alignment,  
   size_t offset  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `memblock`  
 O ponteiro do bloco de memória atual.  
  
 `size`  
 O tamanho da alocação de memória.  
  
 `alignment`  
 O valor de alinhamento, que deve ser um inteiro elevado à segunda potência.  
  
 `offset`  
 O deslocamento na alocação de memória para forçar o alinhamento.  
  
## <a name="return-value"></a>Valor de retorno  
 `_aligned_offset_realloc` retorna um ponteiro nulo para o bloco de memória realocado (e possivelmente migrado). O valor retornado é `NULL` se o tamanho for zero e o argumento do buffer não for `NULL`, ou se não houver memória suficiente para expandir o bloco para o tamanho determinado. No primeiro caso, o bloco original é liberado. No segundo caso, ele permanece inalterado. O valor retornado indica um espaço de armazenamento que sempre está sutilmente alinhado para armazenamento de qualquer tipo de objeto. Para obter um ponteiro para um tipo que não seja nulo, digite a conversão no valor retornado.  
  
 `_aligned_offset_realloc` é marcado como `__declspec(noalias)` e `__declspec(restrict)`, o que representa a garantia de que a função não modifica variáveis globais e que o ponteiro retornado não é um alias. Para obter mais informações, consulte [noalias](../../cpp/noalias.md) e [restrict](../../cpp/restrict.md).  
  
## <a name="remarks"></a>Comentários  
 Assim como [_aligned_offset_malloc](../../c-runtime-library/reference/aligned-offset-malloc.md), `_aligned_offset_realloc` permite que uma estrutura seja alinhada em um deslocamento dentro da estrutura.  
  
 `_aligned_offset_realloc` baseia-se em `malloc`. Para obter mais informações sobre como usar `_aligned_offset_malloc`, consulte [malloc](../../c-runtime-library/reference/malloc.md). Se `memblock` é `NULL`, a função chama `_aligned_offset_malloc` internamente.  
  
 Essa função define `errno` como `ENOMEM` se a alocação da memória tiver falhado ou se o tamanho solicitado for maior que `_HEAP_MAXREQ`. Para obter mais informações sobre `errno`, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md). Além disso, `_aligned_offset_realloc` valida seus parâmetros. Se `alignment` não for um número elevado à segunda potência ou se `offset` for maior ou igual a `size` e diferente de zero, essa função invocará o manipulador de parâmetro inválido, conforme a descrição em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essa função retornará `NULL` e definirá `errno` como `EINVAL`.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_aligned_offset_realloc`|\<malloc.h>|  
  
## <a name="example"></a>Exemplo  
 Para obter mais informações, consulte [_aligned_malloc](../../c-runtime-library/reference/aligned-malloc.md).  
  
## <a name="see-also"></a>Consulte também  
 [Alinhamento de dados](../../c-runtime-library/data-alignment.md)
