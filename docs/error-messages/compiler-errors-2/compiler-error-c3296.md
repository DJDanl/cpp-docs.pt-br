---
title: Erro do compilador C3296
ms.date: 11/04/2016
f1_keywords:
- C3296
helpviewer_keywords:
- C3296
ms.assetid: fc4c9dcd-16cf-4eee-a1ac-c43e7c29e443
ms.openlocfilehash: 2e9787b063a5a37af8d0e0fdd04492a743792646
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50588104"
---
# <a name="compiler-error-c3296"></a>Erro do compilador C3296

'property': já existe uma propriedade com esse nome

O compilador encontrou mais de uma propriedade com o mesmo nome. Cada propriedade em um tipo deve ter um nome exclusivo.

Para obter mais informações, consulte [propriedade](../../windows/property-cpp-component-extensions.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3296.

```
// C3296.cpp
// compile with: /clr /c
using namespace System;

ref class R {
public:
   property int MyProp[int] { int get(int); }

   property String^ MyProp[int] { void set(int, String^); }   // C3296
};
```