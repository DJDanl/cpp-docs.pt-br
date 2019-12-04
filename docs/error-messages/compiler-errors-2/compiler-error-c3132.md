---
title: Erro do compilador C3132
ms.date: 11/04/2016
f1_keywords:
- C3132
helpviewer_keywords:
- C3132
ms.assetid: d54a3d12-336a-4ed0-ad4e-43cddac33b5e
ms.openlocfilehash: d3ef68e693b77b72c1e4cc2590a404b09b38ab04
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74760199"
---
# <a name="compiler-error-c3132"></a>Erro do compilador C3132

' função-parâmetro ': matrizes de parâmetros só podem ser aplicadas a um argumento formal do tipo ' matriz gerenciada unidimensional '

O atributo <xref:System.ParamArrayAttribute> foi aplicado a um parâmetro que não era uma matriz de dimensão única.

O exemplo a seguir gera C3132:

```cpp
// C3132.cpp
// compile with: /clr /c
using namespace System;
void f( [ParamArray] Int32[,] );   // C3132
void g( [ParamArray] Int32[] );   // C3132

void h( [ParamArray] array<Char ^> ^ MyArray );   // OK
```
