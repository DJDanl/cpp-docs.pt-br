---
title: Macro _STATIC_ASSERT | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: reference
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
- _STATIC_ASSERT
dev_langs:
- C++
helpviewer_keywords:
- _STATIC_ASSERT macro
ms.assetid: 89b0350c-2c2f-4be6-9786-8b1f0780a5da
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: f62f2f2f5a0d78a0b77cb21d869be209d9293bd0
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="staticassert-macro"></a>Macro _STATIC_ASSERT
Avaliar uma expressão em tempo de compilação e gerar um erro quando o resultado é `FALSE`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
_STATIC_ASSERT(  
    booleanExpression  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `booleanExpression`  
 Uma expressão (incluindo ponteiros) avaliada como não zero (`TRUE`) ou 0 (`FALSE`).  
  
## <a name="remarks"></a>Comentários  
 Essa macro é semelhante às [macros _ASSERT e _ASSERTE](../../c-runtime-library/reference/assert-asserte-assert-expr-macros.md), exceto pelo fato de que `booleanExpression` é avaliada em tempo de compilação em vez de em tempo de execução. Se `booleanExpression` é avaliada como `FALSE` (0), o [Erro do compilador C2466](../../error-messages/compiler-errors-1/compiler-error-c2466.md) é gerado.  
  
## <a name="example"></a>Exemplo  
 Neste exemplo, verificamos se o `sizeof` um `int` é maior ou igual a 2 bytes e se o `sizeof` um `long` é 1 byte. O programa não será compilado e gerará o [Erro do compilador C2466](../../error-messages/compiler-errors-1/compiler-error-c2466.md) porque um `long` é maior do que 1 byte.  
  
```  
// crt__static_assert.c  
  
#include <crtdbg.h>  
#include <stdio.h>  
  
_STATIC_ASSERT(sizeof(int) >= 2);  
_STATIC_ASSERT(sizeof(long) == 1);  // C2466  
  
int main()  
{  
    printf("I am sure that sizeof(int) will be >= 2: %d\n",  
        sizeof(int));  
    printf("I am not so sure that sizeof(long) == 1: %d\n",  
        sizeof(long));  
}  
```  
  
## <a name="requirements"></a>Requisitos  
  
|Macro|Cabeçalho necessário|  
|-----------|---------------------|  
|`_STATIC_ASSERT`|\<crtdbg.h>|  
  
## <a name="see-also"></a>Consulte também  
 [Alphabetical Function Reference](../../c-runtime-library/reference/crt-alphabetical-function-reference.md)  (Referência da função alfabética)  
 [Macros _ASSERT, _ASSERTE, _ASSERT_EXPR](../../c-runtime-library/reference/assert-asserte-assert-expr-macros.md)