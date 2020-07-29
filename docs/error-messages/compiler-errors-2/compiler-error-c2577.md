---
title: Erro do compilador C2577
ms.date: 11/04/2016
f1_keywords:
- C2577
helpviewer_keywords:
- C2577
ms.assetid: fc79ef83-8362-40a2-9257-8037c3195ce4
ms.openlocfilehash: 0a7c711fa399c1bf31bc9de61f0b77ad19172a73
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87206907"
---
# <a name="compiler-error-c2577"></a>Erro do compilador C2577

' member ': o destruidor/finalizador não pode ter um tipo de retorno

Um destruidor ou finalizador não pode retornar um valor de **`void`** ou qualquer outro tipo. Remova a **`return`** instrução da definição do destruidor.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2577.

```cpp
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
