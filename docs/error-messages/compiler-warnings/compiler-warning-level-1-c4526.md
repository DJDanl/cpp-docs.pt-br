---
title: Compilador aviso (nível 1) C4526 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4526
dev_langs:
- C++
helpviewer_keywords:
- C4526
ms.assetid: 490f8916-5fdc-4cad-b412-76c3382a5976
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 2ed6f2da3252c27b7a84b4d5b73f7e8ba52823dd
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46118499"
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