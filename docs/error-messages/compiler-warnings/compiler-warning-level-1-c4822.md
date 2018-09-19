---
title: Compilador aviso (nível 1) C4822 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4822
dev_langs:
- C++
helpviewer_keywords:
- C4822
ms.assetid: 0f231a30-2eb0-4722-aaa0-e2d19d3e7eea
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 33748a39eae4b6f2a84cadb818570f9a311b1fe1
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46078316"
---
# <a name="compiler-warning-level-1-c4822"></a>Compilador aviso (nível 1) C4822

'member': função de membro de classe local não tem um corpo

Uma função de membro de classe local foi declarada mas não definida na classe. Para usar uma função de membro de classe local, você deve defini-lo na classe. Você não pode declará-la na classe e defini-lo fora da classe.

Qualquer definição fora da classe para uma função de membro de classe local será um erro.

O exemplo a seguir gera C4822:

```
// C4822.cpp
// compile with: /W1
int main() {
   struct C {
      void func1(int);   // C4822
      // try the following line instead
      // void func1(int){}
  };
}
```