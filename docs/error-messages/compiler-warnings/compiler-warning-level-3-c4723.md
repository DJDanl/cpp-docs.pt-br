---
title: Aviso do compilador (nível 3) C4723
description: Descreve o C4723 de aviso do compilador MSVC para divisão potencial por zero.
ms.date: 07/08/2020
f1_keywords:
- C4723
helpviewer_keywords:
- C4723
ms.assetid: 07669d14-3fd8-4a43-94bc-b61c50e58460
ms.openlocfilehash: 57a5758d8a3198d7701bdead2e1bbe567b72701a
ms.sourcegitcommit: 80c8a512b361bd84e38958beb1a1bf6db7434021
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/09/2020
ms.locfileid: "86180988"
---
# <a name="compiler-warning-level-3-c4723"></a>Aviso do compilador (nível 3) C4723

> `potential divide by 0`

O segundo operando em uma operação de divisão foi avaliado como zero no tempo de compilação, fornecendo resultados indefinidos.

Esse aviso é emitido somente quando as otimizações estão habilitadas.

O compilador pode ter gerado o operando zero.
