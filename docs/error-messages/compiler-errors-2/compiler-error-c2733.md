---
title: Erro do compilador C2733
ms.date: 11/04/2016
f1_keywords:
- C2733
helpviewer_keywords:
- C2733
ms.assetid: 67f83561-c633-407c-a2ee-f9fd16e165bf
ms.openlocfilehash: 26819f1928223b5fa96d275290105f32787057f5
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50518840"
---
# <a name="compiler-error-c2733"></a>Erro do compilador C2733

segundo vínculo a C de função sobrecarregada 'function' não permitido

Mais de uma função sobrecarregada foi declarada com vinculação C. Ao usar a ligação de C, apenas uma forma de uma função especificada pode ser externa. Como funções sobrecarregadas têm o mesmo nome não decorado, não pode ser usados com programas em C.

O exemplo a seguir gera C2733:

```
// C2733.cpp
extern "C" {
   void F1(int);
}

extern "C" {
   void F1();   // C2733
   // try the following line instead
   // void F2();
}
```