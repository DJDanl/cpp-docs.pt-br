---
title: Compilador aviso (nível 1) C4369
ms.date: 11/04/2016
f1_keywords:
- C4369
helpviewer_keywords:
- C4369
ms.assetid: ade87e84-36be-4e00-be99-2930af848feb
ms.openlocfilehash: b374b67fa3319be35490358d7664bcb45bc640db
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50623945"
---
# <a name="compiler-warning-level-1-c4369"></a>Compilador aviso (nível 1) C4369

'enumerador': valor do enumerador 'value' não pode ser representado como 'type', valor é 'novo_valor'

Um enumerador foi calculado para ser maior que o maior valor para o tipo subjacente especificado.  Isso causou um estouro e o compilador encapsulado o valor do enumerador para o menor valor possível para o tipo.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4369.

```
// C4369.cpp
// compile with: /W1
int main() {
   enum Color: char { red = 0x7e, green, blue };   // C4369
   enum Color2: char { red2 = 0x7d, green2, blue2};   // OK
}
```