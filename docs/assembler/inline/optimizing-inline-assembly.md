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
ms.openlocfilehash: 0051b16ddc19e233cfac2688c0b77e1e023f0833
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80169260"
---
# <a name="optimizing-inline-assembly"></a>Otimizando o assembly embutido

**Seção específica da Microsoft**

A presença de um bloco de `__asm` em uma função afeta a otimização de várias maneiras. Primeiro, o compilador não tenta otimizar o bloco de `__asm` em si. O que você escreve na linguagem do assembly é exatamente o que você obtém. Em segundo lugar, a presença de um bloco de `__asm` afeta o armazenamento de variável de registro. O compilador evita o registro de variáveis em um bloco de `__asm` se o conteúdo do registro for alterado pelo bloco de `__asm`. Por fim, outras otimizações em toda a função serão afetadas pela inclusão da linguagem do assembly em uma função.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Confira também

[Assembler embutido](../../assembler/inline/inline-assembler.md)<br/>
