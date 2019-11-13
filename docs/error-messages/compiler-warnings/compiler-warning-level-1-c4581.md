---
title: Aviso do compilador (nível 1) C4581
ms.date: 11/04/2016
f1_keywords:
- C4581
helpviewer_keywords:
- C4581
ms.assetid: 598bcd87-257d-4eb3-94e4-15bb31aadc99
ms.openlocfilehash: 5931516e3f4eba91c3b7a3ab4d0ca4979ce1ed84
ms.sourcegitcommit: e5192a25c084eda9eabfa37626f3274507e026b3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/12/2019
ms.locfileid: "73965918"
---
# <a name="compiler-warning-level-1-c4581"></a>Aviso do compilador (nível 1) C4581

comportamento preterido: ' "seqüência1" ' substituído por ' seqüência2 ' para processar atributo

Esse erro pode ser gerado como resultado do trabalho de conformidade do compilador que foi feito para o Visual Studio 2005: verificação de C++ parâmetros para atributos visuais.

Em versões anteriores, os valores de atributo foram aceitos, independentemente de eles terem sido colocados entre aspas. Se o valor for uma enumeração, ele não deverá ser colocado entre aspas.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4581.

```cpp
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