---
title: Compilador aviso (nível 1) C4920 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4920
dev_langs:
- C++
helpviewer_keywords:
- C4920
ms.assetid: 1e501f2e-93c1-4d27-a4fa-54fc86271ae7
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 4873fcb1e5bb6d712e44b86d6f60589d6c8ddf4d
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46091732"
---
# <a name="compiler-warning-level-1-c4920"></a>Compilador aviso (nível 1) C4920

membro de membro de enumeração de enum = valor já visto em enumeração de enum como membro = valor

Se um TLB que você passa para #import tem o mesmo símbolo definido em dois ou mais enumerações, este aviso indica que símbolos idênticos subsequentes serão ignorados e serão ser comentados no arquivo. TLH.

Supondo que um. tlb que contém:

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

Os exemplos a seguir gera C4920,

```
// C4920.cpp
// compile with: /W1
#import "t4920.tlb"   // C4920

int main() {
}
```