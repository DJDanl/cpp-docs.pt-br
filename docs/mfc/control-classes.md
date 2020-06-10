---
title: Classes de controle
ms.date: 11/04/2016
f1_keywords:
- vc.classes.control
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
ms.openlocfilehash: 277802bff3e4833396c4bf114ff8880fcd26343d
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84623010"
---
# <a name="control-classes"></a>Classes de controle

Classes de controle encapsulam uma ampla variedade de controles padrão do Windows, variando de controles de texto estáticos a controles de árvore. Além disso, o MFC fornece alguns controles novos, incluindo botões com bitmaps e barras de controle.

Os controles cujos nomes de classe terminam em "**Ctrl**" eram novos no Windows 95 e no Windows NT versão 3,51.

## <a name="static-display-controls"></a>Controles de exibição estáticos

[CStatic](reference/cstatic-class.md)<br/>
Uma janela de exibição estática. Os controles estáticos são usados para rotular, caixar ou separar outros controles em uma caixa de diálogo ou janela. Eles também podem exibir imagens gráficas em vez de texto ou uma caixa.

## <a name="text-controls"></a>Controles de texto

[CEdit](reference/cedit-class.md)<br/>
Uma janela de controle de texto editável. Os controles de edição são usados para aceitar a entrada textual do usuário.

[CIPAddressCtrl](reference/cipaddressctrl-class.md)<br/>
Dá suporte a uma caixa de edição para manipular um endereço IP (Internet Protocol).

[CRichEditCtrl](reference/cricheditctrl-class.md)<br/>
Um controle no qual o usuário pode inserir e editar texto. Ao contrário do controle encapsulado no `CEdit` , um controle de edição rico dá suporte à formatação de caracteres e parágrafos e objetos OLE.

## <a name="controls-that-represent-numbers"></a>Controles que representam números

[CSliderCtrl](reference/csliderctrl-class.md)<br/>
Um controle que contém um controle deslizante, que o usuário move para selecionar um valor ou conjunto de valores.

[CSpinButtonCtrl](reference/cspinbuttonctrl-class.md)<br/>
Um par de botões de seta que o usuário pode clicar para incrementar ou decrementar um valor.

[CProgressCtrl](reference/cprogressctrl-class.md)<br/>
Exibe um retângulo que é gradualmente preenchido da esquerda para a direita para indicar o progresso de uma operação.

[CScrollBar](reference/cscrollbar-class.md)<br/>
Uma janela de controle da barra de rolagem. A classe fornece a funcionalidade de uma barra de rolagem, para uso como um controle em uma caixa de diálogo ou janela, por meio da qual o usuário pode especificar uma posição dentro de um intervalo.

## <a name="buttons"></a>Botões

[CButton](reference/cbutton-class.md)<br/>
Uma janela de controle de botão. A classe fornece uma interface programática para um botão de ação, caixa de seleção ou botão de opção em uma caixa de diálogo ou janela.

[CBitmapButton](reference/cbitmapbutton-class.md)<br/>
Um botão com um bitmap em vez de uma legenda de texto.

## <a name="lists"></a>Listas

[CListBox](reference/clistbox-class.md)<br/>
Uma janela de controle da caixa de listagem. Uma caixa de listagem exibe uma lista de itens que o usuário pode exibir e selecionar.

[CDragListBox](reference/cdraglistbox-class.md)<br/>
Fornece a funcionalidade de uma caixa de listagem do Windows; permite que o usuário mova itens da caixa de listagem, como nomes de texto e literais de cadeia de caracteres, dentro da caixa de listagem. As caixas de listagem com esse recurso são úteis para uma lista de itens em uma ordem diferente da ordem alfabética, como incluir caminhos ou arquivos em um projeto.

[CComboBox](reference/ccombobox-class.md)<br/>
Uma janela de controle de caixa de combinação. Uma caixa de combinação consiste em um controle de edição, além de uma caixa de listagem.

[CComboBoxEx](reference/ccomboboxex-class.md)<br/>
Estende o controle de caixa de combinação fornecendo suporte para listas de imagens.

[CCheckListBox](reference/cchecklistbox-class.md)<br/>
Exibe uma lista de itens com caixas de seleção, que o usuário pode marcar ou desmarcar ao lado de cada item.

[CListCtrl](reference/clistctrl-class.md)<br/>
Exibe uma coleção de itens, cada um consistindo em um ícone e um rótulo, de forma semelhante ao painel direito do explorador de arquivos.

[CTreeCtrl](reference/ctreectrl-class.md)<br/>
Exibe uma lista hierárquica de ícones e rótulos organizados de uma maneira semelhante ao painel esquerdo do explorador de arquivos.

## <a name="toolbars-and-status-bars"></a>Barras de ferramentas e barras de status

[CToolBarCtrl](reference/ctoolbarctrl-class.md)<br/>
Fornece a funcionalidade do controle comum da barra de ferramentas do Windows. A maioria dos programas MFC usa [CToolBar](reference/ctoolbar-class.md) em vez dessa classe.

[CStatusBarCtrl](reference/cstatusbarctrl-class.md)<br/>
Uma janela horizontal, geralmente dividida em painéis, em que um aplicativo pode exibir informações de status. A maioria dos programas MFC usa [CStatusBar](reference/cstatusbar-class.md) em vez dessa classe.

## <a name="miscellaneous-controls"></a>Controles diversos

[CAnimateCtrl](reference/canimatectrl-class.md)<br/>
Exibe um clipe de vídeo simples.

[CToolTipCtrl](reference/ctooltipctrl-class.md)<br/>
Uma pequena janela pop-up que exibe uma única linha de texto que descreve a finalidade de uma ferramenta em um aplicativo.

[CDateTimeCtrl](reference/cdatetimectrl-class.md)<br/>
Dá suporte a um controle de edição estendido ou a um controle de interface de calendário simples, que permite que um usuário escolha um valor de data ou hora específico.

[CHeaderCtrl](reference/cheaderctrl-class.md)<br/>
Exibe títulos ou rótulos para colunas.

[CMonthCalCtrl](reference/cmonthcalctrl-class.md)<br/>
Dá suporte a um controle de interface de calendário simples que permite que um usuário selecione uma data.

[CTabCtrl](reference/ctabctrl-class.md)<br/>
Um controle com guias nas quais o usuário pode clicar, análogo aos divisores em um notebook.

[CHotKeyCtrl](reference/chotkeyctrl-class.md)<br/>
Permite que o usuário crie uma combinação de teclas de acesso, que o usuário pode pressionar para executar uma ação rapidamente.

[CLinkCtrl](reference/clinkctrl-class.md)<br/>
Renderiza o texto marcado para cima e inicia os aplicativos apropriados quando o usuário clica no link inserido.

[CHtmlEditCtrl](reference/chtmleditctrl-class.md)<br/>
Fornece a funcionalidade do controle ActiveX do WebBrowser em uma janela do MFC.

## <a name="related-classes"></a>Classes relacionadas

[CImageList](reference/cimagelist-class.md)<br/>
Fornece a funcionalidade da lista de imagens do Windows. As listas de imagens são usadas com controles de lista e de árvore. Eles também podem ser usados para armazenar e arquivar um conjunto de bitmaps de mesmo tamanho.

[CCtrlView](reference/cctrlview-class.md)<br/>
A classe base para todas as exibições associadas aos controles do Windows. As exibições baseadas em controles são descritas abaixo.

[CEditView](reference/ceditview-class.md)<br/>
Uma exibição que contém um controle de edição padrão do Windows.

[CRichEditView](reference/cricheditview-class.md)<br/>
Uma exibição que contém um controle de edição Rich do Windows.

[CListView](reference/clistview-class.md)<br/>
Uma exibição que contém um controle de lista do Windows.

[CTreeView](reference/ctreeview-class.md)<br/>
Uma exibição que contém um controle de árvore do Windows.

## <a name="see-also"></a>Consulte também

[Visão geral da classe](class-library-overview.md)
