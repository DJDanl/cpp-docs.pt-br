---
title: Macro _STATIC_ASSERT | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
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
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 8eda76666679b133b2d5486d21cd4c8e24d1fdf3
ms.sourcegitcommit: 761c5f7c506915f5a62ef3847714f43e9b815352
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/07/2018
ms.locfileid: "44105075"
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
