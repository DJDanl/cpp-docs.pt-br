---
title: Aviso do compilador (nível 1) C4129
ms.date: 11/04/2016
f1_keywords:
- C4129
helpviewer_keywords:
- C4129
ms.assetid: a4190c64-4bfb-48fd-8e98-52720bc0d878
ms.openlocfilehash: 1a48fc806f3274a59c99be25ac7a0e7b03a0454b
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80176215"
---
# <a name="compiler-warning-level-1-c4129"></a>Aviso do compilador (nível 1) C4129

' character ': sequência de escape de caractere não reconhecida

A `character` seguindo uma barra invertida (\\) em uma constante de caractere ou de cadeia de caracteres não é reconhecida como uma sequência de escape válida. A barra invertida é ignorada e não é impressa. O caractere após a barra invertida é impresso.

Para imprimir uma barra invertida, especifique uma barra invertida dupla (\\\\).

O C++ padrão, na seção 2.13.2, aborda as sequências de escape.

O exemplo a seguir gera C4129:

```cpp
// C4129.cpp
// compile with: /W1
int main() {
   char array1[] = "\/709";   // C4129
   char array2[] = "\n709";   // OK
}
```
