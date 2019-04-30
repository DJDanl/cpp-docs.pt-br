---
title: Aviso (nível 4) do compilador C4400
ms.date: 11/04/2016
f1_keywords:
- C4400
helpviewer_keywords:
- C4400
ms.assetid: f135fe98-4f92-4e07-9d71-2621b36ee755
ms.openlocfilehash: 61a6d3090355c9bda8aa11c041b302e4ec77ec8d
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62391537"
---
# <a name="compiler-warning-level-4-c4400"></a>Aviso (nível 4) do compilador C4400

'type': não há suporte para qualificadores const/volatile neste tipo

O [const](../../cpp/const-cpp.md)e [volátil](../../cpp/volatile-cpp.md)qualificadores não funcionará com variáveis de tipos common language runtime.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4400.

```
// C4400.cpp
// compile with: /clr /W4
// C4401 expected
using namespace System;
#pragma warning (disable : 4101)
int main() {
   const String^ str;   // C4400
   volatile String^ str2;   // C4400
}
```