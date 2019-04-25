---
title: Erro do compilador C2500
ms.date: 11/04/2016
f1_keywords:
- C2500
helpviewer_keywords:
- C2500
ms.assetid: 6bff8161-dc9a-48ca-91f1-fd2eefdbbc93
ms.openlocfilehash: a5753fc99efcdb1064a21981c62faaba84d44189
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62165580"
---
# <a name="compiler-error-c2500"></a>Erro do compilador C2500

'identifier1': 'identifier2' já é uma classe base direta

Uma classe ou estrutura aparece mais de uma vez em uma lista de classes base.

Uma base direta é um mencionado na lista de base. Uma base indireta é uma classe base de uma das classes na lista base.

Uma classe não pode ser especificada como uma classe base direta de mais de uma vez. Uma classe pode ser usada como uma classe base indireta mais de uma vez.

O exemplo a seguir gera C2500:

```
// C2500.cpp
// compile with: /c
class A {};
class B : public A, public A {};    // C2500

// OK
class C : public A {};
class D : public A {};
class E : public C, public D {};
```