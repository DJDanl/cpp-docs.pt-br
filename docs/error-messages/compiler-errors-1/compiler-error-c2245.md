---
title: Erro do compilador C2245
ms.date: 11/04/2016
f1_keywords:
- C2245
helpviewer_keywords:
- C2245
ms.assetid: 08aaeadf-10ec-485a-b2a6-6e775289082b
ms.openlocfilehash: 53288d86a59fe2cd31ddac4af7766360544c65c3
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50603938"
---
# <a name="compiler-error-c2245"></a>Erro do compilador C2245

a função de membro inexistente 'function' especificada como friend (assinatura de função de membro não corresponde a nenhuma sobrecarga)

Uma função especificada como amiga não foi encontrada pelo compilador.

O exemplo a seguir gera C2245:

```
// C2245.cpp
// compile with: /c
class B {
   void f(int i);
};

class A {
   int m_i;
   friend void B::f(char);   // C2245
   // try the following line instead
   // friend void B::f(int);
};

void B::f(int i) {
   A a;
   a.m_i = 0;
}
```