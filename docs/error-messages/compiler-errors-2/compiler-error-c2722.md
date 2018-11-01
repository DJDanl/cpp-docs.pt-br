---
title: Erro do compilador C2722
ms.date: 11/04/2016
f1_keywords:
- C2722
helpviewer_keywords:
- C2722
ms.assetid: 4cc2c7fa-cb12-4bcf-9df1-6d627ef62973
ms.openlocfilehash: 4274ac6ec33e0176f998fcf5a2b3efd570a4009f
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50546257"
---
# <a name="compiler-error-c2722"></a>Erro do compilador C2722

':: operador ': inválido após comando operator; Use 'operator operador'

Uma `operator` instrução redefinições `::new` ou `::delete`. O `new` e `delete` operadores são globais, portanto, o operador de resolução de escopo (`::`) não faz sentido. Remover o `::` operador.