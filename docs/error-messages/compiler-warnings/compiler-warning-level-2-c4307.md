---
title: Compilador aviso (nível 2) C4307
ms.date: 11/04/2016
f1_keywords:
- C4307
helpviewer_keywords:
- C4307
ms.assetid: 7cca11e9-be61-49e4-8b15-88b84f0cbf07
ms.openlocfilehash: e9ad30f60260893130beed921aab811c894868cc
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62402496"
---
# <a name="compiler-warning-level-2-c4307"></a>Compilador aviso (nível 2) C4307

'operator': estouro de constante integral

O operador é usado em uma expressão que resulta em uma constante de inteiro estourar o espaço alocado para ele. Talvez você precise usar um tipo maior para a constante. Um **assinado int** contém um valor menor que um `unsigned int` porque o **assinado int** usa um bit para representar o sinal.

O exemplo a seguir gera C4307:

```
// C4307.cpp
// compile with: /W2
int i = 2000000000 + 2000000000;   // C4307
int j = (unsigned)2000000000 + 2000000000;   // OK

int main()
{
}
```