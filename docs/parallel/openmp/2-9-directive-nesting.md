---
title: 2.9 aninhamento de diretiva | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: 6565a43c-fd2d-4366-8322-8d75e1b06600
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 28e690ba531b4b37973bc2555d904317181ff918
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
---
# <a name="29-directive-nesting"></a>2.9 Aninhamento de diretiva
Aninhamento dinâmico de diretivas deve seguir as regras a seguir:  
  
-   Um **paralela** diretiva dinamicamente dentro de outro **paralela** logicamente estabelece uma nova equipe, que é composta de apenas o thread atual, a menos que aninhados paralelismo está habilitada.  
  
-   **para**, **seções**, e **único** diretivas que se vincular à mesma **paralela** não podem ser aninhadas dentro de outro.  
  
-   **crítico** diretivas com o mesmo nome não pode ser aninhado dentro de outro. Observe que essa restrição não é suficiente para evitar deadlock.  
  
-   **para**, **seções**, e **único** diretivas não são permitidas na extensão dinâmica de **crítico**, **ordenados**, e **mestre** regiões se as diretivas de ligação ao mesmo **paralela** como as regiões.  
  
-   **barreira** diretivas não são permitidas na extensão dinâmica de **para**, **ordenados**, **seções**, **único**, **mestre**, e **crítico** regiões se as diretivas de ligação ao mesmo **paralela** como as regiões.  
  
-   **mestre** diretivas não são permitidas na extensão dinâmica de **para**, **seções**, e **único** diretivas se o **mestre** diretivas ligar à mesma **paralela** como as diretivas de compartilhamento de trabalho.  
  
-   **ordenados** diretivas não são permitidas na extensão dinâmica de **crítico** regiões se as diretivas de ligação ao mesmo **paralela** como as regiões.  
  
-   Nenhuma diretiva que é permitida quando executado dinamicamente dentro de uma região parallel também é permitida quando executado fora de uma região parallel. Quando executado dinamicamente fora de uma região parallel especificado pelo usuário, a diretiva é executada por uma equipe composta somente o thread principal.