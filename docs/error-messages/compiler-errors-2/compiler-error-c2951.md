---
title: Erro do compilador C2951
ms.date: 11/04/2016
f1_keywords:
- C2951
helpviewer_keywords:
- C2951
ms.assetid: c6f95aa2-c894-425b-a51c-d40d70c8daa1
ms.openlocfilehash: dbc7186edfce6cc12a38fb2fc1dda08ac4a181c7
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50638692"
---
# <a name="compiler-error-c2951"></a>Erro do compilador C2951

declarações de tipo são permitidas apenas em um namespace global, ou escopo de classe

Você não pode declarar um genérico ou escopo de namespace ou classe de modelo global externo. Se você tornar suas declarações genérico ou modelo em um arquivo de inclusão, verifique se o arquivo de inclusão está no escopo global.

O exemplo a seguir gera C2951:

```
// C2951.cpp
template <class T>
class A {};

int main() {
   template <class T>   // C2951
   class B {};
}
```

C2951 também podem ocorrer ao usar genéricos:

```
// C2951b.cpp
// compile with: /clr /c

// OK
generic <class T>
ref class GC { };

int main() {
   generic <class T> ref class GC2 {};   // C2951
}
```