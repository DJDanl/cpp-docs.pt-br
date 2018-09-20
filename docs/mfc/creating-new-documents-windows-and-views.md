---
title: Criando novos documentos, Windows e modos de exibição | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 0b4ccddbed0d347468331218614cad70cfd49a62
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46427232"
---
# <a name="creating-new-documents-windows-and-views"></a>Criando novos documentos, janelas e exibições

As figuras a seguir oferecem uma visão geral do processo de criação de documentos, exibições e janelas de quadro. Outros artigos que se concentram nos objetos participantes fornecem mais detalhes.

Após a conclusão desse processo, os objetos de cooperação existem e armazenam ponteiros uns aos outros. As figuras a seguir mostram a sequência na qual os objetos são criados. Você pode seguir a sequência de figura da figura.

![Sequência para a criação de um documento](../mfc/media/vc387l1.gif "vc387l1") sequência na criação de um documento

![Sequência de criação da janela de quadro](../mfc/media/vc387l2.png "vc387l2") sequência na criação de uma janela do quadro

![Sequência para a criação de um modo de exibição](../mfc/media/vc387l3.gif "vc387l3") sequência na criação de um modo de exibição

Para obter informações sobre como o framework inicializa o novo documento, exibição e objetos de janela com moldura, consulte classes [CDocument](../mfc/reference/cdocument-class.md), [CView](../mfc/reference/cview-class.md), [CFrameWnd](../mfc/reference/cframewnd-class.md), [CMDIFrameWnd](../mfc/reference/cmdiframewnd-class.md), e [CMDIChildWnd](../mfc/reference/cmdichildwnd-class.md) na referência da biblioteca MFC. Consulte também [22 de observação técnica](../mfc/tn022-standard-commands-implementation.md), que explica os processos de criação e a inicialização adicional em sua discussão de comandos de padrão da estrutura para o **New** e **abrir** itens sobre os **arquivo** menu.

##  <a name="_core_initializing_your_own_additions_to_these_classes"></a> Inicializando suas própria adições a essas Classes

As figuras anteriores também sugerem os pontos em que você pode substituir as funções de membro para inicializar objetos do seu aplicativo. Uma substituição do `OnInitialUpdate` na exibição de classe é o melhor lugar para inicializar a exibição. O `OnInitialUpdate` chamada ocorre imediatamente depois que a janela do quadro é criada e o modo de exibição dentro da janela de quadro é anexado ao seu documento. Por exemplo, se o modo de exibição é um modo de exibição de rolagem (derivado de `CScrollView` em vez de `CView`), você deve definir o tamanho de exibição com base no tamanho do documento no seu `OnInitialUpdate` substituir. (Esse processo é descrito na descrição da classe [CScrollView](../mfc/reference/cscrollview-class.md).) Você pode substituir a `CDocument` funções de membro `OnNewDocument` e `OnOpenDocument` para fornecer a inicialização de aplicativo específica do documento. Normalmente, você deve substituir ambos como um documento pode ser criado de duas maneiras.

Na maioria dos casos, sua substituição deve chamar a versão da classe base. Para obter mais informações, consulte as funções de membro nomeado das classes [CDocument](../mfc/reference/cdocument-class.md), [CView](../mfc/reference/cview-class.md), [CFrameWnd](../mfc/reference/cframewnd-class.md), e [CWinApp](../mfc/reference/cwinapp-class.md) no MFC Referência da biblioteca.

## <a name="see-also"></a>Consulte também

[Modelos de documento e o processo de criação de documento/exibição](../mfc/document-templates-and-the-document-view-creation-process.md)<br/>
[Criação do modelo de documento](../mfc/document-template-creation.md)<br/>
[Criação de documento/exibição](../mfc/document-view-creation.md)<br/>
[Relacionamentos entre objetos MFC](../mfc/relationships-among-mfc-objects.md)

