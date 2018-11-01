---
title: Erro do compilador C3895
ms.date: 11/04/2016
f1_keywords:
- C3895
helpviewer_keywords:
- C3895
ms.assetid: 771b9fe5-d6d4-4297-bf57-e2f857722155
ms.openlocfilehash: 61dd280caa3c8c9b28dd77ecab2ed50ab9532d4b
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50501277"
---
# <a name="compiler-error-c3895"></a>Erro do compilador C3895

'var': membros de dados de tipo não podem ser 'volatile'

Determinados tipos de membros de dados, por exemplo [literal](../../windows/literal-cpp-component-extensions.md) ou [initonly](../../dotnet/initonly-cpp-cli.md), não pode ser [volátil](../../cpp/volatile-cpp.md).

O exemplo a seguir gera C3895:

```
// C3895.cpp
// compile with: /clr
ref struct Y1 {
   initonly
   volatile int data_var2;   // C3895
};
```