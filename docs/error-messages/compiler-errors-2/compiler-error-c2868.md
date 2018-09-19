---
title: Erro do compilador C2868 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2868
dev_langs:
- C++
helpviewer_keywords:
- C2868
ms.assetid: 6ff5837b-e66d-44d1-9d17-80af35e08d08
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 2de22b34f9dc564ef89d7776af86718af70d51eb
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46037860"
---
# <a name="compiler-error-c2868"></a>Erro do compilador C2868

> '*identificador*': sintaxe inválida para declaração de using; esperado nome qualificado

Um [usando a declaração](../../cpp/using-declaration.md) requer uma *nome qualificado*, um operador de escopo (`::`) separados por sequência de nomes de namespace, classe ou enumeração que termina com o nome do identificador. Um operador de resolução de escopo único pode ser usado para introduzir um nome de namespace global.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2868 e também mostra o uso correto:

```cpp
// C2868.cpp
class X {
public:
   int i;
};

class Y : X {
public:
   using X::i;   // OK
};

int main() {
   using X;   // C2868
}
```