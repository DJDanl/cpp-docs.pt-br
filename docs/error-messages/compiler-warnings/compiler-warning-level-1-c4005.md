---
title: Compilador aviso (nível 1) C4005
ms.date: 11/04/2016
f1_keywords:
- C4005
helpviewer_keywords:
- C4005
ms.assetid: 7f2dc79a-9fcb-4d5b-be61-120d9cb487ad
ms.openlocfilehash: 76aab2160bd5f7918771dcf63b7297a869da751e
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62187333"
---
# <a name="compiler-warning-level-1-c4005"></a>Compilador aviso (nível 1) C4005

'identifier': redefinição de macro

O identificador de macro é definido duas vezes. O compilador usa a segunda definição de macro.

### <a name="to-fix-by-checking-the-following-possible-causes"></a>Para corrigir verificando as possíveis causas a seguir

1. Definindo uma macro na linha de comando e no código com um `#define` diretiva.

1. Macros importadas de arquivos de inclusão.

### <a name="to-fix-by-using-the-following-possible-solutions"></a>Para corrigir usando as seguintes soluções possíveis

1. Remova uma das definições.

1. Use uma [#undef](../../preprocessor/hash-undef-directive-c-cpp.md) diretiva antes da definição de segundo.

O exemplo a seguir gera C4005:

```
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