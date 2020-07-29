---
title: Erro do compilador C3072
ms.date: 11/04/2016
f1_keywords:
- C3072
helpviewer_keywords:
- C3072
ms.assetid: cdd5cb6b-c478-4698-adfa-c40188d34a18
ms.openlocfilehash: bcf2548fbe1182f7f6c4bd966ca6aa9ef9f10089
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87212599"
---
# <a name="compiler-error-c3072"></a>Erro do compilador C3072

> operador '*Operator-Name*' não pode ser aplicado a uma instância de uma ref class

usar o operador *operador-nome* unário para converter uma instância de uma ref class em um tipo de identificador

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
