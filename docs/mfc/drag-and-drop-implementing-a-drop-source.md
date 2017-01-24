---
title: "Arrastar e soltar: implementando uma origem para soltar | Microsoft Docs"
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
  - "arrastar e soltar, Chamando DoDragDrop"
  - "arrastar e soltar, origem para soltar"
  - "arrastar e soltar, iniciando operações de soltar"
  - "arrastar e soltar OLE, Chamando DoDragDrop"
  - "arrastar e soltar OLE, origem para soltar"
  - "arrastar e soltar OLE, iniciando operações de soltar"
ms.assetid: 0ed2fda0-63fa-4b1e-b398-f1f142f40035
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Arrastar e soltar: implementando uma origem para soltar
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este artigo explica como obter seu aplicativo para fornecer dados a uma operação de arrastar e soltar.  
  
 A implementação básica de uma origem de remoção é relativamente simples.  A primeira etapa é determinar quais eventos iniciam uma operação.  As diretrizes recomendadas da interface do usuário definem o início de uma operação de arrastar como a seleção de dados e um evento de `WM_LBUTTONDOWN` que ocorre em um ponto dentro dos dados selecionados.  Os exemplos [OCLIENT](../top/visual-cpp-samples.md) e [HIERSVR](../top/visual-cpp-samples.md) MFC OLE seguem estas diretrizes.  
  
 Se seu aplicativo for um contêiner e os dados selecionados são um objeto vinculado ou inserido de tipo `COleClientItem`, chame a função de membro de `DoDragDrop` .  Caso contrário, construir um objeto de `COleDataSource` , para inicializá\-lo com a seleção, e chame a função de membro de `DoDragDrop` do objeto de fonte de dados.  Se seu aplicativo for um servidor, use `COleServerItem::DoDragDrop`.  Para obter informações sobre como personalizar o comportamento padrão de arrastar e soltar, consulte o artigo [Arraste e solte: Personalizar](../Topic/Drag%20and%20Drop:%20Customizing.md).  
  
 Se `DoDragDrop` retorna `DROPEFFECT_MOVE`, exclua os dados de origem do documento de origem imediatamente.  Nenhum outro valor de retorno de `DoDragDrop` tem efeito em uma origem de descarte.  
  
 Para obter mais informações, consulte:  
  
-   [Implementando um destino de descarte](../mfc/drag-and-drop-implementing-a-drop-target.md)  
  
-   [Personalizando ao arrastar e soltar](../Topic/Drag%20and%20Drop:%20Customizing.md)  
  
-   [Objetos de dados e fontes de dados OLE e designers de destruições](../mfc/data-objects-and-data-sources-creation-and-destruction.md)  
  
-   [Objetos de dados e fontes de dados OLE de manipulação](../mfc/data-objects-and-data-sources-manipulation.md)  
  
## Consulte também  
 [Arrastar e soltar \(OLE\)](../mfc/drag-and-drop-ole.md)   
 [COleDataSource::DoDragDrop](../Topic/COleDataSource::DoDragDrop.md)   
 [COleClientItem::DoDragDrop](../Topic/COleClientItem::DoDragDrop.md)   
 [CView::OnDragLeave](../Topic/CView::OnDragLeave.md)