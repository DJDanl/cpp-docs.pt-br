---
title: "Arquivos de ajuda (ajuda HTML) | Microsoft Docs"
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
  - "tipos de arquivo [C++], Arquivos da Ajuda HTML"
ms.assetid: d30a1b1b-318f-4a78-8b60-93da53a224a8
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Arquivos de ajuda (ajuda HTML)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Os seguintes arquivos são criados quando você adiciona o tipo de Ajuda em HTML de suporte de ajuda para seu aplicativo, selecionando o  **Ajuda contextual** caixa de seleção e, em seguida, selecionando  **formato de Ajuda em HTML** na  [Advanced Features](../mfc/reference/advanced-features-mfc-application-wizard.md) página do Assistente de aplicativo MFC.  
  
|File name|Local do diretório|Localização do Solution Explorer|Descrição|  
|---------------|------------------------|--------------------------------------|---------------|  
|*Nomedoprojeto*. hhp|*Nomedoprojeto*\\hlp|Arquivos de Ajuda em HTML|O arquivo de projeto de Ajuda.  Ele contém os dados necessários para compilar os arquivos de Ajuda em um arquivo HXS ou um arquivo. chm.|  
|*Nomedoprojeto*.hhk|*Nomedoprojeto*\\hlp|Arquivos de Ajuda em HTML|Contém um índice dos tópicos da Ajuda.|  
|*Nomedoprojeto*.hhc|*Nomedoprojeto*\\hlp|Arquivos de Ajuda em HTML|O conteúdo do projeto ajuda.|  
|Makehtmlhelp.bat|*Nomedoprojeto*|Arquivos de origem|Usado pelo sistema para construir o projeto de ajuda quando o projeto é compilado.|  
|Afxcore.htm|*Nomedoprojeto*\\hlp|Tópicos da Ajuda HTML|Contém os tópicos de ajuda padrão para comandos padrão da MFC e objetos da tela.  Adicione seus próprios tópicos da Ajuda para este arquivo.|  
|Afxprint.htm|*Nomedoprojeto*\\hlp|Tópicos da Ajuda HTML|Contém os tópicos da Ajuda para os comandos de impressão.|  
|jpg; GIF|*Nomedoprojeto*\\hlp\\Images|Arquivos de recursos|Contêm imagens para os tópicos do arquivo de ajuda gerado.|  
  
## Consulte também  
 [Tipos de arquivo criados para projetos do Visual C\+\+](../ide/file-types-created-for-visual-cpp-projects.md)