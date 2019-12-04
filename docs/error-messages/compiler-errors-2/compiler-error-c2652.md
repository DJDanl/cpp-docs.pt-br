---
title: Erro do compilador C2652
ms.date: 11/04/2016
f1_keywords:
- C2652
helpviewer_keywords:
- C2652
ms.assetid: 6e3d1a90-a989-4088-8afd-dc82f6a2d66f
ms.openlocfilehash: cedee3f1e3289aaf0ea38d75b6c812b61f891435
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74756117"
---
# <a name="compiler-error-c2652"></a>Erro do compilador C2652

' identifier ': Construtor de cópia inválido: o primeiro parâmetro não deve ser um ' identifier '

O primeiro parâmetro no construtor de cópia tem o mesmo tipo que a classe, estrutura ou União para o qual ele está definido. O primeiro parâmetro pode ser uma referência ao tipo, mas não ao próprio tipo.

O exemplo a seguir gera C2651:

```cpp
// C2652.cpp
// compile with: /c
class A {
   A( A );   // C2652 takes an A
};
class B {
   B( B& );   // OK, reference to B
};
```
