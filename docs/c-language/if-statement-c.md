---
title: Instrução if (C)
ms.date: 11/04/2016
f1_keywords:
- else
- if
helpviewer_keywords:
- if keyword [C]
- else clauses
- else keyword [C]
- if keyword [C], if statement syntax
- nested statements
ms.assetid: d7fc16a0-fdbc-4f39-b596-76e1ca4ad4a5
ms.openlocfilehash: b6df50d483a6e2958de3100a07c18b89b0c4f12f
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62233054"
---
# <a name="if-statement-c"></a>Instrução if (C)

A instrução **if** controla a ramificação condicional. O corpo de uma instrução **if** será executado se o valor de expressão for diferente de zero. A sintaxe da instrução **if** tem dois formatos.

## <a name="syntax"></a>Sintaxe

instrução *de seleção*: instrução **If (***expression***)***statement*      

*instrução* **If (***expression***)***Statement***else**          

Em ambos os formatos da instrução **if**, as expressões (que podem ter qualquer valor exceto uma estrutura) são avaliadas, inclusive todos os efeitos colaterais.

No primeiro formato da sintaxe, se a *expressão* for verdadeira (diferente de zero), a *instrução* será executada. Se a *expressão* for falsa, a *instrução* será ignorada. No segundo formato da sintaxe, que usa **else**, a segunda *instrução* é executada se a *expressão* for falsa. Com ambos os formatos, o controle passará da instrução **if** para a próxima instrução do programa, a menos que uma das instruções contenha **break**, **continue** ou `goto`.

Estes são exemplos da instrução **if**:

```
if ( i > 0 )
    y = x / i;
else
{
    x = i;
    y = f( x );
}
```

Neste exemplo, a instrução `y = x/i;` é executada se `i` for maior que 0. Se `i` for menor ou igual a 0, `i` é atribuído a `x` e `f( x )` é atribuído a `y`. Observe que a instrução que forma a cláusula **if** termina com um ponto e vírgula.

Ao aninhar as instruções **if** e cláusulas **else**, use chaves para agrupar as instruções e cláusulas em instruções compostas que esclareçam sua intenção. Se nenhuma chave estiver presente, o compilador resolve as ambiguidades associando cada **else** com o **if** sem **else** mais próximo.

```
if ( i > 0 )           /* Without braces */
    if ( j > i )
        x = j;
    else
        x = i;
```

Neste exemplo, a cláusula **else** está associada à instrução **if** interna. Se `i` for menor ou igual a 0, nenhum valor será atribuído a `x`.

```
if ( i > 0 )
{                      /* With braces */
    if ( j > i )
        x = j;
}
else
    x = i;
```

As chaves que cercam a instrução interna **if** neste exemplo formam a parte da cláusula **else** da instrução **if** externa. Se `i` for menor ou igual a 0, `i` é atribuído a `x`.

## <a name="see-also"></a>Confira também

[Instrução if-else (C++)](../cpp/if-else-statement-cpp.md)
