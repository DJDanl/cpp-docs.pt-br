---
title: Erro do compilador C2523
ms.date: 11/04/2016
f1_keywords:
- C2523
helpviewer_keywords:
- C2523
ms.assetid: 7951b700-8f37-45a0-beb4-a79ae0ced72e
ms.openlocfilehash: 88a55a469fb8bc08d2ae73209c2e98a99dbc1df0
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62282190"
---
# <a name="compiler-error-c2523"></a>Erro do compilador C2523

' classe:: ~ identificador ': incompatibilidade de marca de destruidor/finalizador

O nome do destruidor deve ser o nome da classe precedido por um til (`~`). O construtor e destruidor são os únicos membros que têm o mesmo nome que a classe.

O exemplo a seguir gera C2523:

```
// C2523.cpp
// compile with: /c
class A {
   ~B();    // C2523
   ~A();   // OK
};
```