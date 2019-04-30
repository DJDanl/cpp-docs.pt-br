---
title: Erro do compilador C3873
ms.date: 11/04/2016
f1_keywords:
- C3873
helpviewer_keywords:
- C3873
ms.assetid: e68fd3be-2391-492b-ac3f-d2428901b2e9
ms.openlocfilehash: eb2a6935073c3b4a2b9eb3d9b099b372cfa34303
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62385635"
---
# <a name="compiler-error-c3873"></a>Erro do compilador C3873

'char': Este caractere não é permitido como primeiro caractere de um identificador

O compilador C++ segue o padrão C++11 em caracteres permitidos em um identificador. Somente determinados intervalos de caracteres e nomes de caracteres universais são permitidos em um identificador. Restrições adicionais se aplicam para o caractere inicial de um identificador. Para obter mais informações e uma lista de intervalos de nome de caractere universal e caracteres permitidos, consulte [identificadores](../../cpp/identifiers-cpp.md).

O intervalo de caracteres permitido em um identificador é menos restritivo quando compilando c++ /CLI código CLI. Identificadores no código compilado usando /clr devem seguir [Standard ECMA-335: Common Language Infrastructure (CLI)](http://www.ecma-international.org/publications/standards/Ecma-335.htm).

O exemplo a seguir gera C3873:

```
// C3873.cpp
int main() {
   int \u036F_abc;   // C3873, not in allowed range for initial character
   int abc_\u036F;   // OK, in allowed range for non-initial character
}
```