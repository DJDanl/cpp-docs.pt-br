---
title: Erro do compilador C2723
ms.date: 11/04/2016
f1_keywords:
- C2723
helpviewer_keywords:
- C2723
ms.assetid: 86925601-2297-4cfd-94e2-2caf27c474c4
ms.openlocfilehash: bc07a99f12ed0e447427990969e54f7f3d3d3b7f
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50635377"
---
# <a name="compiler-error-c2723"></a>Erro do compilador C2723

'function': especificador de 'especificador' inválido em definição de função

O especificador não pode aparecer com uma definição de função fora de uma declaração de classe. O `virtual` especificador pode ser especificada somente em uma declaração de função de membro dentro de uma declaração de classe.

O exemplo a seguir gera C2723 e mostra como corrigi-lo:

```
// C2723.cpp
struct X {
   virtual void f();
   virtual void g();
};

virtual void X::f() {}   // C2723

// try the following line instead
void X::g() {}
```