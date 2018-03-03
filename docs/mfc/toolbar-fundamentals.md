---
title: Fundamentos da barra de ferramentas | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- RT_TOOLBAR
dev_langs:
- C++
helpviewer_keywords:
- embedding toolbar in frame window class [MFC]
- application wizards [MFC], installing default application toolbars
- toolbars [MFC], creating
- resources [MFC], toolbar
- toolbar controls [MFC], toolbars created using Application Wizard
- toolbar controls [MFC], command ID
- RT_TOOLBAR resource [MFC]
- toolbars [MFC], adding default using Application Wizard
- LoadBitmap method [MFC], toolbars
- Toolbar editor [MFC], Application Wizard
- command IDs [MFC], toolbar buttons
- SetButtons method [MFC]
- CToolBar class [MFC], default toolbars in Application Wizard
- frame window classes [MFC], toolbar embedded in
- LoadToolBar method [MFC]
ms.assetid: cc00aaff-8a56-433b-b0c0-b857d76b4ffd
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 136b9f5dd36c9e4092b8e5c15ac1738541cf71f2
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="toolbar-fundamentals"></a>Fundamentos da barra de ferramentas
Este artigo descreve a implementação MFC fundamental que permite adicionar uma barra de ferramentas padrão para seu aplicativo selecionando uma opção no Assistente do aplicativo. Os tópicos abordados incluem:  
  
-   [A opção de barra de ferramentas do Assistente de aplicativo](#_core_the_appwizard_toolbar_option)  
  
-   [A barra de ferramentas no código](#_core_the_toolbar_in_code)  
  
-   [O recurso da barra de ferramentas de edição](#_core_editing_the_toolbar_resource)  
  
-   [Várias barras de ferramentas](#_core_multiple_toolbars)  
  
##  <a name="_core_the_appwizard_toolbar_option"></a>A opção de barra de ferramentas do Assistente de aplicativo  
 Para obter uma única barra de ferramentas com botões padrão, selecione a opção de barra de ferramentas padrão de encaixe na página de rotulado como recursos de Interface do usuário. Isso adiciona código para seu aplicativo que:  
  
-   Cria o objeto de barra de ferramentas.  
  
-   Gerencia a barra de ferramentas, incluindo a capacidade para encaixar ou flutuar.  
  
##  <a name="_core_the_toolbar_in_code"></a>A barra de ferramentas no código  
 A barra de ferramentas é um [CToolBar](../mfc/reference/ctoolbar-class.md) objeto declarado como um membro de dados do seu aplicativo **CMainFrame** classe. Em outras palavras, o objeto de barra de ferramentas está incorporado no objeto de janela do quadro principal. Isso significa que o MFC cria a barra de ferramentas quando ele cria a janela do quadro e destrói a barra de ferramentas quando ele destrói a janela do quadro. A seguinte declaração de classe parcial, para um aplicativo de interface MDI vários documentos, mostra os membros de dados para uma barra de ferramentas inserida e uma barra de status incorporada. Ele também mostra a substituição do `OnCreate` função de membro.  
  
 [!code-cpp[NVC_MFCListView#6](../atl/reference/codesnippet/cpp/toolbar-fundamentals_1.h)]  
  
 Criação de barra de ferramentas ocorre em **CMainFrame::OnCreate**. Chamadas MFC [OnCreate](../mfc/reference/cwnd-class.md#oncreate) depois de criar a janela do quadro, mas antes de se tornar visível. O padrão `OnCreate` que o Assistente de aplicativo gera realiza as seguintes tarefas de barra de ferramentas:  
  
1.  Chamadas de `CToolBar` do objeto [criar](../mfc/reference/ctoolbar-class.md#create) a função de membro para criar subjacente [CToolBarCtrl](../mfc/reference/ctoolbarctrl-class.md) objeto.  
  
2.  Chamadas [LoadToolBar](../mfc/reference/ctoolbar-class.md#loadtoolbar) para carregar as informações de recurso da barra de ferramentas.  
  
3.  Chama funções para habilitar o encaixe, flutuantes e dicas de ferramenta. Para obter detalhes sobre essas chamadas, consulte o artigo [encaixe e barras de ferramentas flutuantes](../mfc/docking-and-floating-toolbars.md).  
  
> [!NOTE]
>  O exemplo de MFC geral [DOCKTOOL](../visual-cpp-samples.md) inclui ilustrações das barras de ferramentas MFC antigas e novas. As barras de ferramentas que usam **COldToolbar** exigem chamadas na etapa 2 para `LoadBitmap` (em vez de `LoadToolBar`) e `SetButtons`. Novas barras de ferramentas exigem chamadas para `LoadToolBar`.  
  
 O encaixe flutuante e chamadas de dicas de ferramenta são opcionais. Você pode remover as linhas de `OnCreate` se você preferir. O resultado é uma barra de ferramentas que permanece fixo, não é possível float ou encaixe-o novamente e não é possível exibir dicas de ferramenta.  
  
##  <a name="_core_editing_the_toolbar_resource"></a>O recurso da barra de ferramentas de edição  
 A barra de ferramentas padrão obter com o Assistente de aplicativo é baseada em um **RT_TOOLBAR** recurso personalizado, introduzido na versão 4.0 do MFC. Você pode editar esse recurso com o [editor de barra de ferramentas](../windows/toolbar-editor.md). O editor permite que você facilmente adicionar, excluir e reorganizar os botões. Ele contém um editor gráfico para os botões que é muito semelhantes para o editor gráfico geral no Visual C++. Se você editou barras de ferramentas nas versões anteriores do Visual C++, você encontrará a tarefa mais fácil agora.  
  
 Para se conectar a um botão de barra de ferramentas para um comando, você concede botão uma ID de comando, como `ID_MYCOMMAND`. Especifique a ID de comando na página de propriedades do botão no editor de barra de ferramentas. Em seguida, crie uma função de manipulador para o comando (consulte [mapeando mensagens para funções](../mfc/reference/mapping-messages-to-functions.md) para obter mais informações).  
  
 Novo [CToolBar](../mfc/reference/ctoolbar-class.md) funções de membro de trabalham com o **RT_TOOLBAR** recursos. [LoadToolBar](../mfc/reference/ctoolbar-class.md#loadtoolbar) agora assume o lugar de [LoadBitmap](../mfc/reference/ctoolbar-class.md#loadbitmap) para carregar o bitmap das imagens de botão de barra de ferramentas, e [SetButtons](../mfc/reference/ctoolbar-class.md#setbuttons) para definir os estilos de botão e conectar botões com imagens de bitmap.  
  
 Para obter detalhes sobre como usar o editor de barra de ferramentas, consulte [Editor de barra de ferramentas](../windows/toolbar-editor.md).  
  
##  <a name="_core_multiple_toolbars"></a>Várias barras de ferramentas  
 O Assistente de aplicativo fornece ferramentas padrão de um. Se você precisar de mais de uma barra de ferramentas em seu aplicativo, você pode modelar o código de barras de ferramentas adicionais com base no código gerado pelo Assistente para a barra de ferramentas padrão.  
  
 Se você quiser exibir uma barra de ferramentas como o resultado de um comando, você precisará:  
  
-   Criar um novo recurso da barra de ferramentas com a barra de ferramentas do editor e carregá-la em `OnCreate` com o [LoadToolbar](../mfc/reference/ctoolbar-class.md#loadtoolbar) função de membro.  
  
-   Inserir um novo [CToolBar](../mfc/reference/ctoolbar-class.md) objeto em sua classe de janela do quadro principal.  
  
-   Verifique que chama a função apropriada no `OnCreate` para encaixar ou flutuar a barra de ferramentas, defina seus estilos e assim por diante.  
  
### <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre  
  
-   [Implementação de barra de ferramentas MFC (informações de visão geral das barras de ferramentas)](../mfc/mfc-toolbar-implementation.md)  
  
-   [Encaixando e flutuando barras de ferramentas](../mfc/docking-and-floating-toolbars.md)  
  
-   [Dicas de ferramenta da barra de ferramentas](../mfc/toolbar-tool-tips.md)  
  
-   O [CToolBar](../mfc/reference/ctoolbar-class.md) e [CToolBarCtrl](../mfc/reference/ctoolbarctrl-class.md) classes  
  
-   [Trabalhando com o controle de barra de ferramentas](../mfc/working-with-the-toolbar-control.md)  
  
-   [Usando as barras de ferramentas antigas](../mfc/using-your-old-toolbars.md)  
  
## <a name="see-also"></a>Consulte também  
 [Implementação da barra de ferramentas do MFC](../mfc/mfc-toolbar-implementation.md)

