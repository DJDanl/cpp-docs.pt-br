---
title: Erro do compilador C2533
ms.date: 11/04/2016
f1_keywords:
- C2533
helpviewer_keywords:
- C2533
ms.assetid: 5b335652-076c-4824-87c8-a741f64a3ce0
ms.openlocfilehash: 6c598c2c5b3ac6d88fb843534cae240c65a2d322
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87207908"
---
# <a name="compiler-error-c2533"></a>Erro do compilador C2533

' identifier ': construtores não permitidos um tipo de retorno

Um construtor não pode ter um tipo de retorno (nem mesmo um **`void`** tipo de retorno).

Uma fonte comum desse erro é um ponto-e-vírgula ausente entre o final de uma definição de classe e a primeira implementação do construtor. O compilador vê a classe como uma definição do tipo de retorno para a função de construtor e gera C2533.

O exemplo a seguir gera C2533 e mostra como corrigi-lo:

```cpp
// C2533.cpp
// compile with: /c
class X {
public:
   X();
};

int X::X() {}   // C2533 - constructor return type not allowed
X::X() {}   // OK - fix by using no return type
```
