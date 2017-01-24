---
title: "Criando um aplicativo MFC no estilo de Explorador de Arquivos | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "vc.appwiz.mfcexplorer.project"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "navegadores, Aplicativos de estilo do Explorer"
  - "Aplicativos de estilo do Explorer, criando"
  - "Aplicativos MFC, estilo do Windows Explorer"
ms.assetid: f843ab5d-2d5d-41ca-88a4-badc0d2f8052
caps.latest.revision: 12
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Criando um aplicativo MFC no estilo de Explorador de Arquivos
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Muitos aplicativos do sistema windows usam a interface do usuário \(UI\) para o Explorador de Arquivos.  Quando você inicia o gerenciador de Arquivos, por exemplo, você vê um aplicativo por uma barra vertical de divisão que divide a área do cliente.  O lado esquerdo da área de cliente fornece navegação e os recursos de navegação, e o lado direito da área de cliente mostra os detalhes pertinentes à seleção no painel esquerdo.  Quando um usuário clica em um item no painel esquerdo, será repopulado de aplicativo do painel direito.  Em um aplicativo MDI, você pode usar comandos no menu de **Exibir** alterar a quantidade de detalhes mostrada no painel direito. \(Em um aplicativo de nível superior do documento de SDI ou múltiplos, você pode alterar os detalhes usando os botões da barra de ferramentas somente\).  
  
 O conteúdo dos painéis depende do aplicativo.  Em um navegador do sistema de arquivos, o painel esquerdo mostra uma exibição hierárquica dos diretórios ou os computadores, ou grupos do computador, quando o painel direito, exibir pastas arquivos individuais, ou computadores, e os detalhes sobre elas.  O conteúdo não necessariamente têm que ser arquivos.  Podem ser mensagens de email, relatórios de erros, ou outros itens em um base de dados.  
  
 O assistente cria as seguintes classes para você:  
  
-   A classe de **CLeftView** define o painel esquerdo da área do cliente.  Sempre é derivado de [CTreeView](../../mfc/reference/ctreeview-class.md).  
  
-   A classe C*ProjName*View define o painel direito da área do cliente.  Por padrão, é derivada de [CListView](../../mfc/reference/clistview-class.md) mas pode ser outro tipo de exibição dependendo da classe que você especifica na lista de **Classe Base** na página de [Classes geradas](../../mfc/reference/generated-classes-mfc-application-wizard.md) do assistente.  
  
 O aplicativo gerado pode ter uma interface \(SDI\) de um único documento, um ambiente MDI \(MDI\), ou uma arquitetura de vários documentos de nível superior.  Cada janela de quadro o aplicativo cria é dividida verticalmente usando [CSplitterWnd](../../mfc/reference/csplitterwnd-class.md).  Codificar esse tipo de aplicativo é semelhante ao codificar um aplicativo normal de MFC que usa um separador, exceto que este tipo de aplicativo tiver exibições separadas de controle em cada painel do separador.  
  
 Se você usar a exibição de lista padrão no painel direito, o assistente criará opções adicionais no menu \(em aplicativos MDI somente\) e botões da barra de ferramentas para alternar o estilo de exibição entre ícones grandes, ícones pequenos, lista, e modos de detalhes.  
  
### Para começar a criar um executável MFC de Explorer\- estilo de Arquivo  
  
1.  Siga as instruções em [Criando um aplicativo de MFC](../../mfc/reference/creating-an-mfc-application.md).  
  
2.  Na página de [Tipo de aplicativo](../Topic/Application%20Type,%20MFC%20Application%20Wizard.md) do assistente de aplicativo MFC, selecione o estilo do projeto de **Explorador de Arquivos** .  
  
3.  Definir todas as outras opções desejadas nas outras páginas do assistente.  
  
4.  Clique em **Concluir** para gerar o aplicativo do esqueleto.  
  
 Para obter mais informações, consulte:  
  
-   [Vários tipos de documento, exibições e janelas com moldura](../../mfc/multiple-document-types-views-and-frame-windows.md)  
  
-   [Classes derivadas da exibição](../../mfc/derived-view-classes-available-in-mfc.md)  
  
-   [Opções de design do aplicativo](../../mfc/application-design-choices.md)  
  
## Consulte também  
 [Assistente de aplicativo MFC](../Topic/MFC%20Application%20Wizard.md)   
 [Criando um aplicativo MFC no estilo de navegador da Web](../../mfc/reference/creating-a-web-browser-style-mfc-application.md)   
 [Criando um aplicativo MFC com base em formulários](../Topic/Creating%20a%20Forms-Based%20MFC%20Application.md)