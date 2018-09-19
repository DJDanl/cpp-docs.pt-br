---
title: Erro do compilador C2464 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2464
dev_langs:
- C++
helpviewer_keywords:
- C2464
ms.assetid: ace953d6-b414-49ee-bfef-90578a8da00c
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: ff74085364d6638772ab2376aace93fea741056b
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46103133"
---
# <a name="compiler-error-c2464"></a>Erro do compilador C2464

'identifier': não é possível usar 'new' para alocar uma referência

Um identificador de referência foi alocado com o `new` operador. As referências não são objetos de memória, portanto, `new` não pode retornar um ponteiro para eles. Use a sintaxe de declaração de variável padrão para declarar uma referência.

O exemplo a seguir gera C2464:

```
// C2464.cpp
int main() {
   new ( int& ir );   // C2464
}
```