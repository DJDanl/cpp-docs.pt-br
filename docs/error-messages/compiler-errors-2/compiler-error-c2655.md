---
title: Erro do compilador C2655 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2655
dev_langs:
- C++
helpviewer_keywords:
- C2655
ms.assetid: beaefa6e-51b3-4df9-9150-960f3fbf40e0
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 456fd31e6d618774bff13c9800d6a44ffd3deb73
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46078680"
---
# <a name="compiler-error-c2655"></a>Erro do compilador C2655

'identifier': definição ou redeclaração inválida no escopo atual

Um identificador pode ser declarado novamente somente no escopo global.

O exemplo a seguir gera C2655:

```
// C2655.cpp
class A {};
class B {
public:
   static int i;
};

int B::i;  // OK

int main() {
   A B::i;  // C2655
}
```