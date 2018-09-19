---
title: Compilador aviso (nível 1) C4624 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4624
dev_langs:
- C++
helpviewer_keywords:
- C4624
ms.assetid: 14f61769-d92e-482b-9515-debd87b30a66
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: dbc482fe693da366a3ba3ce7e53d5e8bbf23618c
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46118382"
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