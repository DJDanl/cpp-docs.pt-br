---
title: Criando novos documentos, janelas e exibições
ms.date: 11/19/2018
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
ms.openlocfilehash: 7a714b5d7ba97c12b7134fa4890bddf5ed095c5b
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84620558"
---
# <a name="creating-new-documents-windows-and-views"></a>Criando novos documentos, janelas e exibições

As figuras a seguir fornecem uma visão geral do processo de criação para documentos, exibições e janelas de quadros. Outros artigos que se concentram nos objetos participantes fornecem mais detalhes.

Após a conclusão desse processo, os objetos cooperativos existem e armazenam ponteiros entre si. As figuras a seguir mostram a sequência na qual os objetos são criados. Você pode seguir a sequência da figura para a figura.

![Sequência para criar um documento](../mfc/media/vc387l1.gif "Sequência para criar um documento") <br/>
Sequência na criação de um documento

![Sequência de criação de janela do quadro](../mfc/media/vc387l2.png "Sequência de criação de janela do quadro") <br/>
Sequência na criação de uma janela de quadro

![Sequência para criar uma exibição](../mfc/media/vc387l3.gif "Sequência para criar uma exibição") <br/>
Sequência na criação de uma exibição

Para obter informações sobre como a estrutura Inicializa o novo documento, exibição e objetos de janela de quadro, consulte classes [CDocument](reference/cdocument-class.md), [cvisualização](reference/cview-class.md), [CFrameWnd](reference/cframewnd-class.md), [CMDIFrameWnd](reference/cmdiframewnd-class.md)e [CMDIChildWnd](reference/cmdichildwnd-class.md) na referência da biblioteca do MFC. Consulte também a [Nota técnica 22](tn022-standard-commands-implementation.md), que explica os processos de criação e inicialização além de sua discussão sobre os comandos padrão da estrutura para os itens **novos** e **abertos** no menu **arquivo** .

## <a name="initializing-your-own-additions-to-these-classes"></a><a name="_core_initializing_your_own_additions_to_these_classes"></a>Inicializando suas próprias adições a essas classes

Os números anteriores também sugerem os pontos em que você pode substituir as funções de membro para inicializar os objetos do aplicativo. Uma substituição de `OnInitialUpdate` na sua classe de exibição é o melhor local para inicializar a exibição. A `OnInitialUpdate` chamada ocorre imediatamente depois que a janela do quadro é criada e a exibição dentro da janela do quadro é anexada a seu documento. Por exemplo, se sua exibição for uma exibição de rolagem (derivada de `CScrollView` em vez de `CView` ), você deverá definir o tamanho da exibição com base no tamanho do documento em sua `OnInitialUpdate` substituição. (Esse processo é descrito na descrição da classe [CScrollView](reference/cscrollview-class.md).) Você pode substituir as `CDocument` funções de membro `OnNewDocument` e `OnOpenDocument` fornecer a inicialização específica do aplicativo do documento. Normalmente, você deve substituir ambos, uma vez que um documento pode ser criado de duas maneiras.

Na maioria dos casos, sua substituição deve chamar a versão da classe base. Para obter mais informações, consulte as funções membro nomeado das classes [CDocument](reference/cdocument-class.md), [cvisualização](reference/cview-class.md), [CFrameWnd](reference/cframewnd-class.md)e [CWinApp](reference/cwinapp-class.md) na referência da biblioteca do MFC.

## <a name="see-also"></a>Consulte também

[Modelos de documento e o processo de criação de documento/exibição](document-templates-and-the-document-view-creation-process.md)<br/>
[Criação do modelo de documento](document-template-creation.md)<br/>
[Criação de documento/exibição](document-view-creation.md)<br/>
[Relacionamentos entre objetos MFC](relationships-among-mfc-objects.md)
