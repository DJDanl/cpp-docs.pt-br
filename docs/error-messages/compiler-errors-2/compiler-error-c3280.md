---
title: Erro do compilador C3280 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3280
dev_langs:
- C++
helpviewer_keywords:
- C3280
ms.assetid: 86dc5bbc-8818-4786-a728-9334268d308b
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: ed102abc0f46b896b70cb4681db4b0924b6c5822
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46085103"
---
# <a name="compiler-error-c3280"></a>Erro do compilador C3280

'class': uma função de membro de um tipo gerenciado não pode ser compilada como uma função não gerenciada

Gerenciado funções não podem ser compiladas como funções não gerenciadas de membro de classe.

O exemplo a seguir gera C3280:

```
// C3280_2.cpp
// compile with: /clr
ref struct A {
   void func();
};

#pragma managed(push,off)

void A::func()   // C3280
{
}

#pragma managed(pop)
```
