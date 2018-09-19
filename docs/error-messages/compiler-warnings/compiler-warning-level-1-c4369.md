---
title: Compilador aviso (nível 1) C4369 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4369
dev_langs:
- C++
helpviewer_keywords:
- C4369
ms.assetid: ade87e84-36be-4e00-be99-2930af848feb
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 9c8b292717168f7f6ead676528a5b7769b7c8ec4
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46024145"
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