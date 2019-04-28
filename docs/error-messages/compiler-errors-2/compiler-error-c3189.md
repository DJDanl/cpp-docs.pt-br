---
title: Erro do compilador C3189
ms.date: 11/04/2016
f1_keywords:
- C3189
helpviewer_keywords:
- C3189
ms.assetid: b254de79-931e-4a59-a9f4-1c690d90ca5e
ms.openlocfilehash: b2de290178657ae427b5ad7999c511ae7ff9f1eb
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62300623"
---
# <a name="compiler-error-c3189"></a>Erro do compilador C3189

' typeid\<digite declarador abstrato >': não há suporte para esta sintaxe, use:: typeid em vez disso

Um formato obsoleto da [typeid](../../extensions/typeid-cpp-component-extensions.md) foi usado, use o novo formulário.

O exemplo a seguir gera C3189:

```
// C3189.cpp
// compile with: /clr
int main() {
   System::Type^ t  = typeid<System::Object>;   // C3189
   System::Type^ t2  = System::Object::typeid;   // OK
}
```