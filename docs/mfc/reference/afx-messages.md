---
title: "Mensagens AFX | Microsoft Docs"
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
  - "SB_LINELEFT"
  - "SB_THUMBTRACK"
  - "AFX_TOOLTIP_TYPE_EDIT"
  - "AFX_WM_ON_HSCROLL"
  - "SB_PAGERIGHT"
  - "AFX_WM_RESETPROMPT"
  - "AFX_WM_CHANGE_RIBBON_CATEGORY"
  - "AFX_TOOLTIP_TYPE_MINIFRAME"
  - "AFX_WM_CUSTOMIZETOOLBAR"
  - "AFX_WM_CHANGE_ACTIVE_TAB"
  - "AFX_WM_ACCGETOBJECT"
  - "AFX_WM_TOOLBARMENU"
  - "AFX_TOOLTIP_TYPE_DOCKBAR"
  - "AFX_WM_CUSTOMIZEHELP"
  - "AFX_WM_ON_GET_TAB_TOOLTIP"
  - "AFX_WM_ON_RIBBON_CUSTOMIZE"
  - "AFX_WM_ON_DRAGCOMPLETE"
  - "AFX_WM_RESETTOOLBAR"
  - "AFX_WM_ON_MOVETOTABGROUP"
  - "AFX_WM_CHECKEMPTYMINIFRAME"
  - "AFX_WM_GETDOCUMENTCOLORS"
  - "SB_RIGHT"
  - "AFX_WM_ON_BEFORE_SHOW_RIBBON_ITEM_MENU"
  - "AFX_WM_ACCGETSTATE"
  - "SB_PAGELEFT"
  - "SB_ENDSCROLL"
  - "AFX_WM_ON_CANCELTABMOVE"
  - "AFX_TOOLTIP_TYPE_TAB"
  - "AFX_WM_WINDOW_HELP"
  - "AFX_WM_HIGHLIGHT_RIBBON_LIST_ITEM"
  - "AFX_WM_SHOWREGULARMENU"
  - "AFX_TOOLTIP_TYPE_TOOLBAR"
  - "AFX_WM_CHANGE_CURRENT_FOLDER"
  - "AFX_WM_UPDATETOOLTIPS"
  - "AFX_WM_ON_MOVE_TAB"
  - "AFX_WM_CHANGING_ACTIVE_TAB"
  - "AFX_WM_RESETMENU"
  - "AFX_WM_GETDRAGBOUNDS"
  - "AFX_WM_RESETCONTEXTMENU"
  - "AFX_TOOLTIP_TYPE_BUTTON"
  - "AFX_WM_ON_CLOSEPOPUPWINDOW"
  - "AFX_TOOLTIP_TYPE_TOOLBOX"
  - "AFX_WM_CHANGEVISUALMANAGER"
  - "SB_LINERIGHT"
  - "AFX_WM_ON_RENAME_TAB"
  - "AFX_TOOLTIP_TYPE_DEFAULT"
  - "AFX_WM_ON_TABGROUPMOUSEMOVE"
  - "SB_LEFT"
  - "AFX_WM_DELETETOOLBAR"
  - "AFX_WM_PROPERTY_CHANGED"
  - "AFX_TOOLTIP_TYPE_ALL"
  - "AFX_WM_ACCHITTEST"
  - "AFX_WM_ON_AFTER_SHELL_COMMAND"
  - "AFX_WM_ON_PRESS_CLOSE_BUTTON"
  - "AFX_WM_RESETKEYBOARD"
  - "AFX_WM_ON_MOVETABCOMPLETE"
  - "AFX_WM_CREATETOOLBAR"
  - "SB_THUMBPOSITION"
  - "AFX_WM_POSTSETPREVIEWFRAME"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Mensagens AFX"
ms.assetid: 3d601f3c-af6d-47d3-8553-34f1318fa74f
caps.latest.revision: 24
caps.handback.revision: 16
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Mensagens AFX
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essas mensagens são usadas em MFC.  
  
## Mensagens  
 A tabela a seguir lista as mensagens que são usadas na biblioteca MFC:  
  
||||||  
|-|-|-|-|-|  
|Message \(Mensagem\)|Descrição|\[entrada\] `wParam`|`lParam` \(todos os parâmetros são \[in\] salvo indicação em contrário.\)|Valor de Retorno|  
|AFX\_WM\_ACCGETOBJECT|Não usado.|Não usado.|Não aplicável.|Não aplicável.|  
|AFX\_WM\_ACCGETSTATE|Usado para suporte de acessibilidade.  Enviar esta mensagem a `CMFCPopupMenu` ou a `CMFCRibbonPanelMenu` para recuperar o estado do elemento atual.|Índice do elemento, que pode ser um botão ou um separador no menu.|Não usado.|O estado do elemento.  Será \-1 se o índice for inválido, 0 se o botão de menu não tem nenhum atributo especial.  Se não for uma combinação dos sinalizadores a seguir:<br /><br /> TBBS\_DISABLED – o item é desabilitado<br /><br /> TBBS\_CHECKED – o item é verificado<br /><br /> TBBS\_BUTTON – o item é uma tecla padrão<br /><br /> TBBS\_PRESSED – o botão é pressionada<br /><br /> TBBS\_INDETERMINATE – estado indeterminado<br /><br /> TBBS\_SEPARATOR \- em vez de um botão no menu, esse elemento forma uma separação entre outros itens de menu|  
|AFX\_WM\_CHANGE\_ACTIVE\_TAB|A estrutura envia a mensagem ao controle redimensionável da barra de controle.  Processar esta mensagem para receber notificações de objetos de `CMFCTabCtrl` quando um usuário altera um guia ativa.|O índice de um guia.|Não usado.|Diferente de zero.|  
|AFX\_WM\_CHANGE\_CURRENT\_FOLDER|A estrutura envia a mensagem ao pai de `CMFCShellListCtrl` quando o usuário modificou a pasta atual.|Não usado.|Não usado.|Não usado.|  
|AFX\_WM\_CHANGEVISUALMANAGER|A estrutura envia essa mensagem para todas as janelas do quadro quando o usuário altera o gerenciador visual atual.  Em resposta a essa mensagem, uma janela do quadro recalcula sua região e ajusta outros parâmetros quando necessário.  É possível processar a mensagem de AFX\_WM\_CHANGEVISUALMANAGER em seu aplicativo se você precisar ser notificado sobre esse evento.  Você deve chamar o manipulador da classe base`OnChangeVisualManager`\(\) para garantir que o processamento interno da estrutura desse evento ocorra.|Não usado.|Não usado.|Não usado.|  
|AFX\_WM\_CHANGING\_ACTIVE\_TAB|Enviado ao pai do objeto de `CMFCTabCtrl` .  Processar esta mensagem se você desejar receber notificações de objetos de `CMFCTabCtrl` quando um usuário redefine um guia.|O índice da guia que está sendo ativado.|Não usado.|Diferente de zero.|  
|AFX\_WM\_CHECKEMPTYMINIFRAME|Somente para uso interno.|Não aplicável.|Não aplicável.|Não aplicável.|  
|AFX\_WM\_CREATETOOLBAR|Enviado de `CMFCToolBarsListPropertyPage` quando um usuário criar uma nova barra de ferramentas durante o processo de personalização.  Você pode processar esta mensagem para criar uma instância de um objeto CMFCToolBar\- derivada personalizadas.  Se você trata esta mensagem e criar sua própria barra de ferramentas, omita a chamada para o manipulador padrão.|Não usado.|Um ponteiro para uma cadeia de caracteres que contém o nome da barra de ferramentas.|Um ponteiro para a barra de ferramentas recém\-criado.  NULL indica que a criação da barra de ferramentas esteve cancelada.|  
|AFX\_WM\_CUSTOMIZEHELP|Enviado à janela principal do quadro de folha de propriedade `CMFCToolbarCustomize`de personalização`Dialog` quando o usuário pressionar o botão de **Ajuda** ou a tecla F1.|Especifica a página ativa da folha de propriedades personalizadas.|Um ponteiro para um objeto de `CMFCToolbarCustomize``Dialog`.|Zero.|  
|AFX\_WM\_CUSTOMIZETOOLBAR|`CMFCToolbarCustomize` `Dialog` envia essa mensagem para notificar o quadro pai que o usuário estiver criando uma nova barra de ferramentas.|`TRUE` quando a personalização é iniciada, `FALSE` quando a personalização é concluída.|Não usado.|Zero.|  
|AFX\_WM\_DELETETOOLBAR|Enviado à janela principal do quadro quando o usuário está prestes a excluir uma barra de ferramentas no modo de personalização.<br /><br /> Processar esta mensagem executar ações adicionais quando um usuário exclui uma barra de ferramentas no modo de personalização.  Você também deve chamar o manipulador`OnToolbarDelete`\(padrão\), que exclui a barra de ferramentas.  O manipulador padrão retorna um valor que indica se é possível excluir a barra de ferramentas.|Não usado.|Ponteiro para um objeto de `CMFCToolBar` a ser excluído.|Diferente de zero se uma barra de ferramentas não pode ser excluída; se não 0.|  
|AFX\_WM\_GETDOCUMENTCOLORS|`CMFCColorMenuButton` envia essa mensagem à janela principal do quadro para recuperar as cores do documento.|Não usado.|no, \[out\] ponteiro para um objeto de `CList<COLORREF, COLORREF>` .|Zero.|  
|AFX\_WM\_GETDRAGBOUNDS|Somente para uso interno.|Não aplicável.|Não aplicável.|Não aplicável.|  
|AFX\_WM\_HIGHLIGHT\_RIBBON\_LIST\_ITEM|Enviado à janela principal do quadro quando um usuário realçar um item da lista de fita.|Índice do item realçado|Um ponteiro para `CMFCBaseRibbonElement`|Não usado.|  
|AFX\_WM\_ON\_AFTER\_SHELL\_COMMAND|Enviado a um pai de `CMFCShellListCtrl` ou de controles de `CMFCShellTreeCtrl` quando um usuário concluir a execução de um comando shell.|A ID de O comando executado para que o usuário|Não usado.|Se o aplicativo processe esta mensagem, ele retornará nulo.|  
|AFX\_WM\_ON\_BEFORE\_SHOW\_RIBBON\_ITEM\_MENU|A estrutura envia a mensagem ao pai de fita antes que exibe o menu pop\-up.  Você pode processar esta mensagem e alterar o menu suspenso a qualquer momento.|Não usado.|Um ponteiro para `CMFCBaseRibbonElement`|Não usado.|  
|AFX\_WM\_ON\_CANCELTABMOVE|Somente para uso interno.|Não aplicável.|Não aplicável.||  
|AFX\_WM\_ON\_CHANGE\_RIBBON\_CATEGORY|A estrutura envia a mensagem ao quadro principal quando o usuário altera a categoria ativa do controle da Faixa De Opções.|Não usado.|Um ponteiro para `CMFCRibbonBar` cuja categoria foi alterado.|Não usado.|  
|AFX\_WM\_ON\_CLOSEPOPUPWINDOW|A estrutura envia essa mensagem para notificar o proprietário de `CMFCDesktopAlertWnd` que a janela está prestes a ser fechada.|Não usado.|Um ponteiro para o objeto de `CMFCDesktopAlertWnd` .|Não usado.|  
|AFX\_WM\_ON\_DRAGCOMPLETE|Somente para uso interno.|Não aplicável.|Não aplicável.|Não aplicável.|  
|AFX\_WM\_ON\_GET\_TAB\_TOOLTIP|Enviado à janela principal do quadro quando uma janela da guia está prestes a exibir uma dica de ferramenta para um guia, se as dicas de ferramenta personalizadas estão habilitados.|Não usado.|Um ponteiro para uma estrutura de `CMFCTabToolTipInfo` .|Não usado.|  
|AFX\_WM\_ON\_HSCROLL|Enviado ao controle redimensionável da barra de controle.  Processar esta mensagem para receber notificações de objetos de `CMFCTabCtrl` quando um evento de rolagem ocorre na barra de rolagem horizontal do widget com guias.|As palavras do da ordem mais baixa especificam um valor da barra de rolagem que indica a solicitação de rolagem do usuário.  Para obter mais informações, consulte a tabela posteriormente neste tópico.|Não usado.|Diferente de zero.|  
|AFX\_WM\_ON\_MOVE\_TAB|Enviado ao pai de uma janela com guias quando um usuário arrastar uma guia para uma nova posição.|O índice de base zero da guia em sua posição original.|\[out\] o índice de base zero da guia na nova posição.|Zero.|  
|AFX\_WM\_ON\_MOVETABCOMPLETE|Somente para uso interno.|Não aplicável.|Não aplicável.|Não aplicável.|  
|AFX\_WM\_ON\_MOVETOTABGROUP|Enviado à janela principal do quadro quando um usuário mover uma janela filho MDI de um grupo listado para outro.|Um identificador de janela com guias`CMFCTabCtrl`\(\) que a janela filho MDI foi removida.|\[out\] o identificador da janela com guias`CMFCTabCtrl`\(\) a que a janela filho MDI foi inserida.|Ignorado.|  
|AFX\_WM\_ON\_PRESS\_CLOSE\_BUTTON|Enviado a um pai de `CDockablePane` quando o usuário clicar no botão de **Fechar** na legenda da barra de controle.|Não usado.|Um ponteiro para um painel encaixável em que o usuário clicou o botão de **Fechar** .|`TRUE` se o painel não pode ser fechado; caso contrário FALSE.|  
|AFX\_WM\_ON\_RENAME\_TAB|Enviado ao pai da janela com guias após o usuário renomear um guia editável.|O índice de base zero da guia renomeado.|\[out\] de ponteiro para uma cadeia de caracteres que contém o novo nome da guia.|Diferente de zero se o aplicativo processe esta mensagem; a estrutura suprimirá a chamada a `CMFCBaseTabCtrl::SetTabLabel`.  Se zero são retornados, então `CMFCBaseTabCtrl::SetTabLabel` é chamado pela estrutura.|  
|AFX\_WM\_ON\_RIBBON\_CUSTOMIZE|Enviado ao quadro pai quando o usuário começar a personalização.  Processar esta mensagem se você quiser exibir sua própria caixa de diálogo personalizadas.|Não usado.|Um ponteiro para o controle de fita a ser personalizado.|Diferente de zero se o aplicativo processe esta mensagem e exibe sua própria caixa de diálogo personalizadas.  Se o aplicativo retorna zero, a estrutura exibirá a caixa de diálogo interno de personalização.|  
|AFX\_WM\_ON\_TABGROUPMOUSEMOVE|Somente para uso interno.|Não aplicável.|Não aplicável.|Não aplicável.|  
|AFX\_WM\_POSTSETPREVIEWFRAME|Enviado para notificar o quadro principal que o usuário modificou o modo de visualização de impressão|`TRUE` indica que o modo de visualização de impressão será definido.  `FALSE` indica que o modo de visualização de impressão é desativado.|Não usado.|Não usado.|  
|AFX\_WM\_PROPERTY\_CHANGED|Enviado ao proprietário do controle da grade de propriedades \(\)`CMFCPropertyGridCtrl`quando o usuário altere o valor da propriedade selecionada.|A ID de O controle da lista de propriedades.|Um ponteiro para a propriedade \(`CMFCProp``ertyGridProperty`\) que foi alterada.|Não usado.|  
|AFX\_WM\_RESETCONTEXTMENU|Enviado à janela principal do quadro quando o usuário redefinir o menu de contexto durante a personalização.|A ID do recurso do menu de contexto.|Um ponteiro para o menu de contexto atual, `CMFCPopupMenu`.|Não usado.|  
|AFX\_WM\_RESETKEYBOARD|A estrutura envia essa mensagem à janela principal do quadro quando o usuário redefine todos os aceleradores de teclado durante a personalização.|Não usado.|Não usado.|Não usado.|  
|AFX\_WM\_RESETMENU|A estrutura envia a mensagem ao proprietário do menu \(uma janela do quadro\) quando o usuário redefine um menu do quadro do aplicativo durante a personalização|A ID do recurso do menu|Não usado.|Não usado.|  
|AFX\_WM\_RESETPROMPT|A estrutura envia essa mensagem quando o usuário redefinirá uma barra de ferramentas da barra de ferramentas personalizar a caixa de diálogo.  O manipulador padrão exibe uma caixa de mensagem que perguntar se o usuário desejar redefinir a barra de ferramentas.|Não usado.|Não usado.|Não usado.|  
|AFX\_WM\_RESETTOOLBAR|Um objeto de `CMFCToolBar` envia essa mensagem quando uma barra de ferramentas é restaurado para seu estado original, ou seja, carregado de recursos.  Processar esta mensagem para reinserir os botões da barra de ferramentas cujas classes são derivadas de `CMFCToolbarButton`.  Para obter mais informações, consulte `CMFCToolbarComboBoxButton`.|A ID do recurso de uma barra de ferramentas cujo estado é restaurado.|Não usado.|Zero.|  
|AFX\_WM\_SHOWREGULARMENU|o objeto de`CMFCToolbarMenuButton` envia essa mensagem para seu proprietário quando o usuário clica em um botão normal de menu.  Processar esta mensagem toda vez que você usa `CMFCToolbarMenuButton` para exibir um menu pop\-up quando o usuário clica em um botão.|A ID de comando de um botão que envia a mensagem.|Coordenadas de tela de cursor.  As palavras do da ordem mais baixa especificam a coordenada x.  As palavras de ordem alta especifica a coordenada y.|Não usado.|  
|AFX\_WM\_TOOLBARMENU|Enviado à janela principal do quadro quando o usuário libere o botão direito do mouse em uma quando o ponteiro do mouse estiver na área de cliente ou não clientes de um painel.|Não usado.|Coordenadas de tela do ponteiro do mouse em.  As palavras do da ordem mais baixa especificam a coordenada x.  As palavras de ordem alta especifica a coordenada y.|Nulo se o aplicativo processe esta mensagem; se não, diferente de zero.|  
|AFX\_WM\_UPDATETOOLTIPS|Enviada a todos os proprietários de dica de ferramenta para indicar que os controles de dica de ferramenta devem ser recriados.|O tipo de controle que deve processar esta mensagem.  Consulte a tabela posteriormente neste tópico para obter uma lista de valores possíveis.|Não usado.|Não usado.|  
|AFX\_WM\_WINDOW\_HELP|`CMFCWindowsManagerDialog` envia a mensagem ao quadro pai quando o usuário clicar no botão de **Ajuda** , ou passa para o modo de ajuda clicando no botão da legenda de **Ajuda** ou a tecla F1.|Não usado.|Um ponteiro para a instância de `CMFCWindowsManagerDialog`.|Não usado.|  
  
 A tabela a seguir mostra os valores para as baixas palavras do parâmetro de `lParam` do método de AFX\_WM\_HSCROLL:  
  
|||  
|-|-|  
|Valor|Significado|  
|SB\_ENDSCROLL|O usuário termina role.|  
|SB\_LEFT|Rolagens do usuário ao canto superior esquerdo.|  
|SB\_RIGHT|Rolagens do usuário ao inferior direito.|  
|SB\_LINELEFT|O usuário rolar para a esquerda em uma unidade.|  
|SB\_LINERIGHT|O usuário rolar certeza por uma unidade.|  
|SB\_PAGELEFT|O usuário rolar à esquerda pela largura da janela.|  
|SB\_PAGERIGHT|O usuário rolar certeza pela largura da janela.|  
|SB\_THUMBPOSITION|O usuário arrastou a caixa de rolagem \(polegar\) e liberado o botão do mouse em.  As palavras de ordem alta indicam a posição da caixa de rolagem no final da operação.|  
|SB\_THUMBTRACK|O usuário está arrastando a caixa de rolagem.  A mensagem de AFX\_WM\_ON\_HSCROLL será enviada repetidamente com esse valor até que o usuário libere o botão do mouse em.  As palavras de ordem alta indicam a posição na qual a caixa de rolagem foi arrastada.|  
  
> [!NOTE]
>  As palavras de ordem alta do parâmetro de `lParam` especificam a posição atual da caixa de rolagem se palavras de ordem mais inferior são SB\_THUMBPOSITION ou SB\_THUMBTRACK; caso contrário, essas palavras não são usadas.  
  
 A tabela a seguir lista os valores de sinalizador para o parâmetro de `lParam` da mensagem de AFX\_WM\_UPDATETOOLTIPS:  
  
|||  
|-|-|  
|Sinalizador|Valor|  
|AFX\_TOOLTIP\_TYPE\_DEFAULT|0x0001|  
|AFX\_TOOLTIP\_TYPE\_TOOLBAR|0x0002|  
|AFX\_TOOLTIP\_TYPE\_TAB|0x0004|  
|AFX\_TOOLTIP\_TYPE\_MINIFRAME|0x0008|  
|AFX\_TOOLTIP\_TYPE\_DOCKBAR|0x0010|  
|AFX\_TOOLTIP\_TYPE\_EDIT|0x0020|  
|AFX\_TOOLTIP\_TYPE\_BUTTON|0x0040|  
|AFX\_TOOLTIP\_TYPE\_TOOLBOX|0x0080|  
|AFX\_TOOLTIP\_TYPE\_ALL|0xFFFF|  
  
## Consulte também  
 [Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)