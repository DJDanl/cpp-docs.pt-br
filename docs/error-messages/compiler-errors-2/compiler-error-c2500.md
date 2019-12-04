---
title: Erro do compilador C2500
ms.date: 11/04/2016
f1_keywords:
- C2500
helpviewer_keywords:
- C2500
ms.assetid: 6bff8161-dc9a-48ca-91f1-fd2eefdbbc93
ms.openlocfilehash: 152546fce8f3ee63f8b95595bff052f18cd4ebda
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74746962"
---
# <a name="compiler-error-c2500"></a>Erro do compilador C2500

' identifier1 ': ' identifier2 ' já é uma classe base direta

Uma classe ou estrutura aparece mais de uma vez em uma lista de classes base.

Uma base direta é uma mencionada na lista de base. Uma base indireta é uma classe base de uma das classes na lista de base.

Uma classe não pode ser especificada como uma classe base direta mais de uma vez. Uma classe pode ser usada como uma classe base indireta mais de uma vez.

O exemplo a seguir gera C2500:

```cpp
// C2500.cpp
// compile with: /c
class A {};
class B : public A, public A {};    // C2500

// OK
class C : public A {};
class D : public A {};
class E : public C, public D {};
```
