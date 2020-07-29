---
title: Aviso do compilador (nível 1) C4807
ms.date: 11/04/2016
f1_keywords:
- C4807
helpviewer_keywords:
- C4807
ms.assetid: 089c9f87-fd81-402e-9826-66a8ef1ef1fe
ms.openlocfilehash: 17a33f7c55fa2825eae1c7d8b9d8ab78e4ed5274
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87225326"
---
# <a name="compiler-warning-level-1-c4807"></a>Aviso do compilador (nível 1) C4807

' Operation ': combinação não segura do tipo ' type ' e um campo de bits assinado do tipo ' type '

Esse aviso é gerado ao comparar um campo de bit assinado de um bit com uma **`bool`** variável. Como um campo de bit assinado de um bit pode conter apenas os valores-1 ou 0, é perigoso compará-lo com **`bool`** . Nenhum aviso é gerado sobre mixagem **`bool`** e bitfields não assinados, pois eles são idênticos a **`bool`** e só podem conter 0 ou 1.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4807:

```cpp
// C4807.cpp
// compile with: /W1
typedef struct bitfield {
   signed mybit : 1;
} mybitfield;

int main() {
   mybitfield bf;
   bool b = true;

   // try..
   // int b = true;

   bf.mybit = -1;
   if (b == bf.mybit) {   // C4807
      b = false;
   }
}
```
