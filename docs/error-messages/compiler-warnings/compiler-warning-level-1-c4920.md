---
title: Aviso do compilador (nível 1) C4920
ms.date: 11/04/2016
f1_keywords:
- C4920
helpviewer_keywords:
- C4920
ms.assetid: 1e501f2e-93c1-4d27-a4fa-54fc86271ae7
ms.openlocfilehash: b587a4ca2a78bc2ac54640adb2b149d97bef4def
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80174655"
---
# <a name="compiler-warning-level-1-c4920"></a>Aviso do compilador (nível 1) C4920

enum enum member membro = valor já visto em enum enum as member = Value

Se um. tlb que você passar para #import tiver o mesmo símbolo definido em duas ou mais enumerações, esse aviso indicará que símbolos idênticos subsequentes serão ignorados e serão comentados no arquivo. tlh.

Supondo um. tlb que contém:

```
library MyLib
{
    typedef enum {
        enumMember = 512
    } AProblem;

    typedef enum {
        enumMember = 1024
    } BProblem;
};
```

o exemplo a seguir gera C4920,

```cpp
// C4920.cpp
// compile with: /W1
#import "t4920.tlb"   // C4920

int main() {
}
```
