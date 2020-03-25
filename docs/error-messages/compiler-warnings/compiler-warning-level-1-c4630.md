---
title: Aviso do compilador (nível 1) C4630
ms.date: 11/04/2016
f1_keywords:
- C4630
helpviewer_keywords:
- C4630
ms.assetid: d8926376-7acc-4fc7-8438-6f0de3468870
ms.openlocfilehash: 414388fc1b9c6a7425d45e2ba92546960cadf404
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80199609"
---
# <a name="compiler-warning-level-1-c4630"></a>Aviso do compilador (nível 1) C4630

' Symbol ': especificador de classe de armazenamento ' extern ' inválido na definição de membro

Um membro de dados ou uma função de membro é definida como `extern`. Os membros não podem ser externos, embora objetos inteiros possam. O compilador ignora a palavra-chave `extern`. O exemplo a seguir gera C4630:

```cpp
// C4630.cpp
// compile with: /W1 /LD
class A {
   void func();
};

extern void A::func() {   // C4630, remove 'extern' to resolve
}
```
