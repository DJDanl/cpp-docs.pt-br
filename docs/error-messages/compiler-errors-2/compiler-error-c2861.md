---
title: Erro do compilador C2861
ms.date: 11/04/2016
f1_keywords:
- C2861
helpviewer_keywords:
- C2861
ms.assetid: 012bb44d-6c9b-4def-b54e-b19f1f8ddd1b
ms.openlocfilehash: 3d6cab186d4acf229a32620f33c9c86e807459dd
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74751983"
---
# <a name="compiler-error-c2861"></a>Erro do compilador C2861

' nome da função ': uma função de membro de interface não pode ser definida

O compilador encontrou a palavra-chave de interface ou deduziu uma struct como uma interface, mas, em seguida, encontrou uma definição de função de membro.  Uma interface não pode conter uma definição para uma função de membro.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2861:

```cpp
// C2861.cpp
// compile with: /c
#include <objbase.h>   // required for IUnknown definition
[ object, uuid("00000000-0000-0000-0000-000000000001") ]
__interface IMyInterface : IUnknown {
   HRESULT mf(int a);
};

HRESULT IMyInterface::mf(int a) {}   // C2861
```
