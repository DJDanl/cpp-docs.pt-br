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
ms.openlocfilehash: 78544424b727797158109fa3000ee2ebf8066cf7
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87229318"
---
# <a name="_static_assert-macro"></a>Macro _STATIC_ASSERT

Avalie uma expressão em tempo de compilação e gere um erro quando o resultado for **false**.

## <a name="syntax"></a>Sintaxe

```C
_STATIC_ASSERT(
    booleanExpression
);
```

### <a name="parameters"></a>parâmetros

*valor booliano*<br/>
Expressão (incluindo ponteiros) que é avaliada como zero (**true**) ou 0 (**false**).

## <a name="remarks"></a>Comentários

Essa macro é semelhante à [_ASSERT e _ASSERTE macros](assert-asserte-assert-expr-macros.md), exceto que a *booliana* é avaliada no momento da compilação, em vez de em tempo de execução. Se *booliana* for avaliada como **false** (0), o [erro do compilador C2466](../../error-messages/compiler-errors-1/compiler-error-c2466.md) será gerado.

## <a name="example"></a>Exemplo

Neste exemplo, verificamos se o [sizeof](../../c-language/sizeof-operator-c.md) **`int`** é maior ou igual a 2 bytes e se o [sizeof](../../c-language/sizeof-operator-c.md) a **`long`** é 1 byte. O programa não será compilado e gerará o [erro C2466 do compilador](../../error-messages/compiler-errors-1/compiler-error-c2466.md) porque um **`long`** é maior que 1 byte.

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

## <a name="see-also"></a>Confira também

[Referência de função alfabética](crt-alphabetical-function-reference.md)<br/>
[_ASSERT, _ASSERTE, _ASSERT_EXPR macros](assert-asserte-assert-expr-macros.md)<br/>
