---
title: "Classes de controle | Microsoft Docs"
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
  - "vc.classes.control"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "botões, classes de controle MFC"
  - "classes de controle"
  - "classes de controle, MFC"
  - "controles [C++], classes de controle MFC"
  - "controles [MFC]"
  - "caixas de listagem, classes de controle MFC"
  - "controles de exibição estática"
  - "texto, controles de entrada"
  - "entrada do usuário, classes de controle MFC"
ms.assetid: f9876606-9f5b-44cb-9135-213298d1df8f
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classes de controle
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

As classes do controle gerenciado uma ampla variedade de controles padrão do windows que variam dos controles de texto estático nos controles de árvore.  Além disso, o MFC fornece alguns novos controles, inclusive os botões com bitmaps e barras de controle.  
  
 Os controles cujos nomes da classe terminam em “**Ctrl**” eram novos na versão 3,51 do Windows 95 e Windows NT.  
  
## Controles de exibição estáticos  
 [CStatic](../Topic/CStatic%20Class.md)  
 Uma janela de estática\- exibição.  Os controles estáticos são usados para rotular, caso, ou separar outros controles em uma caixa de diálogo ou em uma janela.  Também podem exibir imagens gráficas em vez de texto ou uma caixa.  
  
## Controles de texto  
 [CEdit](../Topic/CEdit%20Class.md)  
 Uma janela de controle de editável\- texto.  Os controles de edição são usados para aceitar a entrada textual do usuário.  
  
 [CIPAddressCtrl](../mfc/reference/cipaddressctrl-class.md)  
 Oferece suporte a uma caixa de edição para manipular um endereço IP \(IP\).  
  
 [CRichEditCtrl](../Topic/CRichEditCtrl%20Class.md)  
 Um controle ao qual o usuário pode inserir e editar o texto.  Ao contrário do controle encapsulado em `CEdit`, um controle de edição avançado da suporte à formatação de caractere e de parágrafo e os objetos OLE.  
  
## Controles que representam números  
 [CSliderCtrl](../mfc/reference/csliderctrl-class.md)  
 Um controle que contém um controle deslizante, que o usuário se move para selecionar um valor ou um conjunto de valores.  
  
 [CSpinButtonCtrl](../mfc/reference/cspinbuttonctrl-class.md)  
 Um par de botões de seta que o usuário pode clicar para incrementar ou decrementar um valor.  
  
 [CProgressCtrl](../mfc/reference/cprogressctrl-class.md)  
 Exibe um retângulo que é preenchido gradativamente da esquerda para a direita para indicar o progresso de uma operação.  
  
 [CScrollBar](../mfc/reference/cscrollbar-class.md)  
 Uma janela de controle da barra de rolagem.  A classe fornece a funcionalidade de uma barra de rolagem, para uso como um controle em uma caixa de diálogo ou em uma janela do, através do qual o usuário pode especificar uma posição dentro de um intervalo.  
  
## Botões  
 [CButton](../mfc/reference/cbutton-class.md)  
 Uma janela de controle de botão.  A classe fornece uma interface programática para um botão de ação, uma caixa de seleção, ou um botão de opção em uma caixa de diálogo ou em uma janela.  
  
 [CBitmapButton](../mfc/reference/cbitmapbutton-class.md)  
 Um botão com um bitmap em vez de uma legenda de texto.  
  
## Listas  
 [CListBox](../Topic/CListBox%20Class.md)  
 Uma janela de controle da caixa de listagem.  Uma caixa de listagem exibe uma lista de itens que o usuário pode exibir e selecione.  
  
 [CDragListBox](../mfc/reference/cdraglistbox-class.md)  
 Fornece a funcionalidade de uma caixa de listagem windows; permite que o usuário mover itens da caixa de listagem, como nomes de arquivo e literais, na caixa de listagem.  As caixas de listagem com esse recurso são úteis para uma lista de itens em uma ordem diferente alfabéticos, como incluir nomes de caminho ou arquivos em um projeto.  
  
 [CComboBox](../mfc/reference/ccombobox-class.md)  
 Uma janela de controle da caixa de combinação.  Uma caixa de combinação consiste em um controle de edição mais uma caixa de listagem.  
  
 [CComboBoxEx](../mfc/reference/ccomboboxex-class.md)  
 Estende o controle da caixa de combinação fornecendo suporte a listas de imagens.  
  
 [CCheckListBox](../mfc/reference/cchecklistbox-class.md)  
 Exibe uma lista de itens com caixas de seleção, ele pode verificar ou desmarque, ao lado de cada item.  
  
 [CListCtrl](../Topic/CListCtrl%20Class.md)  
 Exibe uma coleção de itens, cada qual consiste em um ícone e em um rótulo, de forma semelhante ao painel direito do Explorador de Arquivos.  
  
 [CTreeCtrl](../mfc/reference/ctreectrl-class.md)  
 Exibe uma lista hierárquica de ícones e de forma semelhante organizado de rótulos para o painel esquerdo do Explorador de Arquivos.  
  
## Barras de ferramentas e barras de status  
 [CToolBarCtrl](../mfc/reference/ctoolbarctrl-class.md)  
 Fornece a funcionalidade do controle comum de barra de ferramentas comum do Windows.  A maioria de MFC programas usam [CToolBar](../mfc/reference/ctoolbar-class.md) em vez dessa classe.  
  
 [CStatusBarCtrl](../mfc/reference/cstatusbarctrl-class.md)  
 Uma janela horizontal, dividido geralmente painéis, em que um aplicativo pode exibir informações de status.  A maioria de MFC programas usam [CStatusBar](../mfc/reference/cstatusbar-class.md) em vez dessa classe.  
  
## Controles diversos  
 [CAnimateCtrl](../mfc/reference/canimatectrl-class.md)  
 Exibe um videoclip simples.  
  
 [CToolTipCtrl](../Topic/CToolTipCtrl%20Class.md)  
 Um pequeno janela pop\-up que exibe uma única linha de texto que descreve a finalidade de uma ferramenta em um aplicativo.  
  
 [CDateTimeCtrl](../mfc/reference/cdatetimectrl-class.md)  
 Oferece suporte a um controle de edição estendido, ou um controle de interface simples de calendário, que permite que um usuário escolha uma data específica ou o valor do tempo.  
  
 [CHeaderCtrl](../Topic/CHeaderCtrl%20Class.md)  
 Títulos ou rótulos vídeos para colunas.  
  
 [CMonthCalCtrl](../mfc/reference/cmonthcalctrl-class.md)  
 Oferece suporte a um controle de interface simples de calendário que permite que um usuário selecione uma data.  
  
 [CTabCtrl](../Topic/CTabCtrl%20Class.md)  
 Um controle com guias no qual o usuário pode clicar em, análogos a divisores em um caderno.  
  
 [CHotKeyCtrl](../mfc/reference/chotkeyctrl-class.md)  
 Permite que o usuário para criar uma combinação de tecla de acesso, que o usuário possa pressione para executar uma ação rapidamente.  
  
 [CLinkCtrl](../mfc/reference/clinkctrl-class.md)  
 Texto e inicia marcados configura Renders aplicativos apropriadas quando o usuário clica no link inserido.  
  
 [CHtmlEditCtrl](../mfc/reference/chtmleditctrl-class.md)  
 Fornece a funcionalidade do controle ActiveX WebBrowser em uma janela MFC.  
  
## Classes relacionadas  
 [CImageList](../Topic/CImageList%20Class.md)  
 Fornece a funcionalidade da lista da imagem do windows.  As listas de imagem são usadas com controles da lista e controles da árvore.  Também podem ser usados para armazenar e arquivar um conjunto de bitmaps mesmo feito sob medida.  
  
 [CCtrlView](../mfc/reference/cctrlview-class.md)  
 Qualquer classe base para exibe associado aos controles do windows.  Exibições com base em controles são descritas abaixo.  
  
 [CEditView](../Topic/CEditView%20Class.md)  
 Uma exibição que contém um controle de edição padrão do windows.  
  
 [CRichEditView](../mfc/reference/cricheditview-class.md)  
 Uma exibição que contém um controle de edição avançado do windows.  
  
 [CListView](../mfc/reference/clistview-class.md)  
 Uma exibição que contém o lista o controle.  
  
 [CTreeView](../mfc/reference/ctreeview-class.md)  
 Uma exibição que contém um controle de árvore do windows.  
  
## Consulte também  
 [Visão geral da classe](../mfc/class-library-overview.md)