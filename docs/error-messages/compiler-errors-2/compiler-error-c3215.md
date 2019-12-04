---
title: Erro do compilador C3215
ms.date: 11/04/2016
f1_keywords:
- C3215
helpviewer_keywords:
- C3215
ms.assetid: d0d16007-8885-42e0-b086-2d3a61f348c5
ms.openlocfilehash: 59d9eb0c28269e95b906042126cc3a9f25bba635
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74751905"
---
# <a name="compiler-error-c3215"></a>Erro do compilador C3215

' type1 ': parâmetro de tipo genérico já restringido por ' type2 '

Uma restrição foi especificada mais de uma vez.

Confira mais informações sobre genéricos em [Genéricos](../../extensions/generics-cpp-component-extensions.md).

O exemplo a seguir gera C3215:

```cpp
// C3215.cpp
// compile with: /clr
interface struct A {};

generic <class T>
where T : A,A
ref class C {};   // C3215
```

Resolução possível:

```cpp
// C3215b.cpp
// compile with: /clr /c
interface struct A {};

generic <class T>
where T : A
ref class C {};
```
