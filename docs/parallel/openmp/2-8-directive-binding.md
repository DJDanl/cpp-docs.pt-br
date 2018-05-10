---
title: 2.8 vinculação de diretiva | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: 7bdac45e-ab55-42f0-bd47-a2e3d5bbab3e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 02492b228b4bb47a800955f078a59ce680312a87
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
---
# <a name="28-directive-binding"></a>2.8 Associação de diretiva
Associação dinâmica de diretivas deve seguir as regras a seguir:  
  
-   O **para**, **seções**, **único**, **mestre**, e **barreira** diretivas de associar o dinamicamente delimitador **paralela**, se houver, independentemente do valor de qualquer **se** cláusula que pode estar presente em que a diretiva. Se nenhuma região parallel está sendo executada atualmente, as diretivas são executadas por uma equipe composta somente o thread principal.  
  
-   O **ordenados** diretiva vincula a dinamicamente delimitador **para**.  
  
-   O **atômico** diretiva garante o acesso exclusivo com relação a **atômico** diretivas em todos os threads, não apenas a equipe atual.  
  
-   O **crítico** diretiva garante o acesso exclusivo com relação a **crítico** diretivas em todos os threads, não apenas a equipe atual.  
  
-   Uma diretiva nunca pode vincular dinamicamente para nenhuma diretiva fora o mais próximo de circunscrição **paralela**.