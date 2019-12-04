---
title: Erro do compilador C2877
ms.date: 11/04/2016
f1_keywords:
- C2877
helpviewer_keywords:
- C2877
ms.assetid: 0b54837e-fcae-4d90-9658-623250435e24
ms.openlocfilehash: b28a301b757e41e6ba238f361520bc89e0744eba
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74736307"
---
# <a name="compiler-error-c2877"></a>Erro do compilador C2877

' Symbol ' não é acessível de ' class '

Todos os membros derivados de uma classe base devem estar acessíveis na classe derivada.

O exemplo a seguir gera C2877:

```cpp
// C2877.cpp
// compile with: /c
class A {
private:
   int a;
};

class B : public A {
   using A::a;   // C2877
};
```
