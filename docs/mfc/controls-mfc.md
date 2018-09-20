---
title: Controles (MFC) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- Windows common controls [MFC]
- common controls [MFC]
- controls [MFC]
ms.assetid: b2842884-6435-4b8f-933b-21671bf8af95
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: b3607af849b1e395a0a467bcdbe65a2763fb3603
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46405054"
---
# <a name="controls-mfc"></a>Controles (MFC)

Os controles são objetos que os usuários podem interagir com a inserção ou manipular dados. Normalmente, eles aparecem nas caixas de diálogo ou na barra de ferramentas. Família este tópico aborda três principais tipos de controles:

- Controles comuns do Windows, incluindo controles desenhados pelo proprietário

- Controles ActiveX

- Outras classes de controle fornecidos pelo Microsoft Foundation Class Library (MFC)

## <a name="windows-common-controls"></a>Controles comuns do Windows

O sistema operacional Windows sempre forneceu uma série de controles comuns do Windows. Esses objetos de controle são programáveis, e o editor de caixa de diálogo do Visual C++ dá suporte ao adicioná-los para suas caixas de diálogo. O Microsoft Foundation Class Library (MFC) fornece classes que encapsulam cada um desses controles, conforme mostrado na tabela [controles comuns do Windows e Classes MFC](#_core_windows_common_controls_and_mfc_classes). (Alguns itens na tabela têm relacionado a tópicos que descrevem-los ainda mais. Para controles que não têm tópicos, consulte a documentação para a classe do MFC.)

Classe [CWnd](../mfc/reference/cwnd-class.md) é a classe base de todas as classes de janela, incluindo todas as classes de controle.

## <a name="activex-controls"></a>Controles ActiveX

Controles ActiveX, anteriormente conhecidos como controles OLE, podem ser usados nas caixas de diálogo em seus aplicativos para Windows ou em páginas HTML na World Wide Web. Para obter mais informações, consulte [controles ActiveX do MFC](../mfc/mfc-activex-controls.md).

## <a name="other-mfc-control-classes"></a>Outras Classes de controle MFC

Além das classes que encapsulam a todos os controles comuns do Windows e que suporte seus próprios controles ActiveX de programação (ou usando os controles ActiveX fornecidos por outras pessoas), o MFC fornece as seguintes classes de controle de seu próprio:

- [CBitmapButton](../mfc/reference/cbitmapbutton-class.md)

- [CCheckListBox](../mfc/reference/cchecklistbox-class.md)

- [CDragListBox](../mfc/reference/cdraglistbox-class.md)

##  <a name="_core_finding_information_about_windows_common_controls"></a> Localizando informações sobre controles comuns do Windows

A tabela a seguir descreve resumidamente cada um dos controles comuns do Windows, incluindo a classe de wrapper do controle MFC.

### <a name="_core_windows_common_controls_and_mfc_classes"></a>  Controles comuns do Windows e Classes do MFC

|Controle|Classe do MFC|Descrição|Novo no Windows 95|
|-------------|---------------|-----------------|------------------------|
|[Animação](../mfc/using-canimatectrl.md)|[CAnimateCtrl](../mfc/reference/canimatectrl-class.md)|Exibe quadros sucessivos de um clipe de vídeo AVI|Sim|
|Botão|[CButton](../mfc/reference/cbutton-class.md)|Comportarem que causam uma ação; também é usado para caixas de seleção, botões de opção e caixas de grupo|Não|
|caixa de combinação|[CComboBox](../mfc/reference/ccombobox-class.md)|Combinação de uma caixa de edição e uma caixa de listagem|Não|
|[seletor de data e hora](../mfc/using-cdatetimectrl.md)|[CDateTimeCtrl](../mfc/reference/cdatetimectrl-class.md)|Permite que o usuário escolha uma data específica ou um valor de tempo|Sim|
|Caixa de edição|[CEdit](../mfc/reference/cedit-class.md)|Caixas para inserir texto|Não|
|[caixa de combinação estendida](../mfc/using-ccomboboxex.md)|[CComboBoxEx](../mfc/reference/ccomboboxex-class.md)|Um controle de caixa de combinação com a capacidade de exibir imagens|Sim|
|[Cabeçalho](../mfc/using-cheaderctrl.md)|[CHeaderCtrl](../mfc/reference/cheaderctrl-class.md)|Botão que aparece acima de uma coluna de texto; Controla a largura do texto exibido|Sim|
|[hotkey](../mfc/using-chotkeyctrl.md)|[CHotKeyCtrl](../mfc/reference/chotkeyctrl-class.md)|Janela que permite que o usuário crie uma "chave hot" para executar uma ação rapidamente|Sim|
|[lista de imagens](../mfc/using-cimagelist.md)|[CImageList](../mfc/reference/cimagelist-class.md)|Coleção de imagens usadas para gerenciar grandes conjuntos de ícones ou bitmaps (lista de imagens não é um controle; ele dá suporte a listas usadas por outros controles)|Sim|
|[list](../mfc/using-clistctrl.md)|[CListCtrl](../mfc/reference/clistctrl-class.md)|Janela que exibe uma lista de texto com ícones|Sim|
|Caixa de listagem|[CListBox](../mfc/reference/clistbox-class.md)|Caixa que contém uma lista de cadeias de caracteres|Não|
|[Calendário mensal](../mfc/using-cmonthcalctrl.md)|[CMonthCalCtrl](../mfc/reference/cmonthcalctrl-class.md)|Controle que exibe informações de data|Sim|
|[Progresso](../mfc/using-cprogressctrl.md)|[CProgressCtrl](../mfc/reference/cprogressctrl-class.md)|Janela que indica o progresso de uma operação longa|Sim|
|[rebar](../mfc/using-crebarctrl.md)|[CRebarCtrl](../mfc/reference/crebarctrl-class.md)|Barra de ferramentas que pode conter windows filho adicionais na forma de controles|Sim|
|[Edição avançada](../mfc/using-cricheditctrl.md)|[CRichEditCtrl](../mfc/reference/cricheditctrl-class.md)|Janela em que o usuário pode editar com o caractere e formatação de parágrafo (consulte [Classes relacionadas para os controles de edição de Rich](../mfc/classes-related-to-rich-edit-controls.md))|Sim|
|barra de rolagem|[CScrollBar](../mfc/reference/cscrollbar-class.md)|Barra de rolagem usada como um controle dentro de uma caixa de diálogo (não em uma janela)|Não|
|[slider](../mfc/using-csliderctrl.md)|[CSliderCtrl](../mfc/reference/csliderctrl-class.md)|Janela que contém um controle deslizante com marcas de seleção opcionais|Sim|
|[botão de rotação](../mfc/using-cspinbuttonctrl.md)|[CSpinButtonCtrl](../mfc/reference/cspinbuttonctrl-class.md)|Par de usuário de botões de seta pode clicar para incrementar ou decrementar um valor|Sim|
|texto estático|[CStatic](../mfc/reference/cstatic-class.md)|Texto para outros controles de rotulação|Não|
|[Barra de status](../mfc/using-cstatusbarctrl.md)|[CStatusBarCtrl](../mfc/reference/cstatusbarctrl-class.md)|Janela para exibir informações de status, semelhantes à classe do MFC `CStatusBar`|Sim|
|[tab](../mfc/using-ctabctrl.md)|[CTabCtrl](../mfc/reference/ctabctrl-class.md)|Análogo aos divisores de um bloco de anotações; usado em "caixas de diálogo de guia" ou folhas de propriedades|Sim|
|[toolbar](../mfc/using-ctoolbarctrl.md)|[CToolBarCtrl](../mfc/reference/ctoolbarctrl-class.md)|Botões de janela com a geração de comando, semelhante à classe do MFC `CToolBar`|Sim|
|[Dica de ferramenta](../mfc/using-ctooltipctrl.md)|[CToolTipCtrl](../mfc/reference/ctooltipctrl-class.md)|Pequena janela pop-up que descreve a finalidade de um botão de barra de ferramentas ou outra ferramenta|Sim|
|[Árvore](../mfc/using-ctreectrl.md)|[CTreeCtrl](../mfc/reference/ctreectrl-class.md)|Janela que exibe uma lista hierárquica de itens|Sim|

### <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre

- Um controle individual: consulte a tabela [controles comuns do Windows e Classes MFC](#_core_windows_common_controls_and_mfc_classes) neste tópico para obter links para todos os controles

- [Criando e usando controles](../mfc/making-and-using-controls.md)

- [Usando o editor de caixa de diálogo para adicionar controles](../mfc/using-the-dialog-editor-to-add-controls.md)

- [Adicionando controles a uma caixa de diálogo manualmente](../mfc/adding-controls-by-hand.md)

- [Derivando de classes de controle de classes de controle MFC](../mfc/deriving-controls-from-a-standard-control.md)

- [Usando controles comuns como janelas filho](../mfc/using-a-common-control-as-a-child-window.md)

- [Notificações de controles comuns](../mfc/receiving-notification-from-common-controls.md)

- [Adicionar controles comuns para uma caixa de diálogo](../mfc/using-common-controls-in-a-dialog-box.md).

- [Derivar um controle de um controle padrão do Windows](../mfc/deriving-controls-from-a-standard-control.md)

- [Controles de caixa de diálogo de acesso com segurança de tipo](../mfc/type-safe-access-to-controls-in-a-dialog-box.md)

- [Receber mensagens de notificação de controles comuns](../mfc/receiving-notification-from-common-controls.md)

- [Amostras](../mfc/common-control-sample-list.md)

Para obter informações sobre controles comuns do Windows no SDK do Windows, consulte [controles comuns](/windows/desktop/Controls/common-controls-intro).

## <a name="see-also"></a>Consulte também

[Elementos da Interface do usuário](../mfc/user-interface-elements-mfc.md)<br/>
[Editor de caixa de diálogo](../windows/dialog-editor.md)

