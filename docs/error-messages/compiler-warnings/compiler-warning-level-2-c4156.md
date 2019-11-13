---
title: Aviso do compilador (nível 2) C4156
ms.date: 11/04/2016
f1_keywords:
- C4156
helpviewer_keywords:
- C4156
ms.assetid: 9adf3acb-c0fe-42a8-a4db-5822b1493f77
ms.openlocfilehash: 95605aa29e1faba449e19dcf20e6895d31cc5874
ms.sourcegitcommit: 458dcc794e3841919c01a3a5ff6b9a3767f8861b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/13/2019
ms.locfileid: "74052138"
---
# <a name="compiler-warning-level-2-c4156"></a>Aviso do compilador (nível 2) C4156

exclusão de uma expressão de matriz sem usar a forma de matriz de ' Delete '; formulário de matriz substituído

A forma não matricial da **exclusão** não pode excluir uma matriz. O compilador converteu a **exclusão** para o formulário de matriz.

Esse aviso ocorre somente em extensões da Microsoft (/Ze).

## <a name="example"></a>Exemplo

```cpp
// C4156.cpp
// compile with: /W2
int main()
{
   int (*array)[ 10 ] = new int[ 5 ][ 10 ];
   delete array; // C4156, changed by compiler to "delete [] array;"
}
```