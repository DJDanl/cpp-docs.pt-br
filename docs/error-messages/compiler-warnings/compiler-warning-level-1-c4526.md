---
title: Aviso do compilador (nível 1) C4526
ms.date: 11/04/2016
f1_keywords:
- C4526
helpviewer_keywords:
- C4526
ms.assetid: 490f8916-5fdc-4cad-b412-76c3382a5976
ms.openlocfilehash: d4d772f3e505979a6ea5c3e7923fefa621601370
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80186498"
---
# <a name="compiler-warning-level-1-c4526"></a>Aviso do compilador (nível 1) C4526

' function ': a função de membro static não pode substituir a função virtual ' virtual function'override ignorada, a função virtual ficará oculta

A função de membro estático atende aos critérios para substituir a função virtual, o que torna a função de membro virtual e estática.

O código a seguir gera C4526:

```cpp
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

As seguintes correções são possíveis:

- Se a função foi destinada a substituir a função virtual da classe base, remova o especificador estático.

- Se a função foi destinada a ser uma função membro estática, renomeie-a para que ela não entre em conflito com a função virtual da classe base.
