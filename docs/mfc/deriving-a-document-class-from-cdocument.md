---
title: "Derivando uma classe de documento de CDocument | Microsoft Docs"
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
  - "Classe CDocument, derivando de"
  - "classes [C++], derivando de CDocument"
  - "classes derivadas, funções substituídas com frequência"
  - "classes de documento, funções substituídas com frequência"
  - "objetos de documento, derivado"
ms.assetid: e6a198e0-9799-43c0-83c5-04174d8b532c
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Derivando uma classe de documento de CDocument
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Os documentos contêm e gerenciar seus dados de aplicativo.  Para usar a classe para fornecida aplicativo do documento MFC, você deve fazer o seguinte:  
  
-   Derivar uma classe de **CDocument** para cada tipo de documento.  
  
-   Adicionar variáveis de membro para armazenar os dados de cada documento.  
  
-   Função de membro de **CDocument**`Serialize` de substituição em sua classe do documento.  `Serialize` grava e ler os dados de documento para e de disco.  
  
## Outro documenta as funções substituídas frequentemente  
 Talvez você também queira substituir outras funções de membro de **CDocument** .  Em particular, você precisará substituir frequência de [OnNewDocument](../Topic/CDocument::OnNewDocument.md) e [OnOpenDocument](../Topic/CDocument::OnOpenDocument.md) para inicializar os membros de dados e [DeleteContents](../Topic/CDocument::DeleteContents.md) do documento para destruição dados dinamicamente atribuída.  Para obter informações sobre os membros substituível, consulte a classe [CDocument](../Topic/CDocument%20Class.md)*na referência de MFC*.  
  
## Consulte também  
 [Usando documentos](../mfc/using-documents.md)