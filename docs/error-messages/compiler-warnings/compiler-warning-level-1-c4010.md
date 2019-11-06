---
title: Aviso do compilador (nível 1) C4010
ms.date: 11/04/2016
f1_keywords:
- C4010
helpviewer_keywords:
- C4010
ms.assetid: d607a9ff-8f8f-45c0-b07b-3b2f439e5485
ms.openlocfilehash: 045b3f6e615e11c24caa9a088baf6ea9f6448efb
ms.sourcegitcommit: 0cfc43f90a6cc8b97b24c42efcf5fb9c18762a42
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/05/2019
ms.locfileid: "73627325"
---
# <a name="compiler-warning-level-1-c4010"></a>Aviso do compilador (nível 1) C4010

o comentário de linha única contém o caractere de continuação de linha

Um comentário de linha única, que é introduzido por//, contém uma barra invertida (\\) que funciona como um caractere de continuação de linha. O compilador considera a próxima linha como uma continuação e a trata como um comentário.

Alguns editores orientados por sintaxe não indicam a linha após o caractere de continuação como um comentário. Ignore a cor da sintaxe em qualquer linha que cause esse aviso.

O exemplo a seguir gera C4010:

```cpp
// C4010.cpp
// compile with: /WX
int main() {
   // the next line is also a comment because of the backslash \
   int a = 3; // C4010
   a++;
}
```