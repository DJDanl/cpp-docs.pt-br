---
title: Erro do compilador C2243
ms.date: 11/04/2016
f1_keywords:
- C2243
helpviewer_keywords:
- C2243
ms.assetid: b90065bb-d251-4ba9-8b4c-280ee13fa9c0
ms.openlocfilehash: f5a62b1c12b94735d0383697bf7a92d12d64b21f
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74757794"
---
# <a name="compiler-error-c2243"></a>Erro do compilador C2243

a conversão de ' tipo de conversão ' de ' type1 ' para ' type2 ' existe, mas está inacessível

A proteção de acesso (`protected` ou `private`) impediu a conversão de um ponteiro para uma classe derivada em um ponteiro para a classe base.

O exemplo a seguir gera C2243:

```cpp
// C2243.cpp
// compile with: /c
class B {};
class D : private B {};
class E : public B {};

D d;
B *p = &d;   // C2243

E e;
B *p2 = &e;
```

As classes base com acesso `protected` ou `private` não são acessíveis aos clientes da classe derivada. Esses níveis de controle de acesso são usados para indicar que a classe base é um detalhe de implementação que deve ser invisível para os clientes. Use derivação pública se você quiser que os clientes da classe derivada tenham acesso à conversão implícita de um ponteiro de classe derivada para um ponteiro para a classe base.
