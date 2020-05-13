---
title: Instrução continue (C)
ms.date: 11/04/2016
f1_keywords:
- continue
helpviewer_keywords:
- loop structures, continue keyword
- continue keyword [C]
ms.assetid: 969f293a-45fe-48a7-b4c6-287ba27a631d
ms.openlocfilehash: 983775e6fe9887afa5784358ede1de9583b3afba
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62312551"
---
# <a name="continue-statement-c"></a>Instrução continue (C)

A instrução `continue` transmite o controle para a próxima iteração da instrução `do`, `for` ou `while` delimitadora mais próxima em que aparece, ignorando qualquer instrução restante no corpo da instrução `do`, `for` ou `while`.

## <a name="syntax"></a>Sintaxe

*instrução de salto*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**continue ;**

A próxima iteração de uma instrução `do`, `for` ou `while` é determinada da seguinte maneira:

- Em uma instrução `do` ou `while`, a próxima iteração começa com a reavaliação da expressão da instrução `do` ou `while`.

- Uma instrução `continue` em uma instrução `for` causa a avaliação da expressão de loop da instrução `for`. Então, o compilador reavalia a expressão condicional e, dependendo do resultado, finaliza ou itera o corpo da instrução. Consulte [A instrução for](../c-language/for-statement-c.md) para obter mais informações sobre a instrução `for` e seus não terminais.

Esse é um exemplo da instrução `continue`:

```
while ( i-- > 0 )
{
    x = f( i );
    if ( x == 1 )
        continue;
    y += x * x;
}
```

Nesse exemplo, o corpo da instrução é executado enquanto `i` é maior que 0. Primeiro, `f(i)` é atribuído a `x`; então, se `x` for igual a 1, a instrução `continue` será executada. O restante das instruções no corpo é ignorado, e a execução será retomada na parte superior do loop com a avaliação do teste de loop.

## <a name="see-also"></a>Confira também

[Instrução Continue](../cpp/continue-statement-cpp.md)
