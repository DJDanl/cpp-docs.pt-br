---
title: Erro do compilador C2178 | Microsoft Docs
ms.custom: ''
ms.date: 05/08/2017
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2178
dev_langs:
- C++
helpviewer_keywords:
- C2178
ms.assetid: 79a14158-17f3-4221-bd06-9d675c49cef4
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: af9efdb3258e6793a17a26b552df8ba4e63c9107
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46102327"
---
# <a name="compiler-error-c2178"></a>Erro do compilador C2178

'*identificador*'não pode ser declarada com'*especificador*' especificador

Um `mutable` especificador foi usado em uma declaração, mas o especificador não é permitido neste contexto.

O `mutable` especificador pode ser aplicado somente aos nomes de membros de dados de classe e não pode ser aplicado a nomes declarados `const` ou `static`e não pode ser aplicado para fazer referência a membros.

## <a name="example"></a>Exemplo

O exemplo a seguir mostra como C2178 podem ocorrer e como corrigi-lo.

```
// C2178.cpp
// compile with: cl /c /W4 C2178.cpp

class S {
    mutable const int i; // C2178
    // To fix, declare either const or mutable, not both.
};

mutable int x = 4; // C2178
// To fix, remove mutable keyword
```
