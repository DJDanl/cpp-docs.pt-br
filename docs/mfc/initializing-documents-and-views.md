---
title: "Inicializando documentos e exibi&#231;&#245;es | Microsoft Docs"
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
  - "documentos, inicializando"
  - "inicializando documentos"
  - "inicializando objetos, objetos de documento"
  - "inicializando exibições"
  - "modos de exibição, inicializando"
ms.assetid: 33cb8643-8a16-478c-bc26-eccc734e3661
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Inicializando documentos e exibi&#231;&#245;es
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Os documentos são criados em duas maneiras diferentes, de modo que a sua classe do documento deve oferecer suporte a duas formas.  Primeiro, o usuário pode criar um novo documento, vazio com o novo comando de Arquivo.  Nesse caso, inicializar o documento em sua substituição da função de membro de [OnNewDocument](../Topic/CDocument::OnNewDocument.md) da classe [CDocument](../Topic/CDocument%20Class.md).  Segundo, o usuário pode usar o comando no menu arquivo aberto criar um novo documento cujos conteúdos são lidas de um arquivo.  Nesse caso, inicializar o documento em sua substituição da função de membro de [OnOpenDocument](../Topic/CDocument::OnOpenDocument.md) da classe **CDocument**.  Se ambas as inicializações são as mesmas, você poderá chamar uma função de membro comuns de ambas as substituições, ou `OnOpenDocument` pode chamar `OnNewDocument` para inicializar um documento limpo e para concluir a operação aberta.  
  
 As exibições são criadas depois que os documentos são criados.  O melhor momento para inicializar uma exibição são depois que a estrutura terminar de criar o documento, a janela do quadro, e a exibição.  Você pode inicializar sua exibição substituindo a função de membro de [OnInitialUpdate](../Topic/CView::OnInitialUpdate.md) de [CView](../Topic/CView%20Class.md).  Se você precisar reinicializar ou para ajustar qualquer coisa cada vez que o documento é alterado, você pode substituir [OnUpdate](../Topic/CView::OnUpdate.md).  
  
## Consulte também  
 [Inicializando e limpando documentos e exibições](../mfc/initializing-and-cleaning-up-documents-and-views.md)