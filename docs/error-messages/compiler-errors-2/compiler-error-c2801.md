---
title: Erro do compilador C2801
ms.date: 11/04/2016
f1_keywords:
- C2801
helpviewer_keywords:
- C2801
ms.assetid: 35dfc7ea-9e37-4e30-baa1-944dc61302f5
ms.openlocfilehash: 0d2ea3677d883fa4843c37a41d733872b23cbba0
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74760667"
---
# <a name="compiler-error-c2801"></a>Erro do compilador C2801

' operator Operator ' deve ser um membro não estático

Os operadores a seguir podem ser sobrecarregados somente como membros não estáticos:

- `=` de atribuição

- Acesso de membro de classe `->`

- `[]` de assinaturas

- `()` de chamada de função

Possíveis causas de C2801:

- O operador sobrecarregado não é um membro de classe, estrutura ou União.

- Operador sobrecarregado é declarado `static`.

- O exemplo a seguir gera C2801:

```cpp
// C2801.cpp
// compile with: /c
operator[]();   // C2801 not a member
class A {
   static operator->();   // C2801 static
   operator()();   // OK
};
```
