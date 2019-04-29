---
title: Erro do compilador C3628
ms.date: 11/04/2016
f1_keywords:
- C3628
helpviewer_keywords:
- C3628
ms.assetid: 0ff5a4a4-fcc9-47a0-a4d8-8af9cf2815f6
ms.openlocfilehash: 581aae7e1f979b3dd39caf2ce3d263fdb856c56a
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62221679"
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
