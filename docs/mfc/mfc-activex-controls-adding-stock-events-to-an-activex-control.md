---
title: 'Controles ActiveX MFC: adicionando eventos de estoque a um controle ActiveX'
ms.date: 11/04/2016
f1_keywords:
- EVENT__STOCK_ERROR
- EVENT__STOCK_READYSTATECHANGE
- ReadyStateChange
- EVENT__STOCK_MOUSEMOVE
- EVENT__STOCK_MOUSEUP
- EVENT__STOCK_DBLCLICK
- KeyPress
- EVENT__STOCK_KEYDOWN
- EVENT__STOCK
- EVENT__STOCK_MOUSEDOWN
- EVENT__STOCK_KEYPRESS
- EVENT__STOCK_CLICK
- EVENT__STOCK_KEYUP
helpviewer_keywords:
- MFC ActiveX controls [MFC], events
- KeyPress event
- FireDblClick event
- FireMouseDown event
- events [MFC], stock
- FireKeyPress event
- EVENT_STOCK_MOUSEMOVE event
- EVENT_STOCK_CLICK event
- FireClick event
- FireKeyUp event
- FireMouseUp event
- EVENT_STOCK_ERROREVENT event
- EVENT_STOCK_KEYDOWN event
- EVENT_STOCK_MOUSEDOWN event
- EVENT_STOCK_KEYPRESS macro [MFC]
- EVENT_STOCK_KEYUP event
- EVENT_STOCK_DBLCLICK event
- FireError event
- FireKeyDown event
- ReadyStateChange event
- EVENT_STOCK_MOUSEUP event
- FireMouseMove event
- EVENT_STOCK prefix
- EVENT_STOCK_READYSTATECHANGE event
- EVENT_STOCK_KEYPRESS event
ms.assetid: 3eeadc67-4b3d-4444-8caa-53054073988a
ms.openlocfilehash: a97c08baaf3c11b0436e52bb4fd4ac380999d69a
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84615600"
---
# <a name="mfc-activex-controls-adding-stock-events-to-an-activex-control"></a>Controles ActiveX MFC: adicionando eventos de estoque a um controle ActiveX

Os eventos de ações diferem dos eventos personalizados, pois são automaticamente disparados pela classe [COleControl](reference/colecontrol-class.md). `COleControl`contém funções de membro predefinidas que acionam eventos resultantes de ações comuns. Algumas ações comuns implementadas por `COleControl` incluem cliques únicos e duplos no controle, eventos de teclado e alterações no estado dos botões do mouse. As entradas de mapa de eventos para eventos de ações são sempre precedidas pelo prefixo EVENT_STOCK.

## <a name="stock-events-supported-by-the-add-event-wizard"></a><a name="_core_stock_events_supported_by_classwizard"></a>Eventos de estoque com suporte pelo Assistente para adicionar evento

A `COleControl` classe fornece dez eventos de estoque, listados na tabela a seguir. Você pode especificar os eventos que deseja no seu controle usando o [Assistente para adicionar evento](../ide/add-event-wizard.md).

### <a name="stock-events"></a>Eventos de estoque

|Evento|Acionando função|Comentários|
|-----------|---------------------|--------------|
|Clique em |**void FireClick ()**|Acionado quando o controle captura o mouse, qualquer mensagem **BUTTONUP** (esquerda, intermediária ou direita) é recebida e o botão é liberado sobre o controle. Os eventos MouseDown e MouseUp de estoque ocorrem antes desse evento.<br /><br /> Entrada do mapa de eventos: **EVENT_STOCK_CLICK ()**|
|DblClick|**void FireDblClick ()**|Semelhante a Click, mas acionado quando uma mensagem **BUTTONDBLCLK** é recebida.<br /><br /> Entrada do mapa de eventos: **EVENT_STOCK_DBLCLICK ()**|
|Erro do|**void FireError (SCODE***SCODE* **, LPCSTR** `lpszDescription` **, uint** `nHelpID` **= 0)**        |Acionado quando ocorre um erro dentro do controle ActiveX fora do escopo de uma chamada de método ou de um acesso de propriedade.<br /><br /> Entrada do mapa de eventos: **EVENT_STOCK_ERROREVENT ()**|
|KeyDown|**void FireKeyDown (curto** `nChar` **, curto** `nShiftState` **)**      |Acionado quando `WM_SYSKEYDOWN` uma `WM_KEYDOWN` mensagem ou é recebida.<br /><br /> Entrada do mapa de eventos: **EVENT_STOCK_KEYDOWN ()**|
|Pressionar|**void FireKeyPress (curto** <strong>\*</strong> `pnChar` **)**    |Acionado quando uma `WM_CHAR` mensagem é recebida.<br /><br /> Entrada do mapa de eventos: **EVENT_STOCK_KEYPRESS ()**|
|KeyUp|**void FireKeyUp (curto** `nChar` **, curto** `nShiftState` **)**      |Acionado quando `WM_SYSKEYUP` uma `WM_KEYUP` mensagem ou é recebida.<br /><br /> Entrada do mapa de eventos: **EVENT_STOCK_KEYUP ()**|
|MouseDown|**void FireMouseDown (curto** `nButton` **, curto** `nShiftState` **, float***x* **, float***y***)**          |Acionado se qualquer **PreviewMouseLeftButtonDown** (esquerda, intermediária ou direita) for recebida. O mouse é capturado imediatamente antes que esse evento seja acionado.<br /><br /> Entrada do mapa de eventos: **EVENT_STOCK_MOUSEDOWN ()**|
|Ocorra|**void FireMouseMove (curto** `nButton` **, curto** `nShiftState` **, float***x* **, float***y***)**          |Acionado quando uma mensagem de WM_MOUSEMOVE é recebida.<br /><br /> Entrada do mapa de eventos: **EVENT_STOCK_MOUSEMOVE ()**|
|MouseUp|**void FireMouseUp (curto** `nButton` **, curto** `nShiftState` **, float***x* **, float***y***)**          |Acionado se qualquer **BUTTONUP** (esquerda, intermediária ou direita) for recebida. A captura do mouse é liberada antes que esse evento seja acionado.<br /><br /> Entrada do mapa de eventos: **EVENT_STOCK_MOUSEUP ()**|
|ReadyStateChange|**void FireReadyStateChange ()**|Acionado quando um controle faz a transição para o próximo estado pronto devido à quantidade de dados recebidos.<br /><br /> Entrada do mapa de eventos: **EVENT_STOCK_READYSTATECHANGE ()**|

## <a name="adding-a-stock-event-using-the-add-event-wizard"></a><a name="_core_adding_a_stock_event_using_classwizard"></a>Adicionando um evento de ações usando o assistente para adicionar eventos

A adição de eventos de estoque requer menos trabalho do que adicionar eventos personalizados, pois o acionamento do evento real é manipulado automaticamente pela classe base, `COleControl` . O procedimento a seguir adiciona um evento de ação a um controle que foi desenvolvido usando o [Assistente de controle ActiveX do MFC](reference/mfc-activex-control-wizard.md). O evento, chamado KeyPress, é acionado quando uma tecla é pressionada e o controle está ativo. Esse procedimento também pode ser usado para adicionar outros eventos de estoque. Substitua o nome do evento de ações selecionado por KeyPress.

#### <a name="to-add-the-keypress-stock-event-using-the-add-event-wizard"></a>Para adicionar o evento de ação de pressionamento de tecla usando o assistente para adicionar evento

1. Carregue o projeto do seu controle.

1. Em Modo de Exibição de Classe, clique com o botão direito do mouse em sua classe de controle ActiveX para abrir o menu de atalho.

1. No menu de atalho, clique em **Adicionar** e em **Adicionar evento**.

   Isso abre o assistente para adicionar evento.

1. Na lista suspensa **nome do evento** , selecione `KeyPress` .

1. Clique em **Concluir**.

## <a name="add-event-wizard-changes-for-stock-events"></a><a name="_core_classwizard_changes_for_stock_events"></a>Adicionar alterações do assistente de evento para eventos de estoque

Como os eventos de ações são tratados pela classe base do controle, o assistente para adicionar eventos não altera sua declaração de classe de nenhuma forma. Ele adiciona o evento ao mapa de eventos do controle e faz uma entrada em seu. Arquivo IDL. A linha a seguir é adicionada ao mapa de eventos do controle, localizado na implementação da classe de controle (. CPP) arquivo:

[!code-cpp[NVC_MFC_AxUI#5](codesnippet/cpp/mfc-activex-controls-adding-stock-events-to-an-activex-control_1.cpp)]

A adição desse código dispara um evento KeyPress quando uma mensagem WM_CHAR é recebida e o controle está ativo. O evento KeyPress pode ser acionado em outros momentos chamando a função de acionamento (por exemplo, `FireKeyPress` ) de dentro do código de controle.

O assistente para adicionar evento adiciona a linha de código a seguir ao controle. Arquivo IDL:

[!code-cpp[NVC_MFC_AxUI#6](codesnippet/cpp/mfc-activex-controls-adding-stock-events-to-an-activex-control_2.idl)]

Essa linha associa o evento KeyPress à sua ID de expedição padrão e permite que o contêiner antecipe o evento KeyPress.

## <a name="see-also"></a>Confira também

[Controles ActiveX do MFC](mfc-activex-controls.md)<br/>
[Controles ActiveX do MFC: métodos](mfc-activex-controls-methods.md)<br/>
[Classe COleControl](reference/colecontrol-class.md)
