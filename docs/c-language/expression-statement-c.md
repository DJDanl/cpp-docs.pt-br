---
title: Instrução de expressão (C)
ms.date: 11/04/2016
helpviewer_keywords:
- statements, expression
- expression statements
ms.assetid: 1085982b-dc16-4c1e-9ddd-0cd85c8fe2e3
ms.openlocfilehash: 736ed4fbbd9f87c675c0bb9566c6c31287e77917
ms.sourcegitcommit: f4be868c0d1d78e550fba105d4d3c993743a1f4b
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/12/2019
ms.locfileid: "56148784"
---
# <a name="expression-statement-c"></a>Instrução de expressão (C)

Quando uma instrução de expressão é executada, ela é avaliada de acordo com as regras descritas em [Expressões e atribuições](../c-language/expressions-and-assignments.md).

## <a name="syntax"></a>Sintaxe

*expression-statement*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*expression*<sub>opt</sub> **;**

Todos os efeitos colaterais de avaliação da expressão são concluídos antes de a próxima instrução ser executada. Uma instrução expression vazia é chamada de instrução null. Consulte [A instrução null](../c-language/null-statement-c.md) para obter mais informações.

Estes exemplos demonstram instruções expression.

```C
x = ( y + 3 );            /* x is assigned the value of y + 3  */
x++;                      /* x is incremented                  */
x = y = 0;                /* Both x and y are initialized to 0 */
proc( arg1, arg2 );       /* Function call returning void      */
y = z = ( f( x ) + 3 );   /* A function-call expression        */
```

Na última instrução, a expressão de chamada de função, o valor da expressão, que inclui os valores retornados pela função, é aumentada em 3 e atribuída às duas variáveis `y` e `z`.

## <a name="see-also"></a>Consulte também

[Instruções](../c-language/statements-c.md)
