---
title: Erro do compilador C2577
ms.date: 11/04/2016
f1_keywords:
- C2577
helpviewer_keywords:
- C2577
ms.assetid: fc79ef83-8362-40a2-9257-8037c3195ce4
ms.openlocfilehash: 4406aa90b26bc517308132ae9cccd003d44a9aad
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50530540"
---
# <a name="compiler-error-c2577"></a>Erro do compilador C2577

'member': destruidor/finalizador não pode ter um tipo de retorno

Um destruidor ou finalizador não pode retornar um valor de `void` ou qualquer outro tipo. Remover o `return` instrução da definição de destruidor.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2577.

```
// C2577.cpp
// compile with: /c
class A {
public:
   A() {}
   ~A(){
      return 0;   // C2577
   }
};
```