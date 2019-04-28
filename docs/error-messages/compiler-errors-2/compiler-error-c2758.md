---
title: Erro do compilador C2758
ms.date: 11/04/2016
f1_keywords:
- C2758
helpviewer_keywords:
- C2758
ms.assetid: 1d273034-194c-4926-9869-142d1b219cbe
ms.openlocfilehash: c3a86b8b8c7f122929a52221d4f01a17c50395be
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62257654"
---
# <a name="compiler-error-c2758"></a>Erro do compilador C2758

'member': um membro de tipo de referência deve ser inicializado

Erro do compilador C2758 é causado quando o construtor não inicializar um membro do tipo de referência em uma lista de inicializadores. O compilador deixa o membro indefinido. Membro de referência devem variáveis inicializado quando declarados ou receber um valor na lista de inicialização do construtor.

O exemplo a seguir gera C2758:

```
// C2758.cpp
// Compile by using: cl /W3 /c C2758.cpp
struct A {
   const int i;

   A(int n) { };   // C2758
   // try the following line instead
   // A(int n) : i{n} {};
};
```