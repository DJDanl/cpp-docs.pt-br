---
title: "Documentos, exibi&#231;&#245;es e o Framework | Microsoft Docs"
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
  - "objetos de aplicativo [C++], relação a outros objetos MFC"
  - "aplicativos [MFC]"
  - "objetos de documento, em relação a outros objetos MFC"
  - "modelos de documento, objetos de modelo"
  - "arquitetura de documento/exibição, sobre arquitetura de documento/exibição"
  - "documentos [C++]"
  - "MFC [C++], estrutura de aplicativo"
  - "MFC [C++], documentos"
  - "MFC [C++], modos de exibição"
  - "relações de objetos MFC"
  - "objetos [C++], Aplicativos MFC"
  - "objetos de thread"
  - "exibir objetos, relação a outros objetos MFC"
ms.assetid: 409ddd9b-66ad-4625-84f7-bf55a41d697b
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Documentos, exibi&#231;&#245;es e o Framework
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

No centro da estrutura de MFC são os conceitos do documento e exibição.  Um documento é um objeto de dados que interage com o usuário em uma sessão de edição.  É criado pelo comando de `New` ou de **Abrir** no menu de **Arquivo** e normalmente salvo em um arquivo. \(Os documentos padrão, MFC derivados da classe **CDocument**, são diferentes dos documentos ativas e os documentos compostos OLE habilitados.\) Uma exibição é um objeto da janela através do usuário que interage com um documento.  
  
 Os objetos de chave em um aplicativo em execução são:  
  
-   O documento ou documentos.  
  
     A classe do documento \(derivada de [CDocument](../Topic/CDocument%20Class.md)\) especifica os dados de aplicativo.  
  
     Se desejar que a funcionalidade OLE em seu aplicativo, derivar a sua classe de documento de [COleDocument](../mfc/reference/coledocument-class.md) ou uma de suas classes derivadas, dependendo do tipo de funcionalidade que você precisa.  
  
-   A exibição ou exibições.  
  
     A classe da exibição \(derivada de [CView](../Topic/CView%20Class.md)\) é a janela do usuário “nos dados.” Os controles da classe de exibição como o usuário vê os dados do documento e interage com ela.  Em alguns casos, talvez você queira um documento para ter várias exibições dos dados.  
  
     Se você precisar rolar, derivar de [CScrollView](../mfc/reference/cscrollview-class.md).  Se a exibição tem uma interface do usuário que seja apresentada em um recurso de diálogo\- modelo, derivar de [CFormView](../mfc/reference/cformview-class.md).  Para dados simples de texto, use ou derivar de [CEditView](../Topic/CEditView%20Class.md).  Para um aplicativo de acesso a dados de autenticação baseado, como um programa de introdução de dados, para derivar de [CRecordView](../mfc/reference/crecordview-class.md) \(ODBC\).  Também estão disponíveis as classes [CTreeView](../mfc/reference/ctreeview-class.md), [CListView](../mfc/reference/clistview-class.md), e [CRichEditView](../mfc/reference/cricheditview-class.md).  
  
-   As janelas do quadro  
  
     As exibições são exibido dentro do windows “do quadro documento.” Em um aplicativo de SDI, a janela do quadro do documento também é “quadro da janela principal” para o aplicativo.  Em um aplicativo MDI, as janelas de documentos são exibidas janelas filho dentro de uma janela principal do quadro.  A classe principal derivado da janela quadro\- especifica os estilos e outras características do windows do tableau que contêm as exibições.  Se você precisar personalizar o windows do quadro, derivar de [CFrameWnd](../mfc/reference/cframewnd-class.md) para personalizar a janela do quadro do documento para aplicativos de SDI.  Derivar de [CMDIFrameWnd](../mfc/reference/cmdiframewnd-class.md) para personalizar a janela principal do quadro para aplicativos MDI.  Também derivar uma classe de [CMDIChildWnd](../mfc/reference/cmdichildwnd-class.md) para personalizar cada tipo distinto do windows do quadro de documentos MDI com suporte no seu aplicativo.  
  
-   O modelo ou modelos do documento  
  
     Um modelo de documento orquestra a criação de documentos, exibições, e do windows do quadro.  Uma classe específica do documento modelo, derivado da classe [CDocTemplate](../mfc/reference/cdoctemplate-class.md), o cria e gerencia todos os documentos abertos de um tipo.  Os aplicativos que dão suporte a mais de um tipo de documento têm vários modelos do documento.  Use a classe [CSingleDocTemplate](../mfc/reference/csingledoctemplate-class.md) para aplicativos de SDI, ou use a classe [CMultiDocTemplate](../mfc/reference/cmultidoctemplate-class.md) para aplicativos MDI.  
  
-   O objeto de aplicativo  
  
     A classe do aplicativo \(derivada de [CWinApp](../mfc/reference/cwinapp-class.md)\) controla todos os objetos acima e especifica o comportamento de aplicativo como a inicialização e a limpeza.  Esse do aplicativo e somente o objeto do aplicativo cria e gerencia os modelos do documento para todos os tipos de documento que o aplicativo dar suporte.  
  
-   Objetos do thread  
  
     Se seu aplicativo cria threads separados de execução — por exemplo, para executar cálculos no plano de fundo — você usará as classes derivadas de [CWinThread](../mfc/reference/cwinthread-class.md).  [CWinApp](../mfc/reference/cwinapp-class.md) próprio é derivado de `CWinThread` e representa o thread principal de execução \(ou o processo principal\) em seu aplicativo.  Você também pode usar o MFC threads secundários.  
  
 Em um aplicativo em execução, esses objetos cooperativa respondem a ações do usuário, junto com o limite por comandos e outras mensagens.  Um único objeto de aplicativo gerencia um ou mais modelos do documento.  Cada modelo de documento cria e gerencia um ou mais documentos \(dependendo se o aplicativo é SDI ou MDI\).  As exibições de usuário e manipulam um documento com uma exibição contida em uma janela do quadro.  A figura a seguir mostra as relações entre esses objetos para um aplicativo de SDI.  
  
 ![Executando objetos de aplicativo SDI](../mfc/media/vc386v1.png "vc386V1")  
Objetos em um aplicativo de SDI de execução  
  
 O restante desta família de artigos explica como as ferramentas da estrutura, o assistente de aplicativo MFC, e os editores de recursos, criam tais objetos, como eles trabalham em conjunto, e como devem ser usados em sua programação.  Os documentos, exibições, e as janelas de peças são discutidos em mais detalhes em [Objetos da janela](../mfc/window-objects.md) e em [Arquitetura do documento\/exibição](../Topic/Document-View%20Architecture.md).  
  
## Consulte também  
 [Usando as classes para escrever aplicativos para Windows](../Topic/Using%20the%20Classes%20to%20Write%20Applications%20for%20Windows.md)