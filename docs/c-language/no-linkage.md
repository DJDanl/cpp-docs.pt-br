---
title: "Sem liga&#231;&#227;o | Microsoft Docs"
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
  - "vinculação [C++], nenhum"
  - "sem vinculação"
ms.assetid: 5a413082-1034-4e04-b76b-8d14668bf434
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Sem liga&#231;&#227;o
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Se uma declaração de um identificador em um bloco não inclui o especificador de classe de armazenamento `extern`, o identificador não tem nenhuma vinculação e é exclusivo à função.  
  
 Os seguintes identificadores não têm nenhuma vinculação:  
  
-   Um identificador declarado como qualquer coisa que não seja um objeto ou uma função  
  
-   Um identificador declarado como um parâmetro de função  
  
-   Um identificador de escopo de bloco referente a um objeto declarado sem o especificador de classe de armazenamento `extern`  
  
 Se um identificador não tem nenhuma vinculação, declarar o mesmo nome novamente \(em um declarador ou especificador de tipo\) no mesmo nível de escopo gera um erro de redefinição de símbolo.  
  
## Consulte também  
 [Usando extern para especificar ligação](../cpp/using-extern-to-specify-linkage.md)