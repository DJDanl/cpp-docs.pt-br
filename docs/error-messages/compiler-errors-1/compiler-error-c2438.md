---
title: Erro do compilador C2438
ms.date: 11/04/2016
f1_keywords:
- C2438
helpviewer_keywords:
- C2438
ms.assetid: 3a0ab3ba-d0e4-4d8f-971d-e503397cc827
ms.openlocfilehash: b2861090b5f7629c7f0cd94ea38a99e888909258
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50630497"
---
# <a name="compiler-error-c2438"></a>Erro do compilador C2438

'identifier': não é possível inicializar dados de classe static via construtor

Um construtor é usado para inicializar um membro estático de uma classe. Membros estáticos devem ser inicializados em uma definição fora da declaração de classe.

O exemplo a seguir gera C2438:

```
// C2438.cpp
struct X {
   X(int i) : j(i) {}   // C2438
   static int j;
};

int X::j;

int main() {
   X::j = 1;
}
```