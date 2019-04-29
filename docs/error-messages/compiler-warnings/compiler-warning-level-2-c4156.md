---
title: Compilador aviso (nível 2) C4156
ms.date: 11/04/2016
f1_keywords:
- C4156
helpviewer_keywords:
- C4156
ms.assetid: 9adf3acb-c0fe-42a8-a4db-5822b1493f77
ms.openlocfilehash: 7d9a4ed09f026267e2c0f37fbbe4550ecd668dfc
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62350459"
---
# <a name="compiler-warning-level-2-c4156"></a>Compilador aviso (nível 2) C4156

exclusão de uma expressão de matriz sem o uso da forma matricial de 'delete'; forma matricial substituída

Forma de não-matriz **excluir** não é possível excluir uma matriz. O compilador traduziu **excluir** para o formato da matriz.

Este aviso ocorre apenas sob extensões da Microsoft (/Ze).

## <a name="example"></a>Exemplo

```
// C4156.cpp
// compile with: /W2
int main()
{
   int (*array)[ 10 ] = new int[ 5 ][ 10 ];
   delete array; // C4156, changed by compiler to "delete [] array;"
}
```