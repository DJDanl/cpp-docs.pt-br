---
title: Erro do compilador C3625
ms.date: 11/04/2016
f1_keywords:
- C3625
helpviewer_keywords:
- C3625
ms.assetid: fdf49f21-d6b1-42f4-9eec-23b04ae8b4aa
ms.openlocfilehash: a3c69b05e22c2d267ad07f19a0d0ab60f3eebb94
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "58779008"
---
# <a name="compiler-error-c3625"></a>Erro do compilador C3625

'native_type': um tipo nativo não pode derivar de gerenciada ou WinRT tipo 'type'

Uma classe nativa não pode herdar de gerenciada ou WinRT classe. Para obter mais informações, consulte [Classes e Structs](../../extensions/classes-and-structs-cpp-component-extensions.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3625:

```
// C3625.cpp
// compile with: /clr /c
ref class B {};
class D : public B {};   // C3625 cannot inherit from a managed class
```
