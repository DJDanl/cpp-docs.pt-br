---
title: Aviso do compilador (nível 4) C4221
ms.date: 11/04/2016
f1_keywords:
- C4221
helpviewer_keywords:
- C4221
ms.assetid: 8532bd68-54dc-4526-8597-f61dcb0a0129
ms.openlocfilehash: fa87c240472df2926753781f0f14cbd69752de00
ms.sourcegitcommit: 3ee06ec53153cf21910fc8cfef78a4f25f9633f3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/26/2019
ms.locfileid: "74541933"
---
# <a name="compiler-warning-level-4-c4221"></a>Aviso do compilador (nível 4) C4221

extensão não padrão usada: ' identifier ': não pode ser inicializada usando endereço de variável automática

Com as extensões padrão da Microsoft (/Ze), você pode inicializar um tipo de agregação (**matriz**, `struct`ou **União**) com o endereço de uma variável local (automática).

## <a name="example"></a>Exemplo

```c
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

Essas inicializações são inválidas sob compatibilidade com ANSI ([/za](../../build/reference/za-ze-disable-language-extensions.md)).