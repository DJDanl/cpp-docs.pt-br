---
title: Erro do compilador C3872
ms.date: 11/04/2016
f1_keywords:
- C3872
helpviewer_keywords:
- C3872
ms.assetid: 519e95be-5641-40cc-894c-da4819506604
ms.openlocfilehash: f4b116729ad3b84014d202deb31ab490435fcef3
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74761436"
---
# <a name="compiler-error-c3872"></a>Erro do compilador C3872

' char ': este caractere não é permitido em um identificador

O C++ compilador segue o padrão c++ 11 em caracteres permitidos em um identificador. Somente determinados intervalos de caracteres e nomes de caracteres universais são permitidos em um identificador. Restrições adicionais se aplicam ao caractere inicial de um identificador. Para obter mais informações e uma lista de caracteres permitidos e intervalos de nome de caractere universal, consulte [identificadores](../../cpp/identifiers-cpp.md).

O intervalo de caracteres permitido em um identificador é menos restritivo ao compilar C++o código/CLI. Identificadores no código compilados usando/CLR devem seguir o [padrão ECMA-335: Common Language Infrastructure (CLI)](https://www.ecma-international.org/publications/standards/Ecma-335.htm).

O exemplo a seguir gera C3872:

```cpp
// C3872.cpp
int main() {
   int abc_\u0040;   // C3872, U+0040 is in base char set
   int abc_\u3001;   // C3872, U+3001 is not in allowed range
   int \u30A2_abc_\u3042;   // OK, UCNs in allowed range
}
```
