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
ms.openlocfilehash: a558761ff49c2b508a5bad6172cda2283801e30e
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87191723"
---
# <a name="optimizing-inline-assembly"></a>Otimizando o assembly embutido

**Específico da Microsoft**

A presença de um **`__asm`** bloco em uma função afeta a otimização de várias maneiras. Primeiro, o compilador não tenta otimizar o **`__asm`** próprio bloco. O que você escreve na linguagem do assembly é exatamente o que você obtém. Em segundo lugar, a presença de um **`__asm`** bloco afeta o armazenamento da variável de registro. O compilador evita o registro de variáveis em um **`__asm`** bloco se o conteúdo do registro for alterado pelo **`__asm`** bloco. Por fim, outras otimizações em toda a função serão afetadas pela inclusão da linguagem do assembly em uma função.

**FINAL específico da Microsoft**

## <a name="see-also"></a>Confira também

[Assembler embutido](../../assembler/inline/inline-assembler.md)<br/>
