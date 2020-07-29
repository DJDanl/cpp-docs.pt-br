---
title: Instrução continue (C)
ms.date: 11/04/2016
f1_keywords:
- continue
helpviewer_keywords:
- loop structures, continue keyword
- continue keyword [C]
ms.assetid: 969f293a-45fe-48a7-b4c6-287ba27a631d
ms.openlocfilehash: 3cf5d1c25b8edc70bd686ca26ad98b15b970383c
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87218904"
---
# <a name="continue-statement-c"></a>Instrução continue (C)

A **`continue`** instrução passa o controle para a próxima iteração da instrução,, ou delimitadora mais próxima, **`do`** **`for`** **`while`** na qual ele aparece, ignorando as instruções restantes no **`do`** **`for`** corpo da instrução, ou **`while`** .

## <a name="syntax"></a>Sintaxe

*instrução de salto*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**continue ;**

A próxima iteração de **`do`** uma **`for`** instrução, ou **`while`** é determinada da seguinte maneira:

- Dentro de uma **`do`** **`while`** instrução ou, a próxima iteração começa reavaliando a expressão da **`do`** instrução or **`while`** .

- Uma **`continue`** instrução em uma **`for`** instrução faz com que a expressão de loop da **`for`** instrução seja avaliada. Então, o compilador reavalia a expressão condicional e, dependendo do resultado, finaliza ou itera o corpo da instrução. Consulte [a instrução for](../c-language/for-statement-c.md) para obter mais informações sobre a **`for`** instrução e seus não terminais.

Este é um exemplo da **`continue`** instrução:

```
while ( i-- > 0 )
{
    x = f( i );
    if ( x == 1 )
        continue;
    y += x * x;
}
```

Nesse exemplo, o corpo da instrução é executado enquanto `i` é maior que 0. `f(i)`O primeiro é atribuído a `x` ; em seguida, se `x` for igual a 1, a **`continue`** instrução será executada. O restante das instruções no corpo é ignorado, e a execução será retomada na parte superior do loop com a avaliação do teste de loop.

## <a name="see-also"></a>Confira também

[Instrução Continue](../cpp/continue-statement-cpp.md)
