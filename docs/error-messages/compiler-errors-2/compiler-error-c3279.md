---
title: Erro do compilador C3279
ms.date: 11/04/2016
f1_keywords:
- C3279
helpviewer_keywords:
- C3279
ms.assetid: 639afc20-984c-4a95-be35-8bf9409f02d5
ms.openlocfilehash: 5f39510ee9ec0e717d675aa8b396405bc33b4ea1
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50445000"
---
# <a name="compiler-error-c3279"></a>Erro do compilador C3279

especializações parciais e explícitas, bem como instanciações explícitas de modelos de classe declaradas no namespace cli não são permitidas

O `cli` namespace é definida pela Microsoft e contém modelos de pseudo. O compilador do Visual C++ não permite especializações definidas pelo usuário, parciais e explícitas e instanciações explícitas de modelos de classe neste namespace.

O exemplo a seguir gera C3279:

```
// C3279.cpp
// compile with: /clr
namespace cli {
   template <> ref class array<int> {};   // C3279
   template <typename T> ref class array<T, 2> {};   // C3279
}
```