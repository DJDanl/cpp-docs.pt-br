---
title: Erro do compilador C3628 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3628
dev_langs:
- C++
helpviewer_keywords:
- C3628
ms.assetid: 0ff5a4a4-fcc9-47a0-a4d8-8af9cf2815f6
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 9a65dc33c5381b063c3adb01072e930075108649
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46037366"
---
# <a name="compiler-error-c3628"></a>Erro do compilador C3628

classe de base: gerenciado ou WinRTclasses suportam apenas herança public

Foi feita uma tentativa para usar um gerenciado ou WinRT da classe como um [privados](../../cpp/private-cpp.md) ou [protegido](../../cpp/protected-cpp.md) classe base. Um gerenciado ou classe do WinRT somente pode ser usada como uma classe base com [pública](../../cpp/public-cpp.md) acesso.

O exemplo a seguir gera C3628 e mostra como corrigi-lo:

```
// C3628a.cpp
// compile with: /clr
ref class B {
};

ref class D : private B {   // C3628

// The following line resolves the error.
// ref class D : public B {
};

int main() {
}
```
