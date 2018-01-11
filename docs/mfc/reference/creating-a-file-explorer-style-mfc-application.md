---
title: Criando um aplicativo MFC no estilo do Explorer arquivo | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: vc.appwiz.mfcexplorer.project
dev_langs: C++
helpviewer_keywords:
- browsers [MFC], Explorer-style applications
- MFC applications [MFC], Windows Explorer-style
- Explorer-style applications [MFC], creating
ms.assetid: f843ab5d-2d5d-41ca-88a4-badc0d2f8052
caps.latest.revision: "12"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 6098e451b4ebc4caf2bb7fad99ea2e407e4872c3
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="creating-a-file-explorer-style-mfc-application"></a>Criando um aplicativo MFC no estilo de Explorador de Arquivos
Muitos aplicativos de sistema do Windows usam a interface do usuário (UI) para o Explorador de arquivos. Quando você inicia o Explorador de arquivos, por exemplo, você ver um aplicativo com uma divisão vertical barra dividir a área cliente. À esquerda da área cliente fornece navegação e os recursos de navegação e o lado direito da área cliente mostra detalhes pertinentes à seleção no painel esquerdo. Quando um usuário clica em um item no painel esquerdo, o aplicativo preenche novamente o painel direito. Em um aplicativo MDI, você pode usar comandos no **exibição** menu para alterar a quantidade de detalhes exibidos no painel direito. (Em um SDI ou vários aplicativos de nível superior do documento, você pode alterar os detalhes usando os botões da barra de ferramentas somente.)  
  
 O conteúdo dos painéis depende do aplicativo. Em um navegador de sistema de arquivos, o painel esquerdo mostra uma exibição hierárquica de diretórios ou computadores ou grupos de computadores, enquanto o painel direito exibe pastas, arquivos individuais, ou máquinas e detalhes sobre elas. O conteúdo não precisam necessariamente ser arquivos. Eles podem ser outros itens em um banco de dados, relatórios de erros ou mensagens de email.  
  
 O assistente cria as classes a seguir para você:  
  
-   O **CLeftView** classe define o painel esquerdo da área cliente. Ele sempre é derivado do [CTreeView](../../mfc/reference/ctreeview-class.md).  
  
-   C*NomeDoProjeto*exibir classe define o painel direito da área do cliente. Por padrão, ele é derivado do [CListView](../../mfc/reference/clistview-class.md) , mas pode ser outro tipo de exibição dependendo da classe que você especificar na **classe Base** lista o [Classes geradas pelo](../../mfc/reference/generated-classes-mfc-application-wizard.md) página do Assistente.  
  
 O aplicativo gerado pode ter uma interface de documento único (SDI), uma interface de documentos múltiplos (MDI) ou uma arquitetura de vários documentos de nível superior. Cada janela do quadro cria o aplicativo é dividir verticalmente usando [CSplitterWnd](../../mfc/reference/csplitterwnd-class.md). Este tipo de aplicativo de codificação é semelhante ao codificar um aplicativo MFC normal que usa uma separador, exceto que esse tipo de aplicativo tem modos de exibição de controle separado dentro de cada painel do divisor.  
  
 Se você usar o modo de exibição de lista padrão no painel direito, o assistente cria as opções de menu adicionais (em apenas aplicativos MDI) e botões de barra de ferramentas para alternar o estilo da exibição entre ícones grandes, ícones pequenos, lista e modos de detalhes.  
  
### <a name="to-begin-creating-a-file-explorer-style-mfc-executable"></a>Para começar a criar um executável de estilo do Explorer arquivo MFC  
  
1.  Siga as instruções na [criando um aplicativo MFC](../../mfc/reference/creating-an-mfc-application.md).  
  
2.  No Assistente de aplicativo MFC [tipo de aplicativo](../../mfc/reference/application-type-mfc-application-wizard.md) página, selecione o **Explorador de arquivos** estilo de projeto.  
  
3.  Defina quaisquer outras opções que desejar nas outras páginas do assistente.  
  
4.  Clique em **concluir** para gerar o aplicativo de esqueleto.  
  
 Para obter mais informações, consulte:  
  
-   [Vários tipos de documento, exibições e janelas com moldura](../../mfc/multiple-document-types-views-and-frame-windows.md)  
  
-   [Classes de exibição derivadas](../../mfc/derived-view-classes-available-in-mfc.md)  
  
-   [Opções de design do aplicativo](../../mfc/application-design-choices.md)  
  
## <a name="see-also"></a>Consulte também  
 [Assistente de aplicativo MFC](../../mfc/reference/mfc-application-wizard.md)   
 [Criando um aplicativo MFC no estilo de navegador da Web](../../mfc/reference/creating-a-web-browser-style-mfc-application.md)   
 [Criando um aplicativo MFC com base em formulários](../../mfc/reference/creating-a-forms-based-mfc-application.md)

