---
title: Aviso do compilador (nível 3) C4101
ms.date: 11/04/2016
f1_keywords:
- C4101
helpviewer_keywords:
- C4101
ms.assetid: d98563cd-9dce-4aae-8f12-bd552a4ea677
ms.openlocfilehash: f9d3875fdc17def1e7d3bcb72149c5faf90f656a
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87220048"
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

No entanto, esse aviso também ocorrerá ao chamar uma **`static`** função de membro por meio de uma instância da classe:

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

Nessa situação, o compilador usa informações sobre o `si` para acessar a **`static`** função, mas a instância da classe não é necessária para chamar a **`static`** função; portanto, o aviso. Para resolver esse aviso, você pode:

- Adicione um construtor, no qual o compilador usaria a instância do `si` na chamada para `func` .

- Remova a **`static`** palavra-chave da definição de `func` .

- Chame a **`static`** função explicitamente: `int y = S::func();` .
