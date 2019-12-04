---
title: Erro do compilador C3657
ms.date: 11/04/2016
f1_keywords:
- C3657
helpviewer_keywords:
- C3657
ms.assetid: 89a28a18-4c17-43a1-bda6-deb52c32d203
ms.openlocfilehash: b1a72fc3d96a5ef3a591fb61d0b2839fb5c1b05b
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74758263"
---
# <a name="compiler-error-c3657"></a>Erro do compilador C3657

os destruidores não podem substituir ou ser substituídos explicitamente

Os destruidores ou finalizadores não podem ser substituídos explicitamente. Para obter mais informações, consulte [substituições explícitas](../../extensions/explicit-overrides-cpp-component-extensions.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3657.

```cpp
// C3657.cpp
// compile with: /clr
public ref struct I {
   virtual ~I() { }
   virtual void a();
};

public ref struct D : I {
   virtual ~D() = I::~I {}   // C3657
   virtual void a() = I::a {}   // OK
};
```
