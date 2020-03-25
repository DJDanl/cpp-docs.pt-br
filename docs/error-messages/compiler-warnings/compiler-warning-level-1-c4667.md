---
title: Aviso do compilador (nível 1) C4667
ms.date: 11/04/2016
f1_keywords:
- C4667
helpviewer_keywords:
- C4667
ms.assetid: 5d2b7fe0-4f0e-4cd6-b432-ca02c3d194ab
ms.openlocfilehash: d306172dcc9904b2d0a32ce5fc6d85d35d6d74cc
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80199427"
---
# <a name="compiler-warning-level-1-c4667"></a>Aviso do compilador (nível 1) C4667

' function ': nenhum modelo de função definido que corresponda à instanciação forçada

Não é possível criar uma instância de um modelo de função que não tenha sido declarado.

O exemplo a seguir causará C4667:

```cpp
// C4667a.cpp
// compile with: /LD /W1
template
void max(const int &, const int &); // C4667 expected
```

Para evitar esse aviso, primeiro declare o modelo de função:

```cpp
// C4667b.cpp
// compile with: /LD
// Declare the function template
template<typename T>
const T &max(const T &a, const T &b) {
   return (a > b) ? a : b;
}
// Then forcibly instantiate it with a desired type ... i.e. 'int'
//
template
const int &max(const int &, const int &);
```
