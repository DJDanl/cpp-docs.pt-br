---
title: Aviso do compilador (nível 1) C4005
ms.date: 11/04/2016
f1_keywords:
- C4005
helpviewer_keywords:
- C4005
ms.assetid: 7f2dc79a-9fcb-4d5b-be61-120d9cb487ad
ms.openlocfilehash: 71b23ec719198d15a99b4fcfd50db8b151e03226
ms.sourcegitcommit: 0cfc43f90a6cc8b97b24c42efcf5fb9c18762a42
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/05/2019
ms.locfileid: "73627363"
---
# <a name="compiler-warning-level-1-c4005"></a>Aviso do compilador (nível 1) C4005

' identificador ': redefinição de macro

O identificador de macro é definido duas vezes. O compilador usa a segunda definição de macro.

### <a name="to-fix-by-checking-the-following-possible-causes"></a>Para corrigir verificando as possíveis causas a seguir

1. Definir uma macro na linha de comando e no código com uma diretiva `#define`.

1. Macros importadas de arquivos de inclusão.

### <a name="to-fix-by-using-the-following-possible-solutions"></a>Para corrigir usando as seguintes soluções possíveis

1. Remova uma das definições.

1. Use uma diretiva [#undef](../../preprocessor/hash-undef-directive-c-cpp.md) antes da segunda definição.

O exemplo a seguir gera C4005:

```cpp
// C4005.cpp
// compile with: /W1 /EHsc
#include <iostream>
using namespace std;

#define TEST "test1"
#define TEST "test2"   // C4005 delete or rename to resolve the warning

int main() {
   cout << TEST << endl;
}
```