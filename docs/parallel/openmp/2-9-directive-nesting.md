---
title: 2.9 aninhamento de diretiva | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
ms.assetid: 6565a43c-fd2d-4366-8322-8d75e1b06600
caps.latest.revision: "4"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: bd3c4f790681b1b044f435c03d185585b565eb62
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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