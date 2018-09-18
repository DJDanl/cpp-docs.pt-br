---
title: Erro do compilador C2533 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2533
dev_langs:
- C++
helpviewer_keywords:
- C2533
ms.assetid: 5b335652-076c-4824-87c8-a741f64a3ce0
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 528b78e71713725907a9f0e2bd06cec1a8c62e67
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46045400"
---
# <a name="compiler-error-c2533"></a>Erro do compilador C2533

'identifier': construtores não permitidas um tipo de retorno

Um construtor não pode ter um tipo de retorno (nem mesmo uma `void` tipo de retorno).

Uma origem comum desse erro é um ponto e vírgula ausente entre o final de uma definição de classe e a primeira implementação do construtor. O compilador considera a classe como uma definição do tipo de retorno para a função de construtor e gera C2533.

O exemplo a seguir gera C2533 e mostra como corrigi-lo:

```
// C2533.cpp
// compile with: /c
class X {
public:
   X();
};

int X::X() {}   // C2533 - constructor return type not allowed
X::X() {}   // OK - fix by using no return type
```