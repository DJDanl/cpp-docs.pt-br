---
title: "Fechando arquivos | Microsoft Docs"
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
  - "Arquivos  [C++], fechamento"
  - "MFC [C++], operações de arquivo"
ms.assetid: 8415a3a8-3c75-45b0-ac2a-d5385f49bdb3
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Fechando arquivos
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Como ocorre em operações de E\/S, quando você terminar com um arquivo, você deve fechá\-lo.  
  
#### Para fechar um arquivo  
  
1.  Use a função de membro de **Fechar** .  Essa função fecha o arquivo do sistema de arquivos e os buffers de liberações se necessário.  
  
 Se você atribuiu o objeto de [CFile](../mfc/reference/cfile-class.md) no quadro \(como no exemplo mostrado em [Abrindo arquivos](../Topic/Opening%20Files.md)\), o objeto será fechado automaticamente e destruído em quando sai do escopo.  Observe que exclui o objeto de `CFile` não exclui o arquivo físico no sistema de arquivos.  
  
## Consulte também  
 [Arquivos](../mfc/files-in-mfc.md)