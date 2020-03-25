---
title: Erro fatal U1070 (NMAKE)
ms.date: 11/04/2016
f1_keywords:
- U1070
helpviewer_keywords:
- U1070
ms.assetid: 8639fc39-b4b1-48f5-ac91-0e9fb61680fd
ms.openlocfilehash: 008d49df3460cb7cf760e4b278db20da444555fe
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80182767"
---
# <a name="nmake-fatal-error-u1070"></a>Erro fatal U1070 (NMAKE)

ciclo na definição de macro ' macroname '

A definição de macro fornecida continha uma macro cuja definição continha a macro fornecida. As definições de macro circular são inválidas.

## <a name="example"></a>Exemplo

As seguintes definições de macro

```
ONE=$(TWO)
TWO=$(ONE)
```

causa o seguinte erro:

```
cycle in macro definition 'TWO'
```
