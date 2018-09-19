---
title: Compilador aviso (nível 3) C4101 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4101
dev_langs:
- C++
helpviewer_keywords:
- C4101
ms.assetid: d98563cd-9dce-4aae-8f12-bd552a4ea677
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 1549a327329d438cb30bd6908e07419eb1b6bc1a
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46060831"
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