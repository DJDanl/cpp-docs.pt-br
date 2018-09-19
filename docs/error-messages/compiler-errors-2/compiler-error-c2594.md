---
title: Erro do compilador C2594 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2594
dev_langs:
- C++
helpviewer_keywords:
- C2594
ms.assetid: 68cd708f-266e-44b0-a211-3e3ab63b11bf
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 9be22544930bb94c36ec5906cbf60d5caac143fe
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46057999"
---
# <a name="compiler-error-c2594"></a>Erro do compilador C2594

'operator': conversões ambíguas de 'type1' em 'type2'

Nenhuma conversão de *type1* à *type2* foi mais direta do que qualquer outro. Sugerimos duas soluções possíveis para converter do *type1* à *type2*. A primeira opção é definir uma conversão direta do *type1* à *type2*, e a segunda opção é especificar uma sequência de conversões de *type1* para  *type2*.

O exemplo a seguir gera C2594. A resolução sugerida para o erro é uma sequência de conversões:

```
// C2594.cpp
// compile with: /c
struct A{};
struct I1 : A {};
struct I2 : A {};
struct D : I1, I2 {};

A *f (D *p) {
   return (A*) (p);    // C2594

// try the following line instead
// return static_cast<A *>(static_cast<I1 *>(p));
}
```