---
title: Erro do compilador C3641
ms.date: 11/04/2016
f1_keywords:
- C3641
helpviewer_keywords:
- C3641
ms.assetid: e8d3613e-5e8d-46fe-a516-eb7d1de7cd21
ms.openlocfilehash: 44356fb1a1818a02102d23e6b308457f2f39506b
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80200506"
---
# <a name="compiler-error-c3641"></a>Erro do compilador C3641

> '*Function*': Convenção de chamada inválida ' calling_convention ' para função compilada com/CLR: pure ou/CLR: safe

## <a name="remarks"></a>Comentários

As opções de compilador **/CLR: Pure** e **/CLR: safe** são preteridas no Visual Studio 2015 e sem suporte no Visual Studio 2017.

Somente [__clrcall](../../cpp/clrcall.md) Convenção de chamada é permitida com [/CLR: Pure](../../build/reference/clr-common-language-runtime-compilation.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3641:

```cpp
// C3641.cpp
// compile with: /clr:pure /c
void __cdecl f() {}   // C3641
```
