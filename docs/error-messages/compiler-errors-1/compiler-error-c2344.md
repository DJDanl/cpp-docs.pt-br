---
title: Erro do compilador C2344
ms.date: 11/04/2016
f1_keywords:
- C2344
helpviewer_keywords:
- C2344
ms.assetid: a84c7b37-c84e-4345-8691-c23abb2dc193
ms.openlocfilehash: d1ba3a0f975dbc96c9c6ca51a8dac89b5a614572
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62188166"
---
# <a name="compiler-error-c2344"></a>Erro do compilador C2344

align(#): alinhamento deve ser uma potência de dois

Ao usar o [alinhar](../../cpp/align-cpp.md) palavra-chave, o valor que você passe deve ser uma potência de dois.

Por exemplo, o código a seguir gera C2344 porque 3 não é uma potência de dois:

```
// C2344.cpp
// compile with: /c
__declspec(align(3)) int a;   // C2344
__declspec(align(4)) int b;   // OK
```