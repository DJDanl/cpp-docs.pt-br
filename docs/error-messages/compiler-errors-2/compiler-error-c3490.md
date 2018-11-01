---
title: Erro do compilador C3490
ms.date: 11/04/2016
f1_keywords:
- C3490
helpviewer_keywords:
- C3490
ms.assetid: 7638559a-fd06-4527-a9c1-0c8ae68b3123
ms.openlocfilehash: 55580533d6a1a6b80f79b017ba78a08fb44df744
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50478150"
---
# <a name="compiler-error-c3490"></a>Erro do compilador C3490

'var' não pode ser modificado porque ele está sendo acessado por meio de um objeto const

Uma expressão lambda que é declarada em um `const` método não é possível modificar os dados de membro não mutável.

### <a name="to-correct-this-error"></a>Para corrigir este erro

- Remover o `const` modificador de sua declaração de método.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3490 porque ele modifica a variável de membro `_i` em um `const` método:

```
// C3490a.cpp
// compile with: /c

class C
{
   void f() const
   {
      auto x = [=]() { _i = 20; }; // C3490
   }

   int _i;
};
```

## <a name="example"></a>Exemplo

O exemplo a seguir resolve C3490, removendo o `const` modificador da declaração de método:

```
// C3490b.cpp
// compile with: /c

class C
{
   void f()
   {
      auto x = [=]() { _i = 20; };
   }

   int _i;
};
```

## <a name="see-also"></a>Consulte também

[Expressões Lambda](../../cpp/lambda-expressions-in-cpp.md)