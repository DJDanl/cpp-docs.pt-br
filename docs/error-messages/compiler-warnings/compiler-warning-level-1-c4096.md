---
title: Aviso do compilador (nível 1) C4096
ms.date: 11/04/2016
f1_keywords:
- C4096
helpviewer_keywords:
- C4096
ms.assetid: abf3cca2-2f21-45d8-b025-6b513b00681e
ms.openlocfilehash: 4f5a45339673b57f946f206e1eaff0d23ec6fee9
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80163930"
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
