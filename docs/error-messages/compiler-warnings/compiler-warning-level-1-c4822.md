---
title: Aviso do compilador (nível 1) C4822
ms.date: 11/04/2016
f1_keywords:
- C4822
helpviewer_keywords:
- C4822
ms.assetid: 0f231a30-2eb0-4722-aaa0-e2d19d3e7eea
ms.openlocfilehash: 59c42227c7e8be9bd31c37776d9724d23db61837
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80174863"
---
# <a name="compiler-warning-level-1-c4822"></a>Aviso do compilador (nível 1) C4822

' member ': a função de membro de classe local não tem um corpo

Uma função de membro de classe local foi declarada, mas não está definida na classe. Para usar uma função membro de classe local, você deve defini-la na classe. Você não pode declará-lo na classe e defini-lo fora da classe.

Qualquer definição fora de classe para uma função membro de classe local será um erro.

O exemplo a seguir gera C4822:

```cpp
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
