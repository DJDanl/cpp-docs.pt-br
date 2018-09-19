---
title: Erro do compilador C2500 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2500
dev_langs:
- C++
helpviewer_keywords:
- C2500
ms.assetid: 6bff8161-dc9a-48ca-91f1-fd2eefdbbc93
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 9b7e24ca520796b63171fe63c2bf841fe8776845
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46026661"
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