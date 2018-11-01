---
title: Compilador aviso (nível 3) C4101
ms.date: 11/04/2016
f1_keywords:
- C4101
helpviewer_keywords:
- C4101
ms.assetid: d98563cd-9dce-4aae-8f12-bd552a4ea677
ms.openlocfilehash: d1109a32e754a6055e5e1d90632ad85332d832f1
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50661117"
---
# <a name="compiler-warning-level-3-c4101"></a>Compilador aviso (nível 3) C4101

'identifier': variável local não referenciada

A variável local nunca é usada. Este aviso ocorrerá na situação óbvia:

```
// C4101a.cpp
// compile with: /W3
int main() {
int i;   // C4101
}
```

No entanto, esse aviso também ocorrerá ao chamar um **estático** função de membro por meio de uma instância da classe:

```
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

Nessa situação, o compilador usa informações sobre `si` para acessar o **estáticos** função, mas a instância da classe não é necessária para chamar o **estático** funcionar; portanto, o aviso. Para resolver este aviso, você pode:

- Adicione um construtor, em que o compilador seria usar a instância do `si` na chamada para `func`.

- Remover o **estáticos** palavra-chave da definição da `func`.

- Chame o **estáticos** função explicitamente: `int y = S::func();`.