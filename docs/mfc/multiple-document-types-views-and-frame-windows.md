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
ms.openlocfilehash: 873903aadc1596fbc56f9a0b0b98dbc5a948113d
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84619962"
---
# <a name="multiple-document-types-views-and-frame-windows"></a>Vários tipos de documento, exibições e janelas com moldura

A relação padrão entre um documento, sua exibição e sua janela de quadro é descrita em [criação de documento/exibição](document-view-creation.md). Muitos aplicativos dão suporte a um único tipo de documento (mas possivelmente a vários documentos abertos desse tipo) com uma única exibição no documento e apenas uma janela de quadro por documento. Mas alguns aplicativos podem precisar alterar um ou mais desses padrões.

## <a name="what-do-you-want-to-know-more-about"></a>Do que você deseja saber mais sobre

- [Vários tipos de documento](#_core_multiple_document_types)

- [Várias exibições](#_core_multiple_views)

- [Várias janelas de quadros](#_core_multiple_frame_windows)

- [Janelas de divisão](#_core_splitter_windows)

## <a name="multiple-document-types"></a><a name="_core_multiple_document_types"></a>Vários tipos de documento

O assistente de aplicativo do MFC cria uma única classe de documento para você. No entanto, em alguns casos, talvez seja necessário dar suporte a mais de um tipo de documento. Por exemplo, seu aplicativo pode precisar de documentos de planilha e gráfico. Cada tipo de documento é representado por sua própria classe de documento e provavelmente por sua própria classe de exibição também. Quando o usuário escolhe o comando arquivo novo, a estrutura exibe uma caixa de diálogo que lista os tipos de documento com suporte. Em seguida, ele cria um documento do tipo que o usuário escolhe. Cada tipo de documento é gerenciado por seu próprio objeto de modelo de documento.

Para criar classes de documento adicionais, consulte [adicionando uma classe](../ide/adding-a-class-visual-cpp.md). Escolha [CDocument](reference/cdocument-class.md) como o tipo de classe para derivar e forneça as informações de documento solicitadas. Em seguida, implemente os dados da nova classe.

Para permitir que a estrutura saiba sobre sua classe de documento extra, você deve adicionar uma segunda chamada para [AddDocTemplate](reference/cwinapp-class.md#adddoctemplate) na substituição de [InitInstance](reference/cwinapp-class.md#initinstance) da sua classe de aplicativo. Para obter mais informações, consulte [modelos de documento](document-templates-and-the-document-view-creation-process.md).

## <a name="multiple-views"></a><a name="_core_multiple_views"></a>Várias exibições

Muitos documentos exigem apenas uma única exibição, mas é possível dar suporte a mais de uma exibição de um único documento. Para ajudá-lo a implementar vários modos de exibição, um objeto de documento mantém uma lista de suas exibições, fornece funções de membro para adicionar e remover exibições e fornece a função membro [UpdateAllViews](reference/cdocument-class.md#updateallviews) para permitir que várias exibições saibam quando os dados do documento foram alterados.

O MFC dá suporte a três interfaces de usuário comuns que exigem várias exibições no mesmo documento. Esses modelos são:

- Exibir objetos da mesma classe, cada um em uma janela de quadro de documento MDI separada.

   Talvez você queira dar suporte à criação de uma segunda janela de quadro em um documento. O usuário pode escolher um novo comando de janela para abrir um segundo quadro com uma exibição do mesmo documento e, em seguida, usar os dois quadros para exibir partes diferentes do documento simultaneamente. A estrutura dá suporte ao comando nova janela no menu janela para aplicativos MDI duplicando a janela inicial do quadro e a exibição anexada ao documento.

- Exibir objetos da mesma classe na mesma janela do quadro do documento.

   Janelas de divisão dividem o espaço de exibição de uma única janela de documento em várias exibições separadas do documento. A estrutura cria vários objetos View da mesma classe View. Para obter mais informações, consulte [divisão do Windows](#_core_splitter_windows).

- Exibir objetos de classes diferentes em uma janela de quadro único.

   Nesse modelo, uma variação da janela separadora, várias exibições compartilham uma única janela de quadro. As exibições são construídas de classes diferentes, cada exibição que fornece uma maneira diferente de exibir o mesmo documento. Por exemplo, um modo de exibição pode mostrar um documento de processamento de texto no modo normal enquanto o outro modo de exibição o mostra no modo de estrutura de tópicos. Um controle de divisão permite que o usuário ajuste os tamanhos relativos das exibições.

A figura a seguir, dividida nas partes a, b e c, mostra os três modelos de interface de usuário na ordem apresentada acima.

![Vários&#45;Exibir interfaces do usuário](../mfc/media/vc37a71.gif "Vários&#45;Exibir interfaces do usuário") <br/>
Interfaces de usuário de várias exibições

A estrutura fornece esses modelos implementando o novo comando de janela e fornecendo a classe [CSplitterWnd](reference/csplitterwnd-class.md), conforme discutido em [janelas de divisão](#_core_splitter_windows). Você pode implementar outros modelos usando esses como ponto de partida. Para programas de exemplo que ilustram diferentes configurações de exibições, janelas de quadros e divisores, consulte [exemplos de MFC](../overview/visual-cpp-samples.md#mfc-samples).

Para obter mais informações sobre `UpdateAllViews` o, consulte classe [Cvisualização](reference/cview-class.md) na *referência do MFC* e o [exemplo de rabisco](../overview/visual-cpp-samples.md).

## <a name="multiple-frame-windows"></a><a name="_core_multiple_frame_windows"></a>Várias janelas de quadros

Você pode usar o comando nova janela no menu janela para aplicativos MDI para criar uma segunda janela de quadro no mesmo documento. Para obter mais informações, consulte o primeiro modelo nas interfaces de usuário da figura com várias exibições.

## <a name="splitter-windows"></a><a name="_core_splitter_windows"></a>Janelas de divisão

Em uma janela divisora, a janela é, ou pode, ser dividida em dois ou mais painéis roláveis. Um controle de Splitter (ou "caixa de divisão") no quadro de janela ao lado das barras de rolagem permite que o usuário ajuste os tamanhos relativos dos painéis. Cada painel é uma exibição no mesmo documento. Em divisores "dinâmicos", as exibições são da mesma classe, conforme mostrado na parte b da figura de interfaces de usuário de várias exibições. Em divisores "estáticos", as exibições podem ser de classes diferentes. As janelas de divisores de ambos os tipos são suportadas pela classe [CSplitterWnd](reference/csplitterwnd-class.md).

Janelas de divisão dinâmica, com exibições da mesma classe, permitem que o usuário divida uma janela em vários painéis em e, em seguida, role painéis diferentes para ver diferentes partes do documento. O usuário também pode desdividir a janela para remover as exibições adicionais. As janelas de Splitter adicionadas ao [exemplo de rabisco](../overview/visual-cpp-samples.md) são um exemplo. Esse tópico descreve a técnica para criar janelas de divisão dinâmica. Uma janela divisora dinâmica é mostrada na parte b da figura de interfaces de usuário de exibição múltipla.

Janelas divisoras estáticas, com exibições de classes diferentes, começam com a janela dividida em vários painéis, cada uma com uma finalidade diferente. Por exemplo, no editor de bitmap Visual C++, a janela de imagem mostra dois painéis lado a lado. O painel esquerdo exibe uma imagem de tamanho da vida do bitmap. O painel direito exibe uma imagem com zoom ou ampliada do mesmo bitmap. Os painéis são separados por uma "barra de divisão" que o usuário pode arrastar para alterar os tamanhos relativos dos painéis. Uma janela divisora estática é mostrada na parte c da figura de interfaces de usuário de exibição múltipla.

Para obter mais informações, consulte Class [CSplitterWnd](reference/csplitterwnd-class.md) na *referência do MFC* e [exemplos do MFC](../overview/visual-cpp-samples.md#mfc-samples).

## <a name="see-also"></a>Consulte também

[Arquitetura de documento/exibição](document-view-architecture.md)
