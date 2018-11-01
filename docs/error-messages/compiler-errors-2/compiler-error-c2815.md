---
title: Erro do compilador C2815
ms.date: 11/04/2016
f1_keywords:
- C2815
helpviewer_keywords:
- C2815
ms.assetid: d0256fd6-0721-4c99-b03c-52d96e77a613
ms.openlocfilehash: ab6708e7ae0a56bd71adebad4fb42d6ea9abe116
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50432650"
---
# <a name="compiler-error-c2815"></a>Erro do compilador C2815

'operator delete': primeiro parâmetro formal deve ser ' void *', mas 'param' foi usada

Qualquer definidos pelo usuário [operador delete](../../standard-library/new-operators.md#op_delete) função deve conter um primeiro parâmetro formal do tipo `void *`.

O exemplo a seguir gera C2815:

```
// C2815.cpp
// compile with: /c
class CMyClass {
public:
   void mf1(int *a);
   void operator delete(CMyClass *);   // C2815
   void operator delete(void *);
};
```