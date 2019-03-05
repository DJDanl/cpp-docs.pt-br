---
title: Criando um aplicativo MFC no estilo de Explorador de Arquivos
ms.date: 11/04/2016
f1_keywords:
- vc.appwiz.mfcexplorer.project
helpviewer_keywords:
- browsers [MFC], Explorer-style applications
- MFC applications [MFC], Windows Explorer-style
- Explorer-style applications [MFC], creating
ms.assetid: f843ab5d-2d5d-41ca-88a4-badc0d2f8052
ms.openlocfilehash: 16969b7ef9c0447dfce971af8d329c5b93367041
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57304880"
---
# <a name="creating-a-file-explorer-style-mfc-application"></a>Criando um aplicativo MFC no estilo de Explorador de Arquivos

Muitos aplicativos de sistema do Windows usam a interface do usuário (IU) para o Explorador de arquivos. Quando você inicia o Explorador de arquivos, por exemplo, você ver um aplicativo com um vertical barra divisora entre a área de cliente. O lado esquerdo da área de cliente fornece navegação e recursos de navegação e o lado direito da área de cliente mostra detalhes pertinentes à seleção no painel esquerdo. Quando um usuário clica em um item no painel esquerdo, o aplicativo preenche novamente o painel direito. Em um aplicativo MDI, você pode usar comandos na **exibição** menu para alterar a quantidade de detalhes mostrados no painel direito. (Em um SDI ou vários aplicativos de nível superior do documento, você pode alterar os detalhes usando apenas os botões de barra de ferramentas.)

O conteúdo dos painéis depende do aplicativo. Em um navegador de sistema de arquivos, o painel esquerdo mostra uma exibição hierárquica de diretórios ou computadores ou grupos de computadores, enquanto o painel direito exibe pastas, arquivos individuais, ou as máquinas e detalhes sobre eles. O conteúdo não precisa necessariamente ser arquivos. Eles poderiam ser mensagens de email, relatórios de erros ou outros itens em um banco de dados.

O assistente cria as classes a seguir para você:

- O `CLeftView` classe define o painel esquerdo da área de cliente. Ela sempre é derivada de [CTreeView](../../mfc/reference/ctreeview-class.md).

- O C*NomeDoProjeto*exibir classe define o painel direito da área de cliente. Por padrão, ela é derivada de [CListView](../../mfc/reference/clistview-class.md) , mas pode ser outro tipo de exibição, dependendo da classe que você especifique do **classe Base** listar no [Classes geradas](../../mfc/reference/generated-classes-mfc-application-wizard.md) página das Assistente.

O aplicativo gerado pode ter uma interface de documento único (SDI), uma interface de documentos múltiplos (MDI) ou uma arquitetura de vários documentos de nível superior. Cada janela de quadro que cria o aplicativo é dividida verticalmente a usando [CSplitterWnd](../../mfc/reference/csplitterwnd-class.md). Esse tipo de aplicativo de codificação é semelhante a codificação de um aplicativo normal do MFC que usa um divisor, exceto que esse tipo de aplicativo tem modos de exibição de controle separado dentro de cada painel do divisor.

Se você usar o modo de exibição de lista padrão no painel direito, o assistente cria as opções de menu adicionais (em aplicativos MDI apenas) e botões de barra de ferramentas para alternar o estilo da exibição entre ícones grandes, ícones pequenos, lista e modos de detalhes.

### <a name="to-begin-creating-a-file-explorer-style-mfc-executable"></a>Para começar a criar um executável de estilo do Explorer arquivo MFC

1. Siga as instruções em [criando um aplicativo MFC](../../mfc/reference/creating-an-mfc-application.md).

1. No Assistente de aplicativo MFC [tipo de aplicativo](../../mfc/reference/application-type-mfc-application-wizard.md) página, selecione o **Explorador de arquivos** estilo do projeto.

1. Defina outras opções desejado nas outras páginas do assistente.

1. Clique em **concluir** para gerar o aplicativo de esqueleto.

Para obter mais informações, consulte:

- [Vários tipos de documento, exibições e janelas com moldura](../../mfc/multiple-document-types-views-and-frame-windows.md)

- [Classes de exibição derivadas](../../mfc/derived-view-classes-available-in-mfc.md)

- [Opções de design do aplicativo](../../mfc/application-design-choices.md)

## <a name="see-also"></a>Consulte também

[Assistente de aplicativo do MFC](../../mfc/reference/mfc-application-wizard.md)<br/>
[Criando um aplicativo MFC no estilo de navegador da Web](../../mfc/reference/creating-a-web-browser-style-mfc-application.md)<br/>
[Criando um aplicativo MFC com base em formulários](../../mfc/reference/creating-a-forms-based-mfc-application.md)
