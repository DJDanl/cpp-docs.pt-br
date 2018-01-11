---
title: "Criando novos documentos, janelas e modos de exibição | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- MDI [MFC], creating windows
- window objects [MFC], creating
- objects [MFC], creating document objects
- MFC default objects
- frame windows [MFC], creating
- windows [MFC], MDI
- MFC, documents
- view objects [MFC], creating
- windows [MFC], creating
- overriding, default view behavior
- views [MFC], initializing
- customizing MFC default objects
- MFC, frame windows
- MFC, views
- MDI [MFC], frame windows
- child windows [MFC], creating MDI
- view objects [MFC]
- document objects [MFC], creating
- MFC default objects [MFC], customizing
- views [MFC], overriding default behavior
- initializing views [MFC]
ms.assetid: 88aa1f5f-2078-4603-b16b-a2b4c7b4a2a3
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 01837b079ba08ea2961b141549476da11a481a0c
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="creating-new-documents-windows-and-views"></a>Criando novos documentos, janelas e exibições
As figuras a seguir oferecem uma visão geral do processo de criação de documentos, exibições e janelas de quadro. Outros artigos que se concentrar nos objetos participantes fornecem mais detalhes.  
  
 Após a conclusão desse processo, os objetos trabalham em conjunto existem e armazenam ponteiros para outro. As figuras a seguir mostram a sequência na qual os objetos são criados. Você pode seguir a sequência da figura figura.  
  
 ![Sequência de criação de um documento](../mfc/media/vc387l1.gif "vc387l1")  
Sequência de criação de um documento  
  
 ![Sequência de criação da janela do quadro](../mfc/media/vc387l2.png "vc387l2")  
Sequência na criação de uma janela do quadro  
  
 ![Sequência para criar uma exibição](../mfc/media/vc387l3.gif "vc387l3")  
Sequência de criação de uma exibição  
  
 Para obter informações sobre como o framework inicializa o novo documento, exibição e objetos de janela do quadro, consulte classes [CDocument](../mfc/reference/cdocument-class.md), [CView](../mfc/reference/cview-class.md), [CFrameWnd](../mfc/reference/cframewnd-class.md), [CMDIFrameWnd](../mfc/reference/cmdiframewnd-class.md), e [CMDIChildWnd](../mfc/reference/cmdichildwnd-class.md) na referência de biblioteca do MFC. Consulte também [22 de observação técnica](../mfc/tn022-standard-commands-implementation.md), que explica os processos de criação e a inicialização adicional em sua discussão dos comandos de padrão da estrutura para o `New` e **abrir** itens na **Arquivo** menu.  
  
##  <a name="_core_initializing_your_own_additions_to_these_classes"></a>Inicializando seus próprios adições para essas Classes  
 As figuras anteriores também sugerirem os pontos em que você pode substituir as funções de membro para inicializar os objetos do aplicativo. Uma substituição de `OnInitialUpdate` na exibição de classe é o melhor local para inicializar o modo de exibição. O `OnInitialUpdate` chamada ocorre imediatamente depois que a janela do quadro é criada e o modo de exibição dentro da janela do quadro é anexado ao seu documento. Por exemplo, se o modo de exibição é um modo de exibição de rolagem (derivado de `CScrollView` em vez de `CView`), você deve definir o tamanho de exibição com base no tamanho do documento em sua `OnInitialUpdate` substituir. (Esse processo é descrito na descrição da classe [CScrollView](../mfc/reference/cscrollview-class.md).) Você pode substituir o **CDocument** funções de membro `OnNewDocument` e `OnOpenDocument` para fornecer específicas do aplicativo de inicialização do documento. Normalmente, você deve substituir ambos como um documento pode ser criado de duas maneiras.  
  
 Na maioria dos casos, a substituição deve chamar a versão da classe base. Para obter mais informações, consulte as funções de membro nomeado de classes [CDocument](../mfc/reference/cdocument-class.md), [CView](../mfc/reference/cview-class.md), [CFrameWnd](../mfc/reference/cframewnd-class.md), e [CWinApp](../mfc/reference/cwinapp-class.md) no MFC Referência da biblioteca.  
  
## <a name="see-also"></a>Consulte também  
 [Modelos de documento e o processo de criação de documento/exibição](../mfc/document-templates-and-the-document-view-creation-process.md)   
 [Criação do modelo de documento](../mfc/document-template-creation.md)   
 [Criação de documento/exibição](../mfc/document-view-creation.md)   
 [Relacionamentos entre objetos MFC](../mfc/relationships-among-mfc-objects.md)

