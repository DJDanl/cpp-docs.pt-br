---
title: Instrução while (C)
ms.date: 11/04/2016
f1_keywords:
- while
helpviewer_keywords:
- while keyword [C]
- while keyword [C], syntax
ms.assetid: d0c970b8-12a9-4827-afb2-a051111834b7
ms.openlocfilehash: 8095dd8672218239dbcfa879e3df929643e93d90
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87231397"
---
# <a name="while-statement-c"></a>Instrução while (C)

A **`while`** instrução permite repetir uma instrução até que uma expressão especificada se torne falsa.

## <a name="syntax"></a>Sintaxe

*instrução Iteration*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*instrução* **while (***expressão***)**      

A *expressão* deve ter o tipo aritmético ou ponteiro. A execução procede da seguinte maneira:

1. A *expressão* é avaliada.

1. Se a *expressão* for inicialmente falsa, o corpo da **`while`** instrução nunca será executado e o controle passará da **`while`** instrução para a próxima instrução no programa.

   Se a *expressão* for verdadeira (diferente de zero), o corpo da instrução será executado e o processo será repetido no início da etapa 1.

A **`while`** instrução também pode terminar quando um **`break`** , **`goto`** ou **`return`** dentro do corpo da instrução for executado. Use a **`continue`** instrução para encerrar uma iteração sem sair do **`while`** loop. A **`continue`** instrução passa o controle para a próxima iteração da **`while`** instrução.

Este é um exemplo da **`while`** instrução:

```C
while ( i >= 0 )
{
    string1[i] = string2[i];
    i--;
}
```

Esse exemplo copia caracteres de `string2` para `string1`. Se `i` for maior ou igual a 0, `string2[i]` é atribuído a `string1[i]` e `i` é diminuído. Quando `i` atinge ou cai abaixo de 0, a execução da **`while`** instrução é encerrada.

## <a name="see-also"></a>Confira também

[Instrução while (C++)](../cpp/while-statement-cpp.md)
