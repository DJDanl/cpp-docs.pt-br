---
title: Erro do compilador C2032
ms.date: 11/04/2016
f1_keywords:
- C2032
helpviewer_keywords:
- C2032
ms.assetid: 625d7c83-70b6-42c2-a558-81fbc0026324
ms.openlocfilehash: 5743aba880f23d7706940936fc4a3a1973a84ca1
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50558243"
---
# <a name="compiler-error-c2032"></a>Erro do compilador C2032

'identifier': função não pode ser membro de struct/union 'structorunion'

A estrutura ou união tem uma função de membro, que é permitida em C++, mas não em C. Para resolver o erro, compilar como um programa C++ ou remova a função de membro.

O exemplo a seguir gera C2032:

```
// C2032.c
struct z {
   int i;
   void func();   // C2032
};
```

Solução possível:

```
// C2032b.c
// compile with: /c
struct z {
   int i;
};
```