---
title: Erro do compilador C3395
ms.date: 11/04/2016
f1_keywords:
- C3395
helpviewer_keywords:
- C3395
ms.assetid: 26a9ebc9-ed97-47ce-b436-19aa2bcf6e50
ms.openlocfilehash: 2e5234abcbe46e17035fd0b16e9816c879d86cfe
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50604097"
---
# <a name="compiler-error-c3395"></a>Erro do compilador C3395

'function': dllexport não pode ser aplicado a uma função com o \__clrcall convenção de chamada

`__declspec(dllexport)` e [clrcall](../../cpp/clrcall.md) não são compatíveis.  Para obter mais informações, consulte [dllexport, dllimport](../../cpp/dllexport-dllimport.md).

O exemplo a seguir gera C3395:

```
// C3395.cpp
// compile with: /clr /c

__declspec(dllexport) void __clrcall Test(){}   // C3395
void __clrcall Test2(){}   // OK
__declspec(dllexport) void Test3(){}   // OK
```