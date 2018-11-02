---
title: Erro do compilador C2801
ms.date: 11/04/2016
f1_keywords:
- C2801
helpviewer_keywords:
- C2801
ms.assetid: 35dfc7ea-9e37-4e30-baa1-944dc61302f5
ms.openlocfilehash: 44f7988f9fedb882972b2823f2fe70d9512d4e87
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50484780"
---
# <a name="compiler-error-c2801"></a>Erro do compilador C2801

'operador operator' deve ser um membro não estático

Os operadores a seguir podem ser sobrecarregados apenas como os membros não estáticos:

- Atribuição `=`

- Acesso de membro de classe `->`

- Subscripting `[]`

- Chamada de função `()`

Possíveis causas de C2801:

- Operador sobrecarregado não é uma classe, estrutura ou membro de união.

- Operador sobrecarregado é declarado `static`.

- O exemplo a seguir gera C2801:

```
// C2801.cpp
// compile with: /c
operator[]();   // C2801 not a member
class A {
   static operator->();   // C2801 static
   operator()();   // OK
};
```