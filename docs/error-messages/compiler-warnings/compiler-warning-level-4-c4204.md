---
title: Aviso do compilador (nível 4) C4204
ms.date: 11/04/2016
f1_keywords:
- C4204
helpviewer_keywords:
- C4204
ms.assetid: 298d2880-6737-448e-b711-15572d540200
ms.openlocfilehash: 45ed4817dbf2c7ecd63cd0c669d6e1cf768184bd
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80174044"
---
# <a name="compiler-warning-level-4-c4204"></a>Aviso do compilador (nível 4) C4204

extensão não padrão usada: inicializador agregado não constante

Com o Microsoft Extensions (/Ze), você pode inicializar tipos de agregação (matrizes, estruturas, uniões e classes) com valores que não são constantes.

## <a name="example"></a>Exemplo

```c
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

Essas inicializações são inválidas sob compatibilidade com ANSI ([/za](../../build/reference/za-ze-disable-language-extensions.md)).
