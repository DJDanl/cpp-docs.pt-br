---
title: Erro do compilador C3189
ms.date: 11/04/2016
f1_keywords:
- C3189
helpviewer_keywords:
- C3189
ms.assetid: b254de79-931e-4a59-a9f4-1c690d90ca5e
ms.openlocfilehash: fe9dc38748fd667734c5d80f1284348184fed450
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50456973"
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