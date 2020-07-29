---
title: Aviso do compilador (nível 4) C4205
ms.date: 11/04/2016
f1_keywords:
- C4205
helpviewer_keywords:
- C4205
ms.assetid: 39b5108c-7230-41b4-b2fe-2293eb6aae28
ms.openlocfilehash: 6e85d4b6382f8d3811585bcf887c08694b86b71a
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87225261"
---
# <a name="compiler-warning-level-4-c4205"></a>Aviso do compilador (nível 4) C4205

extensão não padrão usada: declaração de função estática no escopo de função

Com o Microsoft Extensions (/Ze), as **`static`** funções podem ser declaradas dentro de outra função. A função recebe escopo global.

## <a name="example"></a>Exemplo

```c
// C4205.c
// compile with: /W4
void func1()
{
   static int func2();  // C4205
};

int main()
{
}
```

Essas inicializações são inválidas sob compatibilidade com ANSI ([/za](../../build/reference/za-ze-disable-language-extensions.md)).
