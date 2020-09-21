---
title: Erro do compilador C2092
ms.date: 11/04/2016
f1_keywords:
- C2092
helpviewer_keywords:
- C2092
ms.assetid: 037e44ae-16c8-489a-a512-dcdf7f7795a6
ms.openlocfilehash: 8f2b83b4099308ea1d0bb127d8cea377ab65da96
ms.sourcegitcommit: 72161bcd21d1ad9cc3f12261aa84a5b026884afa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2020
ms.locfileid: "90741885"
---
# <a name="compiler-error-c2092"></a>Erro do compilador C2092

o tipo de elemento de matriz ' nome da matriz ' não pode ser função

Não são permitidas matrizes de funções. Use uma matriz de ponteiros para o functions.

## <a name="examples"></a>Exemplos

O exemplo a seguir gera C2092:

```cpp
// C2092.cpp
typedef void (F) ();
typedef F AT[10];   // C2092
```

Resolução possível:

```cpp
// C2092b.cpp
// compile with: /c
typedef void (F) ();
typedef F * AT[10];
```
