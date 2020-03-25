---
title: Aviso do compilador (nível 3) C4723
ms.date: 11/04/2016
f1_keywords:
- C4723
helpviewer_keywords:
- C4723
ms.assetid: 07669d14-3fd8-4a43-94bc-b61c50e58460
ms.openlocfilehash: 3a47c6f7e83abfc785d602d8ee0734be5d0fa962
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80174083"
---
# <a name="compiler-warning-level-3-c4723"></a>Aviso do compilador (nível 3) C4723

possível divisão por 0

O segundo operando em uma operação de divisão foi avaliado como zero no tempo de compilação, fornecendo resultados indefinidos.

Esse aviso é emitido somente ao usar [/og](../../build/reference/og-global-optimizations.md) ou uma opção de otimização que implica/og.

O compilador pode ter gerado o operando zero.
