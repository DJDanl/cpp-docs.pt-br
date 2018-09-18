---
title: Erro do compilador C2723 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2723
dev_langs:
- C++
helpviewer_keywords:
- C2723
ms.assetid: 86925601-2297-4cfd-94e2-2caf27c474c4
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 2b1be2d81ecec7eb96fd9c1cd7e9938ce509f71e
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46072011"
---
# <a name="compiler-error-c2723"></a>Erro do compilador C2723

'function': especificador de 'especificador' inválido em definição de função

O especificador não pode aparecer com uma definição de função fora de uma declaração de classe. O `virtual` especificador pode ser especificada somente em uma declaração de função de membro dentro de uma declaração de classe.

O exemplo a seguir gera C2723 e mostra como corrigi-lo:

```
// C2723.cpp
struct X {
   virtual void f();
   virtual void g();
};

virtual void X::f() {}   // C2723

// try the following line instead
void X::g() {}
```