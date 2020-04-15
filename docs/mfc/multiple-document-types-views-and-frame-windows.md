---
title: Vários tipos de documento, exibições e janelas com moldura
ms.date: 11/19/2018
helpviewer_keywords:
- static splitter windows [MFC]
- multiple views [MFC]
- multiple document types [MFC]
- multiple views [MFC], frame windows
- document classes [MFC], multiple
- documents [MFC], multiple types of
- splitter windows [MFC], dynamic
- dynamic splitter windows [MFC]
- windows [MFC], dynamic splitter
- windows [MFC], static splitter
- multiple frame windows [MFC]
- splitter windows [MFC], static
ms.assetid: c6b9e4e0-7c9c-45f1-a804-aeac39c9a128
ms.openlocfilehash: 5d8cec0a4ba1580e7ac5fb0e3b81052de08223fc
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81370713"
---
# <a name="multiple-document-types-views-and-frame-windows"></a>Vários tipos de documento, exibições e janelas com moldura

A relação padrão entre um documento, sua visão e sua janela de quadro sao descritas na [Criação de Documentos/Exibição](../mfc/document-view-creation.md). Muitos aplicativos suportam um único tipo de documento (mas possivelmente vários documentos abertos desse tipo) com uma única exibição no documento e apenas uma janela de quadro por documento. Mas alguns aplicativos podem precisar alterar um ou mais desses padrões.

## <a name="what-do-you-want-to-know-more-about"></a>O que você quer saber mais sobre

- [Vários tipos de documentos](#_core_multiple_document_types)

- [Várias exibições](#_core_multiple_views)

- [Janelas de vários quadros](#_core_multiple_frame_windows)

- [Janelas de divisor](#_core_splitter_windows)

## <a name="multiple-document-types"></a><a name="_core_multiple_document_types"></a>Vários tipos de documentos

O MFC Application Wizard cria uma única classe de documento para você. Em alguns casos, porém, você pode precisar suportar mais de um tipo de documento. Por exemplo, seu aplicativo pode precisar de documentos de planilha e gráfico. Cada tipo de documento é representado por sua própria classe de documentos e provavelmente por sua própria classe de visualização também. Quando o usuário escolhe o comando Arquivo Novo, a estrutura exibe uma caixa de diálogo que lista os tipos de documento suportados. Em seguida, ele cria um documento do tipo que o usuário escolhe. Cada tipo de documento é gerenciado por seu próprio objeto de modelo de documento.

Para criar classes extras de documentos, consulte [Adicionar uma classe](../ide/adding-a-class-visual-cpp.md). Escolha [CDocument](../mfc/reference/cdocument-class.md) como o Tipo de Classe para derivar e fornecer as informações do documento solicitadas. Em seguida, implemente os dados da nova classe.

Para que a estrutura saiba sobre sua classe de documentos extras, você deve adicionar uma segunda chamada ao [AddDocTemplate](../mfc/reference/cwinapp-class.md#adddoctemplate) na substituição [initInstance](../mfc/reference/cwinapp-class.md#initinstance) da sua classe de aplicativo. Para obter mais informações, consulte [Modelos de documentos](../mfc/document-templates-and-the-document-view-creation-process.md).

## <a name="multiple-views"></a><a name="_core_multiple_views"></a>Múltiplas visualizações

Muitos documentos exigem apenas uma visão única, mas é possível suportar mais de uma visão de um único documento. Para ajudá-lo a implementar várias visualizações, um objeto de documento mantém uma lista de suas exibições, fornece funções de membros para adicionar e remover visualizações e fornece a função de membro [UpdateAllViews](../mfc/reference/cdocument-class.md#updateallviews) para informar várias visualizações quando os dados do documento foram alterados.

O MFC suporta três interfaces de usuário comuns que exigem várias visualizações no mesmo documento. Estes modelos são:

- Exibir objetos da mesma classe, cada um em uma janela de quadro de documento MDI separada.

   Você pode querer apoiar a criação de uma segunda janela de quadro em um documento. O usuário poderia escolher um comando Nova janela para abrir um segundo quadro com uma exibição do mesmo documento e, em seguida, usar os dois quadros para exibir diferentes partes do documento simultaneamente. O framework suporta o comando Nova janela no menu Janela para aplicativos MDI, duplicando a janela inicial do quadro e a exibição anexada ao documento.

- Exibir objetos da mesma classe na mesma janela do quadro de documentos.

   Janelas divisoras dividem o espaço de exibição de uma única janela de documento em várias visualizações separadas do documento. A estrutura cria vários objetos de exibição da mesma classe de exibição. Para obter mais informações, consulte [Splitter Windows](#_core_splitter_windows).

- Exibir objetos de diferentes classes em uma única janela de quadro.

   Neste modelo, uma variação da janela do divisor, várias visualizações compartilham uma única janela de quadro. As visões são construídas a partir de classes diferentes, cada visão fornecendo uma maneira diferente de visualizar o mesmo documento. Por exemplo, uma exibição pode mostrar um documento de processamento de texto no modo normal, enquanto a outra exibição mostra-o no modo contorno. Um controle divisor permite que o usuário ajuste os tamanhos relativos das visualizações.

A figura a seguir, dividida em partes a, b e c, mostra os três modelos de interface de usuário na ordem apresentada acima.

![Várias interfaces de usuário de visualização de&#45;](../mfc/media/vc37a71.gif "Várias interfaces de usuário de visualização de&#45;") <br/>
Interfaces de usuário de visão múltipla

A estrutura fornece esses modelos implementando o comando New Window e fornecendo classe [CSplitterWnd](../mfc/reference/csplitterwnd-class.md), como discutido no [Splitter Windows](#_core_splitter_windows). Você pode implementar outros modelos usando-os como seu ponto de partida. Para programas de exemplo que ilustram diferentes configurações de visualizações, janelas de quadroe divisores, consulte [MFC Samples](../overview/visual-cpp-samples.md#mfc-samples).

Para obter `UpdateAllViews`mais informações sobre , consulte classe [CView](../mfc/reference/cview-class.md) na *referência MFC* e na [amostra De rabisco](../overview/visual-cpp-samples.md).

## <a name="multiple-frame-windows"></a><a name="_core_multiple_frame_windows"></a>Windows de vários quadros

Você pode usar o comando Nova janela no menu Janela para aplicativos MDI para criar uma segunda janela de quadro no mesmo documento. Para obter mais informações, consulte o primeiro modelo na figura Interfaces de usuário de visão múltipla.

## <a name="splitter-windows"></a><a name="_core_splitter_windows"></a>Janelas splitter

Em uma janela de divisor, a janela é, ou pode ser, dividida em dois ou mais painéis roláveis. Um controle divisor (ou "caixa dividida") no quadro da janela ao lado das barras de rolagem permite que o usuário ajuste os tamanhos relativos dos painéis. Cada painel é uma visão no mesmo documento. Em divisores "dinâmicos", as visualizações são da mesma classe, como mostrado na parte b da figura Interfaces de Usuário de Visão Múltipla. Em divisores "estáticos", as visualizações podem ser de classes diferentes. Janelas divisoras de ambos os tipos são suportadas pela classe [CSplitterWnd](../mfc/reference/csplitterwnd-class.md).

Janelas divisoras dinâmicas, com vistas da mesma classe, permitem que o usuário divida uma janela em vários painéis à vontade e, em seguida, role diferentes painéis para ver diferentes partes do documento. O usuário também pode desdividir a janela para remover as visualizações adicionais. As janelas de divisor adicionadas à [amostra Scribble](../overview/visual-cpp-samples.md) são um exemplo. Esse tópico descreve a técnica para criar janelas divisoras dinâmicas. Uma janela de divisor dinâmico é mostrada na parte b da figura Interfaces de usuário de visão múltipla.

Janelas de divisor estática, com vistas de diferentes classes, começam com a janela dividida em vários painéis, cada um com um propósito diferente. Por exemplo, no editor de bitmap Visual C++, a janela de imagem mostra dois painéis lado a lado. O painel esquerdo exibe uma imagem em tamanho real do bitmap. O painel da direita exibe uma imagem ampliada ou ampliada do mesmo bitmap. Os painéis são separados por uma "barra de divisor" que o usuário pode arrastar para alterar os tamanhos relativos dos painéis. Uma janela de divisor estático é mostrada na parte C da figura Interfaces de usuário de visão múltipla.

Para obter mais informações, consulte a classe [CSplitterWnd](../mfc/reference/csplitterwnd-class.md) nas *amostras de referência mfc* e [mfc](../overview/visual-cpp-samples.md#mfc-samples).

## <a name="see-also"></a>Confira também

[Arquitetura de documento/exibição](../mfc/document-view-architecture.md)
