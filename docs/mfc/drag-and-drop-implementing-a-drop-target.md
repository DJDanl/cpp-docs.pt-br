---
title: "Arrastar e soltar: implementando um destino de soltar | Microsoft Docs"
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
  - "arrastar e soltar, destino de soltar"
  - "arrastar e soltar OLE, destino de soltar"
  - "arrastar e soltar OLE, implementando destinos de soltar"
ms.assetid: 0689f1ec-5326-4008-b226-4b373c881358
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Arrastar e soltar: implementando um destino de soltar
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este artigo descreve como fazer seu aplicativo a um destino de descarte.  Implementá\-la obtidas de um destino de descarte um pouco mais trabalho do que implementando uma origem drop, mas ainda é relativamente simples.  Essas técnicas também se aplicam a não aplicativos OLE.  
  
#### Para implementar um destino de descarte  
  
1.  Adicionar uma variável de membro a cada exibição no aplicativo que você deseja ser um destino de descarte.  Essa variável de membro deve ser do tipo `COleDropTarget` ou de uma classe derivada deles.  
  
2.  Da função da classe da exibição que trata a mensagem de `WM_CREATE` \(normalmente `OnCreate`\), chame função de membro de `Register` a nova da variável de membro.  `Revoke` será chamado automaticamente para o quando a exibição é destruída.  
  
3.  Substituir as funções a seguir.  Se você quiser que o mesmo comportamento durante todo o aplicativo, substituir essas funções em sua classe da exibição.  Se você quiser alterar o comportamento em casos isolados ou desejar habilitar remover no windows não de`CView` , substituir essas funções em seu `COleDropTarget`\- classe derivada.  
  
    |Substituição|Para permitir|  
    |------------------|-------------------|  
    |`OnDragEnter`|Operações de descarte a ocorrer na janela.  Chamado quando o cursor entre primeiro na janela.|  
    |`OnDragLeave`|Comportamento especial quando a operação de arrastamento sair da janela especificada.|  
    |`OnDragOver`|Operações de descarte a ocorrer na janela.  Chamado quando o cursor é arrastado pela janela.|  
    |`OnDrop`|Manipulação dos dados que estão sendo removidos na janela especificada.|  
    |`OnScrollBy`|Comportamento quando especial para rolar necessário na janela de destino.|  
  
 Consulte o arquivo de MAINVIEW.CPP que faz parte do exemplo [OCLIENT](../top/visual-cpp-samples.md) MFC OLE para obter um exemplo de como essas funções trabalham juntos.  
  
 Para obter mais informações, consulte:  
  
-   [Implementando uma origem drop](../mfc/drag-and-drop-implementing-a-drop-source.md)  
  
-   [Objetos de dados e fontes de dados OLE e designers de destruições](../mfc/data-objects-and-data-sources-creation-and-destruction.md)  
  
-   [Objetos de dados e fontes de dados OLE de manipulação](../mfc/data-objects-and-data-sources-manipulation.md)  
  
## Consulte também  
 [Arrastar e soltar \(OLE\)](../mfc/drag-and-drop-ole.md)   
 [Classe de COleDropTarget](../Topic/COleDropTarget%20Class.md)