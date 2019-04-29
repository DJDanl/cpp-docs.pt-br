---
title: Erro do compilador C3857
ms.date: 11/04/2016
f1_keywords:
- C3857
helpviewer_keywords:
- C3857
ms.assetid: 9f746d1e-9708-4945-bc29-3150d5371d3c
ms.openlocfilehash: 1270d09c870bfdf9f390d6afb1625ad3e99e01a0
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62265432"
---
# <a name="compiler-error-c3857"></a>Erro do compilador C3857

'type': não são permitidas várias listas de parâmetros de tipo

Mais de um modelo ou genérico foi especificado para o mesmo tipo, que não é permitido.

O exemplo a seguir gera C3857:

```
// C3857.cpp
template <class T, class TT>
template <class T2>    // C3857
struct B {};
```

Solução possível:

```
// C3857b.cpp
// compile with: /c
template <class T, class TT, class T2>
struct B {};
```

C3857 também podem ocorrer ao usar genéricos:

```
// C3857c.cpp
// compile with: /clr
generic <typename T>
generic <typename U>
ref class GC;   // C3857
```

Solução possível:

```
// C3857d.cpp
// compile with: /clr /c
generic <typename U>
ref class GC;
```