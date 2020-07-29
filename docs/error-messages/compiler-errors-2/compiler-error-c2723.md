---
title: Erro do compilador C2723
ms.date: 11/04/2016
f1_keywords:
- C2723
helpviewer_keywords:
- C2723
ms.assetid: 86925601-2297-4cfd-94e2-2caf27c474c4
ms.openlocfilehash: f723fcc0a3d9626f01f2059a3d9363801221bca0
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87216044"
---
# <a name="compiler-error-c2723"></a>Erro do compilador C2723

especificador ' function ': ' especificador ' inválido na definição de função

O especificador não pode aparecer com uma definição de função fora de uma declaração de classe. O **`virtual`** especificador pode ser especificado somente em uma declaração de função de membro dentro de uma declaração de classe.

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
