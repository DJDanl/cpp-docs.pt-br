---
title: Erro do compilador C2719
ms.date: 11/04/2016
f1_keywords:
- C2719
helpviewer_keywords:
- C2719
ms.assetid: ea6236d3-8286-45cc-9478-c84ad3dd3c8e
ms.openlocfilehash: 574a04923c20c3104083a6aa05a71838e7ec13d2
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74760498"
---
# <a name="compiler-error-c2719"></a>Erro do compilador C2719

' Parameter ': parâmetro formal com __declspec (align (' # ')) não será alinhado

O modificador [align](../../cpp/align-cpp.md) `__declspec` não é permitido em parâmetros de função. O alinhamento do parâmetro de função é controlado pela Convenção de chamada usada. Para obter mais informações, consulte [convenções de chamada](../../cpp/calling-conventions.md).

O exemplo a seguir gera C2719 e mostra como corrigi-lo:

```cpp
// C2719.cpp
void func(int __declspec(align(32)) i);   // C2719
// try the following line instead
// void func(int i);
```
