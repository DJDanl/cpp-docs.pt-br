---
title: Compilador aviso (nível 4) C4714
ms.date: 11/04/2016
f1_keywords:
- C4714
helpviewer_keywords:
- C4714
ms.assetid: 22c7fd0c-899d-4e9b-95f3-725b2c49fb46
ms.openlocfilehash: ed94e5b716a697ec96d7fecac75433823c9a67e9
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50553849"
---
# <a name="compiler-warning-level-4-c4714"></a>Compilador aviso (nível 4) C4714

função 'function' marcada como forceinline não embutida

A função fornecida foi selecionada para expansão embutida, mas o compilador não executou o inlining.

Embora `__forceinline` é uma indicação mais forte para o compilador que `__inline`, inlining ainda é executada, a critério do compilador, mas nenhum heurística é usada para determinar os benefícios de inlining essa função.

Em alguns casos, o compilador não embutirá uma função específica por motivos de mecânicos. Por exemplo, o compilador não embutirá:

- Uma função se resultaria na combinação de SEH e C++ EH.

- Algumas funções de cópia construído objetos passados por valor quando EHs / - GX//EHa está ativado.

- Funções que retornam um objeto liberáveis por valor quando EHs / - GX//EHa está ativado.

- Funções com assembly embutido ao compilar sem - Og/Ox/O1/O2.

- Funções com uma lista de argumentos variável.

- Uma função com um **tente** instrução (tratamento de exceções do C++).

O exemplo a seguir gera C4714:

```
// C4714.cpp
// compile with: /Ob1 /GX /W4
__forceinline void func1()
{
   try
   {
   }
   catch (...)
   {
   }
}

void func2()
{
   func1();   // C4714
}

int main()
{
}
```