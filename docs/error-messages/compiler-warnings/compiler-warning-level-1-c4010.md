---
title: Compilador aviso (nível 1) C4010
ms.date: 11/04/2016
f1_keywords:
- C4010
helpviewer_keywords:
- C4010
ms.assetid: d607a9ff-8f8f-45c0-b07b-3b2f439e5485
ms.openlocfilehash: 40c6724daf17c1c0b546bb7bc64bb704f732e8d6
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62386545"
---
# <a name="compiler-warning-level-1-c4010"></a>Compilador aviso (nível 1) C4010

comentário de linha única contém caractere de continuação de linha

Um comentário de linha única, que é apresentado pelo / /, contém uma barra invertida (\\) que serve como um caractere de continuação de linha. O compilador considera que a próxima linha a ser uma continuação e a trata como um comentário.

Alguns sintaxe orientada para editores não indicam a linha após o caractere de continuação como um comentário. Ignore sintaxe colorida em todas as linhas que causam esse aviso.

O exemplo a seguir gera C4010:

```
// C4010.cpp
// compile with: /WX
int main() {
   // the next line is also a comment because of the backslash \
   int a = 3; // C4010
   a++;
}
```