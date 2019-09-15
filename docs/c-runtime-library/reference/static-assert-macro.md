---
title: Macro _STATIC_ASSERT
ms.date: 11/04/2016
api_location:
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
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- _STATIC_ASSERT
helpviewer_keywords:
- _STATIC_ASSERT macro
ms.assetid: 89b0350c-2c2f-4be6-9786-8b1f0780a5da
ms.openlocfilehash: ac609fc7af937b6f56cd5b310341409187df7de4
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70957941"
---
# <a name="_static_assert-macro"></a>Macro _STATIC_ASSERT

Avalie uma expressão em tempo de compilação e gere um erro quando o resultado for **false**.

## <a name="syntax"></a>Sintaxe

```C
_STATIC_ASSERT(
    booleanExpression
);
```

### <a name="parameters"></a>Parâmetros

*booleanExpression*<br/>
Expressão (incluindo ponteiros) que é avaliada como zero (**true**) ou 0 (**false**).

## <a name="remarks"></a>Comentários

Essa macro é semelhante às [macros _ASSERT e _ASSERTE](assert-asserte-assert-expr-macros.md), exceto que a *booliana* é avaliada no momento da compilação, em vez de em tempo de execução. Se *booliana* for avaliada como **false** (0), o [erro do compilador C2466](../../error-messages/compiler-errors-1/compiler-error-c2466.md) será gerado.

## <a name="example"></a>Exemplo

Neste exemplo, verificamos se o [sizeof](../../c-language/sizeof-operator-c.md) de um **int** é maior ou igual a 2 bytes e se o [sizeof](../../c-language/sizeof-operator-c.md) de um **longo** é de 1 byte. O programa não será compilado e gerará o [erro C2466 do compilador](../../error-messages/compiler-errors-1/compiler-error-c2466.md) porque um **longo** é maior que 1 byte.

```C
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
|**_STATIC_ASSERT**|\<crtdbg.h>|

## <a name="see-also"></a>Consulte também

[Referência da Função Alfabética](crt-alphabetical-function-reference.md)<br/>
[Macros _ASSERT, _ASSERTE, _ASSERT_EXPR](assert-asserte-assert-expr-macros.md)<br/>
