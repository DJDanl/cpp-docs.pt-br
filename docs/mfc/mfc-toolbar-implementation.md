---
title: "Implementa&#231;&#227;o da barra de ferramentas MFC | Microsoft Docs"
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
  - "bitmaps [C++], barra de ferramentas"
  - "botões [C++], Barras de ferramentas MFC"
  - "Classe CToolBar, criando barras de ferramentas"
  - "Classe CToolBarCtrl, implementando barras de ferramentas"
  - "ancorando barras de ferramentas"
  - "barras de ferramentas flutuantes"
  - "Barras de ferramentas MFC"
  - "dicas de ferramenta [C++], ativando"
  - "controles de barra de ferramentas [MFC]"
  - "barras de ferramentas [C++]"
  - "barras de ferramentas [C++], criando"
  - "barras de ferramentas [C++], encaixe"
  - "barras de ferramentas [C++], flutuante"
  - "barras de ferramentas [C++], implementando barras de ferramentas MFC"
ms.assetid: af3319ad-c430-4f90-8361-e6a2c06fd084
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Implementa&#231;&#227;o da barra de ferramentas MFC
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Uma barra de ferramentas é [barra de controle](../Topic/Control%20Bars.md) que contém as imagens de bitmap dos controles.  Essas imagens podem se comportar como chaves, caixas de seleção, ou botões de opção.  Classe [CToolbar](../mfc/reference/ctoolbar-class.md) de fontes MFC para gerenciar as barras de ferramentas.  
  
 Se você habilitar, aos usuários de barras de ferramentas MFC podem entrá\-las à borda de uma janela ou “flutue\-as” em qualquer lugar dentro da janela do aplicativo.  MFC O não oferece suporte às barras de ferramentas e como ele no ambiente de desenvolvimento.  
  
 MFC dicas de ferramentas de suporte também: janela pop\-up pequenos que descrevem a finalidade de um botão da barra de ferramentas quando você posicionar o mouse no botão.  Por padrão, quando o usuário pressionar o botão da barra de ferramentas, uma cadeia de caracteres de status aparece na barra de status \(se houver\).  Você pode ativar a “geral” pela barra de status que atualiza para exibir a cadeia de caracteres de status quando o mouse é posicionado no botão sem o pressione.  
  
> [!NOTE]
>  A partir da versão 4,0 do MFC, barras de ferramentas e as dicas de ferramenta é implementada usando o Windows 95 e uma funcionalidade posterior em vez do anterior a implementação específica de MFC.  
  
 Para compatibilidade com versões anteriores, o MFC retém a implementação mais antigo da barra de ferramentas da classe **COldToolBar**.  A documentação para versões anteriores de MFC descreve **COldToolBar** em `CToolBar`.  
  
 Crie a primeira barra de ferramentas no programa selecionando a opção na barra de ferramentas no assistente do aplicativo.  Você também pode criar barras de ferramentas adicionais.  
  
 Os seguintes são apresentados neste artigo:  
  
-   [Botões da barra de ferramentas](#_core_toolbar_buttons)  
  
-   [Barras de ferramentas de acoplamento flexível e flutuante](#_core_docking_and_floating_toolbars)  
  
-   [Barras de ferramentas e dicas de ferramenta](#_core_toolbars_and_tool_tips)  
  
-   [As classes de CToolBar e de CToolBarCtrl](#_core_the_ctoolbar_and_ctoolbarctrl_classes)  
  
-   [O bitmap da barra de ferramentas](#_core_the_toolbar_bitmap)  
  
##  <a name="_core_toolbar_buttons"></a> Botões da barra de ferramentas  
 Os botões em uma barra de ferramentas são análogos a itens em um menu.  Os dois tipos de objetos de interface do usuário para gerenciar os comandos, que seu programa trata fornecendo funções do manipulador.  Frequentemente os botões da barra de ferramentas duplicam a funcionalidade dos comandos de menu, fornecendo uma interface do usuário de backup na mesma funcionalidade.  Essa duplicação só é organizada no botão e o item de menu a mesma ID  
  
 Você pode tornar os botões em uma barra de ferramentas é exibida e se comportar como chaves, caixas de seleção, ou botões de opção.  Classe de [CToolBar](../mfc/reference/ctoolbar-class.md)Para obter mais informações, consulte.  
  
##  <a name="_core_docking_and_floating_toolbars"></a> Barras de ferramentas de acoplamento flexível e flutuante  
 Uma barra de ferramentas de MFC pode:  
  
-   Permaneça estável em um lado da janela pai.  
  
-   É arrastado para e “conectado”, ou anexado, pelo usuário em qualquer lado ou lados da janela pai que você especifica.  
  
-   É flutuado “,” ou desanexado da janela do quadro, em sua própria janela de mini\- quadro assim que o usuário pode movê\-la em relação a qualquer posição conveniente.  
  
-   É redimensionado a serem flutuantes.  
  
 Para obter mais informações, consulte o artigo [Barras de ferramentas de acoplamento flexível e flutuante](../mfc/docking-and-floating-toolbars.md).  
  
##  <a name="_core_toolbars_and_tool_tips"></a> Barras de ferramentas e dicas de ferramenta  
 As barras de ferramentas MFC também podem ser feitas para exibir as janelas de “pop\-up minúsculas dicas de ferramenta” — que contém uma breve descrição de texto da finalidade de um botão da barra de ferramentas.  Porque o usuário passar o mouse sobre um botão da barra de ferramentas, os mensagem pop\-up da janela da dica de ferramenta oferecem até uma dica.  Para obter mais informações, consulte o artigo [Dicas de ferramenta da barra de ferramentas](../Topic/Toolbar%20Tool%20Tips.md).  
  
##  <a name="_core_the_ctoolbar_and_ctoolbarctrl_classes"></a> As classes de CToolBar e de CToolBarCtrl  
 Você gerencia as barras de ferramentas do seu aplicativo pela classe [CToolBar](../mfc/reference/ctoolbar-class.md).  A partir da versão 4,0, `CToolBar` MFC reimplemented para usar o controle comuns Windows 95 inferior disponível na barra de ferramentas ou posterior e a versão do Windows NT 3,51 ou posterior.  
  
 Este reimplementation resulta em menos códigos de MFC para barras de ferramentas, porque o MFC utiliza o suporte do sistema operacional.  O reimplementation também melhora o recurso.  Você pode usar as funções de membro de `CToolBar` para manipular barras de ferramentas ou, você pode obter uma referência ao objeto subjacente de [CToolBarCtrl](../mfc/reference/ctoolbarctrl-class.md) e chame as funções de membro para personalização e a funcionalidade adicional da barra de ferramentas.  
  
> [!TIP]
>  Se você investiu pesadamente na implementação mais antigo MFC de `CToolBar`, o que oferecem suporte ao ainda está disponível.  Consulte o artigo [Usando suas barras de ferramentas antigos](../Topic/Using%20Your%20Old%20Toolbars.md).  
  
 Consulte também o exemplo [DOCKTOOL](../top/visual-cpp-samples.md)gerais de MFC.  
  
##  <a name="_core_the_toolbar_bitmap"></a> O bitmap da barra de ferramentas  
 Uma vez que construído, um objeto de `CToolBar` cria a imagem da barra de ferramentas para carregar um único bitmap que contém uma imagem de cada botão.  O assistente de aplicativo cria um bitmap padrão da barra de ferramentas que você pode personalizar o Visual C\+\+ [editor da barra de ferramentas](../mfc/toolbar-editor.md).  
  
### Que você deseja saber mais?  
  
-   [Conceitos básicos da barra de ferramentas](../mfc/toolbar-fundamentals.md)  
  
-   [Barras de ferramentas de acoplamento flexível e flutuante](../mfc/docking-and-floating-toolbars.md)  
  
-   [Dicas de ferramenta da barra de ferramentas](../Topic/Toolbar%20Tool%20Tips.md)  
  
-   [Trabalhar com o controle da barra de ferramentas](../Topic/Working%20with%20the%20Toolbar%20Control.md)  
  
-   [Usando suas barras de ferramentas antigos](../Topic/Using%20Your%20Old%20Toolbars.md)  
  
-   As classes de [CToolBar](../mfc/reference/ctoolbar-class.md) e de [CToolBarCtrl](../mfc/reference/ctoolbarctrl-class.md)  
  
## Consulte também  
 [Barras de ferramentas](../mfc/toolbars.md)   
 [Editor de Barra de Ferramentas](../mfc/toolbar-editor.md)