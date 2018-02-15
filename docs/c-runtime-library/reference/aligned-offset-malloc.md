---
title: _aligned_offset_malloc | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: reference
apiname:
- _aligned_offset_malloc
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
- _aligned_offset_malloc
- aligned_offset_malloc
dev_langs:
- C++
helpviewer_keywords:
- _aligned_offset_malloc function
- aligned_offset_malloc function
ms.assetid: 447681a3-7c95-4655-86ba-fa3a4ca4c521
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 1b192d8bf88ac40fffdbdf601e74ee1b265e7171
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="alignedoffsetmalloc"></a>_aligned_offset_malloc
Aloca memória em um limite de alinhamento especificado.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
void * _aligned_offset_malloc(  
   size_t size,   
   size_t alignment,   
   size_t offset  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 [in] `size`  
 Tamanho da alocação de memória solicitada.  
  
 [in] `alignment`  
 O valor de alinhamento, que deve ser um inteiro elevado à segunda potência.  
  
 [in] `offset`  
 O deslocamento na alocação de memória para forçar o alinhamento.  
  
## <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o bloco de memória alocado ou `NULL`, se a operação tiver falhado.  
  
## <a name="remarks"></a>Comentários  
 `_aligned_offset_malloc` é útil em situações em que o alinhamento é necessário em um elemento aninhado. Por exemplo, se o alinhamento foi necessário em uma classe aninhada.  
  
 `_aligned_offset_malloc` é baseado em `malloc`. Para obter mais informações, consulte [malloc](../../c-runtime-library/reference/malloc.md).  
  
 `_aligned_offset_malloc` é marcado como `__declspec(noalias)` e `__declspec(restrict)`, o que representa a garantia de que a função não modifica variáveis globais e que o ponteiro retornado não é um alias. Para obter mais informações, consulte [noalias](../../cpp/noalias.md) e [restrict](../../cpp/restrict.md).  
  
 Essa função define `errno` como `ENOMEM` se a alocação da memória tiver falhado ou se o tamanho solicitado for maior que `_HEAP_MAXREQ`. Para obter mais informações sobre `errno`, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md). Além disso, `_aligned_offset_malloc` valida seus parâmetros. Se `alignment` não for um número elevado à segunda potência ou se `offset` for maior ou igual a `size` e diferente de zero, essa função invocará o manipulador de parâmetro inválido, conforme a descrição em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essa função retornará `NULL` e definirá `errno` como `EINVAL`.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_aligned_offset_malloc`|\<malloc.h>|  
  
## <a name="example"></a>Exemplo  
 Para obter mais informações, consulte [_aligned_malloc](../../c-runtime-library/reference/aligned-malloc.md).  
  
## <a name="see-also"></a>Consulte também  
 [Alinhamento de dados](../../c-runtime-library/data-alignment.md)