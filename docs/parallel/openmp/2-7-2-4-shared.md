---
title: 2.7.2.4 shared
ms.date: 11/04/2016
ms.assetid: c9c5d653-58fc-4620-ab0a-443ac4f8ba2e
ms.openlocfilehash: ae470f4be67fac57146017d3e2791f6f95aa61b5
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50583437"
---
# <a name="2724-shared"></a>2.7.2.4 shared

Essa cláusula compartilha as variáveis que aparecem na *lista variável* entre todos os threads em uma equipe. Todos os threads em uma equipe de acessem a área de armazenamento para **compartilhado** variáveis.

A sintaxe do **compartilhado** cláusula é da seguinte maneira:

```
shared(variable-list)
```