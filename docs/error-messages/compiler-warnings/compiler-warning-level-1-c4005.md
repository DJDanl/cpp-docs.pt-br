---
title: Aviso do compilador (nível 1) C4005
ms.date: 11/04/2016
f1_keywords:
- C4005
helpviewer_keywords:
- C4005
ms.assetid: 7f2dc79a-9fcb-4d5b-be61-120d9cb487ad
ms.openlocfilehash: 4e95f8deeb61c5a4d56e0643beb6a746f848e33e
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80164723"
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
