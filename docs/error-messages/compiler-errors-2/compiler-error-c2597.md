---
title: Erro do compilador C2597
ms.date: 11/04/2016
f1_keywords:
- C2597
helpviewer_keywords:
- C2597
ms.assetid: 2e48127d-e3ff-4a40-8156-2863e45b1a38
ms.openlocfilehash: b7bdd10ebd70eb61746690958532854dd98c6429
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50641188"
---
# <a name="compiler-error-c2597"></a>Erro do compilador C2597

referência inválida para membro não estática 'identifier'

Possíveis causas:

1. Um membro não estático é especificado em uma função de membro estático. Para acessar o membro não estático, você deve passar em ou crie uma instância local da classe e usar um operador de acesso de membro (`.` ou `->`).

1. O identificador especificado não é um membro de classe, estrutura ou união. Verifica a ortografia de identificador.

1. Um operador de acesso de membro se refere a uma função não membro.

1. O exemplo a seguir gera C2597 e mostra como corrigi-lo:

```
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