---
title: Compilador aviso (nível 4) C4234
ms.date: 11/04/2016
f1_keywords:
- C4234
helpviewer_keywords:
- C4234
ms.assetid: f7fecd5c-8248-4fde-8446-502aedc357ca
ms.openlocfilehash: 314ee068fb2be6148304360b0aaa3bd8029c283b
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62401066"
---
# <a name="compiler-warning-level-4-c4234"></a>Compilador aviso (nível 4) C4234

extensão não padrão usada: palavra-chave de 'palavra-chave' reservada para uso futuro

O compilador ainda não implementa a palavra-chave que você usou.

Esse aviso é promovido automaticamente a um erro. Se você quiser modificar esse comportamento, use [#pragma aviso](../../preprocessor/warning.md). Por exemplo, para tornar um problema de aviso de nível 4, C4234

```
#pragma warning(2:4234)
```

no arquivo de código fonte.