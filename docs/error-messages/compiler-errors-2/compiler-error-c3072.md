---
title: Erro do compilador C3072
ms.date: 11/04/2016
f1_keywords:
- C3072
helpviewer_keywords:
- C3072
ms.assetid: cdd5cb6b-c478-4698-adfa-c40188d34a18
ms.openlocfilehash: a8fe0802a7529551fce1c0b7242c867db52d8842
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74756754"
---
# <a name="compiler-error-c3072"></a>Erro do compilador C3072

operador "Operator" não pode ser aplicado a uma instância de uma ref class

usar o operador '`operator` ' unário para converter uma instância de uma ref class em um tipo de identificador

Um tipo CLR requer operadores CLR, não operadores nativos (ou padrão).  Para obter mais informações, consulte [Control Reference Operator](../../extensions/tracking-reference-operator-cpp-component-extensions.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3072.

```cpp
// C3072.cpp
// compile with: /clr
ref class R {};

int main() {
   R r1;
   R^ r2 = &r1;   // C3072
   R^ r3 = %r1;   // OK
}
```
