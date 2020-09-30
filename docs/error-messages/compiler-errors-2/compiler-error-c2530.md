---
title: Erro do compilador C2530
ms.date: 11/04/2016
f1_keywords:
- C2530
helpviewer_keywords:
- C2530
ms.assetid: b790a312-48df-4a6a-9e27-be2c5f32f16c
ms.openlocfilehash: 4eca5579f6bf132452a813d8dd99193df5f76b92
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91500534"
---
# <a name="compiler-error-c2530"></a>Erro do compilador C2530

' identifier ': referências devem ser inicializadas

Você deve inicializar uma referência quando ela foi declarada, a menos que já seja declarado:

- Com a palavra-chave [extern](../../cpp/extern-cpp.md).

- Como um membro de uma classe, estrutura ou União (e é inicializada no Construtor).

- Como um parâmetro em uma declaração ou definição de função.

- Como o tipo de retorno de uma função.

O exemplo a seguir gera C2530:

```cpp
// C2530.cpp
int main() {
   int i = 0;
   int &j;   // C2530
   int &k = i;   // OK
}
```
