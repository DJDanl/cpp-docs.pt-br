---
title: Compilador aviso (nível 1) C4584
ms.date: 11/04/2016
f1_keywords:
- C4584
helpviewer_keywords:
- C4584
ms.assetid: ad86582f-cb8c-4d21-8c4c-a6c800059e25
ms.openlocfilehash: 3c60575e766ea3490a40711fe26c3e402c41fbdd
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50552720"
---
# <a name="compiler-warning-level-1-c4584"></a>Compilador aviso (nível 1) C4584

'class1': classe base 'class2' já é uma classe base de 'class3'

A classe definida por você herda de duas classes, uma que herda de outra. Por exemplo:

```
// C4584.cpp
// compile with: /W1 /LD
class A {
};

class B : public A {
};

class C : public A, public B { // C4584
};
```

Nesse caso, um aviso seria emitido na classe C porque ele herda da classe e de classe B, que também herda a classe A. Esse aviso serve como um lembrete de que você deve qualificar totalmente o uso de membros a partir dessas classes base ou um erro do compilador será gerado devido à ambiguidade sobre qual membro de classe se referem.