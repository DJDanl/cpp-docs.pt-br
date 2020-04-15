---
title: Controles (MFC)
ms.date: 11/04/2016
helpviewer_keywords:
- Windows common controls [MFC]
- common controls [MFC]
- controls [MFC]
ms.assetid: b2842884-6435-4b8f-933b-21671bf8af95
ms.openlocfilehash: 454a76e8fdf55f43d75abb63d7d98a9fe4926127
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81365320"
---
# <a name="controls-mfc"></a>Controles (MFC)

Controles são objetos com os quais os usuários podem interagir para inserir ou manipular dados. Eles geralmente aparecem em caixas de diálogo ou em barras de ferramentas. Esta família de tópicos abrange três tipos principais de controles:

- Controles comuns do Windows, incluindo controles desenhados pelo proprietário

- Controles ActiveX

- Outras classes de controle fornecidas pela Microsoft Foundation Class Library (MFC)

## <a name="windows-common-controls"></a>Controles comuns do Windows

O sistema operacional Windows sempre forneceu uma série de controles comuns do Windows. Esses objetos de controle são programáveis e o editor de diálogo Visual C++ suporta adicioná-los às caixas de diálogo. A Microsoft Foundation Class Library (MFC) fornece classes que encapsulam cada um desses controles, como mostrado na tabela [Controles Comuns do Windows e Classes MFC](#_core_windows_common_controls_and_mfc_classes). (Alguns itens na tabela têm tópicos relacionados que os descrevem mais adiante. Para controles que não possuem tópicos, consulte a documentação para a classe MFC.)

Class [CWnd](../mfc/reference/cwnd-class.md) é a classe base de todas as classes de janela, incluindo todas as classes de controle.

## <a name="activex-controls"></a>Controles ActiveX

Os controles ActiveX, anteriormente conhecidos como controles OLE, podem ser usados em caixas de diálogo em seus aplicativos para Windows ou em páginas HTML na World Wide Web. Para obter mais informações, consulte [Controles MFC ActiveX](../mfc/mfc-activex-controls.md).

## <a name="other-mfc-control-classes"></a>Outras classes de controle do MFC

Além de classes que encapsulam todos os controles comuns do Windows e que suportam a programação de seus próprios controles ActiveX (ou usando controles ActiveX fornecidos por outros), o MFC fornece as seguintes classes de controle próprias:

- [Cbitmapbutton](../mfc/reference/cbitmapbutton-class.md)

- [Cchecklistbox](../mfc/reference/cchecklistbox-class.md)

- [Cdraglistbox](../mfc/reference/cdraglistbox-class.md)

## <a name="finding-information-about-windows-common-controls"></a><a name="_core_finding_information_about_windows_common_controls"></a>Encontrando informações sobre controles comuns do Windows

A tabela abaixo descreve brevemente cada um dos controles comuns do Windows, incluindo a classe de invólucro MFC do controle.

### <a name="windows-common-controls-and-mfc-classes"></a><a name="_core_windows_common_controls_and_mfc_classes"></a>Controles comuns do Windows e Classes MFC

|Control|Classe MFC|Descrição|Novidade no Windows 95|
|-------------|---------------|-----------------|------------------------|
|[Animação](../mfc/using-canimatectrl.md)|[CAnimateCtrl](../mfc/reference/canimatectrl-class.md)|Exibe quadros sucessivos de um clipe de vídeo AVI|Sim|
|botão|[CButton](../mfc/reference/cbutton-class.md)|Botões que causam uma ação; também usado para caixas de seleção, botões de rádio e caixas de grupo|Não|
|caixa de combinação|[CComboBox](../mfc/reference/ccombobox-class.md)|Combinação de uma caixa de edição e uma caixa de lista|Não|
|[seleção de data e hora](../mfc/using-cdatetimectrl.md)|[CDateTimeCtrl](../mfc/reference/cdatetimectrl-class.md)|Permite que o usuário escolha uma data ou valor de hora específicos|Sim|
|editar caixa|[CEdit](../mfc/reference/cedit-class.md)|Caixas para inserir texto|Não|
|[caixa de combinação estendida](../mfc/using-ccomboboxex.md)|[Ccomboboxex](../mfc/reference/ccomboboxex-class.md)|Um controle de caixa combo com a capacidade de exibir imagens|Sim|
|[cabeçalho](../mfc/using-cheaderctrl.md)|[Cheaderctrl](../mfc/reference/cheaderctrl-class.md)|Botão que aparece acima de uma coluna de texto; controla a largura do texto exibido|Sim|
|[Hotkey](../mfc/using-chotkeyctrl.md)|[CHotKeyCtrl](../mfc/reference/chotkeyctrl-class.md)|Janela que permite ao usuário criar uma "chave quente" para executar uma ação rapidamente|Sim|
|[lista de imagens](../mfc/using-cimagelist.md)|[Cimagelist](../mfc/reference/cimagelist-class.md)|Coleção de imagens usadas para gerenciar grandes conjuntos de ícones ou bitmaps (lista de imagens não é realmente um controle; suporta listas usadas por outros controles)|Sim|
|[list](../mfc/using-clistctrl.md)|[CListCtrl](../mfc/reference/clistctrl-class.md)|Janela que exibe uma lista de texto com ícones|Sim|
|caixa de lista|[CListBox](../mfc/reference/clistbox-class.md)|Caixa que contém uma lista de strings|Não|
|[calendário mês](../mfc/using-cmonthcalctrl.md)|[CMonthCalCtrl](../mfc/reference/cmonthcalctrl-class.md)|Controle que exibe informações de data|Sim|
|[Progresso](../mfc/using-cprogressctrl.md)|[CProgressCtrl](../mfc/reference/cprogressctrl-class.md)|Janela que indica progresso de uma operação longa|Sim|
|[Rebar](../mfc/using-crebarctrl.md)|[Crebarctrl](../mfc/reference/crebarctrl-class.md)|Barra de ferramentas que pode conter janelas de crianças adicionais na forma de controles|Sim|
|[edição rica](../mfc/using-cricheditctrl.md)|[CRichEditCtrl](../mfc/reference/cricheditctrl-class.md)|Janela na qual o usuário pode editar com formatação de caracteres e parágrafos (ver [Classes Relacionadas aos Controles de Edição De Rich](../mfc/classes-related-to-rich-edit-controls.md))|Sim|
|barra de rolagem|[CScrollBar](../mfc/reference/cscrollbar-class.md)|Barra de rolagem usada como controle dentro de uma caixa de diálogo (não em uma janela)|Não|
|[Controle deslizante](../mfc/using-csliderctrl.md)|[CSliderCtrl](../mfc/reference/csliderctrl-class.md)|Janela contendo um controle deslizante com marcas de tique-taque opcionais|Sim|
|[botão de rotação](../mfc/using-cspinbuttonctrl.md)|[CSpinButtonCtrl](../mfc/reference/cspinbuttonctrl-class.md)|Par de botões de seta que o usuário pode clicar para incrementar ou diminuir um valor|Sim|
|texto estático|[Cstatic](../mfc/reference/cstatic-class.md)|Texto para rotular outros controles|Não|
|[barra de status](../mfc/using-cstatusbarctrl.md)|[Cstatusbarctrl](../mfc/reference/cstatusbarctrl-class.md)|Janela para exibir informações de status, semelhante à classe MFC`CStatusBar`|Sim|
|[Guia](../mfc/using-ctabctrl.md)|[CTabCtrl](../mfc/reference/ctabctrl-class.md)|Análogo aos divisores em um caderno; usado em "caixas de diálogo de guia" ou folhas de propriedade|Sim|
|[Toolbar](../mfc/using-ctoolbarctrl.md)|[Ctoolbarctrl](../mfc/reference/ctoolbarctrl-class.md)|Janela com botões geradores de comando, semelhante à classe MFC`CToolBar`|Sim|
|[ponta de ferramenta](../mfc/using-ctooltipctrl.md)|[Ctooltipctrl](../mfc/reference/ctooltipctrl-class.md)|Pequena janela pop-up que descreve o propósito de um botão de barra de ferramentas ou outra ferramenta|Sim|
|[Árvore](../mfc/using-ctreectrl.md)|[CTreeCtrl](../mfc/reference/ctreectrl-class.md)|Janela que exibe uma lista hierárquica de itens|Sim|

### <a name="what-do-you-want-to-know-more-about"></a>O que você quer saber mais sobre

- Um controle individual: veja a tabela [Controles Comuns do Windows e Classes MFC](#_core_windows_common_controls_and_mfc_classes) neste tópico para links para todos os controles

- [Fabricação e uso de controles](../mfc/making-and-using-controls.md)

- [Usando o editor de diálogo para adicionar controles](../mfc/using-the-dialog-editor-to-add-controls.md)

- [Adicionando controles a uma caixa de diálogo manualmente](../mfc/adding-controls-by-hand.md)

- [Derivando classes de controle das classes de controle mfc](../mfc/deriving-controls-from-a-standard-control.md)

- [Usando controles comuns como janelas de crianças](../mfc/using-a-common-control-as-a-child-window.md)

- [Notificações de controles comuns](../mfc/receiving-notification-from-common-controls.md)

- [Adicione controles comuns a uma caixa de diálogo](../mfc/using-common-controls-in-a-dialog-box.md).

- [Obtenha um controle de um controle padrão do Windows](../mfc/deriving-controls-from-a-standard-control.md)

- [Acesse os controles da caixa de diálogo com segurança de tipo](../mfc/type-safe-access-to-controls-in-a-dialog-box.md)

- [Receba mensagens de notificação de controles comuns](../mfc/receiving-notification-from-common-controls.md)

- [Exemplos](../mfc/common-control-sample-list.md)

Para obter informações sobre controles comuns do Windows no Windows SDK, consulte [Controles comuns](/windows/win32/Controls/common-controls-intro).

## <a name="see-also"></a>Confira também

[Elementos da interface do usuário](../mfc/user-interface-elements-mfc.md)<br/>
[Editor de caixa de diálogo](../windows/dialog-editor.md)
