---
title: Otimizando o assembly embutido
ms.date: 08/30/2018
helpviewer_keywords:
- storage, optimizing in inline assembly
- optimization, inline assembly
- inline assembly, optimizing
- optimizing performance, inline assembly
- __asm keyword [C++], optimizing
ms.assetid: 52a7ec83-9782-4d96-94c1-53bb2ac9e8c8
ms.openlocfilehash: d4956ba12e0bc268d78a895e6cb1ec6e2059262a
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50538856"
---
# <a name="optimizing-inline-assembly"></a>Otimizando o assembly embutido

**Seção específica da Microsoft**

A presença de um `__asm` bloco em uma função afeta a otimização de várias maneiras. Primeiro, o compilador não tenta otimizar o `__asm` bloquear em si. O que você escreve na linguagem assembly é exatamente o que você obtém. Segundo, a presença de um `__asm` bloco afeta registrar armazenamento variável. O compilador evita as variáveis de registro em um `__asm` bloqueie se o conteúdo do registro será alterado pelo `__asm` bloco. Por fim, algumas outras otimizações de toda a função serão afetadas pela inclusão de linguagem de assembly em uma função.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Assembler embutido](../../assembler/inline/inline-assembler.md)<br/>