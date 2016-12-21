---
title: "&#193;rea de Transfer&#234;ncia | Microsoft Docs"
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
  - "Área de Transferência"
  - "Área de Transferência, programação"
  - "copiando dados"
  - "recortando e copiando dados"
  - "transferindo dados"
ms.assetid: a71b2824-1f14-4914-8816-54578d73ad4e
caps.latest.revision: 10
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# &#193;rea de Transfer&#234;ncia
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Esta família de artigos explica como implementar o suporte para a área de transferência do windows em aplicativos MFC.  A área de transferência do windows é usada em duas maneiras:  
  
-   Implementando comandos de menu padrão de edição, como divisão, copie e cole.  
  
-   Implementando a transferência de dados com uniforme de arrastar e soltar \(OLE\).  
  
 A área de transferência é o método padrão do windows de transferir dados entre uma origem e um destino.  Também pode ser muito útil em operações do.  Com o advento OLE, há dois mecanismos da área de transferência do windows.  A área de transferência padrão apis do windows ainda estiver disponível, mas foi complementadas com o mecanismo OLE de transferência de dados.  A transferência de dados \(OLE \(UDT\) oferece suporte a segmentação de dados, a cópia, e a pasta com a área de transferência e arrastar e remoção.  
  
 A área de transferência é um serviço do sistema compartilhado por sessão inteira do windows, o que não tem um identificador ou uma classe de seu próprio.  Você gerencia a área de transferência com as funções de membro da classe [CWnd](../Topic/CWnd%20Class.md).  
  
## Que você deseja saber mais?  
  
-   [Quando usar cada o mecanismo da área de transferência](../mfc/clipboard-when-to-use-each-clipboard-mechanism.md)  
  
-   [Usando a área de transferência tradicional apis do windows](../mfc/clipboard-using-the-windows-clipboard.md)  
  
-   [Usando o mecanismo OLE da área de transferência](../mfc/clipboard-using-the-ole-clipboard-mechanism.md)  
  
-   [Copiando e colando dados](../Topic/Clipboard:%20Copying%20and%20Pasting%20Data.md)  
  
-   [Adicionar outros formatos](../mfc/clipboard-adding-other-formats.md)  
  
-   [\<caps:sentence id\="tgt18" sentenceid\="1bc8aafd7da110d0b343b54cffa169d9" class\="tgtSentence"\>A área de transferência do windows\<\/caps:sentence\>](https://msdn.microsoft.com/en-us/library/ms648709)  
  
-   [Implementando o arraste e descartar \(OLE\)](../mfc/drag-and-drop-ole.md)  
  
## Consulte também  
 [Elementos da interface do usuário](../mfc/user-interface-elements-mfc.md)