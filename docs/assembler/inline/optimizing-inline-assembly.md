---
title: Otimizando Assembly embutido | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
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
ms.openlocfilehash: c494594e3b7c541487f34fd33359b0e31f73dd61
ms.sourcegitcommit: dbca5fdd47249727df7dca77de5b20da57d0f544
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/28/2018
ms.locfileid: "32050552"
---
# <a name="optimizing-inline-assembly"></a>Otimizando o assembly embutido
## <a name="microsoft-specific"></a>Específico da Microsoft  
 A presença de um `__asm` bloco em uma função afeta a otimização de várias maneiras. Primeiro, o compilador não tenta otimizar o `__asm` próprio bloco. O que você escreve em linguagem de assembly é exatamente o que você tem. Segundo, a presença de um `__asm` bloco afeta registrar armazenamento variável. O compilador evita as variáveis de registro em um `__asm` bloqueado se o conteúdo do registro será alterado pelo `__asm` bloco. Finalmente, algumas outras otimizações de toda a função serão afetadas pela inclusão de linguagem de assembly em uma função.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Assembler embutido](../../assembler/inline/inline-assembler.md)