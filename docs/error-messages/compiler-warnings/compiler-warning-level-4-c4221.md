---
title: Compilador aviso (nível 4) C4221
ms.date: 11/04/2016
f1_keywords:
- C4221
helpviewer_keywords:
- C4221
ms.assetid: 8532bd68-54dc-4526-8597-f61dcb0a0129
ms.openlocfilehash: f552a5d76d1a778cdf72cbe079138f609350ffb1
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50511235"
---
# <a name="compiler-warning-level-4-c4221"></a>Compilador aviso (nível 4) C4221

extensão não padrão usada: 'identifier': não pode ser inicializado usando endereço da variável automática

Com as extensões da Microsoft padrão (/Ze), você pode inicializar um tipo de agregação (**array**, `struct`, ou **união**) com o endereço de uma variável de local (automático).

## <a name="example"></a>Exemplo

```
// C4221.c
// compile with: /W4
struct S
{
   int *i;
};

void func()
{
   int j;
   struct S s1 = { &j };   // C4221
}

int main()
{
}
```

Essas inicializações são inválidas para a compatibilidade com ANSI ([/Za](../../build/reference/za-ze-disable-language-extensions.md)).