---
title: Aviso do compilador (nível 4) C4234
ms.date: 11/04/2016
f1_keywords:
- C4234
helpviewer_keywords:
- C4234
ms.assetid: f7fecd5c-8248-4fde-8446-502aedc357ca
ms.openlocfilehash: 63a22fed0832677837eb786268fc92946d295b79
ms.sourcegitcommit: 3ee06ec53153cf21910fc8cfef78a4f25f9633f3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/26/2019
ms.locfileid: "74541769"
---
# <a name="compiler-warning-level-4-c4234"></a>Aviso do compilador (nível 4) C4234

extensão não padrão usada: palavra-chave ' keyword ' reservada para uso futuro

O compilador ainda não implementou a palavra-chave usada.

Esse aviso é promovido automaticamente para um erro. Se você quiser modificar esse comportamento, use [#pragma Aviso](../../preprocessor/warning.md). Por exemplo, para tornar o C4234 em um problema de aviso de nível 4,

```cpp
#pragma warning(2:4234)
```

no arquivo de código-fonte.