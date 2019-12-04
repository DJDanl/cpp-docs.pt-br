---
title: Erro do compilador C2597
ms.date: 11/04/2016
f1_keywords:
- C2597
helpviewer_keywords:
- C2597
ms.assetid: 2e48127d-e3ff-4a40-8156-2863e45b1a38
ms.openlocfilehash: 680268948f8642b02768bd4b3092666982e14eb7
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74759302"
---
# <a name="compiler-error-c2597"></a>Erro do compilador C2597

referência inválida para membro não estático ' identifier '

Possíveis causas:

1. Um membro não estático é especificado em uma função de membro estático. Para acessar o membro não estático, você deve passar ou criar uma instância local da classe e usar um operador de acesso para membro (`.` ou `->`).

1. O identificador especificado não é um membro de uma classe, estrutura ou União. Verifique a ortografia do identificador.

1. Um operador de acesso de membro refere-se a uma função não membro.

1. O exemplo a seguir gera C2597 e mostra como corrigi-lo:

```cpp
// C2597.cpp
// compile with: /c
struct s1 {
   static void func();
   static void func2(s1&);
   int i;
};

void s1::func() {
   i = 1;    // C2597 - static function can't access non-static data member
}

// OK - fix by passing an instance of s1
void s1::func2(s1& a) {
   a.i = 1;
}
```
