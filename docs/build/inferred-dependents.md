---
title: "Dependentes inferidos | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "dependentes, inferido"
  - "dependentes inferidos em NMAKE"
ms.assetid: 9303045c-69b3-4f35-bffc-19d5cd6ea3c3
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Dependentes inferidos
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Um dependente inferido é derivado de uma regra de inferência e avaliado antes dos dependentes explícitos.  Se um dependente inferido estiver expirado em relação a seu destino, NMAKE invoca o bloco de comandos da dependência.  Se um dependente deduzido existe ou não estiver expirado em relação aos seus próprios dependentes, NMAKE primeiro atualiza o dependente deduzido.  Para obter mais informações sobre os dependentes deduzidos, consulte [Regras de inferência](../build/inference-rules.md).  
  
## Consulte também  
 [Dependentes](../build/dependents.md)