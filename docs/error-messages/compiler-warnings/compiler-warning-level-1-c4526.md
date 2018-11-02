---
title: Compilador aviso (nível 1) C4526
ms.date: 11/04/2016
f1_keywords:
- C4526
helpviewer_keywords:
- C4526
ms.assetid: 490f8916-5fdc-4cad-b412-76c3382a5976
ms.openlocfilehash: 892e6c37e54a868be48ced35354a1096aa7bf9d3
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50536695"
---
# <a name="compiler-warning-level-1-c4526"></a>Compilador aviso (nível 1) C4526

'function': função de membro estático não pode substituir função virtual ' virtual function'override ignorada, função virtual será ocultada

A função membro estática atende aos critérios para substituir a função virtual, o que torna a função membro virtual e estáticos.

O código a seguir gera C4526:

```
// C4526.cpp
// compile with: /W1 /c
// C4526 expected
struct myStruct1 {
   virtual void __stdcall func( int ) = 0;
};

struct myStruct2: public myStruct1 {
   static void __stdcall func( int );
};
```

Estas são as possíveis correções:

- Se a função foi se destina a substituir a função de classe base virtual, remova o especificador estático.

- Se a função foi destinada a ser uma função de membro estático, renomeie-o para que ele não entra em conflito com a função de classe base virtual.