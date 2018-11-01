---
title: Compilador aviso (nível 4) C4690
ms.date: 07/03/2018
f1_keywords:
- C4690
helpviewer_keywords:
- C4690
ms.assetid: 080a0ea1-458b-477b-a37a-4a34c94709ff
ms.openlocfilehash: c7facdde54b44ba2ce07db0447b251d7014f76c8
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50518476"
---
# <a name="compiler-warning-level-4-c4690"></a>Compilador aviso (nível 4) C4690

> \[ emitidl (pop)]: mais ativações do que envios por push

## <a name="remarks"></a>Comentários

O [emitidl](../../windows/emitidl.md) atributo foi aparecido mais uma vez que ela foi enviada por push.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4690. Para corrigir esse problema, verifique se que o atributo é aparecido exatamente como quantas vezes ela é enviada por push.

```cpp
// C4690.cpp
// compile with: /c /W4
[emitidl(pop)];   // C4690
class x {};
```
