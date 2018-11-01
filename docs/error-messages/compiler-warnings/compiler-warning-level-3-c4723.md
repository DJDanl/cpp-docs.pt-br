---
title: Compilador aviso (nível 3) C4723
ms.date: 11/04/2016
f1_keywords:
- C4723
helpviewer_keywords:
- C4723
ms.assetid: 07669d14-3fd8-4a43-94bc-b61c50e58460
ms.openlocfilehash: b970c9ee02339fa3b48135d321638db7e64baf82
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50505879"
---
# <a name="compiler-warning-level-3-c4723"></a>Compilador aviso (nível 3) C4723

possível divisão por 0

O segundo operando em uma operação de divisão avaliada como zero em tempo de compilação, fornecendo resultados indefinidos.

Esse aviso é emitido somente ao usar [/Og](../../build/reference/og-global-optimizations.md) ou uma opção de otimização que implica /Og.

O compilador pode ter gerado o zero operando.