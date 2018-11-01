---
title: Macro _STATIC_ASSERT
ms.date: 11/04/2016
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
helpviewer_keywords:
- _STATIC_ASSERT macro
ms.assetid: 89b0350c-2c2f-4be6-9786-8b1f0780a5da
ms.openlocfilehash: 5d3aa1d9665b48a0690d8eb62353fc98c5a550f7
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50539536"
---
# <a name="staticassert-macro"></a>Macro _STATIC_ASSERT

Avaliar uma expressão em tempo de compilação e gerar um erro quando o resultado será **falsos**.

## <a name="syntax"></a>Sintaxe

```C
_STATIC_ASSERT(
    booleanExpression
);
```

### <a name="parameters"></a>Parâmetros

*booleanExpression*<br/>
Expressão (incluindo ponteiros) avaliada como não zero (**verdadeira**) ou 0 (**falso**).

## <a name="remarks"></a>Comentários

Essa macro é semelhante a [macros Assert e asserte](assert-asserte-assert-expr-macros.md), exceto pelo fato *booleanExpression* é avaliada em tempo de compilação em vez de em tempo de execução. Se *booleanExpression* é avaliada como **falso** (0), [erro do compilador C2466](../../error-messages/compiler-errors-1/compiler-error-c2466.md) é gerado.

## <a name="example"></a>Exemplo

Neste exemplo, verificamos se o [sizeof](../../c-language/sizeof-operator-c.md) um **int** é maior que ou igual a 2 bytes e se o [sizeof](../../c-language/sizeof-operator-c.md) um **longo** é de 1 byte. O programa não será compilado e gerará [erro do compilador C2466](../../error-messages/compiler-errors-1/compiler-error-c2466.md) porque uma **longo** é maior do que 1 byte.

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
