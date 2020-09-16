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
ms.openlocfilehash: 6fe92d3f2927cd6c5b3df16850e2925fc42055d0
ms.sourcegitcommit: c1fd917a8c06c6504f66f66315ff352d0c046700
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/16/2020
ms.locfileid: "90684138"
---
# <a name="if-statement-c"></a>Instrução if (C)

A **`if`** instrução controla a ramificação condicional. O corpo de uma **`if`** instrução será executado se o valor da expressão for diferente de zero. A sintaxe da **`if`** instrução tem duas formas.

## <a name="syntax"></a>Sintaxe

instrução *de seleção*: instrução **If (***expression***)***statement*      

instrução de*instrução* **If (***expression***)** **`else`** *statement*          

Em ambas as formas da **`if`** instrução, as expressões, que podem ter qualquer valor, exceto uma estrutura, são avaliadas, incluindo todos os efeitos colaterais.

No primeiro formato da sintaxe, se a *expressão* for verdadeira (diferente de zero), a *instrução* será executada. Se a *expressão* for falsa, a *instrução* será ignorada. Na segunda forma de sintaxe, que usa **`else`** , a segunda *instrução* é executada se *expression* for false. Com ambos os formulários, o controle passa da **`if`** instrução para a próxima instrução no programa, a menos que uma das instruções contenha um **`break`** , **`continue`** ou **`goto`** .

Veja a seguir exemplos da **`if`** instrução:

```C
if ( i > 0 )
    y = x / i;
else
{
    x = i;
    y = f( x );
}
```

Neste exemplo, a instrução `y = x/i;` é executada se `i` for maior que 0. Se `i` for menor ou igual a 0, `i` é atribuído a `x` e `f( x )` é atribuído a `y`. Observe que a instrução que formam a **`if`** cláusula termina com um ponto e vírgula.

Ao aninhar **`if`** instruções e **`else`** cláusulas, use chaves para agrupar as instruções e cláusulas em instruções compostas que esclarecem sua intenção. Se nenhuma chave estiver presente, o compilador resolverá as ambiguidades associando cada **`else`** uma com o mais próximo **`if`** que não tem um **`else`** .

```C
if ( i > 0 )           /* Without braces */
    if ( j > i )
        x = j;
    else
        x = i;
```

A **`else`** cláusula é associada à instrução interna **`if`** neste exemplo. Se `i` for menor ou igual a 0, nenhum valor será atribuído a `x`.

```C
if ( i > 0 )
{                      /* With braces */
    if ( j > i )
        x = j;
}
else
    x = i;
```

As chaves que circundam a **`if`** instrução interna neste exemplo fazem a **`else`** parte da cláusula da **`if`** instrução externa. Se `i` for menor ou igual a 0, `i` é atribuído a `x`.

## <a name="see-also"></a>Confira também

[Instrução if-else (C++)](../cpp/if-else-statement-cpp.md)
