---
title: Aviso do compilador (nível 1) C4096
ms.date: 11/04/2016
f1_keywords:
- C4096
helpviewer_keywords:
- C4096
ms.assetid: abf3cca2-2f21-45d8-b025-6b513b00681e
ms.openlocfilehash: 8f526b26eda4c02825d225aa007c6029cc4b03dd
ms.sourcegitcommit: 0cfc43f90a6cc8b97b24c42efcf5fb9c18762a42
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/05/2019
ms.locfileid: "73627073"
---
# <a name="compiler-warning-level-1-c4096"></a>Aviso do compilador (nível 1) C4096

' a ': a interface não é uma interface COM; Não será emitido para IDL

Uma definição de interface que você pode ter pretendido como uma interface COM não foi definida como uma interface COM e, portanto, não será emitida para o arquivo IDL.

Consulte [atributos de interface](../../windows/attributes/interface-attributes.md) para obter uma lista de atributos que indicam que uma interface é uma interface com.

O exemplo a seguir gera C4096:

```cpp
// C4096.cpp
// compile with: /W1 /LD
#include "windows.h"
[module(name="xx")];

// [object, uuid("00000000-0000-0000-0000-000000000001")]
__interface a
{
};

[coclass, uuid("00000000-0000-0000-0000-000000000002")]
struct b : a
{
};   // C4096, remove coclass or uncomment object
```