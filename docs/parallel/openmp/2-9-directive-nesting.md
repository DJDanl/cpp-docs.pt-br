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
ms.openlocfilehash: f1af9f515861863af5906c99d78aa66d08aa09b6
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
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