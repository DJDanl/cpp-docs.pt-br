---
title: Erro do compilador C2530
ms.date: 11/04/2016
f1_keywords:
- C2530
helpviewer_keywords:
- C2530
ms.assetid: b790a312-48df-4a6a-9e27-be2c5f32f16c
ms.openlocfilehash: 0816fcb4d9e2a3e6588dfcf937383fed7ab11395
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74737121"
---
# <a name="compiler-error-c2530"></a>Erro do compilador C2530

' identifier ': referências devem ser inicializadas

Você deve inicializar uma referência quando ela foi declarada, a menos que já seja declarado:

- Com a palavra-chave [extern](../../cpp/using-extern-to-specify-linkage.md).

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
