---
title: Erro do compilador C3490
ms.date: 11/04/2016
f1_keywords:
- C3490
helpviewer_keywords:
- C3490
ms.assetid: 7638559a-fd06-4527-a9c1-0c8ae68b3123
ms.openlocfilehash: 940eae39222548ec74bda8ccb38e669748ffa74f
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74738395"
---
# <a name="compiler-error-c3490"></a>Erro do compilador C3490

' var ' não pode ser modificado porque está sendo acessado por meio de um objeto const

Uma expressão lambda que é declarada em um método `const` não pode modificar dados de membros não mutáveis.

### <a name="to-correct-this-error"></a>Para corrigir esse erro

- Remova o modificador `const` da declaração do método.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3490 porque ele modifica a variável de membro `_i` em um método `const`:

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

O exemplo a seguir resolve C3490 removendo o modificador `const` da declaração do método:

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

## <a name="see-also"></a>Consulte também

[Expressões Lambda](../../cpp/lambda-expressions-in-cpp.md)
