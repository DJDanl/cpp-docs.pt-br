---
title: Erro do compilador C3891 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3891
dev_langs:
- C++
helpviewer_keywords:
- C3891
ms.assetid: 6e1a9458-97f5-4580-bc0f-aa97a1bfd20d
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: c85e5fa5ed5e6f202750fef05ffc96e9a0c86bc1
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46051692"
---
# <a name="compiler-error-c3891"></a>Erro do compilador C3891

'var': um membro de dados literal não pode ser usado como um l-value

Um [literal](../../windows/literal-cpp-component-extensions.md) variável é const, e seu valor não pode ser alterado depois que ele é inicializado na declaração.

O exemplo a seguir gera C3891:

```
// C3891.cpp
// compile with: /clr
ref struct Y1 {
   literal int staticConst = 9;
};

int main() {
   Y1::staticConst = 0;   // C3891
}
```