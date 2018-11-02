---
title: Erro fatal U1070 (NMAKE)
ms.date: 11/04/2016
f1_keywords:
- U1070
helpviewer_keywords:
- U1070
ms.assetid: 8639fc39-b4b1-48f5-ac91-0e9fb61680fd
ms.openlocfilehash: 35bea47f6626dfe283a537d3d96340921c37f3f6
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50484208"
---
# <a name="nmake-fatal-error-u1070"></a>Erro fatal U1070 (NMAKE)

ciclo em definição de macro 'macroname'

A definição da macro determinada continha uma macro cuja definição macro determinada. As definições de macro circulares são inválidas.

## <a name="example"></a>Exemplo

As seguintes definições de macro

```
ONE=$(TWO)
TWO=$(ONE)
```

fazer com que o erro a seguir:

```
cycle in macro definition 'TWO'
```