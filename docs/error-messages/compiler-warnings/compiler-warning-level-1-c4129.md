---
title: Aviso do compilador (nível 1) C4129
ms.date: 11/04/2016
f1_keywords:
- C4129
helpviewer_keywords:
- C4129
ms.assetid: a4190c64-4bfb-48fd-8e98-52720bc0d878
ms.openlocfilehash: ab3108c60c18276e8e4797c7cfde1b66535dbaaa
ms.sourcegitcommit: 0cfc43f90a6cc8b97b24c42efcf5fb9c18762a42
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/05/2019
ms.locfileid: "73627430"
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