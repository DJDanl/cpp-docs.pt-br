---
title: "Fundamentos da barra de ferramentas | Microsoft Docs"
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
  - "RT_TOOLBAR"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "assistentes de aplicativo [C++], instalando barras de ferramentas de aplicativo padrão"
  - "IDs de comando, botões da barra de ferramentas"
  - "Classe CToolBar, barras de ferramentas no Assistente de Aplicativo"
  - "inserindo barra de ferramentas na classe de janela com moldura"
  - "classes de janela com moldura, barra de ferramentas inserida em"
  - "Método LoadBitmap, barras de ferramentas"
  - "Método LoadToolBar"
  - "recursos [MFC], barra de ferramentas"
  - "Recurso RT_TOOLBAR"
  - "Método SetButtons"
  - "controles de barra de ferramentas [MFC], ID de comando"
  - "controles de barra de ferramentas [MFC], barras de ferramentas criadas com o Assistente de Aplicativo"
  - "Editor da barra de ferramentas, Assistente de Aplicativo"
  - "barras de ferramentas [C++], adicionando padrão com o Assistente de Aplicativo"
  - "barras de ferramentas [C++], criando"
ms.assetid: cc00aaff-8a56-433b-b0c0-b857d76b4ffd
caps.latest.revision: 12
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Fundamentos da barra de ferramentas
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este artigo descreve a implementação fundamental de MFC que permite adicionar uma barra de ferramentas padrão para o seu aplicativo selecionando uma opção no assistente do aplicativo.  Os tópicos abordados incluem:  
  
-   [A opção da barra de ferramentas do assistente de aplicativo](#_core_the_appwizard_toolbar_option)  
  
-   [A barra de ferramentas do código](#_core_the_toolbar_in_code)  
  
-   [Editando o recurso da barra de ferramentas](#_core_editing_the_toolbar_resource)  
  
-   [Mais barras de ferramentas](#_core_multiple_toolbars)  
  
##  <a name="_core_the_appwizard_toolbar_option"></a> A opção da barra de ferramentas do assistente de aplicativo  
 Para obter uma única barra de ferramentas com botões padrão, selecione a opção padrão da barra de ferramentas de encaixe na página rotulada recursos de interface do usuário.  Isso adicionará o código no aplicativo que:  
  
-   Cria o objeto da barra de ferramentas.  
  
-   Gerencia a barra de ferramentas, inclusive sua capacidade de inserir ou float.  
  
##  <a name="_core_the_toolbar_in_code"></a> A barra de ferramentas do código  
 A barra de ferramentas é um objeto de [CToolBar](../mfc/reference/ctoolbar-class.md) declarado como um membro de dados da classe de **CMainFrame** do seu aplicativo.  Ou seja o objeto da barra de ferramentas é inserido no objeto da janela principal do quadro.  Isso significa que o MFC cria a barra de ferramentas quando cria a janela do quadro e destrói a barra de ferramentas quando destrói a janela do quadro.  A seguinte declaração parcial da classe, para um aplicativo \(MDI\) de interface de documentos, mostra membros de dados para uma barra de ferramentas inserido e uma barra de status inserido.  Também mostra a substituição da função de membro de `OnCreate` .  
  
 [!CODE [NVC_MFCListView#6](../CodeSnippet/VS_Snippets_Cpp/NVC_MFCListView#6)]  
  
 A criação da barra de ferramentas ocorre em **CMainFrame::OnCreate**.  MFC O chama [OnCreate](../Topic/CWnd::OnCreate.md) depois de criar a janela para o quadro mas antes que fique visível.  `OnCreate` padrão que o assistente do aplicativo gerenciar faz as seguintes tarefas da barra de ferramentas:  
  
1.  Chama a função de membro de [Crie](../Topic/CToolBar::Create.md) do objeto de `CToolBar` para criar o objeto subjacente de [CToolBarCtrl](../mfc/reference/ctoolbarctrl-class.md) .  
  
2.  Chama [LoadToolBar](../Topic/CToolBar::LoadToolBar.md) para carregar informações de recursos da barra de ferramentas.  
  
3.  As chamadas funcionam para habilitar o encaixe, flutuação, e as dicas de ferramenta.  Para obter detalhes sobre essas chamadas, consulte o artigo [Barras de ferramentas de acoplamento flexível e flutuante](../mfc/docking-and-floating-toolbars.md).  
  
> [!NOTE]
>  O exemplo [DOCKTOOL](../top/visual-cpp-samples.md) gerais de MFC inclui ilustrações de barras de ferramentas novos e antigos MFC.  As barras de ferramentas que usam **COldToolbar** exigem chamadas na etapa 2 para `LoadBitmap` \(em vez de `LoadToolBar`\) e a `SetButtons`.  As novas barras de ferramentas requerem chamadas a `LoadToolBar`.  
  
 Encaixe o, flutuação, e as chamadas das dicas de ferramentas são opcionais.  Você pode remover as linhas de `OnCreate` se preferir.  O resultado é uma barra de ferramentas que permanece fixa, não é possível de float ou redock e conseguir exibir dicas de ferramenta.  
  
##  <a name="_core_editing_the_toolbar_resource"></a> Editando o recurso da barra de ferramentas  
 A barra de ferramentas padrão que você obtém o com o assistente de aplicativo é baseada em um recurso personalizado de **RT\_TOOLBAR** , apresentado na versão 4,0 do MFC.  Você poderá editar esse recurso com [editor da barra de ferramentas](../mfc/toolbar-editor.md).  O publicador permite facilmente adicionar, excluir, e reordenar os botões.  Contém um editor gráfico dos botões que é muito semelhante ao editor de gráficos geral no Visual C\+\+.  Se você editar barras de ferramentas em versões anteriores do Visual C\+\+, você encontrará a tarefa muito mais fácil agora.  
  
 Para conectar um botão da barra de ferramentas para um comando, você fornece ao botão uma ID de comando, como `ID_MYCOMMAND`.  Especifique a ID do comando na página de propriedades do publicador no botão da barra de ferramentas.  Crie uma função de manipulador para o comando \(consulte [Mensagens de mapeamento a funções](../Topic/Mapping%20Messages%20to%20Functions.md) para obter mais informações\).  
  
 Novo trabalho das funções de membro de [CToolBar](../mfc/reference/ctoolbar-class.md) com o recurso de **RT\_TOOLBAR** .  [LoadToolBar](../Topic/CToolBar::LoadToolBar.md) tem agora o local de [LoadBitmap](../Topic/CToolBar::LoadBitmap.md) para carregar o bitmap das imagens do botão da barra de ferramentas, e [SetButtons](../Topic/CToolBar::SetButtons.md) para definir os estilos do botão e para conectar os botões com bitmap create imagem.  
  
 Para obter detalhes sobre como usar o editor da barra de ferramentas, consulte [Editor da barra de ferramentas](../mfc/toolbar-editor.md).  
  
##  <a name="_core_multiple_toolbars"></a> Mais barras de ferramentas  
 O assistente de aplicativo fornece com uma barra de ferramentas padrão.  Se você precisar de mais de uma barra de ferramentas em seu aplicativo, você pode definir seu código para as barras de ferramentas adicionais com base no código script gerado para a barra de ferramentas padrão.  
  
 Se você quiser exibir uma barra de ferramentas como o resultado de um comando, você precisará:  
  
-   Crie um novo recurso da barra de ferramentas com o publicador da barra de ferramentas e carregá\-los em `OnCreate` com a função de membro de [LoadToolbar](../Topic/CToolBar::LoadToolBar.md) .  
  
-   Digitar um novo objeto de [CToolBar](../mfc/reference/ctoolbar-class.md) em sua classe da janela principal do quadro.  
  
-   Faça as chamadas de funções apropriadas em `OnCreate` para inserir ou em float a barra de ferramentas, defina os estilos, e assim por diante.  
  
### Que você deseja saber mais?  
  
-   [Implementação da barra de ferramentas \(MFC informações de visão geral em barras de ferramentas\)](../mfc/mfc-toolbar-implementation.md)  
  
-   [Barras de ferramentas de acoplamento flexível e flutuante](../mfc/docking-and-floating-toolbars.md)  
  
-   [Dicas de ferramenta da barra de ferramentas](../Topic/Toolbar%20Tool%20Tips.md)  
  
-   As classes de [CToolBar](../mfc/reference/ctoolbar-class.md) e de [CToolBarCtrl](../mfc/reference/ctoolbarctrl-class.md)  
  
-   [Trabalhar com o controle da barra de ferramentas](../Topic/Working%20with%20the%20Toolbar%20Control.md)  
  
-   [Usando suas barras de ferramentas antigos](../Topic/Using%20Your%20Old%20Toolbars.md)  
  
## Consulte também  
 [Implementação da barra de ferramentas MFC](../mfc/mfc-toolbar-implementation.md)