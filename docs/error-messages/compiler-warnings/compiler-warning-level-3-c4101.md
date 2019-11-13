---
title: Aviso do compilador (nível 3) C4101
ms.date: 11/04/2016
f1_keywords:
- C4101
helpviewer_keywords:
- C4101
ms.assetid: d98563cd-9dce-4aae-8f12-bd552a4ea677
ms.openlocfilehash: 5effdbb4c7e83999655641a248c389c7c4d260d0
ms.sourcegitcommit: 458dcc794e3841919c01a3a5ff6b9a3767f8861b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/13/2019
ms.locfileid: "74051898"
---
# <a name="compiler-warning-level-3-c4101"></a>Aviso do compilador (nível 3) C4101

' identifier ': variável local não referenciada

A variável local nunca é usada. Esse aviso ocorrerá na situação óbvia:

```cpp
// C4101a.cpp
// compile with: /W3
int main() {
int i;   // C4101
}
```

No entanto, esse aviso também ocorrerá ao chamar uma função de membro **estático** por meio de uma instância da classe:

```cpp
// C4101b.cpp
// compile with:  /W3
struct S {
   static int func()
   {
      return 1;
   }
};

int main() {
   S si;   // C4101, si is never used
   int y = si.func();
   return y;
}
```

Nessa situação, o compilador usa informações sobre `si` acessar a função **estática** , mas a instância da classe não é necessária para chamar a função **estática** ; Portanto, o aviso. Para resolver esse aviso, você pode:

- Adicione um construtor, no qual o compilador usaria a instância de `si` na chamada para `func`.

- Remova a palavra-chave **static** da definição de `func`.

- Chame a função **estática** explicitamente: `int y = S::func();`.