---
title: Erro do compilador C3490 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3490
dev_langs:
- C++
helpviewer_keywords:
- C3490
ms.assetid: 7638559a-fd06-4527-a9c1-0c8ae68b3123
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 503302d323f45b5f7c3971803fef0547ff28e0c8
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46077692"
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