---
title: Erro do compilador C3279
ms.date: 11/04/2016
f1_keywords:
- C3279
helpviewer_keywords:
- C3279
ms.assetid: 639afc20-984c-4a95-be35-8bf9409f02d5
ms.openlocfilehash: 3025dbf7c6bf4701218c2d9a956cae26d7180848
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74757599"
---
# <a name="compiler-error-c3279"></a>Erro do compilador C3279

especializações parciais e explícitas, bem como instanciações explícitas de modelos de classe declarados no namespace CLI, não são permitidas

O namespace `cli` é definido pela Microsoft e contém os pseudo modelos. O compilador C++ da Microsoft não permite especializações explícitas, parciais e explícitas, e instanciações explicitas de modelos de classe neste namespace.

O exemplo a seguir gera C3279:

```cpp
// C3279.cpp
// compile with: /clr
namespace cli {
   template <> ref class array<int> {};   // C3279
   template <typename T> ref class array<T, 2> {};   // C3279
}
```
