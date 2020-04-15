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
ms.openlocfilehash: aa1c58b02df92d79ca9915032b97fb5c0e2eaffc
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81371662"
---
# <a name="creating-new-documents-windows-and-views"></a>Criando novos documentos, janelas e exibições

As figuras a seguir dão uma visão geral do processo de criação de documentos, visualizações e janelas de quadros. Outros artigos que se concentram nos objetos participantes fornecem mais detalhes.

Após a conclusão deste processo, os objetos cooperativos existem e armazenam ponteiros uns para os outros. As figuras a seguir mostram a seqüência em que os objetos são criados. Você pode seguir a seqüência de figura em figura.

![Sequência para criar um documento](../mfc/media/vc387l1.gif "Sequência para criar um documento") <br/>
Seqüência na criação de um documento

![Seqüência de criação de janelas de quadro](../mfc/media/vc387l2.png "Seqüência de criação de janelas de quadro") <br/>
Seqüência em Criar uma Janela de Quadro

![Seqüência para criar uma visualização](../mfc/media/vc387l3.gif "Seqüência para criar uma visualização") <br/>
Seqüência em Criar uma Exibição

Para obter informações sobre como a estrutura inicializa os novos objetos de documento, visualização e janela de quadro, consulte as classes [CDocument,](../mfc/reference/cdocument-class.md) [CView,](../mfc/reference/cview-class.md) [CFrameWnd,](../mfc/reference/cframewnd-class.md) [CMDIFrameWnd](../mfc/reference/cmdiframewnd-class.md)e [CMDIChildWnd](../mfc/reference/cmdichildwnd-class.md) no MFC Library Reference. Consulte também [a Nota Técnica 22](../mfc/tn022-standard-commands-implementation.md), que explica os processos de criação e inicialização ainda mais em sua discussão dos comandos padrão do quadro para os itens **Novo** e **Aberto** no menu **Arquivo.**

## <a name="initializing-your-own-additions-to-these-classes"></a><a name="_core_initializing_your_own_additions_to_these_classes"></a>Inicializando suas próprias adições a essas aulas

Os números anteriores também sugerem os pontos em que você pode substituir as funções do membro para inicializar os objetos do aplicativo. Uma substituição `OnInitialUpdate` de na sua classe de visão é o melhor lugar para inicializar a vista. A `OnInitialUpdate` chamada ocorre imediatamente após a criação da janela do quadro e a exibição dentro da janela do quadro é anexada ao documento. Por exemplo, se a sua exibição `CScrollView` for `CView`uma exibição de pergaminho (derivada de `OnInitialUpdate` vez em que), você deve definir o tamanho da exibição com base no tamanho do documento em sua substituição. (Este processo é descrito na descrição da classe [CScrollView](../mfc/reference/cscrollview-class.md).) Você pode substituir `CDocument` as `OnNewDocument` funções do membro e `OnOpenDocument` fornecer inicialização específica do documento. Normalmente, você deve substituir ambos, pois um documento pode ser criado de duas maneiras.

Na maioria dos casos, sua substituição deve chamar a versão da classe base. Para obter mais informações, consulte as funções de membro nomeadas das classes [CDocument,](../mfc/reference/cdocument-class.md) [CView,](../mfc/reference/cview-class.md) [CFrameWnd](../mfc/reference/cframewnd-class.md)e [CWinApp](../mfc/reference/cwinapp-class.md) na Referência da Biblioteca MFC.

## <a name="see-also"></a>Confira também

[Modelos de documento e o processo de criação de documento/exibição](../mfc/document-templates-and-the-document-view-creation-process.md)<br/>
[Criação do modelo de documento](../mfc/document-template-creation.md)<br/>
[Criação de documento/exibição](../mfc/document-view-creation.md)<br/>
[Relacionamentos entre objetos MFC](../mfc/relationships-among-mfc-objects.md)
