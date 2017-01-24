---
title: "Erro fatal C1013 | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-csharp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "C1013"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C1013"
ms.assetid: 5514a679-efe7-4055-bdd3-5693ca0c332f
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro fatal C1013
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

limite do compilador: muitos parênteses abertos  
  
 Uma expressão contém muitos níveis de parênteses em uma única expressão. Simplificar a expressão ou dividi\-lo em várias instruções.  
  
 Antes do Visual C\+\+ 6.0 Service Pack 3, o limite de parênteses aninhados em uma única expressão era 59. Atualmente, o limite de parênteses aninhados é 256.