---
title: Erro do compilador C3490
ms.date: 11/04/2016
f1_keywords:
- C3490
helpviewer_keywords:
- C3490
ms.assetid: 7638559a-fd06-4527-a9c1-0c8ae68b3123
ms.openlocfilehash: ea7341b9c587a764c7366fa7b7c89e4fc67bc7d8
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87230851"
---
# <a name="compiler-error-c3490"></a>Erro do compilador C3490

' var ' não pode ser modificado porque está sendo acessado por meio de um objeto const

Uma expressão lambda que é declarada em um **`const`** método não pode modificar dados de membros não mutáveis.

### <a name="to-correct-this-error"></a>Para corrigir este erro

- Remova o **`const`** modificador da declaração do método.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3490 porque ele modifica a variável de membro `_i` em um **`const`** método:

```cpp
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

O exemplo a seguir resolve C3490 removendo o **`const`** modificador da declaração do método:

```cpp
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

## <a name="see-also"></a>Confira também

[Expressões lambda](../../cpp/lambda-expressions-in-cpp.md)
