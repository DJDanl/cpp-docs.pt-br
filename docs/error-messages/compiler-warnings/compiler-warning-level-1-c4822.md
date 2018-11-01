---
title: Compilador aviso (nível 1) C4822
ms.date: 11/04/2016
f1_keywords:
- C4822
helpviewer_keywords:
- C4822
ms.assetid: 0f231a30-2eb0-4722-aaa0-e2d19d3e7eea
ms.openlocfilehash: 02e7ba11f7bda134bcc98ce2c494a3ef367c0d6f
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50591237"
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