---
title: Erro do compilador C3625
ms.date: 11/04/2016
f1_keywords:
- C3625
helpviewer_keywords:
- C3625
ms.assetid: fdf49f21-d6b1-42f4-9eec-23b04ae8b4aa
ms.openlocfilehash: 08ad1d09cb9149811566f67a585a718340254de9
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50635378"
---
# <a name="compiler-error-c3625"></a>Erro do compilador C3625

'native_type': um tipo nativo não pode derivar de gerenciada ou WinRT tipo 'type'

Uma classe nativa não pode herdar de gerenciada ou WinRT classe. Para obter mais informações, consulte [Classes e Structs](../../windows/classes-and-structs-cpp-component-extensions.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3625:

```
// C3625.cpp
// compile with: /clr /c
ref class B {};
class D : public B {};   // C3625 cannot inherit from a managed class
```
