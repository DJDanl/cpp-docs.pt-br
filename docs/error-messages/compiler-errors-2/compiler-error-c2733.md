---
title: Erro do compilador C2733
ms.date: 11/04/2016
f1_keywords:
- C2733
helpviewer_keywords:
- C2733
ms.assetid: 67f83561-c633-407c-a2ee-f9fd16e165bf
ms.openlocfilehash: 3ef669a49f4a3ec5a1af1a15a79f2511fa2699dd
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74755779"
---
# <a name="compiler-error-c2733"></a>Erro do compilador C2733

o segundo vínculo C da função sobrecarregada ' function ' não é permitido

Mais de uma função sobrecarregada é declarada com vínculo C. Ao usar vínculo C, apenas uma forma de uma função especificada pode ser externa. Como as funções sobrecarregadas têm o mesmo nome não decorado, elas não podem ser usadas com programas C.

O exemplo a seguir gera C2733:

```cpp
// C2733.cpp
extern "C" {
   void F1(int);
}

extern "C" {
   void F1();   // C2733
   // try the following line instead
   // void F2();
}
```
