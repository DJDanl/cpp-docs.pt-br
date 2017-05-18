---
title: Criando um aplicativo MFC no estilo do Explorer arquivo | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- vc.appwiz.mfcexplorer.project
dev_langs:
- C++
helpviewer_keywords:
- browsers, Explorer-style applications
- MFC applications, Windows Explorer-style
- Explorer-style applications, creating
ms.assetid: f843ab5d-2d5d-41ca-88a4-badc0d2f8052
caps.latest.revision: 12
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: f70afaa5653138e10b6ce0686437ee2ea6e1a9e4
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="creating-a-file-explorer-style-mfc-application"></a>Criando um aplicativo MFC no estilo de Explorador de Arquivos
Muitos aplicativos de sistema do Windows usam a interface do usuário (UI) para o Explorador de arquivos. Ao iniciar o Gerenciador de arquivos, por exemplo, você ver um aplicativo com uma divisão vertical barra dividindo a área do cliente. O lado esquerdo da área do cliente fornece navegação e os recursos de navegação e o lado direito da área do cliente mostra detalhes pertinentes à seleção no painel esquerdo. Quando um usuário clica em um item no painel esquerdo, o aplicativo preenche novamente o painel direito. Em um aplicativo MDI, você pode usar comandos no **exibição** menu para alterar a quantidade de detalhes exibidos no painel à direita. (Em um SDI ou vários aplicativos de nível superior do documento, você pode alterar os detalhes usando os botões da barra de ferramentas somente.)  
  
 O conteúdo dos painéis depende do aplicativo. Em um navegador de sistema de arquivos, o painel esquerdo mostra uma exibição hierárquica de diretórios ou computadores ou grupos de computadores, enquanto o painel direito exibe pastas, arquivos individuais, ou máquinas e detalhes sobre elas. O conteúdo não necessariamente precisa ser arquivos. Ele pode ser mensagens de email, relatórios de erros ou outros itens em um banco de dados.  
  
 O assistente cria as classes a seguir para você:  
  
-   O **CLeftView** classe define um painel à esquerda da área do cliente. Ela sempre é derivada de [CTreeView](../../mfc/reference/ctreeview-class.md).  
  
-   O C*NomeDoProjeto*exibir classe define o painel direito da área do cliente. Por padrão, ela é derivada de [CListView](../../mfc/reference/clistview-class.md) , mas pode ser outro tipo de exibição dependendo da classe especificada do **classe Base** lista no [Classes geradas](../../mfc/reference/generated-classes-mfc-application-wizard.md) página do assistente.  
  
 Aplicativo gerado pode ter uma interface de documento único (SDI), uma interface de documentos múltiplos (MDI) ou uma arquitetura de vários documentos de nível superior. Cada janela de quadro cria o aplicativo é dividida verticalmente usando [CSplitterWnd](../../mfc/reference/csplitterwnd-class.md). Esse tipo de aplicativo de codificação é semelhante a um aplicativo MFC normal que usa um divisor de codificação, exceto que esse tipo de aplicativo tem modos de exibição de controle separado dentro de cada painel divisor.  
  
 Se você usar o modo de exibição de lista padrão no painel à direita, o assistente cria as opções de menu adicionais (em aplicativos MDI apenas) e botões de barra de ferramentas para alternar o estilo da exibição entre ícones grandes, ícones pequenos, lista e modos de detalhes.  
  
### <a name="to-begin-creating-a-file-explorer-style-mfc-executable"></a>Para começar a criar um executável estilo do Explorer arquivo MFC  
  
1.  Siga as instruções na [criando um aplicativo MFC](../../mfc/reference/creating-an-mfc-application.md).  
  
2.  No Assistente de aplicativo MFC [tipo de aplicativo](../../mfc/reference/application-type-mfc-application-wizard.md) página, selecione o **File Explorer** estilo de projeto.  
  
3.  Defina qualquer outra opção que desejar em outras páginas do assistente.  
  
4.  Clique em **concluir** para gerar o aplicativo de esqueleto.  
  
 Para obter mais informações, consulte:  
  
-   [Vários tipos de documento, exibições e janelas com moldura](../../mfc/multiple-document-types-views-and-frame-windows.md)  
  
-   [Classes de exibição derivadas](../../mfc/derived-view-classes-available-in-mfc.md)  
  
-   [Opções de Design de aplicativo](../../mfc/application-design-choices.md)  
  
## <a name="see-also"></a>Consulte também  
 [Assistente de aplicativo MFC](../../mfc/reference/mfc-application-wizard.md)   
 [Criando um aplicativo MFC no estilo de navegador da Web](../../mfc/reference/creating-a-web-browser-style-mfc-application.md)   
 [Criando um aplicativo MFC com base em formulários](../../mfc/reference/creating-a-forms-based-mfc-application.md)


