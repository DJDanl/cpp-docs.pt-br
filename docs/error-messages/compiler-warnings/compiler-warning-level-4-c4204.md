---
title: Compilador aviso (nível 4) C4204
ms.date: 11/04/2016
f1_keywords:
- C4204
helpviewer_keywords:
- C4204
ms.assetid: 298d2880-6737-448e-b711-15572d540200
ms.openlocfilehash: e16cb9fb59ee6ec24bb9b68dad1be9432d9eee3f
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62401235"
---
# <a name="compiler-warning-level-4-c4204"></a>Compilador aviso (nível 4) C4204

extensão não padrão usada: inicializador agregado não constante

Com extensões da Microsoft (/Ze), você pode inicializar os tipos de agregação (matrizes, estruturas, uniões e classes) com valores que não são constantes.

## <a name="example"></a>Exemplo

```
// C4204.c
// compile with: /W4
int func1()
{
   return 0;
}
struct S1
{
   int i;
};

int main()
{
   struct S1 s1 = { func1() };   // C4204
   return s1.i;
}
```

Essas inicializações são inválidas para a compatibilidade com ANSI ([/Za](../../build/reference/za-ze-disable-language-extensions.md)).