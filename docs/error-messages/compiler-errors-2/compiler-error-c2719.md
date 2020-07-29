---
title: Erro do compilador C2719
ms.date: 11/04/2016
f1_keywords:
- C2719
helpviewer_keywords:
- C2719
ms.assetid: ea6236d3-8286-45cc-9478-c84ad3dd3c8e
ms.openlocfilehash: a0a993069a0bd232154cf6c1b365c0828d9bede8
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87220243"
---
# <a name="compiler-error-c2719"></a>Erro do compilador C2719

' Parameter ': parâmetro formal com __declspec (align (' # ')) não será alinhado

O [align](../../cpp/align-cpp.md) **`__declspec`** modificador align não é permitido em parâmetros de função. O alinhamento do parâmetro de função é controlado pela Convenção de chamada usada. Para obter mais informações, consulte [convenções de chamada](../../cpp/calling-conventions.md).

O exemplo a seguir gera C2719 e mostra como corrigi-lo:

```cpp
// C2719.cpp
void func(int __declspec(align(32)) i);   // C2719
// try the following line instead
// void func(int i);
```
