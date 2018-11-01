---
title: Erro do compilador C2208
ms.date: 11/04/2016
f1_keywords:
- C2208
helpviewer_keywords:
- C2208
ms.assetid: 9ae704bc-bf70-45f1-8e47-0470f21edd4e
ms.openlocfilehash: 7970ba5d8d2b19bd6e330fad1879880fc5cbf32d
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50516931"
---
# <a name="compiler-error-c2208"></a>Erro do compilador C2208

'type': nenhum membro definido usando esse tipo

Um identificador de resolução para um nome de tipo é em uma declaração de agregação, mas o compilador não pode declarar um membro.

O exemplo a seguir gera C2208:

```
// C2208.cpp
class C {
   C;   // C2208
   C(){}   // OK
};
```