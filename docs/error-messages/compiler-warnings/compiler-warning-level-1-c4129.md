---
title: Compilador aviso (nível 1) C4129
ms.date: 11/04/2016
f1_keywords:
- C4129
helpviewer_keywords:
- C4129
ms.assetid: a4190c64-4bfb-48fd-8e98-52720bc0d878
ms.openlocfilehash: dc4f4c4c1feeba543ce0baa71e1ee5dfd81fdcae
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50428659"
---
# <a name="compiler-warning-level-1-c4129"></a>Compilador aviso (nível 1) C4129

'character': não reconhecido de sequência de escape de caractere

O `character` seguindo uma barra invertida (\\) em um caractere ou cadeia de caracteres constante não é reconhecida como uma sequência de escape válidos. A barra invertida é ignorada e não-impresso. O caractere que segue a barra invertida é impresso.

Para imprimir uma única barra invertida, especifique uma barra invertida dupla (\\\\).

O C++ padrão, na seção 2.13.2 discute as sequências de escape.

O exemplo a seguir gera C4129:

```
// C4129.cpp
// compile with: /W1
int main() {
   char array1[] = "\/709";   // C4129
   char array2[] = "\n709";   // OK
}
```