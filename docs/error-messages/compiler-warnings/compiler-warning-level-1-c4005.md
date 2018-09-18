---
title: Compilador aviso (nível 1) C4005 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4005
dev_langs:
- C++
helpviewer_keywords:
- C4005
ms.assetid: 7f2dc79a-9fcb-4d5b-be61-120d9cb487ad
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 8be172086e316c991f461b3ac42f58739801cfa7
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46022962"
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