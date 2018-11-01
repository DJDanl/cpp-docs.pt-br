---
title: Erro do compilador C3291
ms.date: 11/04/2016
f1_keywords:
- C3291
helpviewer_keywords:
- C3291
ms.assetid: ed2e9f89-8dbc-4387-bc26-cc955e840858
ms.openlocfilehash: 6d9602d1ec9f2e4a72784e20bfd90c7f3aac0781
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50611335"
---
# <a name="compiler-error-c3291"></a>Erro do compilador C3291

'default': não pode ser o nome de uma propriedade trivial

Uma propriedade trivial não pode ser nomeada `default`. Ver [propriedade](../../windows/property-cpp-component-extensions.md) para obter mais informações.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3291.

```
// C3291.cpp
// compile with: /clr /c
ref struct C {
   property System::String ^ default;   // C3291
   property System::String ^ Default;   // OK
};
```