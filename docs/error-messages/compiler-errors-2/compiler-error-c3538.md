---
title: Erro do compilador C3538
ms.date: 11/04/2016
f1_keywords:
- C3538
helpviewer_keywords:
- C3538
ms.assetid: ef3698a5-7356-4c62-b9af-5d3a4baed958
ms.openlocfilehash: 50c6d108c8f2bc42a624ce6376d66111df00478b
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50608846"
---
# <a name="compiler-error-c3538"></a>Erro do compilador C3538

em uma lista de declaradores 'auto' sempre deve ser deduzido para o mesmo tipo

Todas as variáveis declaradas em uma lista de declaração não resolver para o mesmo tipo.

### <a name="to-correct-this-error"></a>Para corrigir este erro

1. Certifique-se de que todos os `auto` declarações na lista de deduzam para o mesmo tipo.

## <a name="example"></a>Exemplo

As instruções a seguir produzem C3538. Cada instrução declara diversas variáveis, mas cada uso do `auto` palavra-chave não deduzir o mesmo tipo.

```
// C3538.cpp
// Compile with /Zc:auto
// C3538 expected
int main()
{
// Variable x1 is a pointer to char, but y1 is a double.
   auto * x1 = "a", y1 = 3.14;
// Variable c is a char and c1 is char*, but c2, and c3 are pointers to pointers.
   auto c = 'a', *c1 = &c, * c2 = &c1, * c3 = &c2;
// Variable x2 is an int, but y2 is a double and z is a char.
   auto x2(1), y2(0.0), z = 'a';
// Variable a is a pointer to int, but b is a pointer to double.
   auto *a = new auto(1), *b = new auto(2.0);
   return 0;
}
```

## <a name="see-also"></a>Consulte também

[Palavra-chave auto](../../cpp/auto-keyword.md)