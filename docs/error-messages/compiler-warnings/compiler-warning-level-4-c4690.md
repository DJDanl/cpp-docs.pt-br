---
title: Aviso do compilador (nível 4) C4690
ms.date: 07/03/2018
f1_keywords:
- C4690
helpviewer_keywords:
- C4690
ms.assetid: 080a0ea1-458b-477b-a37a-4a34c94709ff
ms.openlocfilehash: de996128c68ebf96b4a00f6206cbaf54d97ca275
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91509971"
---
# <a name="compiler-warning-level-4-c4690"></a>Aviso do compilador (nível 4) C4690

> \[ emitidl (pop)]: mais Pops do que envios

## <a name="remarks"></a>Comentários

O atributo [emitidl](../../windows/attributes/emitidl.md) foi retirado mais uma vez que foi enviado por push.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4690. Para corrigir esse problema, verifique se o atributo foi exibido exatamente quantas vezes forem enviados por push.

```cpp
// C4690.cpp
// compile with: /c /W4
[emitidl(pop)];   // C4690
class x {};
```
