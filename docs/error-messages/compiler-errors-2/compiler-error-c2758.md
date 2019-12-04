---
title: Erro do compilador C2758
ms.date: 11/04/2016
f1_keywords:
- C2758
helpviewer_keywords:
- C2758
ms.assetid: 1d273034-194c-4926-9869-142d1b219cbe
ms.openlocfilehash: c854aeff1c57b8be6b445bc3615008519ca00af7
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74759510"
---
# <a name="compiler-error-c2758"></a>Erro do compilador C2758

' member ': um membro de tipo de referência deve ser inicializado

Erro do compilador C2758 é causado quando o construtor não inicializa um membro do tipo de referência em uma lista de inicializadores. O compilador deixa o membro indefinido. Variáveis de membro de referência devem ser inicializadas quando declaradas ou receber um valor na lista de inicialização do construtor.

O exemplo a seguir gera C2758:

```cpp
// C2758.cpp
// Compile by using: cl /W3 /c C2758.cpp
struct A {
   const int i;

   A(int n) { };   // C2758
   // try the following line instead
   // A(int n) : i{n} {};
};
```
