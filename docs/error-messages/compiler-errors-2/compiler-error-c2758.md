---
title: Erro do compilador C2758 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2758
dev_langs:
- C++
helpviewer_keywords:
- C2758
ms.assetid: 1d273034-194c-4926-9869-142d1b219cbe
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 6ffa6d33dba70a463d789f3b0f016dc1d157eb65
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46072921"
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