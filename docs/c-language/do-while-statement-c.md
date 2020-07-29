---
title: Instrução do-while (C)
ms.date: 11/04/2016
f1_keywords:
- do
helpviewer_keywords:
- do-while keyword [C]
ms.assetid: f2ac20a6-10c7-4a08-b5e3-c3b3639dbeaf
ms.openlocfilehash: 4a10b9df9f7276eb8e241d76726bca26f2c0cb75
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87218865"
---
# <a name="do-while-statement-c"></a>Instrução do-while (C)

A instrução *do-while* permite que você repita uma instrução ou instrução composta até que uma expressão especificada seja falsa.

## <a name="syntax"></a>Sintaxe

instrução *Iteration*: &nbsp; &nbsp; &nbsp; &nbsp; **`do`** *instrução***while (***expressão***);**        

A *expressão* em uma instrução *do-while* é avaliada depois que o corpo do loop é executado. Portanto, o corpo do loop é sempre executado ao menos uma vez.

A *expressão* deve ter o tipo aritmético ou ponteiro. A execução procede da seguinte maneira:

1. O corpo da instrução é executado.

1. Em seguida, a *expressão* é avaliada. Se a *expressão* for falsa, a instrução *do-while* será finalizada e o controle será passado para a próxima instrução no programa. Se a *expressão* for verdadeira (diferente de zero), o processo será repetido, começando da etapa 1.

A instrução *do-while* também pode terminar quando uma **`break`** **`goto`** instrução, ou **`return`** for executada dentro do corpo da instrução.

Esse é um exemplo da instrução *do-while*:

```C
do
{
    y = f( x );
    x--;
} while ( x > 0 );
```

Nesta instrução *do-while*, as duas instruções `y = f( x );` e `x--;` são executadas, independentemente do valor inicial de `x`. Em seguida, `x > 0` é avaliado. Se `x` for maior que 0, o corpo da instrução é executado novamente e `x > 0` é reavaliado. O corpo da instrução é executado repetidamente, enquanto `x` permanece maior que 0. A execução da instrução *do-while* termina quando `x` se torna 0 ou negativo. O corpo do loop é executado ao menos uma vez.

## <a name="see-also"></a>Confira também

[Instrução do-while (C++)](../cpp/do-while-statement-cpp.md)
