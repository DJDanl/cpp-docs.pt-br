---
title: Erro do compilador C2344
ms.date: 11/04/2016
f1_keywords:
- C2344
helpviewer_keywords:
- C2344
ms.assetid: a84c7b37-c84e-4345-8691-c23abb2dc193
ms.openlocfilehash: 7aa1d5dfad67120556c9f4a1f69cf22dfca9acd2
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74760030"
---
# <a name="compiler-error-c2344"></a>Erro do compilador C2344

align (#): o alinhamento deve ser a potência de dois

Ao usar a palavra-chave [align](../../cpp/align-cpp.md) , o valor que você passa deve ser uma potência de dois.

Por exemplo, o código a seguir gera C2344 porque 3 não é uma potência de dois:

```cpp
// C2344.cpp
// compile with: /c
__declspec(align(3)) int a;   // C2344
__declspec(align(4)) int b;   // OK
```
