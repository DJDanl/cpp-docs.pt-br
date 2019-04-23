---
title: Erro do compilador C3215
ms.date: 11/04/2016
f1_keywords:
- C3215
helpviewer_keywords:
- C3215
ms.assetid: d0d16007-8885-42e0-b086-2d3a61f348c5
ms.openlocfilehash: 24f17d2990c9258168a6d37fef101c21f62cb08d
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "59778716"
---
# <a name="compiler-error-c3215"></a>Erro do compilador C3215

'type1': parâmetro de tipo genérico já restringido por 'type2'

Uma restrição foi especificada mais de uma vez.

Para obter mais informações sobre os genéricos, consulte [genéricos](../../extensions/generics-cpp-component-extensions.md).

O exemplo a seguir gera C3215:

```
// C3215.cpp
// compile with: /clr
interface struct A {};

generic <class T>
where T : A,A
ref class C {};   // C3215
```

Solução possível:

```
// C3215b.cpp
// compile with: /clr /c
interface struct A {};

generic <class T>
where T : A
ref class C {};
```