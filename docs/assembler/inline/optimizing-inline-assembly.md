---
title: Otimizando o Assembly embutido | Microsoft Docs
ms.custom: ''
ms.date: 08/30/2018
ms.technology:
- cpp-masm
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- storage, optimizing in inline assembly
- optimization, inline assembly
- inline assembly, optimizing
- optimizing performance, inline assembly
- __asm keyword [C++], optimizing
ms.assetid: 52a7ec83-9782-4d96-94c1-53bb2ac9e8c8
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 49660bdc6d2eb84e6e1bbaeb5ebf0d57e484e9e1
ms.sourcegitcommit: a7046aac86f1c83faba1088c80698474e25fe7c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/04/2018
ms.locfileid: "43687870"
---
# <a name="optimizing-inline-assembly"></a>Otimizando o assembly embutido

**Seção específica da Microsoft**

A presença de um `__asm` bloco em uma função afeta a otimização de várias maneiras. Primeiro, o compilador não tenta otimizar o `__asm` bloquear em si. O que você escreve na linguagem assembly é exatamente o que você obtém. Segundo, a presença de um `__asm` bloco afeta registrar armazenamento variável. O compilador evita as variáveis de registro em um `__asm` bloqueie se o conteúdo do registro será alterado pelo `__asm` bloco. Por fim, algumas outras otimizações de toda a função serão afetadas pela inclusão de linguagem de assembly em uma função.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Assembler embutido](../../assembler/inline/inline-assembler.md)<br/>