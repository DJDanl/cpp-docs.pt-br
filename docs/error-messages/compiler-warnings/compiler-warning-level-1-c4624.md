---
title: Compilador aviso (nível 1) C4624
ms.date: 11/04/2016
f1_keywords:
- C4624
helpviewer_keywords:
- C4624
ms.assetid: 14f61769-d92e-482b-9515-debd87b30a66
ms.openlocfilehash: b1a7d715057f4c6d8ada104ad07f6ad0b9c52fb2
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62221385"
---
# <a name="compiler-warning-level-1-c4624"></a>Compilador aviso (nível 1) C4624

'derived class': destrutor foi implicitamente definido como excluído porque um destruidor de classe base está inacessível ou foi excluído

Um destruidor não estava acessível ou excluídas em uma classe base e, portanto, não foi gerado para uma classe derivada. Qualquer tentativa de criar um objeto desse tipo na pilha causará um erro do compilador.

O exemplo a seguir gera C4624 e mostra como corrigi-lo:

```
// C4624.cpp
// compile with: /W1 /c
class B {
// Uncomment the following line to fix.
// public:
   ~B();
};

class D : public B {};   // C4624 B's destructor not public
```