---
title: Compilador aviso (nível 1) C4581
ms.date: 11/04/2016
f1_keywords:
- C4581
helpviewer_keywords:
- C4581
ms.assetid: 598bcd87-257d-4eb3-94e4-15bb31aadc99
ms.openlocfilehash: 9e370bcff0c30fb508ebc22aaff1f6a56dd420a1
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62397263"
---
# <a name="compiler-warning-level-1-c4581"></a>Compilador aviso (nível 1) C4581

comportamento preterido: '"string1" ' substituído por string2 para processar atributo

Esse erro pode ser gerado como resultado do trabalho de conformidade do compilador que foi feito para o Visual C++ 2005: parâmetros de verificação para os atributos do Visual C++.

Nas versões anteriores, os valores de atributo foram aceitos se eles foram colocados entre aspas. Se o valor é uma enumeração, não devem ser colocado entre aspas.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4581.

```
// C4581.cpp
// compile with: /c /W1
#include "unknwn.h"
[object, uuid("00000000-0000-0000-0000-000000000001")]
__interface IMyI : IUnknown {};

[coclass, uuid(12345678-1111-2222-3333-123456789012), threading("free")]   // C4581
// try the following line instead
// [coclass, uuid(12345678-1111-2222-3333-123456789012), threading(free)]
class CSample : public IMyI {};
```