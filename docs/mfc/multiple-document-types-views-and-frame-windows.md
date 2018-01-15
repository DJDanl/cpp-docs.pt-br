---
title: "Vários tipos de documento, exibições e janelas com moldura | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
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
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 2ab8bff6484f81c482ddd8629ff33772fab1aeba
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="multiple-document-types-views-and-frame-windows"></a>Vários tipos de documento, exibições e janelas com moldura
A relação padrão entre um documento, o modo de exibição e sua janela do quadro é descrita em [criação de documento/exibição](../mfc/document-view-creation.md). Muitos aplicativos oferecem suporte a um único documento tipo (mas possivelmente vários documentos abertos desse tipo) com uma única exibição no documento e janela de apenas um quadro por documento. Mas alguns aplicativos podem precisar alterar um ou mais desses padrões.  
  
## <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre  
  
-   [Vários tipos de documento](#_core_multiple_document_types)  
  
-   [Várias exibições](#_core_multiple_views)  
  
-   [Várias janelas com moldura](#_core_multiple_frame_windows)  
  
-   [Janelas separadoras](#_core_splitter_windows)  
  
##  <a name="_core_multiple_document_types"></a>Vários tipos de documento  
 O Assistente de aplicativo MFC cria uma classe de documento único para você. Em alguns casos, no entanto, você talvez seja necessário dar suporte a mais de um tipo de documento. Por exemplo, seu aplicativo pode ser necessário documentos de planilha e gráfico. Cada tipo de documento é representado por sua própria classe de documento e, provavelmente, por sua própria classe de exibição também. Quando o usuário escolhe o comando novo arquivo, o framework exibe uma caixa de diálogo que lista os tipos de documento com suporte. Em seguida, ele cria um documento do tipo que o usuário escolhe. Cada tipo de documento é gerenciado pelo seu próprio objeto de modelo de documento.  
  
 Para criar classes de documento adicionais, consulte [adicionando uma classe](../ide/adding-a-class-visual-cpp.md). Escolha [CDocument](../mfc/reference/cdocument-class.md) como o tipo de classe derivam e forneça as informações do documento solicitado. Em seguida, implemente os dados da nova classe.  
  
 Para permitir que a estrutura de conhecer a sua classe de documento extras, você deve adicionar uma segunda chamada para [AddDocTemplate](../mfc/reference/cwinapp-class.md#adddoctemplate) em sua classe de aplicativo [InitInstance](../mfc/reference/cwinapp-class.md#initinstance) substituir. Para obter mais informações, consulte [modelos de documento](../mfc/document-templates-and-the-document-view-creation-process.md).  
  
##  <a name="_core_multiple_views"></a>Várias exibições  
 Muitos documentos exigem apenas um modo de exibição, mas é possível dar suporte a mais de uma exibição de um único documento. Para ajudá-lo a implementar vários modos de exibição, um objeto de documento mantém uma lista de seus modos de exibição, fornece funções de membro para adicionar e remover os modos de exibição e fornece o [UpdateAllViews](../mfc/reference/cdocument-class.md#updateallviews) a função de membro de vários modos de exibição informar quando o dados do documento foi alterado.  
  
 MFC dá suporte a três interfaces de usuário comuns que exigem várias exibições no mesmo documento. Esses modelos são:  
  
-   Objetos de exibição da mesma classe, cada um em uma janela do quadro de documentos MDI separada.  
  
     Você talvez queira oferecer suporte à criação de uma segunda janela do quadro de um documento. O usuário pode escolher um comando nova janela a abrir um segundo quadro com um modo de exibição do mesmo documento e, em seguida, usar os dois quadros para exibir diferentes partes do documento simultaneamente. A estrutura suporta o comando nova janela no menu janela para aplicativos MDI duplicando a janela do quadro inicial e a exibição anexada ao documento.  
  
-   Objetos de exibição da mesma classe na mesma janela do quadro de documento.  
  
     Janelas separadoras dividir o espaço do modo de exibição de uma janela de documento único em várias exibições separadas do documento. A estrutura cria vários objetos de exibição da mesma classe de exibição. Para obter mais informações, consulte [janelas separadoras](#_core_splitter_windows).  
  
-   Exibir objetos de classes diferentes em uma janela do quadro.  
  
     Neste modelo, uma variação da janela separadora, vários modos de exibição compartilham uma janela do quadro único. As exibições são construídas a partir de classes diferentes, cada exibição fornecendo uma maneira diferente de exibir o mesmo documento. Por exemplo, um modo de exibição pode mostrar um documento de processamento de texto no modo normal, enquanto o outro modo de exibição mostra-lo no modo de estrutura de tópicos. Um controle de separador permite que o usuário ajuste os tamanhos relativos dos modos de exibição.  
  
 A figura a seguir, dividido em partes a, b e c, mostra os três modelos de interface do usuário na ordem apresentada acima.  
  
 ![Vários &#45; interfaces de usuário de exibição](../mfc/media/vc37a71.gif "vc37a71")  
Interfaces de usuário de exibição de vários  
  
 O framework fornece esses modelos ao implementar o comando nova janela e fornecendo classe [CSplitterWnd](../mfc/reference/csplitterwnd-class.md), conforme discutido em [janelas separadoras](#_core_splitter_windows). Você pode implementar outros modelos de usá-las como ponto de partida. Para programas de exemplo que ilustram as diferentes configurações de modos de exibição e janelas com moldura divisores, consulte [amostras MFC](../visual-cpp-samples.md).  
  
 Para obter mais informações sobre `UpdateAllViews`, consulte a classe [CView](../mfc/reference/cview-class.md) no *referência MFC* e [Rabisco exemplo](../visual-cpp-samples.md).  
  
##  <a name="_core_multiple_frame_windows"></a>Várias janelas com moldura  
 Você pode usar o comando nova janela no menu janela para aplicativos MDI para criar uma segunda janela do quadro no mesmo documento. Para obter mais informações, consulte o primeiro modelo na figura, a exibição de várias Interfaces de usuário.  
  
##  <a name="_core_splitter_windows"></a>Janelas separadoras  
 Em uma janela separadora, a janela está ou pode ser dividido em dois ou mais painéis roláveis. Um separador controle (ou "caixa de divisão") no quadro de janela ao lado de barras de rolagem permite ao usuário ajustar os tamanhos relativos dos painéis. Cada painel é uma exibição no mesmo documento. Divisores "dinâmicos", as exibições são da mesma classe, conforme mostrado na parte b a figura a exibição de várias Interfaces de usuário. Em divisores "estáticos", os modos de exibição podem ser de classes diferentes. Janelas separadoras de ambos os tipos são suportadas pela classe [CSplitterWnd](../mfc/reference/csplitterwnd-class.md).  
  
 Janelas separadoras dinâmicas, com modos de exibição da mesma classe, permitir que o usuário dividir uma janela em vários painéis conforme o desejado e, em seguida, role painéis diferentes para diferentes partes do documento. O usuário também pode remover a divisão de janela para remover os modos de exibição adicionais. As janelas separadoras adicionadas para o [Rabisco exemplo](../visual-cpp-samples.md) são um exemplo. Esse tópico descreve a técnica para a criação de janelas separadoras dinâmicas. Uma janela separadora dinâmica é mostrada na figura, a exibição de várias Interfaces de usuário parte b.  
  
 Janelas separadoras estáticas, modos de exibição de classes diferentes, inicie com a janela dividida em vários painéis, cada um com uma finalidade diferente. Por exemplo, no editor de bitmap do Visual C++, a janela de imagem mostra dois painéis lado a lado. O painel esquerdo exibe uma imagem life-sized do bitmap. O painel direito exibe uma imagem com zoom ou ampliada do mesmo bitmap. Os painéis são separados por uma "barra divisória" que o usuário pode arrastar para alterar o tamanho relativo dos painéis. Uma janela separadora estático é mostrada na parte c da figura exibir várias Interfaces de usuário.  
  
 Para obter mais informações, consulte a classe [CSplitterWnd](../mfc/reference/csplitterwnd-class.md) no *referência MFC* e [amostras MFC](../visual-cpp-samples.md).  
  
## <a name="see-also"></a>Consulte também  
 [Arquitetura de documento/exibição](../mfc/document-view-architecture.md)

