---
title: Classes de controle | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: vc.classes.control
dev_langs: C++
helpviewer_keywords:
- static display controls [MFC]
- control classes [MFC]
- buttons, MFC control classes
- controls [MFC], MFC control classes
- controls [MFC]
- list boxes [MFC], MFC control classes
- control classes [MFC], MFC
- text, controls for input [MFC]
- user input [MFC], MFC control classes
ms.assetid: f9876606-9f5b-44cb-9135-213298d1df8f
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: c1bba69597425c10119af1f2c7d29afd870d8c48
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="control-classes"></a>Classes de controle
Classes de controle encapsulam uma ampla variedade de controles padrão do Windows, variando de controles de texto estático para controles em árvore. Além disso, o MFC fornece alguns novos controles, inclusive botões com barras de bitmaps e controle.  
  
 Os controles cujos nomes de classe terminam em "**Ctrl**" eram novos no Windows 95 e Windows NT versão 3.51.  
  
## <a name="static-display-controls"></a>Controles de exibição estática  
 [CStatic](../mfc/reference/cstatic-class.md)  
 Uma janela de exibição estática. Controles estáticos são usados para rotular, caixa ou separar outros controles em uma caixa de diálogo ou janela. Eles também podem exibir imagens gráficas em vez de texto ou uma caixa.  
  
## <a name="text-controls"></a>Controles de texto  
 [CEdit](../mfc/reference/cedit-class.md)  
 Uma janela de controle de texto editável. Editar controles são usados para aceitar a entrada textual do usuário.  
  
 [CIPAddressCtrl](../mfc/reference/cipaddressctrl-class.md)  
 Oferece suporte a uma caixa de edição para manipular um endereço IP (Internet Protocol).  
  
 [CRichEditCtrl](../mfc/reference/cricheditctrl-class.md)  
 Um controle no qual o usuário pode inserir e editar texto. Ao contrário do controle encapsulado em `CEdit`, um controle de edição oferece suporte a caracteres e formatação de parágrafo e objetos OLE.  
  
## <a name="controls-that-represent-numbers"></a>Controles que representam números  
 [CSliderCtrl](../mfc/reference/csliderctrl-class.md)  
 Um controle que contém um controle deslizante, que o usuário move para selecionar um valor ou conjunto de valores.  
  
 [CSpinButtonCtrl](../mfc/reference/cspinbuttonctrl-class.md)  
 Um par de botões de seta para o usuário pode clicar para incrementar ou decrementar um valor.  
  
 [CProgressCtrl](../mfc/reference/cprogressctrl-class.md)  
 Exibe um retângulo que é preenchido da esquerda para a direita para indicar o progresso de uma operação.  
  
 [CScrollBar](../mfc/reference/cscrollbar-class.md)  
 Uma janela de controle de barra de rolagem. A classe fornece a funcionalidade de uma barra de rolagem, para uso como um controle em uma caixa de diálogo ou janela, por meio do qual o usuário pode especificar uma posição dentro do intervalo.  
  
## <a name="buttons"></a>Botões  
 [CButton](../mfc/reference/cbutton-class.md)  
 Uma janela de controle de botão. A classe fornece uma interface programática para um botão de ação, a caixa de seleção ou o botão de opção em uma caixa de diálogo ou janela.  
  
 [CBitmapButton](../mfc/reference/cbitmapbutton-class.md)  
 Um botão com um bitmap em vez de uma legenda de texto.  
  
## <a name="lists"></a>Listas  
 [CListBox](../mfc/reference/clistbox-class.md)  
 Uma janela de controle de caixa de listagem. Uma caixa de listagem exibe uma lista de itens que o usuário pode exibir e selecionar.  
  
 [CDragListBox](../mfc/reference/cdraglistbox-class.md)  
 Fornece a funcionalidade de uma caixa de listagem do Windows; permite ao usuário mover itens da caixa de lista, como nomes de arquivo e a cadeia de caracteres literais, na caixa de listagem. Caixas de listagem com esse recurso são úteis para uma lista de itens em uma ordem diferente de em ordem alfabética, como incluir nomes de caminho ou arquivos em um projeto.  
  
 [CComboBox](../mfc/reference/ccombobox-class.md)  
 Uma janela de controle de caixa de combinação. Uma caixa de combinação consiste em um controle de edição e uma caixa de listagem.  
  
 [CComboBoxEx](../mfc/reference/ccomboboxex-class.md)  
 Estende a caixa de combinação controle de caixa, fornecendo suporte para listas de imagens.  
  
 [CCheckListBox](../mfc/reference/cchecklistbox-class.md)  
 Exibe uma lista de itens com caixas de seleção, que o usuário pode verificar ou limpar, ao lado de cada item.  
  
 [CListCtrl](../mfc/reference/clistctrl-class.md)  
 Exibe uma coleção de itens, cada consiste em um ícone e um rótulo, de maneira semelhante para o painel direito do Explorador de arquivos.  
  
 [CTreeCtrl](../mfc/reference/ctreectrl-class.md)  
 Exibe uma lista hierárquica de ícones e rótulos organizados de maneira semelhante ao painel esquerdo do Explorador de arquivos.  
  
## <a name="toolbars-and-status-bars"></a>Barras de ferramentas e barras de Status  
 [CToolBarCtrl](../mfc/reference/ctoolbarctrl-class.md)  
 Fornece a funcionalidade de controle comum da barra de ferramentas do Windows. MFC a maioria dos programas usam [CToolBar](../mfc/reference/ctoolbar-class.md) em vez desta classe.  
  
 [CStatusBarCtrl](../mfc/reference/cstatusbarctrl-class.md)  
 Uma janela horizontal, geralmente é dividida em painéis, no qual um aplicativo pode exibir informações de status. MFC a maioria dos programas usam [CStatusBar](../mfc/reference/cstatusbar-class.md) em vez desta classe.  
  
## <a name="miscellaneous-controls"></a>Diversos controles  
 [CAnimateCtrl](../mfc/reference/canimatectrl-class.md)  
 Exibe um clipe de vídeo simple.  
  
 [CToolTipCtrl](../mfc/reference/ctooltipctrl-class.md)  
 Uma pequena janela pop-up que exibe uma única linha de texto que descreve a finalidade de uma ferramenta em um aplicativo.  
  
 [CDateTimeCtrl](../mfc/reference/cdatetimectrl-class.md)  
 Oferece suporte a um controle de edição estendida ou um controle de interface de calendário simples, que permite que um usuário escolha uma data específica ou um valor de tempo.  
  
 [CHeaderCtrl](../mfc/reference/cheaderctrl-class.md)  
 Exibe os títulos ou rótulos de colunas.  
  
 [CMonthCalCtrl](../mfc/reference/cmonthcalctrl-class.md)  
 Oferece suporte a um controle de interface de calendário simples que permite que um usuário selecione uma data.  
  
 [CTabCtrl](../mfc/reference/ctabctrl-class.md)  
 Um controle com guias na qual o usuário pode clicar, análogo ao divisores em um bloco de anotações.  
  
 [CHotKeyCtrl](../mfc/reference/chotkeyctrl-class.md)  
 Permite que o usuário crie uma combinação de teclas ativa, o usuário pode pressionar para executar uma ação rapidamente.  
  
 [CLinkCtrl](../mfc/reference/clinkctrl-class.md)  
 Renderiza o texto marcado e inicia os aplicativos apropriados quando o usuário clica no link incorporado.  
  
 [CHtmlEditCtrl](../mfc/reference/chtmleditctrl-class.md)  
 Fornece a funcionalidade do controle ActiveX do WebBrowser em uma janela do MFC.  
  
## <a name="related-classes"></a>Classes relacionadas  
 [CImageList](../mfc/reference/cimagelist-class.md)  
 Fornece a funcionalidade da lista de imagens do Windows. Listas de imagens são usadas com controles de árvore e controles de lista. Eles também podem ser usados para armazenar e arquivar um conjunto de bitmaps do mesmo tamanho.  
  
 [CCtrlView](../mfc/reference/cctrlview-class.md)  
 A classe base para todos os modos de exibição associados a controles de Windows. Os modos de exibição com base nos controles descritos abaixo.  
  
 [CEditView](../mfc/reference/ceditview-class.md)  
 Controle de edição de uma exibição que contém um padrão do Windows.  
  
 [CRichEditView](../mfc/reference/cricheditview-class.md)  
 Controle de edição de uma exibição que contém um avançado do Windows.  
  
 [CListView](../mfc/reference/clistview-class.md)  
 Uma exibição que contém uma lista de controle do Windows.  
  
 [CTreeView](../mfc/reference/ctreeview-class.md)  
 Uma exibição que contém um controle de árvore do Windows.  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral da classe](../mfc/class-library-overview.md)

