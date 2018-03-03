---
title: Criando janelas com moldura de documento | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- frame windows [MFC], creating
- document templates [MFC], and document frame windows
- windows [MFC], creating
- runtime, class information
- run-time class [MFC], and document frame window creation
- document frame windows [MFC], creating
- MFC, frame windows
ms.assetid: 8671e239-b76f-4dea-afa8-7024e6e58ff5
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 9098026c1a38f8e60093415ba1c5a2b3678b64d5
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="creating-document-frame-windows"></a>Criando janelas com moldura de documento
[Criação de documento/exibição](../mfc/document-view-creation.md) mostra como o [CDocTemplate](../mfc/reference/cdoctemplate-class.md) objeto coordena a criar a janela do quadro, documento e exibição e conectá-los juntos. Três [CRuntimeClass](../mfc/reference/cruntimeclass-structure.md) argumentos para o `CDocTemplate` construtor especifique a janela do quadro, documentos e classes de exibição do modelo de documento cria dinamicamente em resposta aos comandos do usuário, como o novo comando no arquivo menu ou o comando nova janela em um menu janela MDI. O modelo de documento armazena essas informações para uso posterior, quando ele cria uma janela do quadro para um modo de exibição e o documento.  
  
 Para o [RUNTIME_CLASS](../mfc/reference/run-time-object-model-services.md#runtime_class) mecanismo funcione corretamente, derivada classes de janela com moldura devem ser declarados com a [DECLARE_DYNCREATE](../mfc/reference/run-time-object-model-services.md#declare_dyncreate) macro. Isso ocorre porque a estrutura precisa criar janelas de quadro usando o mecanismo de criação dinâmica da classe de documento `CObject`.  
  
 Quando o usuário escolhe um comando que cria um documento, o framework chama o modelo de documento para criar o objeto de documento, o modo de exibição e a janela do quadro que exibirá o modo de exibição. Ao criar a janela do quadro de documento, o modelo de documento cria um objeto da classe apropriada, uma classe derivada de [CFrameWnd](../mfc/reference/cframewnd-class.md) para um aplicativo SDI ou [CMDIChildWnd](../mfc/reference/cmdichildwnd-class.md) para um MDI aplicativo. O framework chama o objeto de janela com moldura [LoadFrame](../mfc/reference/cframewnd-class.md#loadframe) função de membro para obter informações sobre a criação de recursos e criar a janela do Windows. A estrutura anexa o identificador de janela para o objeto de janela do quadro. Em seguida, ele cria a exibição como uma janela filho da janela do quadro do documento.  
  
 Tome cuidado ao decidir [quando inicializar](../mfc/when-to-initialize-cwnd-objects.md) sua `CWnd`-objeto derivado.  
  
## <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre  
  
-   [Derivando uma classe de CObject (seu mecanismo de criação dinâmica)](../mfc/deriving-a-class-from-cobject.md)  
  
-   [Criação de documento/exibição (modelos e criação de janela do quadro)](../mfc/document-view-creation.md)  
  
-   [Destruindo janelas com moldura](../mfc/destroying-frame-windows.md)  
  
## <a name="see-also"></a>Consulte também  
 [Usando janelas com moldura](../mfc/using-frame-windows.md)

