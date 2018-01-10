---
title: Otimizando Assembly embutido | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- storage, optimizing in inline assembly
- optimization, inline assembly
- inline assembly, optimizing
- optimizing performance, inline assembly
- __asm keyword [C++], optimizing
ms.assetid: 52a7ec83-9782-4d96-94c1-53bb2ac9e8c8
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 21f6954ece6adcc60fbb3a8620dd427e7c21042a
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="optimizing-inline-assembly"></a>Otimizando o assembly embutido
## <a name="microsoft-specific"></a>Específico da Microsoft  
 A presença de um `__asm` bloco em uma função afeta a otimização de várias maneiras. Primeiro, o compilador não tenta otimizar o `__asm` próprio bloco. O que você escreve em linguagem de assembly é exatamente o que você tem. Segundo, a presença de um `__asm` bloco afeta registrar armazenamento variável. O compilador evita as variáveis de registro em um `__asm` bloqueado se o conteúdo do registro será alterado pelo `__asm` bloco. Finalmente, algumas outras otimizações de toda a função serão afetadas pela inclusão de linguagem de assembly em uma função.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Assembler embutido](../../assembler/inline/inline-assembler.md)