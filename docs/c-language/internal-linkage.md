---
title: "Liga&#231;&#227;o interna | Microsoft Docs"
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
  - "C"
helpviewer_keywords: 
  - "vinculação interna"
  - "vinculação [C++], internal"
ms.assetid: 80be7b51-c930-43db-94d6-4f09a64077bf
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Liga&#231;&#227;o interna
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Se a declaração de um identificador de escopo do arquivo de um objeto ou de uma função contiver o *storage\-class\-specifier* **static**, o identificador terá vinculação interna.  Caso contrário, o identificador terá vinculação externa.  Consulte [Classes de armazenamento](../c-language/c-storage-classes.md) para obter uma discussão do *storage\-class\-specifier* não terminal.  
  
 Em uma unidade de conversão, cada instância de um identificador com vinculação interna denota o mesmo identificador ou a mesma função.  Os identificadores vinculados internamente são exclusivos de uma unidade de conversão.  
  
## Consulte também  
 [Usando extern para especificar ligação](../cpp/using-extern-to-specify-linkage.md)