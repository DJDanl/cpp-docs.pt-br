---
title: Erro do compilador C3873
ms.date: 11/04/2016
f1_keywords:
- C3873
helpviewer_keywords:
- C3873
ms.assetid: e68fd3be-2391-492b-ac3f-d2428901b2e9
ms.openlocfilehash: e63c3870a60194b72f1be8e1b401bbdef8fa47be
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74736718"
---
# <a name="compiler-error-c3873"></a>Erro do compilador C3873

' char ': este caractere não é permitido como primeiro caractere de um identificador

O C++ compilador segue o padrão c++ 11 em caracteres permitidos em um identificador. Somente determinados intervalos de caracteres e nomes de caracteres universais são permitidos em um identificador. Restrições adicionais se aplicam ao caractere inicial de um identificador. Para obter mais informações e uma lista de caracteres permitidos e intervalos de nome de caractere universal, consulte [identificadores](../../cpp/identifiers-cpp.md).

O intervalo de caracteres permitido em um identificador é menos restritivo ao compilar C++o código/CLI. Identificadores no código compilados usando/CLR devem seguir o [padrão ECMA-335: Common Language Infrastructure (CLI)](https://www.ecma-international.org/publications/standards/Ecma-335.htm).

O exemplo a seguir gera C3873:

```cpp
// C3873.cpp
int main() {
   int \u036F_abc;   // C3873, not in allowed range for initial character
   int abc_\u036F;   // OK, in allowed range for non-initial character
}
```
