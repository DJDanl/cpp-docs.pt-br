---
title: Erro do compilador C2698 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2698
dev_langs:
- C++
helpviewer_keywords:
- C2698
ms.assetid: 3ebfe395-c20b-4c56-9980-ca9ed8653382
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: c7ca3e7568640aabd2b7960d97ea94a11a1d5d59
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46118915"
---
# <a name="compiler-error-c2698"></a>Erro do compilador C2698

a declaração de using para ' declaração 1' não pode coexistir com a declaração de using existente para ' declaração 2'

Uma vez que um [usando a declaração](../../cpp/using-declaration.md) para um membro de dados, uso de qualquer declaração no mesmo escopo que usa o mesmo nome não é permitida, pois apenas as funções podem ser sobrecarregadas.

O exemplo a seguir gera C2698:

```
// C2698.cpp
struct A {
   int x;
};

struct B {
   int x;
};

struct C : A, B {
   using A::x;
   using B::x;   // C2698
}
```