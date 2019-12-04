---
title: Erro do compilador C2531
ms.date: 11/04/2016
f1_keywords:
- C2531
helpviewer_keywords:
- C2531
ms.assetid: c49afe15-55f8-4dc8-ac01-bf653622a7db
ms.openlocfilehash: 4247e026f6680adab45ceebe2b395ad781ccfc7e
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74737108"
---
# <a name="compiler-error-c2531"></a>Erro do compilador C2531

' identifier ': referência a um campo de bits inválida

Referências a campos de bits não são permitidas.

O exemplo a seguir gera C2531:

```cpp
// C2531.cpp
// compile with: /c
class P {
   int &b1 : 10;   // C2531
   int b2 : 10;   // OK
};
```
