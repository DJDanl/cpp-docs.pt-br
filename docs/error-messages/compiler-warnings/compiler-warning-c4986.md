---
title: Aviso do compilador C4986
ms.date: 11/04/2016
f1_keywords:
- C4986
helpviewer_keywords:
- C4986
ms.assetid: a3a7b008-29dd-4203-85f3-7740ab6790bb
ms.openlocfilehash: fb52e33ceeadda03105e391d8e0b5b3f6234d6b9
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62280588"
---
# <a name="compiler-warning-c4986"></a>Aviso do compilador C4986

'function': especificação de exceção não corresponde à declaração anterior

Esse aviso pode ser gerado quando há uma especificação de exceção em uma declaração e não na outra.

Por padrão, C4986 está desativado. Para obter mais informações, consulte [compilador avisos que são desativado por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md).

## <a name="example"></a>Exemplo

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

## <a name="example"></a>Exemplo

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