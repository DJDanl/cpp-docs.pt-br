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
ms.openlocfilehash: e64ea6701c5e3ec594c705e8995b5ba605ab0b79
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57301188"
---
# <a name="multiple-document-types-views-and-frame-windows"></a>Vários tipos de documento, exibições e janelas com moldura

A relação padrão entre um documento, seu modo de exibição e sua janela de quadro é descrita em [criação de documento/exibição](../mfc/document-view-creation.md). Muitos aplicativos dão suporte a um único documento tipo (mas, possivelmente, vários documentos abertos desse tipo) com uma única exibição no documento e janela de quadro apenas um por documento. Mas alguns aplicativos podem precisar alterar um ou mais dos padrões.

## <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre

- [Vários tipos de documentos](#_core_multiple_document_types)

- [Vários modos de exibição](#_core_multiple_views)

- [Várias janelas com moldura](#_core_multiple_frame_windows)

- [Janelas separadoras](#_core_splitter_windows)

##  <a name="_core_multiple_document_types"></a> Vários tipos de documentos

O Assistente de aplicativo do MFC cria uma classe de documento único para você. Em alguns casos, no entanto, você talvez precise dar suporte a mais de um tipo de documento. Por exemplo, seu aplicativo pode precisar documentos de planilha e gráfico. Cada tipo de documento é representado por sua própria classe de documento e, provavelmente, por sua própria classe de exibição também. Quando o usuário escolhe o comando novo arquivo, o framework exibe uma caixa de diálogo que lista os tipos de documento com suporte. Em seguida, ele cria um documento do tipo escolhido pelo usuário. Cada tipo de documento é gerenciado pelo seu próprio objeto de modelo de documento.

Para criar classes de documento adicionais, consulte [adicionando uma classe](../ide/adding-a-class-visual-cpp.md). Escolher [CDocument](../mfc/reference/cdocument-class.md) como o tipo de classe para derivar e fornecer as informações do documento solicitado. Em seguida, implemente os dados da nova classe.

Para permitir que a estrutura de conhecer a sua classe de documento extra, você deve adicionar uma segunda chamada para [AddDocTemplate](../mfc/reference/cwinapp-class.md#adddoctemplate) em sua classe de aplicativo [InitInstance](../mfc/reference/cwinapp-class.md#initinstance) substituir. Para obter mais informações, consulte [modelos de documento](../mfc/document-templates-and-the-document-view-creation-process.md).

##  <a name="_core_multiple_views"></a> Vários modos de exibição

Muitos documentos exigem somente uma única exibição, mas é possível oferecer suporte a mais de uma exibição de um único documento. Para ajudá-lo a implementar vários modos de exibição, um objeto de documento mantém uma lista de suas exibições, fornece funções de membro para adicionar e remover os modos de exibição e fornece o [UpdateAllViews](../mfc/reference/cdocument-class.md#updateallviews) a função de membro para permitir que vários modos de exibição saibam quando o dados do documento foi alterado.

MFC dá suporte a três interfaces de usuário comuns que exigem várias exibições no mesmo documento. Esses modelos são:

- Objetos de exibição da mesma classe, cada um em uma janela de quadro de documento MDI separada.

   Você talvez queira dar suporte à criação de uma segunda janela do quadro em um documento. O usuário pode escolher um comando nova janela para abrir um segundo quadro com um modo de exibição do mesmo documento e, em seguida, use dois quadros para exibir as diferentes partes do documento ao mesmo tempo. O framework suporta o comando nova janela no menu janela para aplicativos MDI duplicando a janela de quadro inicial e a exibição anexados ao documento.

- Objetos de exibição da mesma classe na mesma janela de quadro do documento.

   Janelas separadoras dividir o espaço do modo de exibição de uma janela de documento único em vários modos de exibição separados do documento. A estrutura cria vários objetos de exibição da mesma classe de exibição. Para obter mais informações, consulte [divisor Windows](#_core_splitter_windows).

- Exibir objetos de classes diferentes em uma janela de quadro único.

   Nesse modelo, uma variação da janela separadora, vários modos de exibição compartilham uma janela de quadro único. As exibições são construídas a partir de classes diferentes, cada modo de exibição fornece uma maneira diferente para exibir o mesmo documento. Por exemplo, um modo de exibição pode mostrar um documento de processamento de texto no modo normal, enquanto o outro modo de exibição mostra-lo no modo de estrutura de tópicos. Um controle de splitter permite ao usuário ajustar os tamanhos relativos dos modos de exibição.

A figura a seguir, dividido em partes a, b e c, mostra os três modelos de interface do usuário na ordem apresentada acima.

![Vários&#45;exibir interfaces do usuário](../mfc/media/vc37a71.gif "diversos&#45;exibir interfaces do usuário") <br/>
Interfaces do usuário do modo de exibição de vários

A estrutura fornece esses modelos, Implementando o comando nova janela e fornecendo a classe [CSplitterWnd](../mfc/reference/csplitterwnd-class.md), como descrito em [divisor Windows](#_core_splitter_windows). Você pode implementar outros modelos usando esses como seu ponto de partida. Para programas de exemplo que ilustram as diferentes configurações de exibições e janelas com moldura divisores, consulte [exemplos de MFC](../visual-cpp-samples.md).

Para obter mais informações sobre `UpdateAllViews`, consulte a classe [CView](../mfc/reference/cview-class.md) no *referência da MFC* e o [exemplo de rabisco](../visual-cpp-samples.md).

##  <a name="_core_multiple_frame_windows"></a> Windows de vários quadros

Você pode usar o comando nova janela no menu janela para aplicativos MDI para criar uma segunda janela do quadro no mesmo documento. Para obter mais informações, consulte o primeiro modelo na figura, a exibição de várias Interfaces de usuário.

##  <a name="_core_splitter_windows"></a> Windows divisor

Em uma janela separadora, a janela é, ou pode ser dividido em dois ou mais painéis roláveis. Um divisor controle (ou "dividir a caixa") no quadro de janela ao lado de barras de rolagem permite ao usuário ajustar os tamanhos relativos dos painéis. Cada painel é uma exibição no mesmo documento. Divisores "dinâmicos", as exibições são da mesma classe, conforme mostrado na parte b de figura, a exibição de várias Interfaces de usuário. Em divisores "estáticos", os modos de exibição podem ser de classes diferentes. Janelas separadoras de ambos os tipos são suportadas pela classe [CSplitterWnd](../mfc/reference/csplitterwnd-class.md).

Janelas separadoras dinâmicas, com exibições da mesma classe, permitem ao usuário dividir uma janela em vários painéis à vontade e, em seguida, role diferentes painéis para ver as diferentes partes do documento. O usuário também pode reverter divisão da janela para remover os modos de exibição adicionais. As janelas separadoras adicionadas para o [exemplo de Scribble](../visual-cpp-samples.md) são um exemplo. Esse tópico descreve a técnica para a criação de janelas separadoras dinâmicas. Uma janela divisora dinâmica é mostrada na parte b da figura, a exibição de várias Interfaces de usuário.

Janelas separadoras estáticas, modos de exibição de classes diferentes, comece com a janela dividida em vários painéis, cada um com uma finalidade diferente. Por exemplo, no editor de bitmap do Visual C++, a janela de imagem mostra dois painéis lado a lado. O painel esquerdo exibe uma imagem life-sized do bitmap. O painel direito exibe uma imagem ampliada ou ampliada do mesmo bitmap. Os painéis são separados por uma "barra divisória" que o usuário pode arrastar para alterar o tamanho relativo dos painéis. Uma janela separadora estático é mostrada na parte c da figura modo de exibição de várias Interfaces de usuário.

Para obter mais informações, consulte a classe [CSplitterWnd](../mfc/reference/csplitterwnd-class.md) na *referência da MFC* e [exemplos de MFC](../visual-cpp-samples.md).

## <a name="see-also"></a>Consulte também

[Arquitetura de documento/exibição](../mfc/document-view-architecture.md)
