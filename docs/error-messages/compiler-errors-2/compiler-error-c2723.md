---
title: Erro do compilador C2723
ms.date: 11/04/2016
f1_keywords:
- C2723
helpviewer_keywords:
- C2723
ms.assetid: 86925601-2297-4cfd-94e2-2caf27c474c4
ms.openlocfilehash: f9b169f856dba7a76e5f67e1980c4ca47ba912de
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74737446"
---
# <a name="compiler-error-c2723"></a>Erro do compilador C2723

especificador ' function ': ' especificador ' inválido na definição de função

O especificador não pode aparecer com uma definição de função fora de uma declaração de classe. O especificador de `virtual` pode ser especificado somente em uma declaração de função de membro dentro de uma declaração de classe.

O exemplo a seguir gera C2723 e mostra como corrigi-lo:

```cpp
// C2723.cpp
struct X {
   virtual void f();
   virtual void g();
};

virtual void X::f() {}   // C2723

// try the following line instead
void X::g() {}
```
