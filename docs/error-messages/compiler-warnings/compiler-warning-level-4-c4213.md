---
title: Compilador aviso (nível 4) C4213
ms.date: 11/04/2016
f1_keywords:
- C4213
helpviewer_keywords:
- C4213
ms.assetid: 59fc3f61-ebd2-499e-99d7-f57bec11eda1
ms.openlocfilehash: 8a3697b3bf63ac2a7a1e4e4bd0bf3a626c6bd631
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50566121"
---
# <a name="compiler-warning-level-4-c4213"></a>Compilador aviso (nível 4) C4213

extensão não padrão usada: conversão em l-value

Com as extensões da Microsoft padrão (/Ze), você pode usar conversões no lado esquerdo de uma instrução de atribuição.

## <a name="example"></a>Exemplo

```
// C4213.c
// compile with: /W4
void *a;
void f()
{
   int   i[3];
   a = &i;
   *(( int * )a )++ = 3;  // C4213
}

int main()
{
}
```

Tal conversão é inválido para a compatibilidade com ANSI ([/Za](../../build/reference/za-ze-disable-language-extensions.md)).