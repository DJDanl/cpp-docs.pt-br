---
title: Aviso do compilador C4986
ms.date: 11/04/2016
f1_keywords:
- C4986
helpviewer_keywords:
- C4986
ms.assetid: a3a7b008-29dd-4203-85f3-7740ab6790bb
ms.openlocfilehash: ae782ea0a11bd72c867ea9532a62d0b14cd98453
ms.sourcegitcommit: c1fd917a8c06c6504f66f66315ff352d0c046700
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/16/2020
ms.locfileid: "90684386"
---
# <a name="compiler-warning-c4986"></a>Aviso do compilador C4986

' function ': a especificação de exceção não corresponde à declaração anterior

Esse aviso pode ser gerado quando há uma especificação de exceção em uma declaração e não na outra.

Por padrão, C4986 é off. Para obter mais informações, consulte [os avisos do compilador que estão desativados por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md).

## <a name="examples"></a>Exemplos

O exemplo a seguir gera C4986.

```cpp
class X { };
void f1() throw (X*);
// ...
void f1()
{
    // ...
}
```

O exemplo a seguir elimina esse aviso.

```cpp
class X { };
void f1() throw (X*);
// ...
void f1() throw (X*)
{
    // ...
}
```
