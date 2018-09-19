---
title: NMAKE Erro Fatal U1070 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- U1070
dev_langs:
- C++
helpviewer_keywords:
- U1070
ms.assetid: 8639fc39-b4b1-48f5-ac91-0e9fb61680fd
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: b6eb462e5c3c7e497cde55151bf92c62ffb2afcd
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46087013"
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