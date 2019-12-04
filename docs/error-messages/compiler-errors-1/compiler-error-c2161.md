---
title: Erro do compilador C2161
ms.date: 11/04/2016
f1_keywords:
- C2161
helpviewer_keywords:
- C2161
ms.assetid: d6798821-13bb-4e60-924f-85f7bf955387
ms.openlocfilehash: dd75fb4ba035f21a71fff1f345c0c397415bc0ec
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74758418"
---
# <a name="compiler-error-c2161"></a>Erro do compilador C2161

' # # ' não pode ocorrer no final de uma definição de macro

Uma definição de macro terminou com um operador de colagem de tokens (# #).

O exemplo a seguir gera C2161:

```cpp
// C2161.cpp
// compile with: /c
#define mac(a,b) a   // OK
#define mac(a,b) a##   // C2161
```
