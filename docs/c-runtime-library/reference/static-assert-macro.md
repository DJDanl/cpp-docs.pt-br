---
title: Macro _STATIC_ASSERT | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
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
caps.latest.revision: 6
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 3076e2e2a27c4f13222ce5dba8bf66cc46ce20c1
ms.sourcegitcommit: ef859ddf5afea903711e36bfd89a72389a12a8d6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/20/2018
---
# <a name="staticassert-macro"></a>Macro _STATIC_ASSERT

Avaliar uma expressão em tempo de compilação e gerar um erro quando o resultado é **FALSE**.

## <a name="syntax"></a>Sintaxe

```C
_STATIC_ASSERT(
    booleanExpression
);
```

### <a name="parameters"></a>Parâmetros

*booleanExpression* (inclusive ponteiros) de expressão que é avaliada como zero (**TRUE**) ou 0 (**FALSE**).

## <a name="remarks"></a>Comentários

Essa macro é semelhante a [macros Assert e asserte](assert-asserte-assert-expr-macros.md), exceto que *booleanExpression* é avaliado em tempo de compilação em vez de em tempo de execução. Se *booleanExpression* é avaliada como **FALSE** (0), [C2466 de erro do compilador](../../error-messages/compiler-errors-1/compiler-error-c2466.md) é gerado.

## <a name="example"></a>Exemplo

Neste exemplo, precisamos verificar se o [sizeof](../../c-language/sizeof-operator-c.md) um **int** é maior que ou igual a 2 bytes e se o [sizeof](../../c-language/sizeof-operator-c.md) um **longo** é 1 byte. O programa não será compilado e gerará [C2466 de erro do compilador](../../error-messages/compiler-errors-1/compiler-error-c2466.md) porque um **longo** é maior do que 1 byte.

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
