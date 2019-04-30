---
title: Erro do compilador C2388
ms.date: 11/04/2016
f1_keywords:
- C2388
helpviewer_keywords:
- C2388
ms.assetid: 764ad2d7-cb04-425f-ba30-70989488c4a4
ms.openlocfilehash: 62afcb1fafc19d3d61a86f2fbc10cb99e095afc5
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62393656"
---
# <a name="compiler-error-c2388"></a>Erro do compilador C2388

'symbol': um símbolo não pode ser declarado com ambos os __declspec(appdomain) e \__declspec(process)

O `appdomain` e `process` `__declspec` modificadores não podem ser usados no mesmo símbolo. O armazenamento para uma variável existe por processo ou por domínio de aplicativo.

Para obter mais informações, consulte [appdomain](../../cpp/appdomain.md) e [processo](../../cpp/process.md).

O exemplo a seguir gera C2388:

```
// C2388.cpp
// compile with: /clr /c
__declspec(process) __declspec(appdomain) int i;   // C2388
__declspec(appdomain) int i;   // OK
```