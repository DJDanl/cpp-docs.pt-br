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
ms.openlocfilehash: 5caf40fc757e2c5c90c06e1698ce4c15d1ed6240
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62338053"
---
# <a name="afx-messages"></a>Mensagens AFX

Essas mensagens são usadas no MFC.

## <a name="messages"></a>Mensagens

A tabela a seguir lista as mensagens que são usadas na biblioteca do MFC:

||||||
|-|-|-|-|-|
|Mensagem|Descrição|[in] *wParam*|*lParam* (todos os parâmetros são [in], a menos que indicado de outra forma).|Valor de retorno|
|AFX_WM_ACCGETOBJECT|Não usado.|Não usado.|Não aplicável.|Não aplicável.|
|AFX_WM_ACCGETSTATE|Usado para suporte de acessibilidade. Enviar esta mensagem para `CMFCPopupMenu` ou `CMFCRibbonPanelMenu` para recuperar o estado do elemento atual.|Índice do elemento, o que poderia ser um botão de menu ou um separador.|Não usado.|O estado do elemento. Ele é -1 se o índice é inválido, 0 se o botão de menu não tem nenhum atributo especial. Caso contrário, ele é uma combinação dos sinalizadores a seguir:<br /><br /> TBBS_DISABLED — o item está desabilitado<br /><br /> TBBS_CHECKED — o item está marcado<br /><br /> TBBS_BUTTON — o item é um botão de ação padrão<br /><br /> TBBS_PRESSED — é pressionado<br /><br /> TBBS_INDETERMINATE — estado indefinido<br /><br /> TBBS_SEPARATOR - em vez de um botão de menu, essa forma de elemento uma separação entre outros itens de menu|
|AFX_WM_CHANGE_ACTIVE_TAB|O framework envia essa mensagem para o controle de barra de controle redimensionável. Processar essa mensagem para receber notificações de `CMFCTabCtrl` objetos quando um usuário altera a guia ativa.|O índice de uma guia.|Não usado.|Nonzero.|
|AFX_WM_CHANGE_CURRENT_FOLDER|O framework envia essa mensagem para o pai do `CMFCShellListCtrl` quando o usuário alterou a pasta atual.|Não usado.|Não usado.|Não usado.|
|AFX_WM_CHANGEVISUALMANAGER|O framework envia essa mensagem para todas as janelas de quadro quando o usuário altera o Gerenciador Visual atual. Em resposta a essa mensagem, uma janela de quadro recalcula a sua região e ajusta os outros parâmetros conforme necessário. É possível processar a mensagem AFX_WM_CHANGEVISUALMANAGER em seu aplicativo, se você precisar ser notificado sobre esse evento. Você deve chamar o manipulador de classe base (`OnChangeVisualManager`) para garantir que a estrutura do interna processamento esse evento ocorre.|Não usado.|Não usado.|Não usado.|
|AFX_WM_CHANGING_ACTIVE_TAB|Enviado para o pai do `CMFCTabCtrl` objeto.  Processar essa mensagem se você quiser receber notificações de `CMFCTabCtrl` objetos quando um usuário redefine uma guia.|O índice da guia que está sendo ativado.|Não usado.|Nonzero.|
|AFX_WM_CHECKEMPTYMINIFRAME|Somente para uso interno.|Não aplicável.|Não aplicável.|Não aplicável.|
|AFX_WM_CREATETOOLBAR|Enviado de `CMFCToolBarsListPropertyPage` quando um usuário cria uma nova barra de ferramentas durante o processo de personalização. Você pode processar essa mensagem para instanciar um objeto personalizado derivado de CMFCToolBar. Se você lidar com essa mensagem e cria sua própria barra de ferramentas, omita a chamada para o manipulador padrão.|Não usado.|Um ponteiro para uma cadeia de caracteres que contém o nome da barra de ferramentas.|Um ponteiro para a barra de ferramentas criado recentemente. NULL indica que a criação da barra de ferramentas foi cancelada.|
|AFX_WM_CUSTOMIZEHELP|Enviado para a janela de quadro principal da folha de propriedades de personalização `CMFCToolbarCustomize Dialog` quando o usuário pressiona o **ajudar** botão ou a tecla F1.|Especifica a página ativa da folha de propriedades de personalização.|Um ponteiro para um `CMFCToolbarCustomize Dialog` objeto.|Zero.|
|AFX_WM_CUSTOMIZETOOLBAR|O `CMFCToolbarCustomize Dialog` envia essa mensagem para notificar o quadro principal que o usuário está criando uma nova barra de ferramentas.|TRUE quando a personalização é iniciada, Falso quando a personalização for concluída.|Não usado.|Zero.|
|AFX_WM_DELETETOOLBAR|Enviado para a janela de quadro principal quando o usuário está prestes a excluir uma barra de ferramentas no modo de personalização.<br /><br /> Processe essa mensagem, para executar ações adicionais quando um usuário exclui uma barra de ferramentas no modo de personalização. Você também deve chamar o manipulador padrão (`OnToolbarDelete`), que exclui a barra de ferramentas. O manipulador padrão retorna um valor que indica se é possível excluir a barra de ferramentas.|Não usado.|Ponteiro para um `CMFCToolBar` objeto a ser excluído.|Diferente de zero se uma barra de ferramentas não pode ser excluída; Caso contrário, 0.|
|AFX_WM_GETDOCUMENTCOLORS|`CMFCColorMenuButton` envia essa mensagem para a janela do quadro principal para recuperar as cores de documento.|Não usado.|[no, out] Ponteiro para um `CList<COLORREF, COLORREF>` objeto.|Zero.|
|AFX_WM_GETDRAGBOUNDS|Somente para uso interno.|Não aplicável.|Não aplicável.|Não aplicável.|
|AFX_WM_HIGHLIGHT_RIBBON_LIST_ITEM|Enviado para a janela do quadro principal quando um usuário realça um item de lista da faixa de opções.|Índice do item realçado|Um ponteiro para `CMFCBaseRibbonElement`|Não usado.|
|AFX_WM_ON_AFTER_SHELL_COMMAND|Enviado a um pai de `CMFCShellListCtrl` ou `CMFCShellTreeCtrl` controla quando um usuário conclui a execução de um comando de shell.|A ID do comando que o usuário executou|Não usado.|Se o aplicativo processa essa mensagem, ele deverá retornar zero.|
|AFX_WM_ON_BEFORE_SHOW_RIBBON_ITEM_MENU|O framework envia essa mensagem para o pai da faixa de opções antes de exibir o menu pop-up. Você pode processar essa mensagem e modificar os menus pop-up a qualquer momento.|Não usado.|Um ponteiro para `CMFCBaseRibbonElement`|Não usado.|
|AFX_WM_ON_CANCELTABMOVE|Somente para uso interno.|Não aplicável.|Não aplicável.||
|AFX_WM_ON_CHANGE_RIBBON_CATEGORY|O framework envia essa mensagem para o quadro principal quando o usuário altera a categoria de controle de faixa de opções ativa.|Não usado.|Um ponteiro para o `CMFCRibbonBar` cuja categoria foi alterado.|Não usado.|
|AFX_WM_ON_CLOSEPOPUPWINDOW|O framework envia essa mensagem para notificar o proprietário do `CMFCDesktopAlertWnd` que a janela está prestes a ser fechado.|Não usado.|Um ponteiro para `CMFCDesktopAlertWnd` objeto.|Não usado.|
|AFX_WM_ON_DRAGCOMPLETE|Somente para uso interno.|Não aplicável.|Não aplicável.|Não aplicável.|
|AFX_WM_ON_GET_TAB_TOOLTIP|Enviado para a janela do quadro principal quando uma janela de guia está prestes a exibir uma dica de ferramenta para uma guia, se as dicas de ferramenta personalizadas estiverem habilitadas.|Não usado.|Um ponteiro para um `CMFCTabToolTipInfo` estrutura.|Não usado.|
|AFX_WM_ON_HSCROLL|Enviado para o controle de barra de controle redimensionável. Processar essa mensagem para receber notificações de `CMFCTabCtrl` objetos quando ocorre um evento de rolagem na barra de rolagem horizontal de widget com guias.|A palavra de ordem inferior Especifica um valor de barra de rolagem que indica que o usuário da solicitação de rolagem.  Para obter mais informações, consulte a tabela posteriormente neste tópico.|Não usado.|Nonzero.|
|AFX_WM_ON_MOVE_TAB|Enviado para o pai de uma janela com guias quando um usuário arrasta uma guia para uma nova posição.|O índice baseado em zero da guia em sua posição original.|[out] O índice baseado em zero da guia em sua nova posição.|Zero.|
|AFX_WM_ON_MOVETABCOMPLETE|Somente para uso interno.|Não aplicável.|Não aplicável.|Não aplicável.|
|AFX_WM_ON_MOVETOTABGROUP|Enviado para a janela de quadro principal quando um usuário move uma janela filho MDI de um grupo com guias para outro.|Um identificador de janela com guias (`CMFCTabCtrl`) do qual a janela filho MDI foi removida.|[out] Um identificador de janela com guias (`CMFCTabCtrl`) para que a janela filho MDI foi inserida.|Ignorado.|
|AFX_WM_ON_PRESS_CLOSE_BUTTON|Enviado a um pai de `CDockablePane` quando o usuário clica o **fechar** botão na legenda da barra de controle.|Não usado.|Um ponteiro para um painel encaixável no qual o usuário clicou o **fechar** botão.|TRUE se um painel não pode ser fechado. Caso contrário, FALSE.|
|AFX_WM_ON_RENAME_TAB|Enviado para o pai da janela com guias depois que o usuário renomeado uma guia editável.|O índice baseado em zero da guia renomeado.|[out] Um ponteiro para uma cadeia de caracteres que contém o nome da nova guia.|Diferente de zero se o aplicativo processa essa mensagem; o framework irá suprimir a chamada para `CMFCBaseTabCtrl::SetTabLabel`.  Se zero for retornado, em seguida, `CMFCBaseTabCtrl::SetTabLabel` é chamado pelo framework.|
|AFX_WM_ON_RIBBON_CUSTOMIZE|Enviado para o quadro principal quando o usuário começa a personalização. Processe essa mensagem se você quiser exibir sua própria caixa de diálogo de personalização.|Não usado.|Um ponteiro para o controle de faixa de opções para ser personalizado.|Diferente de zero se o aplicativo processa essa mensagem e exibe sua própria caixa de diálogo de personalização. Se o aplicativo retornará zero, o framework exibirá a caixa de diálogo de personalização interna.|
|AFX_WM_ON_TABGROUPMOUSEMOVE|Somente para uso interno.|Não aplicável.|Não aplicável.|Não aplicável.|
|AFX_WM_POSTSETPREVIEWFRAME|Enviado para notificar o quadro principal que o usuário alterou o modo de visualização de impressão|TRUE indica que o modo de visualização de impressão está definido. FALSE indica que o modo de visualização de impressão está desativado.|Não usado.|Não usado.|
|AFX_WM_PROPERTY_CHANGED|Enviado para o proprietário do controle de grade de propriedade (`CMFCPropertyGridCtrl`) quando o usuário altera o valor da propriedade selecionada.|A ID de controle da lista de propriedades.|Um ponteiro para a propriedade (`CMFCPropertyGridProperty`) que foi alterada.|Não usado.|
|AFX_WM_RESETCONTEXTMENU|Enviado para a janela de quadro principal quando o usuário redefine o menu de contexto durante a personalização.|A ID de recurso do menu de contexto.|Um ponteiro para o menu de contexto atual, `CMFCPopupMenu`.|Não usado.|
|AFX_WM_RESETKEYBOARD|O framework envia essa mensagem para a janela do quadro principal quando o usuário redefine todos os aceleradores de teclado durante a personalização.|Não usado.|Não usado.|Não usado.|
|AFX_WM_RESETMENU|O framework envia essa mensagem para o proprietário do menu (uma janela de quadro) quando o usuário redefine a um menu de quadro do aplicativo durante a personalização|A ID do recurso de menu.|Não usado.|Não usado.|
|AFX_WM_RESETPROMPT|O framework envia essa mensagem quando a caixa de diálogo de personalizar as redefinições de usuário, uma barra de ferramentas da barra de ferramentas. O manipulador padrão exibe uma caixa de mensagem que pergunta se o usuário deseja redefinir barra de ferramentas.|Não usado.|Não usado.|Não usado.|
|AFX_WM_RESETTOOLBAR|Um `CMFCToolBar` objeto envia essa mensagem quando uma barra de ferramentas é restaurada ao estado original, ou seja, carregados a partir de recursos. Processar essa mensagem para inserir novamente os botões de barra de ferramentas cujas classes são derivadas de `CMFCToolbarButton`. Para obter mais informações, consulte `CMFCToolbarComboBoxButton`.|A ID de recurso de uma barra de ferramentas cujo estado foi restaurado.|Não usado.|Zero.|
|AFX_WM_SHOWREGULARMENU|`CMFCToolbarMenuButton` objeto envia essa mensagem para o seu proprietário quando o usuário clica em um botão de menu comum. Processar essa mensagem sempre que você use `CMFCToolbarMenuButton` para exibir um menu pop-up quando o usuário clica em um botão.|A ID de comando de um botão que envia a mensagem.|Coordenadas da tela do cursor. A palavra de ordem inferior Especifica a coordenada x. A palavra de ordem superior Especifica a coordenada y.|Não usado.|
|AFX_WM_TOOLBARMENU|Enviado para a janela de quadro principal quando o usuário libera o botão direito do mouse enquanto o ponteiro do mouse está no cliente ou a área não cliente de um painel.|Não usado.|Coordenadas da tela do ponteiro do mouse. A palavra de ordem inferior Especifica a coordenada x. A palavra de ordem superior Especifica a coordenada y.|Zero se o aplicativo processa essa mensagem; Caso contrário, diferente de zero.|
|AFX_WM_UPDATETOOLTIPS|Enviado a todos os proprietários de dica de ferramenta para indicar que os seus controles de dica de ferramenta devem ser recriadas.|O tipo de controle que deve processar essa mensagem. Consulte a tabela neste tópico para obter uma lista de valores possíveis.|Não usado.|Não usado.|
|AFX_WM_WINDOW_HELP|`CMFCWindowsManagerDialog` envia essa mensagem para o quadro pai quando o usuário clica o **ajudar** botão ou entra no modo de Ajuda clicando o **ajudar** botão de legenda ou a tecla F1.|Não usado.|Um ponteiro para a instância do `CMFCWindowsManagerDialog`.|Não usado.|

A tabela a seguir mostra os valores para a palavra inferior do *lParam* parâmetro do método AFX_WM_HSCROLL:

|||
|-|-|
|Valor|Significado|
|SB_ENDSCROLL|O usuário encerra a rolagem.|
|SB_LEFT|O usuário rolar até o canto superior esquerdo.|
|SB_RIGHT|O usuário rolar até o canto inferior direito.|
|SB_LINELEFT|O usuário rola para a esquerda em uma unidade.|
|SB_LINERIGHT|O usuário rola para a direita em uma unidade.|
|SB_PAGELEFT|O usuário rola à esquerda pela largura da janela.|
|SB_PAGERIGHT|O usuário rola a largura da janela à direita.|
|SB_THUMBPOSITION|O usuário arrastar a caixa de rolagem (thumb) e lançado o botão do mouse. A palavra de ordem superior indica a posição da caixa de rolagem no final da operação de arrastar.|
|SB_THUMBTRACK|O usuário está arrastando a caixa de rolagem. A mensagem AFX_WM_ON_HSCROLL é enviada repetidamente com esse valor até que o usuário libera o botão do mouse. A palavra de ordem superior indica a posição aos quais foi arrastada da caixa de rolagem.|

> [!NOTE]
>  A palavra de ordem alta a *lParam* parâmetro especifica a posição atual da caixa de rolagem, se a palavra de ordem inferior é SB_THUMBPOSITION ou SB_THUMBTRACK; caso contrário, essa palavra não é usada.

A tabela a seguir lista os valores de sinalizador para o *lParam* parâmetro da mensagem AFX_WM_UPDATETOOLTIPS:

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
|AFX_TOOLTIP_TYPE_ALL|0xFFFF|

## <a name="see-also"></a>Consulte também

[Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)
