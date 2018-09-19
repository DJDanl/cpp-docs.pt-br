---
title: Erro do compilador C3375 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3375
dev_langs:
- C++
helpviewer_keywords:
- C3375
ms.assetid: f1df78c6-e6ca-48f3-8b29-4e1710002bf3
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: f63d7eb7ef4633f01b65337c9546af260ca50fb4
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46044061"
---
# <a name="compiler-error-c3375"></a>Erro do compilador C3375

'function': função delegate ambígua

Uma instanciação de delegado poderia ter sido para uma função de membro estático, ou como um delegate não associado a uma função de instância, portanto, o compilador emitiu esse erro.

Para obter mais informações, consulte [delegado (extensões de componentes C++)](../../windows/delegate-cpp-component-extensions.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3375.

```
// C3375.cpp
// compile with: /clr
ref struct R {
   static void f(R^) {}
   void f() {}
};

delegate void Del(R^);

int main() {
   Del ^ a = gcnew Del(&R::f);   // C3375
}
```