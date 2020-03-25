---
title: Aviso do compilador (nível 4) C4234
ms.date: 11/04/2016
f1_keywords:
- C4234
helpviewer_keywords:
- C4234
ms.assetid: f7fecd5c-8248-4fde-8446-502aedc357ca
ms.openlocfilehash: c27f16f7d2933ca1860b304afa6e04f96f0687f0
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80173901"
---
# <a name="compiler-warning-level-4-c4234"></a>Aviso do compilador (nível 4) C4234

extensão não padrão usada: palavra-chave ' keyword ' reservada para uso futuro

O compilador ainda não implementou a palavra-chave usada.

Esse aviso é promovido automaticamente para um erro. Se você quiser modificar esse comportamento, use [#pragma Aviso](../../preprocessor/warning.md). Por exemplo, para tornar o C4234 em um problema de aviso de nível 4,

```cpp
#pragma warning(2:4234)
```

no arquivo de código-fonte.
