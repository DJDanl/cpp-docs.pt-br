---
title: "Controles (MFC) | Microsoft Docs"
ms.custom: ""
ms.date: "12/13/2016"
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
  - "controles comuns do Windows [C++]"
  - "controles comuns [C++]"
  - "controles [MFC]"
ms.assetid: b2842884-6435-4b8f-933b-21671bf8af95
caps.latest.revision: 11
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Controles (MFC)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Os controles são objetos que os usuários podem interagir com a inserção ou manipular dados. Normalmente aparecem em caixas de diálogo ou na barra de ferramentas. Família este tópico aborda três principais tipos de controles:  
  
-   Controles comuns do Windows, incluindo controles desenhados pelo proprietário  
  
-   Controles ActiveX  
  
-   Outras classes de controle fornecidos pelo Microsoft Foundation Class Library \(MFC\)  
  
## Controles comuns do Windows  
 O sistema operacional Windows sempre forneceu um número de controles comuns do Windows. Esses objetos de controle são programáveis, e o editor de diálogo do Visual C\+\+ oferece suporte ao adicioná\-los à sua caixa de diálogo. O Microsoft Foundation Class Library \(MFC\) fornece classes que encapsulam cada um desses controles, conforme mostrado na tabela [controles comuns do Windows e Classes MFC](#_core_windows_common_controls_and_mfc_classes). \(Alguns itens na tabela têm relacionado tópicos que descrevem\-los ainda mais. Para controles que não têm tópicos, consulte a documentação para a classe do MFC.\)  
  
 Classe [CWnd](../Topic/CWnd%20Class.md) é a classe base de todas as classes de janela, incluindo todas as classes de controle. Controles comuns do Windows têm suporte nos seguintes ambientes:  
  
-   Windows 95, Windows 98 e Windows 2000  
  
-   Windows NT versão 3.51 e posterior  
  
-   Win32s, versão 1.3 \(Visual C\+\+ versões 4.2 e posteriores não suportam Win32s\)  
  
 Os controles comuns mais antigos — caixas de seleção, caixas de combinação, caixas de edição, caixas de listagem, botões de opção, pushbuttons, controles da barra de rolagem e controles estáticos — estavam disponíveis em versões anteriores do Windows também.  
  
## Controles ActiveX  
 Controles ActiveX, anteriormente conhecidos como controles OLE, podem ser usados nas caixas de diálogo em seus aplicativos para Windows ou em páginas HTML na World Wide Web. Para obter mais informações, consulte [controles ActiveX MFC](../mfc/mfc-activex-controls.md).  
  
## Outras Classes de controle MFC  
 Além das classes que encapsulam todos os controles comuns do Windows e que suporte programação seus próprios controles ActiveX \(ou usando controles ActiveX fornecidos por outras pessoas\), o MFC fornece as seguintes classes de controle de seu próprio:  
  
-   [CBitmapButton](../mfc/reference/cbitmapbutton-class.md)  
  
-   [CCheckListBox](../mfc/reference/cchecklistbox-class.md)  
  
-   [CDragListBox](../mfc/reference/cdraglistbox-class.md)  
  
##  <a name="_core_finding_information_about_windows_common_controls"></a> Localizando informações sobre controles comuns do Windows  
 A tabela a seguir descreve resumidamente cada um dos controles comuns do Windows, incluindo a classe de wrapper MFC do controle.  
  
### Controles comuns do Windows e Classes MFC  
  
|Controle|Classe do MFC|Descrição|Novo no Windows 95?|  
|--------------|-------------------|---------------|-------------------------|  
|[animação](../Topic/Using%20CAnimateCtrl.md)|[CAnimateCtrl](../mfc/reference/canimatectrl-class.md)|Exibe quadros sucessivos de um clipe de vídeo AVI|Sim|  
|botão|[CButton](../mfc/reference/cbutton-class.md)|Pushbuttons que causam uma ação; também é usado para caixas de seleção, botões e caixas de grupo|Não|  
|caixa de combinação|[CComboBox](../mfc/reference/ccombobox-class.md)|Combinação de uma caixa de edição e uma caixa de listagem|Não|  
|[Selecionador de data e hora](../mfc/using-cdatetimectrl.md)|[CDateTimeCtrl](../mfc/reference/cdatetimectrl-class.md)|Permite que o usuário escolha uma data específica ou um valor de tempo|Sim|  
|caixa de edição|[CEdit](../Topic/CEdit%20Class.md)|Caixas para inserir texto|Não|  
|[caixa de combinação estendidas](../mfc/using-ccomboboxex.md)|[CComboBoxEx](../mfc/reference/ccomboboxex-class.md)|Um controle de caixa de combinação com a capacidade de exibir imagens|Sim|  
|[cabeçalho](../mfc/using-cheaderctrl.md)|[CHeaderCtrl](../Topic/CHeaderCtrl%20Class.md)|Botão que aparece acima de uma coluna de texto; Controla a largura do texto exibido|Sim|  
|[teclas de atalho](../mfc/using-chotkeyctrl.md)|[CHotKeyCtrl](../mfc/reference/chotkeyctrl-class.md)|Janela que permite que os usuários criem uma "tecla de acesso" para executar uma ação rapidamente|Sim|  
|[lista de imagens](../mfc/using-cimagelist.md)|[CImageList](../Topic/CImageList%20Class.md)|Coleção de imagens usadas para gerenciar grandes conjuntos de ícones ou bitmaps \(lista de imagens não é um controle; oferece suporte a listas usadas por outros controles\)|Sim|  
|[list](../Topic/Using%20CListCtrl.md)|[CListCtrl](../Topic/CListCtrl%20Class.md)|Janela que exibe uma lista de texto com ícones|Sim|  
|caixa de listagem|[CListBox](../Topic/CListBox%20Class.md)|Caixa que contém uma lista de cadeias de caracteres|Não|  
|[calendário mensal](../Topic/Using%20CMonthCalCtrl.md)|[CMonthCalCtrl](../mfc/reference/cmonthcalctrl-class.md)|Controle que exibe informações de data|Sim|  
|[progresso](../mfc/using-cprogressctrl.md)|[CProgressCtrl](../mfc/reference/cprogressctrl-class.md)|Janela que indica o progresso de uma operação longa|Sim|  
|[rebar](../Topic/Using%20CReBarCtrl.md)|[CRebarCtrl](../mfc/reference/crebarctrl-class.md)|Barra de ferramentas que pode conter windows filho adicionais na forma de controles|Sim|  
|[edição avançada](../mfc/using-cricheditctrl.md)|[CRichEditCtrl](../Topic/CRichEditCtrl%20Class.md)|Janela em que o usuário pode editar com formatação de parágrafo e caractere \(consulte [Classes relacionadas a controles de edição de Rich](../mfc/classes-related-to-rich-edit-controls.md)\)|Sim|  
|barra de rolagem|[CScrollBar](../mfc/reference/cscrollbar-class.md)|Barra de rolagem usada como um controle dentro de uma caixa de diálogo \(não em uma janela\)|Não|  
|[controle deslizante](../mfc/using-csliderctrl.md)|[CSliderCtrl](../mfc/reference/csliderctrl-class.md)|Janela que contém um controle deslizante com marcas de seleção opcionais|Sim|  
|[botão de rotação](../mfc/using-cspinbuttonctrl.md)|[CSpinButtonCtrl](../mfc/reference/cspinbuttonctrl-class.md)|Clique em para incrementar ou decrementar um valor par de usuário de botões de seta|Sim|  
|texto estático|[CStatic](../Topic/CStatic%20Class.md)|Texto para rotular os outros controles|Não|  
|[barra de status](../mfc/using-cstatusbarctrl.md)|[CStatusBarCtrl](../mfc/reference/cstatusbarctrl-class.md)|Janela para exibir informações de status, semelhantes à classe do MFC `CStatusBar`|Sim|  
|[guia](../mfc/using-ctabctrl.md)|[CTabCtrl](../Topic/CTabCtrl%20Class.md)|Como os divisores de um bloco de anotações; usada em "caixas de diálogo de guia" ou folhas de propriedade|Sim|  
|[barra de ferramentas](../mfc/using-ctoolbarctrl.md)|[CToolBarCtrl](../mfc/reference/ctoolbarctrl-class.md)|Botões de janela com a geração de comando, semelhante à classe do MFC `CToolBar`|Sim|  
|[Dica de ferramenta](../mfc/using-ctooltipctrl.md)|[CToolTipCtrl](../Topic/CToolTipCtrl%20Class.md)|Pequena janela pop\-up que descreve a finalidade de um botão da barra de ferramentas ou outra ferramenta|Sim|  
|[árvore](../Topic/Using%20CTreeCtrl.md)|[CTreeCtrl](../mfc/reference/ctreectrl-class.md)|Janela que exibe uma lista hierárquica de itens|Sim|  
  
### O que você deseja saber mais sobre?  
  
-   Um controle individual: consulte a tabela [controles comuns do Windows e Classes MFC](#_core_windows_common_controls_and_mfc_classes) neste tópico para obter links para todos os controles  
  
-   [Criando e usando controles](../mfc/making-and-using-controls.md)  
  
-   [Usando o editor de diálogo para adicionar controles](../mfc/using-the-dialog-editor-to-add-controls.md)  
  
-   [Adicionando controles a uma caixa de diálogo manualmente](../mfc/adding-controls-by-hand.md)  
  
-   [Derivando de classes de controle de classes de controle MFC](../mfc/deriving-controls-from-a-standard-control.md)  
  
-   [Usando controles comuns como janelas filho](../mfc/using-a-common-control-as-a-child-window.md)  
  
-   [Notificações de controles comuns](../Topic/Receiving%20Notification%20from%20Common%20Controls.md)  
  
-   [Adicionar controles comuns para uma caixa de diálogo](../mfc/using-common-controls-in-a-dialog-box.md).  
  
-   [Derivar um controle de um controle padrão do Windows](../mfc/deriving-controls-from-a-standard-control.md)  
  
-   [Controles de caixa de diálogo de acesso com segurança de tipo](../Topic/Type-Safe%20Access%20to%20Controls%20in%20a%20Dialog%20Box.md)  
  
-   [Receber mensagens de notificação de controles comuns](../Topic/Receiving%20Notification%20from%20Common%20Controls.md)  
  
-   [Exemplos](../mfc/common-control-sample-list.md)  
  
 Para obter informações sobre controles comuns do Windows no [!INCLUDE[winSDK](../atl/includes/winsdk_md.md)], consulte [controles comuns](http://msdn.microsoft.com/library/windows/desktop/bb775493).  
  
## Consulte também  
 [Elementos da interface do usuário](../mfc/user-interface-elements-mfc.md)   
 [Editor de Caixa de Diálogo](../mfc/dialog-editor.md)