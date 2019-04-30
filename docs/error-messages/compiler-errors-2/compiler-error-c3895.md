---
title: Erro do compilador C3895
ms.date: 11/04/2016
f1_keywords:
- C3895
helpviewer_keywords:
- C3895
ms.assetid: 771b9fe5-d6d4-4297-bf57-e2f857722155
ms.openlocfilehash: c4b1cad9ef48f1f16b411aab46e1bb9285d69ff3
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62385531"
---
# <a name="compiler-error-c3895"></a>Erro do compilador C3895

'var': membros de dados de tipo não podem ser 'volatile'

Determinados tipos de membros de dados, por exemplo [literal](../../extensions/literal-cpp-component-extensions.md) ou [initonly](../../dotnet/initonly-cpp-cli.md), não pode ser [volátil](../../cpp/volatile-cpp.md).

O exemplo a seguir gera C3895:

```
// C3895.cpp
// compile with: /clr
ref struct Y1 {
   initonly
   volatile int data_var2;   // C3895
};
```