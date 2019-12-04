---
title: Erro do compilador C2951
ms.date: 11/04/2016
f1_keywords:
- C2951
helpviewer_keywords:
- C2951
ms.assetid: c6f95aa2-c894-425b-a51c-d40d70c8daa1
ms.openlocfilehash: fdb837f8e9a9b769d470b70b962ce63d144161e1
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74755974"
---
# <a name="compiler-error-c2951"></a>Erro do compilador C2951

declarações de tipo são permitidas somente em escopo global, de namespace ou de classe

Você não pode declarar uma classe genérica ou de modelo fora do escopo global ou de namespace. Se você fizer suas declarações genéricas ou de modelo em um arquivo de inclusão, verifique se o arquivo de inclusão está em escopo global.

O exemplo a seguir gera C2951:

```cpp
// C2951.cpp
template <class T>
class A {};

int main() {
   template <class T>   // C2951
   class B {};
}
```

C2951 também pode ocorrer ao usar genéricos:

```cpp
// C2951b.cpp
// compile with: /clr /c

// OK
generic <class T>
ref class GC { };

int main() {
   generic <class T> ref class GC2 {};   // C2951
}
```
