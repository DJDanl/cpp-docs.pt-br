---
title: Erro do compilador C2523
ms.date: 11/04/2016
f1_keywords:
- C2523
helpviewer_keywords:
- C2523
ms.assetid: 7951b700-8f37-45a0-beb4-a79ae0ced72e
ms.openlocfilehash: 56b0f88949d7a7fa5af945ab5d03ee9a480d6d3f
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74746416"
---
# <a name="compiler-error-c2523"></a>Erro do compilador C2523

' classe:: ~ identificador ': incompatibilidade de marca de destruidor/finalizador

O nome do destruidor deve ser o nome da classe precedido por um til (`~`). O construtor e o destruidor são os únicos membros que têm o mesmo nome que a classe.

O exemplo a seguir gera C2523:

```cpp
// C2523.cpp
// compile with: /c
class A {
   ~B();    // C2523
   ~A();   // OK
};
```
