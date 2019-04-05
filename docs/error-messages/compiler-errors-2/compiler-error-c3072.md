---
title: Erro do compilador C3072
ms.date: 11/04/2016
f1_keywords:
- C3072
helpviewer_keywords:
- C3072
ms.assetid: cdd5cb6b-c478-4698-adfa-c40188d34a18
ms.openlocfilehash: 2b76fa91d739e9cc89251aaf56aa9b196e62a68d
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "58777123"
---
# <a name="compiler-error-c3072"></a>Erro do compilador C3072

o operador 'operator' não pode ser aplicado a uma instância de uma classe ref

usar o operador unário '`operator` ' operador para converter uma instância de uma classe de referência para um tipo de identificador

Um tipo CLR requer operadores CLR, não os operadores nativos (ou padrão).  Para obter mais informações, consulte [operador de referência de acompanhamento](../../extensions/tracking-reference-operator-cpp-component-extensions.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3072.

```
// C3072.cpp
// compile with: /clr
ref class R {};

int main() {
   R r1;
   R^ r2 = &r1;   // C3072
   R^ r3 = %r1;   // OK
}
```