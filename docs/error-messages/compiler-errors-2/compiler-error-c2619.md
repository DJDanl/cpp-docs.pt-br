---
title: Erro do compilador C2619
ms.date: 11/04/2016
f1_keywords:
- C2619
helpviewer_keywords:
- C2619
ms.assetid: c826f8ab-d66a-4b79-a0b2-93b0af8c41ac
ms.openlocfilehash: 3ca5ea4612091f1e3eee8fead2b1eaebb264b696
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74754765"
---
# <a name="compiler-error-c2619"></a>Erro do compilador C2619

' identifier ': um membro de dados static não é permitido em uma struct ou Union anônima

Um membro de uma struct ou União anônima é declarado `static`.

O exemplo a seguir gera C2619 e demonstra como corrigi-lo removendo a palavra-chave static.

```cpp
// C2619.cpp
int main() {
   union { static int j; };  // C2619
   union { int j; };  // OK
}
```
