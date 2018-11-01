---
title: Erro do compilador C3156
ms.date: 11/04/2016
f1_keywords:
- C3156
helpviewer_keywords:
- C3156
ms.assetid: 1876da78-b94e-4af7-9795-28f72b209b3e
ms.openlocfilehash: 115e8cd63562964b19e4a67f7a649ecfab2596c1
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50465254"
---
# <a name="compiler-error-c3156"></a>Erro do compilador C3156

'class': você não pode ter uma definição de local de um ou um tipo de WinRT

Uma função não pode conter a definição ou declaração de gerenciada ou WinRT class, struct ou interface.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3156.

```
// C3156.cpp
// compile with: /clr /c
void f() {
   ref class X {};   // C3156
   ref class Y;   // C3156
}
```
