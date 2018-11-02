---
title: Compilador aviso (nível 1) C4667
ms.date: 11/04/2016
f1_keywords:
- C4667
helpviewer_keywords:
- C4667
ms.assetid: 5d2b7fe0-4f0e-4cd6-b432-ca02c3d194ab
ms.openlocfilehash: 685cdc2577e1207360c793c82808919c39753f49
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50496535"
---
# <a name="compiler-warning-level-1-c4667"></a>Compilador aviso (nível 1) C4667

'function': nenhum template de função definido que corresponda à instanciação de forçada

Você não pode instanciar um modelo de função não foi declarado.

O exemplo a seguir fará com que C4667:

```
// C4667a.cpp
// compile with: /LD /W1
template
void max(const int &, const int &); // C4667 expected
```

Para evitar esse aviso, primeiro declare o modelo de função:

```
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