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
ms.openlocfilehash: b4ed86c11d3c5b5f1ce38e3146533109f3a6b00d
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81363591"
---
# <a name="afx-messages"></a>Mensagens AFX

Essas mensagens são usadas em MFC.

## <a name="messages"></a>Mensagens

A tabela a seguir lista mensagens usadas na biblioteca Do MFC:

||||||
|-|-|-|-|-|
|Mensagem|Descrição|[em] *wParam*|*lParam* (Todos os parâmetros estão [em] a menos que seja indicado de outra forma.)|Valor retornado|
|AFX_WM_ACCGETOBJECT|Não usado.|Não usado.|Não aplicável.|Não aplicável.|
|AFX_WM_ACCGETSTATE|Usado para suporte de acessibilidade. Envie esta `CMFCPopupMenu` mensagem para ou `CMFCRibbonPanelMenu` para recuperar o estado do elemento atual.|Índice de elemento, que pode ser um botão de menu ou separador.|Não usado.|O estado do elemento. É -1 se o índice for inválido, 0 se o botão de menu não tiver atributos especiais. Caso contrário, é uma combinação das seguintes bandeiras:<br /><br /> TBBS_DISABLED — o item está desativado<br /><br /> TBBS_CHECKED — o item é verificado<br /><br /> TBBS_BUTTON — o item é um botão padrão<br /><br /> TBBS_PRESSED — o botão é pressionado<br /><br /> TBBS_INDETERMINATE — estado indefinido<br /><br /> TBBS_SEPARATOR - em vez de um botão de menu, este elemento forma uma separação entre outros itens do menu|
|AFX_WM_CHANGE_ACTIVE_TAB|A estrutura envia esta mensagem para o controle da barra de controle resizável. Processe esta mensagem `CMFCTabCtrl` para receber notificações de objetos quando um usuário altera uma guia ativa.|O índice de uma guia.|Não usado.|Zero.|
|AFX_WM_CHANGE_CURRENT_FOLDER|O framework envia essa mensagem para o pai de `CMFCShellListCtrl` quando o usuário alterou a pasta atual.|Não usado.|Não usado.|Não usado.|
|AFX_WM_CHANGEVISUALMANAGER|A estrutura envia essa mensagem para todas as janelas de quadroquando o usuário altera o Gerenciador Visual atual. Em resposta a esta mensagem, uma janela de quadro recalcula sua região e ajusta outros parâmetros conforme necessário. Você pode processar a mensagem AFX_WM_CHANGEVISUALMANAGER em seu aplicativo se precisar ser notificado sobre esse evento. Você deve chamar o`OnChangeVisualManager`manipulador de classe base ( ) para garantir que o processamento interno deste evento ocorra.|Não usado.|Não usado.|Não usado.|
|AFX_WM_CHANGING_ACTIVE_TAB|Enviado para o `CMFCTabCtrl` pai do objeto.  Processe esta mensagem se `CMFCTabCtrl` quiser receber notificações de objetos quando um usuário redefinir uma guia.|O índice da guia que está sendo ativada.|Não usado.|Zero.|
|AFX_WM_CHECKEMPTYMINIFRAME|Apenas para uso interno.|Não aplicável.|Não aplicável.|Não aplicável.|
|AFX_WM_CREATETOOLBAR|Enviado `CMFCToolBarsListPropertyPage` a partir de quando um usuário cria uma nova barra de ferramentas durante o processo de personalização. Você pode processar esta mensagem para instanciar um objeto personalizado derivado do CMFCToolBar. Se você manusear esta mensagem e criar sua própria barra de ferramentas, omita a chamada para o manipulador padrão.|Não usado.|Um ponteiro para uma seqüência que contém o nome da barra de ferramentas.|Um ponteiro para a barra de ferramentas recém-criada. NULL indica que a criação da barra de ferramentas foi cancelada.|
|AFX_WM_CUSTOMIZEHELP|Enviado para a janela do quadro `CMFCToolbarCustomize Dialog` principal a partir da folha de propriedade de personalização quando o usuário pressiona o botão **Ajuda** ou a tecla F1.|Especifica a página ativa da folha de propriedade de personalização.|Um ponteiro para um objeto `CMFCToolbarCustomize Dialog`.|Zero.|
|AFX_WM_CUSTOMIZETOOLBAR|O `CMFCToolbarCustomize Dialog` envio desta mensagem para notificar o quadro pai de que o usuário está criando uma nova barra de ferramentas.|TRUE quando a personalização é iniciada, FALSE quando a personalização é concluída.|Não usado.|Zero.|
|AFX_WM_DELETETOOLBAR|Enviado para a janela do quadro principal quando o usuário está prestes a excluir uma barra de ferramentas no modo de personalização.<br /><br /> Processe esta mensagem para tomar ações adicionais quando um usuário exclui uma barra de ferramentas no modo de personalização. Você também deve chamar`OnToolbarDelete`o manipulador padrão (), que exclui a barra de ferramentas. O manipulador padrão retorna um valor que indica se é possível excluir a barra de ferramentas.|Não usado.|Ponteiro para `CMFCToolBar` um objeto a ser excluído.|Não zero se uma barra de ferramentas não puder ser excluída; caso contrário, 0.|
|AFX_WM_GETDOCUMENTCOLORS|`CMFCColorMenuButton`envia essa mensagem para a janela principal do quadro para recuperar as cores do documento.|Não usado.|[dentro, fora] Ponteiro para `CList<COLORREF, COLORREF>` um objeto.|Zero.|
|AFX_WM_GETDRAGBOUNDS|Apenas para uso interno.|Não aplicável.|Não aplicável.|Não aplicável.|
|AFX_WM_HIGHLIGHT_RIBBON_LIST_ITEM|Enviado para a janela do quadro principal quando um usuário destaca um item da lista de fitas.|Índice do item destacado|Um ponteiro para`CMFCBaseRibbonElement`|Não usado.|
|AFX_WM_ON_AFTER_SHELL_COMMAND|Enviado a um `CMFCShellListCtrl` `CMFCShellTreeCtrl` pai ou controles quando um usuário termina de executar um comando shell.|O ID do comando que o usuário executou|Não usado.|Se o aplicativo processa essa mensagem, ela deve retornar zero.|
|AFX_WM_ON_BEFORE_SHOW_RIBBON_ITEM_MENU|O framework envia essa mensagem para o pai da fita antes de exibir o menu pop-up. Você pode processar esta mensagem e modificar menus pop-up a qualquer momento.|Não usado.|Um ponteiro para`CMFCBaseRibbonElement`|Não usado.|
|AFX_WM_ON_CANCELTABMOVE|Apenas para uso interno.|Não aplicável.|Não aplicável.||
|AFX_WM_ON_CHANGE_RIBBON_CATEGORY|O framework envia essa mensagem para o quadro principal quando o usuário altera a categoria controle de fita ativa.|Não usado.|Um ponteiro `CMFCRibbonBar` para a categoria cuja categoria mudou.|Não usado.|
|AFX_WM_ON_CLOSEPOPUPWINDOW|A estrutura envia esta mensagem `CMFCDesktopAlertWnd` para notificar o proprietário de que a janela está prestes a ser fechada.|Não usado.|Um ponteiro `CMFCDesktopAlertWnd` para objeto.|Não usado.|
|AFX_WM_ON_DRAGCOMPLETE|Apenas para uso interno.|Não aplicável.|Não aplicável.|Não aplicável.|
|AFX_WM_ON_GET_TAB_TOOLTIP|Enviado para a janela do quadro principal quando uma janela de guia está prestes a exibir uma dica de ferramenta para uma guia, se as dicas de ferramentas personalizadas estiverem habilitadas.|Não usado.|Um ponteiro `CMFCTabToolTipInfo` para uma estrutura.|Não usado.|
|AFX_WM_ON_HSCROLL|Enviado para o controle da barra de controle resizável. Processe esta mensagem `CMFCTabCtrl` para receber notificações de objetos quando um evento de rolagem ocorrer na barra de rolagem horizontal do widget guiado.|A palavra de baixa ordem especifica um valor de barra de rolagem que indica a solicitação de rolagem do usuário.  Para obter mais informações, consulte a tabela posteriormente neste tópico.|Não usado.|Zero.|
|AFX_WM_ON_MOVE_TAB|Enviado para o pai de uma janela com guias quando um usuário arrasta uma guia para uma nova posição.|O índice baseado em zero da guia em sua posição original.|[fora] O índice baseado em zero da guia em sua nova posição.|Zero.|
|AFX_WM_ON_MOVETABCOMPLETE|Apenas para uso interno.|Não aplicável.|Não aplicável.|Não aplicável.|
|AFX_WM_ON_MOVETOTABGROUP|Enviado para a janela do quadro principal quando um usuário move uma janela de criança MDI de um grupo com guias para outro.|Uma alça para a`CMFCTabCtrl`janela de guias ( ) da qual a janela da criança MDI foi removida.|[fora] Uma alça para a`CMFCTabCtrl`janela de guias ( ) para a qual a janela da criança MDI foi inserida.|Ignorado.|
|AFX_WM_ON_PRESS_CLOSE_BUTTON|Enviado para um `CDockablePane` pai de quando o usuário clica no botão **Fechar** na legenda da barra de controle.|Não usado.|Um ponteiro para um painel dockable no qual o usuário clicou no botão **Fechar.**|VERDADE se um painel não pode ser fechado; caso contrário, FALSO.|
|AFX_WM_ON_RENAME_TAB|Enviado para o pai da janela com guias depois que o usuário renomeou uma guia editável.|O índice baseado em zero da guia renomeada.|[fora] Um ponteiro para uma seqüência que contém o novo nome da guia.|Não zero se o aplicativo processa essa mensagem; o quadro suprimirá `CMFCBaseTabCtrl::SetTabLabel`a chamada para .  Se zero é devolvido, então `CMFCBaseTabCtrl::SetTabLabel` é chamado pelo quadro.|
|AFX_WM_ON_RIBBON_CUSTOMIZE|Enviado para o quadro pai quando o usuário inicia a personalização. Processe esta mensagem se quiser exibir sua própria caixa de diálogo de personalização.|Não usado.|Um ponteiro para o controle da fita a ser personalizado.|Não zero se o aplicativo processa essa mensagem e exibe sua própria caixa de diálogo de personalização. Se o aplicativo retornar zero, a estrutura exibirá a caixa de diálogo de personalização incorporada.|
|AFX_WM_ON_TABGROUPMOUSEMOVE|Apenas para uso interno.|Não aplicável.|Não aplicável.|Não aplicável.|
|AFX_WM_POSTSETPREVIEWFRAME|Enviado para notificar o quadro principal de que o usuário alterou o modo de visualização de impressão|TRUE indica que o modo de visualização de impressão está definido. FALSE indica que o modo de visualização de impressão está desligado.|Não usado.|Não usado.|
|AFX_WM_PROPERTY_CHANGED|Enviado ao proprietário do controle`CMFCPropertyGridCtrl`da grade de propriedade ( ) quando o usuário altera o valor da propriedade selecionada.|A id de controle da lista de propriedades.|Um ponteiro para`CMFCPropertyGridProperty`a propriedade que mudou.|Não usado.|
|AFX_WM_RESETCONTEXTMENU|Enviado para a janela do quadro principal quando o usuário redefine o menu de contexto durante a personalização.|O ID de recurso do menu de contexto.|Um ponteiro para o `CMFCPopupMenu`menu de contexto atual, .|Não usado.|
|AFX_WM_RESETKEYBOARD|A estrutura envia essa mensagem para a janela principal do quadro quando o usuário redefine todos os aceleradores de teclado durante a personalização.|Não usado.|Não usado.|Não usado.|
|AFX_WM_RESETMENU|A estrutura envia essa mensagem para o proprietário do menu (uma janela de quadro) quando o usuário redefine um menu de quadro de aplicativo durante a personalização|O id de recurso do menu.|Não usado.|Não usado.|
|AFX_WM_RESETPROMPT|A estrutura envia esta mensagem quando o usuário redefine uma barra de ferramentas da caixa de diálogo de personalização da barra de ferramentas. O manipulador padrão exibe uma caixa de mensagens que pergunta se o usuário deseja redefinir a barra de ferramentas.|Não usado.|Não usado.|Não usado.|
|Afx_wm_resettoolbar|Um `CMFCToolBar` objeto envia essa mensagem quando uma barra de ferramentas é restaurada ao seu estado original, ou seja, carregada dos recursos. Processe esta mensagem para reinserir botões de `CMFCToolbarButton`barra de ferramentas cujas classes são derivadas de . Para obter mais informações, consulte `CMFCToolbarComboBoxButton`.|A id de recurso de uma barra de ferramentas cujo estado foi restaurado.|Não usado.|Zero.|
|AFX_WM_SHOWREGULARMENU|`CMFCToolbarMenuButton`objeto envia esta mensagem para seu proprietário quando o usuário clica em um botão de menu regular. Processe esta mensagem `CMFCToolbarMenuButton` toda vez que você usar para exibir um menu pop-up quando o usuário clicar em um botão.|O ID de comando de um botão que envia a mensagem.|Coordenadas de tela do cursor. A palavra de baixa ordem especifica a coordenada x. A palavra de alta ordem especifica a coordenada y.|Não usado.|
|AFX_WM_TOOLBARMENU|Enviado para a janela do quadro principal quando o usuário libera o botão direito de um mouse enquanto o ponteiro do mouse está na área cliente ou não-cliente de um painel.|Não usado.|Coordenadas de tela do ponteiro do mouse. A palavra de baixa ordem especifica a coordenada x. A palavra de alta ordem especifica a coordenada y.|Zero se o aplicativo processa essa mensagem; caso contrário, não zero.|
|AFX_WM_UPDATETOOLTIPS|Enviado a todos os proprietários de dicas de ferramentas para indicar que seus controles de ponta de ferramenta devem ser recriados.|O tipo de controle que deve processar esta mensagem. Consulte a tabela mais tarde neste tópico para obter uma lista de possíveis valores.|Não usado.|Não usado.|
|AFX_WM_WINDOW_HELP|`CMFCWindowsManagerDialog`envia esta mensagem para o quadro pai quando o usuário clica no botão **Ajuda** ou entra no modo de ajuda clicando no botão De legenda **de ajuda** ou na tecla F1.|Não usado.|Um ponteiro para `CMFCWindowsManagerDialog`a instância de .|Não usado.|

A tabela a seguir mostra os valores para a palavra baixa do parâmetro *lParam* do método AFX_WM_HSCROLL:

|||
|-|-|
|Valor|Significado|
|SB_ENDSCROLL|O usuário termina o pergaminho.|
|SB_LEFT|O usuário rola para o canto superior esquerdo.|
|SB_RIGHT|O usuário rola para a parte inferior direita.|
|SB_LINELEFT|O usuário rola para a esquerda por uma unidade.|
|SB_LINERIGHT|O usuário rola por uma unidade.|
|SB_PAGELEFT|O usuário rola para a esquerda pela largura da janela.|
|SB_PAGERIGHT|O usuário rola pela largura da janela.|
|Sb_thumbposition|O usuário arrastou a caixa de rolagem (polegar) e liberou o botão do mouse. A palavra de alta ordem indica a posição da caixa de rolagem no final da operação de arrasto.|
|Sb_thumbtrack|O usuário está arrastando a caixa de rolagem. A mensagem AFX_WM_ON_HSCROLL é enviada repetidamente com esse valor até que o usuário libere o botão do mouse. A palavra de alta ordem indica a posição para a qual a caixa de rolagem foi arrastada.|

> [!NOTE]
> A palavra de alta ordem do parâmetro *lParam* especifica a posição atual da caixa de rolagem se a palavra de baixa ordem estiver SB_THUMBPOSITION ou SB_THUMBTRACK; caso contrário, esta palavra não é usada.

A tabela a seguir lista os valores de bandeira para o parâmetro *lParam* da mensagem AFX_WM_UPDATETOOLTIPS:

|||
|-|-|
|Sinalizador|Valor|
|AFX_TOOLTIP_TYPE_DEFAULT|0x0001|
|AFX_TOOLTIP_TYPE_TOOLBAR|0x0002|
|AFX_TOOLTIP_TYPE_TAB|0x0004|
|AFX_TOOLTIP_TYPE_MINIFRAME|0x0008|
|AFX_TOOLTIP_TYPE_DOCKBAR|0x0010|
|AFX_TOOLTIP_TYPE_EDIT|0x0020|
|AFX_TOOLTIP_TYPE_BUTTON|0x0040|
|AFX_TOOLTIP_TYPE_TOOLBOX|0x0080|
|AFX_TOOLTIP_TYPE_ALL|0xffff|

## <a name="see-also"></a>Confira também

[Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)
