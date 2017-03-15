---
title: "Usando documentos | Microsoft Docs"
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
  - "dados [MFC], documentos"
  - "dados [MFC], lendo"
  - "arquitetura de documento/exibição [C++], documentos"
  - "documentos [C++]"
  - "documentos [C++], aplicativos C++"
  - "Arquivos  [C++]"
  - "Arquivos  [C++], gravando em"
  - "imprimindo [MFC], documentos"
  - "lendo dados [C++], documentos e exibições"
  - "exibições [C++], aplicativos C++"
  - "escrevendo em arquivos [C++]"
ms.assetid: f390d6d8-d0e1-4497-9b6a-435f7ce0776c
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Usando documentos
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Trabalhando em conjunto, documentos e exibições:  
  
-   Contém, gerenciar, e exibir seu [dados](../mfc/managing-data-with-document-data-variables.md)de aplicativo específico.  
  
-   Fornecer uma interface que consiste [documentos variáveis de dados](../mfc/managing-data-with-document-data-variables.md) para manipular os dados.  
  
-   Participa de [arquivos de leitura e gravação](../mfc/serializing-data-to-and-from-files.md).  
  
-   Participa de [imprimir](../mfc/role-of-the-view-in-printing.md).  
  
-   [Identificador](../mfc/handling-commands-in-the-document.md) mais dos comandos e de mensagens do seu aplicativo.  
  
 O documento é particularmente envolvido em gerenciar dados.  Armazenar seus dados, normalmente, variáveis do membro da classe do documento.  A exibição usa essas variáveis para acessar os dados para exibição e atualização.  O mecanismo padrão de serialização do documento gerencia a leitura e a gravação aos dados e arquivos.  Os documentos também podem tratar comandos \(mas não mensagens do windows diferentes de **WM\_COMMAND**\).  
  
## Que você deseja saber mais?  
  
-   [Com uma classe do documento de CDocument](../mfc/deriving-a-document-class-from-cdocument.md)  
  
-   [Gerenciando dados com variáveis os dados de documento](../mfc/managing-data-with-document-data-variables.md)  
  
-   [Serializando dados para e de arquivos](../mfc/serializing-data-to-and-from-files.md)  
  
-   [Ignorando o mecanismo de serialização](../mfc/bypassing-the-serialization-mechanism.md)  
  
-   [Comandos de manipulação no documento](../mfc/handling-commands-in-the-document.md)  
  
-   [A função de membro de OnNewDocument](../Topic/CDocument::OnNewDocument.md)  
  
-   [A função de membro de DeleteContents](../Topic/CDocument::DeleteContents.md)  
  
## Consulte também  
 [Arquitetura de documento\/exibição](../Topic/Document-View%20Architecture.md)