---
title: Controles (MFC)
ms.date: 11/04/2016
helpviewer_keywords:
- Windows common controls [MFC]
- common controls [MFC]
- controls [MFC]
ms.assetid: b2842884-6435-4b8f-933b-21671bf8af95
ms.openlocfilehash: 3155889f2fd4002286340ccec7f4a35d1a6a9c20
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69508800"
---
# <a name="controls-mfc"></a>Controles (MFC)

Os controles são objetos com os quais os usuários podem interagir para inserir ou manipular dados. Normalmente aparecem nas caixas de diálogo ou nas barras de ferramentas. Esta família de tópicos aborda três tipos principais de controles:

- Controles comuns do Windows, incluindo controles desenhados pelo proprietário

- Controles ActiveX

- Outras classes de controle fornecidas pelo biblioteca MFC (MFC)

## <a name="windows-common-controls"></a>Controles comuns do Windows

O sistema operacional Windows sempre forneceu vários controles comuns do Windows. Esses objetos de controle são programáveis e o editor C++ de diálogo Visual dá suporte à adição deles às suas caixas de diálogo. O biblioteca MFC (MFC) fornece classes que encapsulam cada um desses controles, conforme mostrado na tabela [controles comuns do Windows e classes do MFC](#_core_windows_common_controls_and_mfc_classes). (Alguns itens na tabela têm tópicos relacionados que os descrevem mais detalhadamente. Para controles que não têm tópicos, consulte a documentação da classe do MFC.)

A classe [CWnd](../mfc/reference/cwnd-class.md) é a classe base de todas as classes de janela, incluindo todas as classes de controle.

## <a name="activex-controls"></a>Controles ActiveX

Os controles ActiveX, anteriormente conhecidos como controles OLE, podem ser usados em caixas de diálogo em seus aplicativos para Windows ou em páginas HTML no World Wide Web. Para obter mais informações, consulte [controles ActiveX do MFC](../mfc/mfc-activex-controls.md).

## <a name="other-mfc-control-classes"></a>Outras classes de controle do MFC

Além das classes que encapsulam todos os controles comuns do Windows e que dão suporte à programação de seus próprios controles ActiveX (ou usando controles ActiveX fornecidos por outros), o MFC fornece as seguintes classes de controle próprias:

- [CBitmapButton](../mfc/reference/cbitmapbutton-class.md)

- [CCheckListBox](../mfc/reference/cchecklistbox-class.md)

- [CDragListBox](../mfc/reference/cdraglistbox-class.md)

##  <a name="_core_finding_information_about_windows_common_controls"></a>Localizando informações sobre os controles comuns do Windows

A tabela abaixo descreve brevemente cada um dos controles comuns do Windows, incluindo a classe de wrapper MFC do controle.

### <a name="_core_windows_common_controls_and_mfc_classes"></a>Controles comuns do Windows e classes do MFC

|Controle|Classe do MFC|Descrição|Novidades no Windows 95|
|-------------|---------------|-----------------|------------------------|
|[animada](../mfc/using-canimatectrl.md)|[CAnimateCtrl](../mfc/reference/canimatectrl-class.md)|Exibe quadros sucessivos de um clipe de vídeo AVI|Sim|
|Button|[CButton](../mfc/reference/cbutton-class.md)|Supressãos que causam uma ação; também usado para caixas de seleção, botões de opção e caixas de grupo|Não|
|caixa de combinação|[CComboBox](../mfc/reference/ccombobox-class.md)|Combinação de uma caixa de edição e uma caixa de listagem|Não|
|[seletor de data e hora](../mfc/using-cdatetimectrl.md)|[CDateTimeCtrl](../mfc/reference/cdatetimectrl-class.md)|Permite que o usuário escolha um valor de data ou hora específico|Sim|
|caixa de edição|[CEdit](../mfc/reference/cedit-class.md)|Caixas para inserir texto|Não|
|[caixa de combinação estendida](../mfc/using-ccomboboxex.md)|[CComboBoxEx](../mfc/reference/ccomboboxex-class.md)|Um controle de caixa de combinação com a capacidade de exibir imagens|Sim|
|[header](../mfc/using-cheaderctrl.md)|[CHeaderCtrl](../mfc/reference/cheaderctrl-class.md)|Botão que aparece acima de uma coluna de texto; controla a largura do texto exibido|Sim|
|[hotkey](../mfc/using-chotkeyctrl.md)|[CHotKeyCtrl](../mfc/reference/chotkeyctrl-class.md)|Janela que permite ao usuário criar uma "tecla de atalho" para executar uma ação rapidamente|Sim|
|[lista de imagens](../mfc/using-cimagelist.md)|[CImageList](../mfc/reference/cimagelist-class.md)|Coleção de imagens usadas para gerenciar grandes conjuntos de ícones ou bitmaps (a lista de imagens não é realmente um controle; ela dá suporte a listas usadas por outros controles)|Sim|
|[list](../mfc/using-clistctrl.md)|[CListCtrl](../mfc/reference/clistctrl-class.md)|Janela que exibe uma lista de texto com ícones|Sim|
|caixa de listagem|[CListBox](../mfc/reference/clistbox-class.md)|Caixa que contém uma lista de cadeias de caracteres|Não|
|[calendário mensal](../mfc/using-cmonthcalctrl.md)|[CMonthCalCtrl](../mfc/reference/cmonthcalctrl-class.md)|Controle que exibe informações de data|Sim|
|[andamento](../mfc/using-cprogressctrl.md)|[CProgressCtrl](../mfc/reference/cprogressctrl-class.md)|Janela que indica o progresso de uma operação longa|Sim|
|[rebar](../mfc/using-crebarctrl.md)|[CRebarCtrl](../mfc/reference/crebarctrl-class.md)|Barra de ferramentas que pode conter janelas filho adicionais na forma de controles|Sim|
|[edição avançada](../mfc/using-cricheditctrl.md)|[CRichEditCtrl](../mfc/reference/cricheditctrl-class.md)|Janela na qual o usuário pode editar com formatação de caractere e de parágrafo (consulte [classes relacionadas a controles de edição avançados](../mfc/classes-related-to-rich-edit-controls.md))|Sim|
|barra de rolagem|[CScrollBar](../mfc/reference/cscrollbar-class.md)|Barra de rolagem usada como um controle dentro de uma caixa de diálogo (não em uma janela)|Não|
|[slider](../mfc/using-csliderctrl.md)|[CSliderCtrl](../mfc/reference/csliderctrl-class.md)|Janela que contém um controle deslizante com marcas de escala opcionais|Sim|
|[botão de rotação](../mfc/using-cspinbuttonctrl.md)|[CSpinButtonCtrl](../mfc/reference/cspinbuttonctrl-class.md)|Par de botões de seta o usuário pode clicar para incrementar ou decrementar um valor|Sim|
|texto estático|[CStatic](../mfc/reference/cstatic-class.md)|Texto para rotular outros controles|Não|
|[barra de status](../mfc/using-cstatusbarctrl.md)|[CStatusBarCtrl](../mfc/reference/cstatusbarctrl-class.md)|Janela para exibir informações de status, semelhante à classe do MFC`CStatusBar`|Sim|
|[tab](../mfc/using-ctabctrl.md)|[CTabCtrl](../mfc/reference/ctabctrl-class.md)|Análogo aos divisores em um notebook; usado em "caixas de diálogo de guia" ou folhas de propriedades|Sim|
|[toolbar](../mfc/using-ctoolbarctrl.md)|[CToolBarCtrl](../mfc/reference/ctoolbarctrl-class.md)|Janela com botões de geração de comandos, semelhantes à classe MFC`CToolBar`|Sim|
|[Dica de ferramenta](../mfc/using-ctooltipctrl.md)|[CToolTipCtrl](../mfc/reference/ctooltipctrl-class.md)|Janela pop-up pequena que descreve a finalidade de um botão da barra de ferramentas ou de outra ferramenta|Sim|
|[três](../mfc/using-ctreectrl.md)|[CTreeCtrl](../mfc/reference/ctreectrl-class.md)|Janela que exibe uma lista hierárquica de itens|Sim|

### <a name="what-do-you-want-to-know-more-about"></a>Do que você deseja saber mais sobre

- Um controle individual: consulte a tabela [controles comuns do Windows e classes do MFC](#_core_windows_common_controls_and_mfc_classes) neste tópico para obter links para todos os controles

- [Criando e usando controles](../mfc/making-and-using-controls.md)

- [Usando o editor de caixa de diálogo para adicionar controles](../mfc/using-the-dialog-editor-to-add-controls.md)

- [Adicionando controles a uma caixa de diálogo manualmente](../mfc/adding-controls-by-hand.md)

- [Derivando classes de controle das classes de controle MFC](../mfc/deriving-controls-from-a-standard-control.md)

- [Usando controles comuns como janelas filhas](../mfc/using-a-common-control-as-a-child-window.md)

- [Notificações de controles comuns](../mfc/receiving-notification-from-common-controls.md)

- [Adicione controles comuns a uma caixa de diálogo](../mfc/using-common-controls-in-a-dialog-box.md).

- [Derivar um controle de um controle padrão do Windows](../mfc/deriving-controls-from-a-standard-control.md)

- [Acessar controles de caixa de diálogo com segurança de tipo](../mfc/type-safe-access-to-controls-in-a-dialog-box.md)

- [Receber mensagens de notificação de controles comuns](../mfc/receiving-notification-from-common-controls.md)

- [Amostras](../mfc/common-control-sample-list.md)

Para obter informações sobre os controles comuns do Windows no SDK do Windows, consulte [controles comuns](/windows/win32/Controls/common-controls-intro).

## <a name="see-also"></a>Consulte também

[Elementos da interface do usuário](../mfc/user-interface-elements-mfc.md)<br/>
[Editor de caixa de diálogo](../windows/dialog-editor.md)
