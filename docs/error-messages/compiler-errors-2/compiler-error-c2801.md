---
title: Erro do compilador C2801
ms.date: 11/04/2016
f1_keywords:
- C2801
helpviewer_keywords:
- C2801
ms.assetid: 35dfc7ea-9e37-4e30-baa1-944dc61302f5
ms.openlocfilehash: cfb89c79534318ab1fbcaa06667d594bfe2f1157
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87214588"
---
# <a name="compiler-error-c2801"></a>Erro do compilador C2801

' operator Operator ' deve ser um membro não estático

Os operadores a seguir podem ser sobrecarregados somente como membros não estáticos:

- Design`=`

- Acesso de membro de classe`->`

- Subscripting`[]`

- Chamada de função`()`

Possíveis causas de C2801:

- O operador sobrecarregado não é um membro de classe, estrutura ou União.

- Operador sobrecarregado é declarado **`static`** .

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
