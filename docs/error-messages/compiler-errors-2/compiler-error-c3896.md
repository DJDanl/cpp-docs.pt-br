---
title: Erro do compilador C3896 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3896
dev_langs:
- C++
helpviewer_keywords:
- C3896
ms.assetid: eb8be0f6-5b4e-4d71-8285-8a2a94f8ba29
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 6714d356fa2f09bdfce2750ff31432b5b4e14461
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46109724"
---
# <a name="compiler-error-c3896"></a>Erro do compilador C3896

'member': inicializador inadequado: este membro de dados literal só pode ser inicializado com 'nullptr'

Um [literal](../../windows/literal-cpp-component-extensions.md) membro de dados foi inicializado incorretamente.  Ver [nullptr](../../windows/nullptr-cpp-component-extensions.md) para obter mais informações.

O exemplo a seguir gera C3896:

```
// C3896.cpp
// compile with: /clr /c
ref class R{};

value class V {
   literal R ^ r = "test";   // C3896
   literal R ^ r2 = nullptr;   // OK
};
```