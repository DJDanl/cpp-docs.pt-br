---
title: Erro do compilador C3291
ms.date: 11/04/2016
f1_keywords:
- C3291
helpviewer_keywords:
- C3291
ms.assetid: ed2e9f89-8dbc-4387-bc26-cc955e840858
ms.openlocfilehash: e3f20d7d7e63079ed9c7a078e9fc9eac06d32677
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62222714"
---
# <a name="compiler-error-c3291"></a>Erro do compilador C3291

'default': não pode ser o nome de uma propriedade trivial

Uma propriedade trivial não pode ser nomeada `default`. Ver [propriedade](../../extensions/property-cpp-component-extensions.md) para obter mais informações.

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