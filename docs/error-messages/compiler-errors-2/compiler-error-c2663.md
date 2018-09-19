---
title: Erro do compilador C2663 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2663
dev_langs:
- C++
helpviewer_keywords:
- C2663
ms.assetid: 1e93e368-fd52-42bf-9908-9b6df467c8c9
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: fed35dcce056eb3d2a660c154e94b8058563dba7
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46083685"
---
# <a name="compiler-error-c2663"></a>Erro do compilador C2663

'function': sobrecargas número não ter nenhuma conversões legais para ponteiro 'this'

O compilador não foi possível converter `this` para qualquer uma das versões sobrecarregadas da função de membro.

Esse erro pode ser causado pela invocação de um não -`const` função de membro em uma `const` objeto.  Possíveis resoluções:

1. Remover o `const` da declaração de objeto.

1. Adicionar `const` para uma das sobrecargas de função de membro.

O exemplo a seguir gera C2663:

```
// C2663.cpp
struct C {
   void f() volatile {}
   void f() {}
};

struct D {
   void f() volatile;
   void f() const {}
};

const C *pcc;
const D *pcd;

int main() {
   pcc->f();    // C2663
   pcd->f();    // OK
}
```