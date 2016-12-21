---
title: "V&#225;rios tipos de documento, exibi&#231;&#245;es e janelas com moldura | Microsoft Docs"
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
  - "janelas separadoras estáticas"
  - "várias exibições"
  - "vários tipos de documento"
  - "vários modos de exibição janelas com moldura"
  - "classes de documento, vários"
  - "documentos [C++], vários tipos de"
  - "janelas separadoras dinâmicas"
  - "janelas separadoras dinâmicas"
  - "janelas [C++], separadoras dinâmicas"
  - "janelas [C++], separador estático"
  - "várias janelas com moldura"
  - "janelas separadoras estáticas"
ms.assetid: c6b9e4e0-7c9c-45f1-a804-aeac39c9a128
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# V&#225;rios tipos de documento, exibi&#231;&#245;es e janelas com moldura
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A relação padrão entre um documento, sua visão e sua janela de quadro é descrita em [criação de documento\/exibição](../mfc/document-view-creation.md). Muitos aplicativos oferecem suporte a um único documento tipo \(mas possivelmente vários documentos abertos desse tipo\) com uma única exibição no documento e janela de apenas um quadro por documento. Mas alguns aplicativos podem precisar alterar um ou mais dos padrões.  
  
## O que você deseja saber mais sobre?  
  
-   [Vários tipos de documento](#_core_multiple_document_types)  
  
-   [Várias exibições](#_core_multiple_views)  
  
-   [Várias janelas com moldura](#_core_multiple_frame_windows)  
  
-   [Janelas separadoras](#_core_splitter_windows)  
  
##  <a name="_core_multiple_document_types"></a> Vários tipos de documento  
 O Assistente para aplicativo do MFC cria uma classe de documento único para você. Em alguns casos, no entanto, você precisará oferecer suporte a mais de um tipo de documento. Por exemplo, seu aplicativo pode precisar documentos de planilha e gráfico. Cada tipo de documento é representado por sua própria classe de documento e, provavelmente, por sua própria classe de exibição também. Quando o usuário escolhe o comando novo arquivo, o framework exibe uma caixa de diálogo que lista os tipos de documento com suporte. Em seguida, ele cria um documento do tipo escolhido pelo usuário. Cada tipo de documento é gerenciado pelo seu próprio objeto de modelo de documento.  
  
 Para criar classes de documento adicionais, consulte [Adicionando uma classe](../Topic/Adding%20a%20Class%20\(Visual%20C++\).md). Escolha [CDocument](../Topic/CDocument%20Class.md) como o tipo de classe derivam e forneça as informações do documento solicitado. Em seguida, implemente os dados da nova classe.  
  
 Para permitir que a estrutura de conhecer sua classe de documento extra, você deve adicionar uma segunda chamada para [AddDocTemplate](../Topic/CWinApp::AddDocTemplate.md) em sua classe de aplicativo [InitInstance](../Topic/CWinApp::InitInstance.md) substituir. Para obter mais informações, consulte [modelos de documento](../mfc/document-templates-and-the-document-view-creation-process.md).  
  
##  <a name="_core_multiple_views"></a> Várias exibições  
 Muitos documentos exigem apenas um modo de exibição, mas é possível oferecer suporte a mais de uma exibição de um único documento. Para ajudá\-lo a implementar vários modos de exibição, um objeto de documento mantém uma lista de suas exibições, fornece funções de membro para adicionar e remover os modos de exibição e fornece o [UpdateAllViews](../Topic/CDocument::UpdateAllViews.md) a função de membro para informando a vários modos de exibição quando os dados do documento foi alterado.  
  
 MFC oferece suporte a três interfaces de usuário comuns que exigem várias exibições no mesmo documento. Esses modelos são:  
  
-   Objetos de exibição da mesma classe, cada um em uma janela de quadro MDI documento.  
  
     Você talvez queira oferecer suporte à criação de uma segunda janela de quadro em um documento. O usuário pode escolher uma nova janela de comando para abrir um segundo quadro com um modo de exibição do mesmo documento e, em seguida, use os dois quadros para exibir diferentes partes do documento simultaneamente. A estrutura suporta o comando nova janela no menu janela para aplicativos MDI duplicando a janela de quadro inicial e a exibição anexado ao documento.  
  
-   Objetos de exibição da mesma classe na mesma janela de quadro do documento.  
  
     Janelas separadoras dividir o espaço do modo de exibição de uma janela de documento único em vários modos de exibição separados do documento. O framework cria vários objetos de exibição da mesma classe de exibição. Para obter mais informações, consulte [janelas separadoras](#_core_splitter_windows).  
  
-   Exibir objetos de classes diferentes em uma janela de quadro.  
  
     Neste modelo, uma variação da janela separadora, vários modos de exibição compartilham uma janela de quadro único. As exibições são construídas a partir de classes diferentes, cada modo de exibição fornece uma maneira diferente de exibir o mesmo documento. Por exemplo, um modo de exibição pode mostrar um documento de processamento de texto no modo normal, enquanto o outro modo de exibição mostra\-lo no modo de estrutura de tópicos. Um controle de splitter permite ao usuário ajustar o tamanho relativo dos modos de exibição.  
  
 A figura a seguir, dividido em partes a, b e c, mostra os três modelos de interface do usuário na ordem apresentada acima.  
  
 ![Várias Interfaces de usuário de modo de exibição](../mfc/media/vc37a71.png "vc37A71")  
Interfaces de usuário de exibição de vários  
  
 O framework fornece esses modelos ao implementar o comando nova janela e fornecendo a classe [CSplitterWnd](../mfc/reference/csplitterwnd-class.md), conforme discutido em [janelas separadoras](#_core_splitter_windows). Você pode implementar outros modelos de usá\-los como ponto de partida. Para programas de exemplo que ilustram as diferentes configurações de modos de exibição, janelas de quadro e separadores, consulte [exemplos de MFC](../top/visual-cpp-samples.md).  
  
 Para obter mais informações sobre `UpdateAllViews`, consulte a classe [CView](../Topic/CView%20Class.md) no *referência da MFC* e [Rabisco exemplo](../top/visual-cpp-samples.md).  
  
##  <a name="_core_multiple_frame_windows"></a> Várias janelas com moldura  
 Você pode usar o comando nova janela no menu janela para aplicativos MDI para criar uma segunda janela de quadro no mesmo documento. Para obter mais informações, consulte o primeiro modelo na Figura [Exibir várias Interfaces de usuário](#_core_multiple.2d.view_user_interfaces).  
  
##  <a name="_core_splitter_windows"></a> Janelas separadoras  
 Em uma janela de separador, a janela é, ou pode ser dividida em duas ou mais painéis roláveis. Um divisor control \(ou "dividir a caixa"\) do quadro de janela ao lado de barras de rolagem permite ao usuário ajustar o tamanho relativo dos painéis. Cada painel é um modo de exibição no mesmo documento. Divisores "dinâmicos", as exibições são da mesma classe, conforme mostrado na figura a parte b [Exibir várias Interfaces de usuário](#_core_multiple.2d.view_user_interfaces). Em "static" divisores, os modos de exibição podem ser de classes diferentes. Janelas separadoras de ambos os tipos são suportadas pela classe [CSplitterWnd](../mfc/reference/csplitterwnd-class.md).  
  
 Janelas separadoras dinâmicas, com modos de exibição da mesma classe, permitem ao usuário dividir a janela em vários painéis à vontade e, em seguida, role painéis diferentes para diferentes partes do documento. O usuário também pode remover a divisão de janela para remover os modos de exibição adicionais. As janelas separadoras adicionadas para o [exemplo Rabisco](../top/visual-cpp-samples.md) são um exemplo. Este tópico descreve a técnica para a criação de janelas separadoras dinâmicas. Uma janela separadora dinâmica é mostrada na figura a parte b [Exibir várias Interfaces de usuário](#_core_multiple.2d.view_user_interfaces).  
  
 Janelas separadoras estáticas, modos de exibição de classes diferentes, começar com a janela dividida em vários painéis, cada um com uma finalidade diferente. Por exemplo, no editor de bitmap do Visual C\+\+, a janela de imagem mostra dois painéis lado a lado. O painel esquerdo exibe uma imagem life\-sized do bitmap. O painel direito exibe uma imagem ampliada ou ampliada do mesmo bitmap. Os painéis são separados por uma "barra divisória" que o usuário pode arrastar para alterar o tamanho relativo dos painéis. Uma janela de separador estático é mostrada na parte c da figura [Exibir várias Interfaces de usuário](#_core_multiple.2d.view_user_interfaces).  
  
 Para obter mais informações, consulte a classe [CSplitterWnd](../mfc/reference/csplitterwnd-class.md) no *referência da MFC* e [exemplos de MFC](../top/visual-cpp-samples.md).  
  
## Consulte também  
 [Arquitetura de documento\/exibição](../Topic/Document-View%20Architecture.md)