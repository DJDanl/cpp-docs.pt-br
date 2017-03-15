---
title: "Acessando status do arquivo | Microsoft Docs"
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
  - "exemplos [MFC], status do arquivo"
  - "status do arquivo [C++]"
  - "Arquivos  [C++], acessando"
  - "Arquivos  [C++], informações de status"
  - "status de arquivos"
ms.assetid: 1b8891d6-eb0f-4037-a837-4928fe595222
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Acessando status do arquivo
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

da  suporte`CFile` também que obtém o status do arquivo, incluindo se o arquivo já existir, a criação e as datas e as horas de alteração, tamanho lógico, e caminho.  
  
### Para obter o status do arquivo  
  
1.  Use a classe de [CFile](../mfc/reference/cfile-class.md) para obter e definir informações sobre um arquivo.  Um aplicativo é útil usar a função de membro estático **GetStatus** de `CFile` para determinar se um arquivo existe.  **GetStatus** retornará 0 se o arquivo especificado não existe.  
  
 Assim, você pode usar o resultado de **GetStatus** para determinar se usar **CFile::modeCreate** sinaliza ao abrir um arquivo, como mostra o exemplo a seguir:  
  
 [!code-cpp[NVC_MFCFiles#3](../mfc/codesnippet/CPP/accessing-file-status_1.cpp)]  
  
 Para obter informações relacionadas, consulte [Serialização](../Topic/Serialization%20in%20MFC.md).  
  
## Consulte também  
 [Arquivos](../mfc/files-in-mfc.md)