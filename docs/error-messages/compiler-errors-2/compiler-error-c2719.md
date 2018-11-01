---
title: Erro do compilador C2719
ms.date: 11/04/2016
f1_keywords:
- C2719
helpviewer_keywords:
- C2719
ms.assetid: ea6236d3-8286-45cc-9478-c84ad3dd3c8e
ms.openlocfilehash: d635601fbf8b36218fb47c09444f3f5d023c823e
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50653109"
---
# <a name="compiler-error-c2719"></a>Erro do compilador C2719

'parameter': parâmetro formal com __declspec(align('#')) não será alinhado

O [alinhar](../../cpp/align-cpp.md) `__declspec` modificador não é permitido em parâmetros de função. Alinhamento de parâmetro de função é controlado pela convenção de chamada usada. Para obter mais informações, consulte [convenções de chamada](../../cpp/calling-conventions.md).

O exemplo a seguir gera C2719 e mostra como corrigi-lo:

```
// C2719.cpp
void func(int __declspec(align(32)) i);   // C2719
// try the following line instead
// void func(int i);
```