---
title: Mensagens AFX
ms.date: 11/04/2016
f1_keywords:
- SB_LINELEFT
- SB_THUMBTRACK
- AFX_TOOLTIP_TYPE_EDIT
- AFX_WM_ON_HSCROLL
- SB_PAGERIGHT
- AFX_WM_RESETPROMPT
- AFX_WM_CHANGE_RIBBON_CATEGORY
- AFX_TOOLTIP_TYPE_MINIFRAME
- AFX_WM_CUSTOMIZETOOLBAR
- AFX_WM_CHANGE_ACTIVE_TAB
- AFX_WM_ACCGETOBJECT
- AFX_WM_TOOLBARMENU
- AFX_TOOLTIP_TYPE_DOCKBAR
- AFX_WM_CUSTOMIZEHELP
- AFX_WM_ON_GET_TAB_TOOLTIP
- AFX_WM_ON_RIBBON_CUSTOMIZE
- AFX_WM_ON_DRAGCOMPLETE
- AFX_WM_RESETTOOLBAR
- AFX_WM_ON_MOVETOTABGROUP
- AFX_WM_CHECKEMPTYMINIFRAME
- AFX_WM_GETDOCUMENTCOLORS
- SB_RIGHT
- AFX_WM_ON_BEFORE_SHOW_RIBBON_ITEM_MENU
- AFX_WM_ACCGETSTATE
- SB_PAGELEFT
- SB_ENDSCROLL
- AFX_WM_ON_CANCELTABMOVE
- AFX_TOOLTIP_TYPE_TAB
- AFX_WM_WINDOW_HELP
- AFX_WM_HIGHLIGHT_RIBBON_LIST_ITEM
- AFX_WM_SHOWREGULARMENU
- AFX_TOOLTIP_TYPE_TOOLBAR
- AFX_WM_CHANGE_CURRENT_FOLDER
- AFX_WM_UPDATETOOLTIPS
- AFX_WM_ON_MOVE_TAB
- AFX_WM_CHANGING_ACTIVE_TAB
- AFX_WM_RESETMENU
- AFX_WM_GETDRAGBOUNDS
- AFX_WM_RESETCONTEXTMENU
- AFX_TOOLTIP_TYPE_BUTTON
- AFX_WM_ON_CLOSEPOPUPWINDOW
- AFX_TOOLTIP_TYPE_TOOLBOX
- AFX_WM_CHANGEVISUALMANAGER
- SB_LINERIGHT
- AFX_WM_ON_RENAME_TAB
- AFX_TOOLTIP_TYPE_DEFAULT
- AFX_WM_ON_TABGROUPMOUSEMOVE
- SB_LEFT
- AFX_WM_DELETETOOLBAR
- AFX_WM_PROPERTY_CHANGED
- AFX_TOOLTIP_TYPE_ALL
- AFX_WM_ACCHITTEST
- AFX_WM_ON_AFTER_SHELL_COMMAND
- AFX_WM_ON_PRESS_CLOSE_BUTTON
- AFX_WM_RESETKEYBOARD
- AFX_WM_ON_MOVETABCOMPLETE
- AFX_WM_CREATETOOLBAR
- SB_THUMBPOSITION
- AFX_WM_POSTSETPREVIEWFRAME
helpviewer_keywords:
- AFX messages [MFC]
ms.assetid: 3d601f3c-af6d-47d3-8553-34f1318fa74f
ms.openlocfilehash: 409760eff6ba6b31413c11fb45ea91a6d07b9485
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88832393"
---
# <a name="afx-messages"></a>Mensagens AFX

Essas mensagens são usadas no MFC.

## <a name="messages"></a>Mensagens

A tabela a seguir lista as mensagens que são usadas na biblioteca do MFC:

|Mensagem|Descrição|no *wParam*|*lParam* (todos os parâmetros são [in], a menos que indicado em contrário.)|Valor Retornado|
|-|-|-|-|-|
|AFX_WM_ACCGETOBJECT|Não usado.|Não usado.|Não aplicável.|Não aplicável.|
|AFX_WM_ACCGETSTATE|Usado para suporte de acessibilidade. Envie esta mensagem para `CMFCPopupMenu` ou `CMFCRibbonPanelMenu` para recuperar o estado do elemento atual.|Índice do elemento, que pode ser um botão de menu ou separador.|Não usado.|O estado do elemento. Será-1 se o índice for inválido, 0 se o botão de menu não tiver nenhum atributo especial. Caso contrário, é uma combinação dos seguintes sinalizadores:<br /><br /> TBBS_DISABLED – o item está desabilitado<br /><br /> TBBS_CHECKED – o item está marcado<br /><br /> TBBS_BUTTON — o item é um botão de pressão padrão<br /><br /> TBBS_PRESSED — o botão é pressionado<br /><br /> TBBS_INDETERMINATE — estado indefinido<br /><br /> TBBS_SEPARATOR-em vez de um botão de menu, esse elemento forma uma separação entre outros itens de menu|
|AFX_WM_CHANGE_ACTIVE_TAB|A estrutura envia essa mensagem para o controle de barra de controle redimensionável. Processe esta mensagem para receber notificações de `CMFCTabCtrl` objetos quando um usuário alterar uma guia ativa.|O índice de uma guia.|Não usado.|Diferente.|
|AFX_WM_CHANGE_CURRENT_FOLDER|A estrutura envia essa mensagem ao pai de `CMFCShellListCtrl` quando o usuário alterou a pasta atual.|Não usado.|Não usado.|Não usado.|
|AFX_WM_CHANGEVISUALMANAGER|A estrutura envia essa mensagem a todas as janelas de quadro quando o usuário altera o Gerenciador de visual atual. Em resposta a essa mensagem, uma janela de quadro recalcula sua região e ajusta outros parâmetros conforme necessário. Você pode processar a mensagem de AFX_WM_CHANGEVISUALMANAGER em seu aplicativo se precisar ser notificado sobre esse evento. Você deve chamar o manipulador de classe base ( `OnChangeVisualManager` ) para garantir que o processamento interno desse evento da estrutura ocorra.|Não usado.|Não usado.|Não usado.|
|AFX_WM_CHANGING_ACTIVE_TAB|Enviado ao pai do `CMFCTabCtrl` objeto.  Processe esta mensagem se você quiser receber notificações de `CMFCTabCtrl` objetos quando um usuário redefine uma guia.|O índice da guia que está sendo ativada.|Não usado.|Diferente.|
|AFX_WM_CHECKEMPTYMINIFRAME|Somente para uso interno.|Não aplicável.|Não aplicável.|Não aplicável.|
|AFX_WM_CREATETOOLBAR|Enviado de `CMFCToolBarsListPropertyPage` quando um usuário cria uma nova barra de ferramentas durante o processo de personalização. Você pode processar essa mensagem para criar uma instância de um objeto personalizado derivado de CMFCToolBar. Se você tratar essa mensagem e criar sua própria barra de ferramentas, omita a chamada para o manipulador padrão.|Não usado.|Um ponteiro para uma cadeia de caracteres que contém o nome da barra de ferramentas.|Um ponteiro para a barra de ferramentas recém-criada. NULL indica que a criação da barra de ferramentas foi cancelada.|
|AFX_WM_CUSTOMIZEHELP|Enviado para a janela de quadro principal da folha de propriedades de personalização `CMFCToolbarCustomize Dialog` quando o usuário pressiona o botão de **ajuda** ou a tecla F1.|Especifica a página ativa da folha de propriedades de personalização.|Um ponteiro para um objeto `CMFCToolbarCustomize Dialog`.|Zero.|
|AFX_WM_CUSTOMIZETOOLBAR|O `CMFCToolbarCustomize Dialog` envia essa mensagem para notificar o quadro pai de que o usuário está criando uma nova barra de ferramentas.|TRUE quando a personalização for iniciada, FALSE quando a personalização for concluída.|Não usado.|Zero.|
|AFX_WM_DELETETOOLBAR|Enviado para a janela do quadro principal quando o usuário está prestes a excluir uma barra de ferramentas no modo de personalização.<br /><br /> Processe esta mensagem para executar ações adicionais quando um usuário excluir uma barra de ferramentas no modo de personalização. Você também deve chamar o manipulador padrão ( `OnToolbarDelete` ), que exclui a barra de ferramentas. O manipulador padrão retorna um valor que indica se é possível excluir a barra de ferramentas.|Não usado.|Ponteiro para um `CMFCToolBar` objeto a ser excluído.|Diferente de zero se uma barra de ferramentas não puder ser excluída; caso contrário, 0.|
|AFX_WM_GETDOCUMENTCOLORS|`CMFCColorMenuButton` envia esta mensagem à janela do quadro principal para recuperar as cores do documento.|Não usado.|[entrada, saída] Ponteiro para um `CList<COLORREF, COLORREF>` objeto.|Zero.|
|AFX_WM_GETDRAGBOUNDS|Somente para uso interno.|Não aplicável.|Não aplicável.|Não aplicável.|
|AFX_WM_HIGHLIGHT_RIBBON_LIST_ITEM|Enviado para a janela do quadro principal quando um usuário realça um item da lista da faixa de faixas.|Índice do item realçado|Um ponteiro para `CMFCBaseRibbonElement`|Não usado.|
|AFX_WM_ON_AFTER_SHELL_COMMAND|Enviado para um pai `CMFCShellListCtrl` ou `CMFCShellTreeCtrl` controles quando um usuário conclui a execução de um comando do Shell.|A ID do comando que o usuário executou|Não usado.|Se o aplicativo processar essa mensagem, ele deverá retornar zero.|
|AFX_WM_ON_BEFORE_SHOW_RIBBON_ITEM_MENU|A estrutura envia essa mensagem para o pai da faixa de medida antes de exibir o menu pop-up. Você pode processar essa mensagem e modificar os menus pop-up a qualquer momento.|Não usado.|Um ponteiro para `CMFCBaseRibbonElement`|Não usado.|
|AFX_WM_ON_CANCELTABMOVE|Somente para uso interno.|Não aplicável.|Não aplicável.||
|AFX_WM_ON_CHANGE_RIBBON_CATEGORY|A estrutura envia essa mensagem ao quadro principal quando o usuário altera a categoria de controle da faixa de quadros ativa.|Não usado.|Um ponteiro para a `CMFCRibbonBar` cuja categoria foi alterada.|Não usado.|
|AFX_WM_ON_CLOSEPOPUPWINDOW|A estrutura envia essa mensagem para notificar o proprietário de `CMFCDesktopAlertWnd` que a janela está prestes a ser fechada.|Não usado.|Um ponteiro para `CMFCDesktopAlertWnd` objeto.|Não usado.|
|AFX_WM_ON_DRAGCOMPLETE|Somente para uso interno.|Não aplicável.|Não aplicável.|Não aplicável.|
|AFX_WM_ON_GET_TAB_TOOLTIP|Enviado para a janela do quadro principal quando uma janela de guia está prestes a exibir uma dica de ferramenta para uma guia, se as dicas de ferramentas personalizadas estiverem habilitadas.|Não usado.|Um ponteiro para uma `CMFCTabToolTipInfo` estrutura.|Não usado.|
|AFX_WM_ON_HSCROLL|Enviado para o controle de barra de controle redimensionável. Processe esta mensagem para receber notificações de `CMFCTabCtrl` objetos quando ocorrer um evento de rolagem na barra de rolagem horizontal do widget com guias.|A palavra de ordem inferior Especifica um valor de barra de rolagem que indica a solicitação de rolagem do usuário.  Para obter mais informações, consulte a tabela posteriormente neste tópico.|Não usado.|Diferente.|
|AFX_WM_ON_MOVE_TAB|Enviado ao pai de uma janela com guias quando um usuário arrasta uma tabulação para uma nova posição.|O índice de base zero da guia em sua posição original.|fora O índice de base zero da guia em sua nova posição.|Zero.|
|AFX_WM_ON_MOVETABCOMPLETE|Somente para uso interno.|Não aplicável.|Não aplicável.|Não aplicável.|
|AFX_WM_ON_MOVETOTABGROUP|Enviado para a janela do quadro principal quando um usuário move uma janela filho MDI de um grupo com guias para outro.|Um identificador para janela com guias ( `CMFCTabCtrl` ) do qual a janela filho MDI foi removida.|fora Um identificador para janela com guias ( `CMFCTabCtrl` ) para o qual a janela filho MDI foi inserida.|Ignorado.|
|AFX_WM_ON_PRESS_CLOSE_BUTTON|Enviado a um pai de `CDockablePane` quando o usuário clica no botão **fechar** na legenda da barra de controle.|Não usado.|Um ponteiro para um painel encaixáveis no qual o usuário clicou no botão **fechar** .|TRUE se um painel não puder ser fechado; caso contrário, FALSE.|
|AFX_WM_ON_RENAME_TAB|Enviado ao pai da janela com guias depois que o usuário renomeou uma guia editável.|O índice de base zero da guia renomeada.|fora Um ponteiro para uma cadeia de caracteres que contém o novo nome de guia.|Diferente de zero se o aplicativo processar esta mensagem; a estrutura irá suprimir a chamada para `CMFCBaseTabCtrl::SetTabLabel` .  Se zero for retornado, `CMFCBaseTabCtrl::SetTabLabel` será chamado pelo Framework.|
|AFX_WM_ON_RIBBON_CUSTOMIZE|Enviado ao quadro pai quando o usuário inicia a personalização. Processe esta mensagem se você quiser exibir sua própria caixa de diálogo de personalização.|Não usado.|Um ponteiro para o controle da faixa de faixas a ser personalizado.|Diferente de zero se o aplicativo processar essa mensagem e exibir sua própria caixa de diálogo de personalização. Se o aplicativo retornar zero, a estrutura exibirá a caixa de diálogo de personalização interna.|
|AFX_WM_ON_TABGROUPMOUSEMOVE|Somente para uso interno.|Não aplicável.|Não aplicável.|Não aplicável.|
|AFX_WM_POSTSETPREVIEWFRAME|Enviado para notificar o quadro principal de que o usuário alterou o modo de visualização de impressão|VERDADEIRO indica que o modo de visualização de impressão está definido. FALSO indica que o modo de visualização de impressão está desativado.|Não usado.|Não usado.|
|AFX_WM_PROPERTY_CHANGED|Enviado ao proprietário do controle de grade de propriedade ( `CMFCPropertyGridCtrl` ) quando o usuário altera o valor da propriedade selecionada.|A ID de controle da lista de propriedades.|Um ponteiro para a propriedade ( `CMFCPropertyGridProperty` ) que foi alterado.|Não usado.|
|AFX_WM_RESETCONTEXTMENU|Enviado para a janela do quadro principal quando o usuário redefine o menu de contexto durante a personalização.|A ID de recurso do menu de contexto.|Um ponteiro para o menu de contexto atual, `CMFCPopupMenu` .|Não usado.|
|AFX_WM_RESETKEYBOARD|A estrutura envia essa mensagem à janela do quadro principal quando o usuário redefine todos os aceleradores de teclado durante a personalização.|Não usado.|Não usado.|Não usado.|
|AFX_WM_RESETMENU|A estrutura envia essa mensagem ao proprietário do menu (uma janela de quadro) quando o usuário redefine um menu de quadro de aplicativo durante a personalização|A ID de recurso do menu.|Não usado.|Não usado.|
|AFX_WM_RESETPROMPT|A estrutura envia essa mensagem quando o usuário redefine uma barra de ferramentas na caixa de diálogo Personalizar barra de ferramentas. O manipulador padrão exibe uma caixa de mensagem que pergunta se o usuário deseja redefinir a barra de ferramentas.|Não usado.|Não usado.|Não usado.|
|AFX_WM_RESETTOOLBAR|Um `CMFCToolBar` objeto envia essa mensagem quando uma barra de ferramentas é restaurada para seu estado original, ou seja, carregada a partir dos recursos. Processe essa mensagem para reinserir os botões da barra de ferramentas cujas classes são derivadas de `CMFCToolbarButton` . Para obter mais informações, consulte `CMFCToolbarComboBoxButton`.|A ID de recurso de uma barra de ferramentas cujo estado foi restaurado.|Não usado.|Zero.|
|AFX_WM_SHOWREGULARMENU|`CMFCToolbarMenuButton` o objeto envia essa mensagem ao seu proprietário quando o usuário clica em um botão de menu normal. Processe esta mensagem toda vez que você usar `CMFCToolbarMenuButton` para exibir um menu pop-up quando o usuário clicar em um botão.|A ID de comando de um botão que envia a mensagem.|Coordenadas de tela do cursor. A palavra de ordem inferior Especifica a coordenada x. A palavra de ordem superior especifica a coordenada y.|Não usado.|
|AFX_WM_TOOLBARMENU|Enviado para a janela do quadro principal quando o usuário libera o botão direito de um mouse enquanto o ponteiro do mouse está na área cliente ou não cliente de um painel.|Não usado.|Coordenadas de tela do ponteiro do mouse. A palavra de ordem inferior Especifica a coordenada x. A palavra de ordem superior especifica a coordenada y.|Zero se o aplicativo processar esta mensagem; caso contrário, diferente de zero.|
|AFX_WM_UPDATETOOLTIPS|Enviado a todos os proprietários da dica de ferramenta para indicar que seus controles de dica de ferramenta devem ser recriados.|O tipo de controle que deve processar esta mensagem. Consulte a tabela mais adiante neste tópico para obter uma lista de possíveis valores.|Não usado.|Não usado.|
|AFX_WM_WINDOW_HELP|`CMFCWindowsManagerDialog` envia essa mensagem para o quadro pai quando o usuário clica no botão **ajuda** ou insere o modo de ajuda clicando no botão de legenda da **ajuda** ou na tecla F1.|Não usado.|Um ponteiro para a instância do `CMFCWindowsManagerDialog` .|Não usado.|

A tabela a seguir mostra os valores para a palavra baixa do parâmetro *lParam* do método AFX_WM_HSCROLL:

|Valor|Significado|
|-|-|
|SB_ENDSCROLL|O usuário encerra a rolagem.|
|SB_LEFT|O usuário rola para a parte superior esquerda.|
|SB_RIGHT|O usuário rola para a parte inferior direita.|
|SB_LINELEFT|O usuário rola para a esquerda por uma unidade.|
|SB_LINERIGHT|O usuário rola diretamente uma unidade.|
|SB_PAGELEFT|O usuário rola para a esquerda pela largura da janela.|
|SB_PAGERIGHT|O usuário rola para a direita pela largura da janela.|
|SB_THUMBPOSITION|O usuário arrastou a caixa de rolagem (Thumb) e liberou o botão do mouse. A palavra de ordem superior indica a posição da caixa de rolagem no final da operação de arrastar.|
|SB_THUMBTRACK|O usuário está arrastando a caixa de rolagem. A mensagem de AFX_WM_ON_HSCROLL é enviada repetidamente com esse valor até que o usuário libere o botão do mouse. A palavra de ordem superior indica a posição para a qual a caixa de rolagem foi arrastada.|

> [!NOTE]
> A palavra de ordem superior do parâmetro *lParam* especifica a posição atual da caixa de rolagem se a palavra de ordem inferior for SB_THUMBPOSITION ou SB_THUMBTRACK; caso contrário, essa palavra não será usada.

A tabela a seguir lista os valores de sinalizador para o parâmetro *lParam* da mensagem de AFX_WM_UPDATETOOLTIPS:

|Sinalizador|Valor|
|-|-|
|AFX_TOOLTIP_TYPE_DEFAULT|0x0001|
|AFX_TOOLTIP_TYPE_TOOLBAR|0x0002|
|AFX_TOOLTIP_TYPE_TAB|0x0004|
|AFX_TOOLTIP_TYPE_MINIFRAME|0x0008|
|AFX_TOOLTIP_TYPE_DOCKBAR|0x0010|
|AFX_TOOLTIP_TYPE_EDIT|0x0020|
|AFX_TOOLTIP_TYPE_BUTTON|0x0040|
|AFX_TOOLTIP_TYPE_TOOLBOX|0x0080|
|AFX_TOOLTIP_TYPE_ALL|0xFFFF|

## <a name="see-also"></a>Confira também

[Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)
