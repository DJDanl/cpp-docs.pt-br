---
title: Compilador aviso (nível 2) C4307 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4307
dev_langs:
- C++
helpviewer_keywords:
- C4307
ms.assetid: 7cca11e9-be61-49e4-8b15-88b84f0cbf07
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: ed18c213b35e79aaae98efa5932ac404a8d84bff
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46079187"
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