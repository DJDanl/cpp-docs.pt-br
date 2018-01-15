---
title: "2.8 vinculação de diretiva | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
ms.assetid: 7bdac45e-ab55-42f0-bd47-a2e3d5bbab3e
caps.latest.revision: "4"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 731c509c0c2f300d7a9d4e39261ffedd1c22a094
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="28-directive-binding"></a>2.8 Associação de diretiva
Associação dinâmica de diretivas deve seguir as regras a seguir:  
  
-   O **para**, **seções**, **único**, **mestre**, e **barreira** diretivas de associar o dinamicamente delimitador **paralela**, se houver, independentemente do valor de qualquer **se** cláusula que pode estar presente em que a diretiva. Se nenhuma região parallel está sendo executada atualmente, as diretivas são executadas por uma equipe composta somente o thread principal.  
  
-   O **ordenados** diretiva vincula a dinamicamente delimitador **para**.  
  
-   O **atômico** diretiva garante o acesso exclusivo com relação a **atômico** diretivas em todos os threads, não apenas a equipe atual.  
  
-   O **crítico** diretiva garante o acesso exclusivo com relação a **crítico** diretivas em todos os threads, não apenas a equipe atual.  
  
-   Uma diretiva nunca pode vincular dinamicamente para nenhuma diretiva fora o mais próximo de circunscrição **paralela**.