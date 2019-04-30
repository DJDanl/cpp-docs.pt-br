---
title: Compilador aviso (nível 4) C4205
ms.date: 11/04/2016
f1_keywords:
- C4205
helpviewer_keywords:
- C4205
ms.assetid: 39b5108c-7230-41b4-b2fe-2293eb6aae28
ms.openlocfilehash: 1b165d2bdb2fb50df89fdd77c734c054a40b6e95
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62401222"
---
# <a name="compiler-warning-level-4-c4205"></a>Compilador aviso (nível 4) C4205

extensão não padrão usada: declaração de função estática no escopo de função

Com extensões da Microsoft (/Ze) **estático** funções podem ser declaradas dentro de outra função. A função tem escopo global.

## <a name="example"></a>Exemplo

```
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

Essas inicializações são inválidas para a compatibilidade com ANSI ([/Za](../../build/reference/za-ze-disable-language-extensions.md)).