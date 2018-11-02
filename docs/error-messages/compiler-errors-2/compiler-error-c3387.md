---
title: Erro do compilador C3387
ms.date: 11/04/2016
f1_keywords:
- C3387
helpviewer_keywords:
- C3387
ms.assetid: c54d9925-ed14-4976-b8db-e8d4dc84e536
ms.openlocfilehash: bd783d9510b1699b33f108a4ce8d8c491028b758
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50541889"
---
# <a name="compiler-error-c3387"></a>Erro do compilador C3387

'member': dllexport /\__declspec(dllimport) não pode ser aplicado a um membro de um ou um tipo de WinRT

O `dllimport` e [dllexport](../../cpp/dllexport-dllimport.md) `__declspec` modificadores não são válidos em membros de um ou de tipo de tempo de execução do Windows.

O exemplo a seguir gera C3387 e mostra como corrigi-lo:

```
// C3387a.cpp
// compile with: /clr /c
ref class X2 {
   void __declspec(dllexport) mf() {   // C3387
   // try the following line instead
   // void mf() {
   }
};
```