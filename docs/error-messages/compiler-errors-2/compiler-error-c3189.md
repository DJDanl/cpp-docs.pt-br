---
title: Erro do compilador C3189 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3189
dev_langs:
- C++
helpviewer_keywords:
- C3189
ms.assetid: b254de79-931e-4a59-a9f4-1c690d90ca5e
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: c4666a16aed6d26f1cf38e4b32523c7c36948274
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46093864"
---
# <a name="compiler-error-c3189"></a>Erro do compilador C3189

' typeid\<digite declarador abstrato >': não há suporte para esta sintaxe, use:: typeid em vez disso

Um formato obsoleto da [typeid](../../windows/typeid-cpp-component-extensions.md) foi usado, use o novo formulário.

O exemplo a seguir gera C3189:

```
// C3189.cpp
// compile with: /clr
int main() {
   System::Type^ t  = typeid<System::Object>;   // C3189
   System::Type^ t2  = System::Object::typeid;   // OK
}
```