---
title: Erro do compilador C2537
ms.date: 11/04/2016
f1_keywords:
- C2537
helpviewer_keywords:
- C2537
ms.assetid: aee81d8e-300e-4a8b-b6c4-b3828398b34e
ms.openlocfilehash: 0dfe9f88fcdfda1325150d480670777a4d42d896
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74758626"
---
# <a name="compiler-error-c2537"></a>Erro do compilador C2537

' especificador ': especificação de vínculo inválida

Possíveis causas:

1. Não há suporte para o especificador de ligação. Há suporte apenas para o especificador de vinculação "C".

1. A ligação "C" é especificada para mais de uma função em um conjunto de funções sobrecarregadas. Isso não é permitido.

O exemplo a seguir gera C2537:

```cpp
// C2537.cpp
// compile with: /c
extern "c" void func();   // C2537
extern "C" void func2();   // OK
```
