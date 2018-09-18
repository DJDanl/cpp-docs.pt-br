---
title: Erro do compilador C2272 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2272
dev_langs:
- C++
helpviewer_keywords:
- C2272
ms.assetid: 1517706a-9c27-452e-9b10-3424b3d232bc
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: e17765ee0acbf20d76e631bf7fccfb3413c5dc1d
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46040304"
---
# <a name="compiler-error-c2272"></a>Erro do compilador C2272

'function': modificadores não permitidos em funções de membro estático

Um `static` função de membro é declarada com um especificador de modelo de memória, como [const](../../cpp/const-cpp.md) ou [volátil](../../cpp/volatile-cpp.md), e esses modificadores não são permitidos em `static` funções de membro.

O exemplo a seguir gera C2272:

```
// C2272.cpp
// compile with: /c
class CMyClass {
public:
   static void func1() const volatile;   // C2272  func1 is static
   void func2() const volatile;   // OK
};
```