---
title: Aviso do compilador (nível 1) C4624
ms.date: 11/04/2016
f1_keywords:
- C4624
helpviewer_keywords:
- C4624
ms.assetid: 14f61769-d92e-482b-9515-debd87b30a66
ms.openlocfilehash: 8ef871f31d5d1d31e6d1d26d46b6f7f99c8fba86
ms.sourcegitcommit: 458dcc794e3841919c01a3a5ff6b9a3767f8861b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/13/2019
ms.locfileid: "74051446"
---
# <a name="compiler-warning-level-1-c4624"></a>Aviso do compilador (nível 1) C4624

' classe derivada ': o destruidor foi implicitamente definido como excluído porque um destruidor de classe base é inacessível ou excluído

Um destruidor não estava acessível ou excluído em uma classe base e, portanto, não foi gerado para uma classe derivada. Qualquer tentativa de criar um objeto desse tipo na pilha causará um erro do compilador.

O exemplo a seguir gera C4624 e mostra como corrigi-lo:

```cpp
// C4624.cpp
// compile with: /W1 /c
class B {
// Uncomment the following line to fix.
// public:
   ~B();
};

class D : public B {};   // C4624 B's destructor not public
```