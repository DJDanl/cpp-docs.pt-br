---
title: Aviso do compilador (nível 1) C4584
ms.date: 11/04/2016
f1_keywords:
- C4584
helpviewer_keywords:
- C4584
ms.assetid: ad86582f-cb8c-4d21-8c4c-a6c800059e25
ms.openlocfilehash: fa736e8dbab775fcd6cdffc467aee1312004fa60
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80162147"
---
# <a name="compiler-warning-level-1-c4584"></a>Aviso do compilador (nível 1) C4584

' class1 ': classe base ' class2 ' já é uma classe base de ' class3 '

A classe que você definiu herda de duas classes, uma das quais herda da outra. Por exemplo:

```cpp
// C4584.cpp
// compile with: /W1 /LD
class A {
};

class B : public A {
};

class C : public A, public B { // C4584
};
```

Nesse caso, um aviso seria emitido na classe C porque ele é herdado da classe A e da classe B, que também é herdada da classe A. Esse aviso serve como um lembrete de que você deve qualificar totalmente o uso de membros dessas classes base ou um erro do compilador será gerado devido à ambiguidade sobre qual membro de classe você se refere.
