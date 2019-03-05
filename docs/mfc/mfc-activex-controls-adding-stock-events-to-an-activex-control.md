---
title: 'Controles ActiveX MFC: Adicionando eventos de estoque a um controle ActiveX'
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
ms.openlocfilehash: 9f6f3c63f0436296791df428c704bce96eca3ec0
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57291113"
---
# <a name="mfc-activex-controls-adding-stock-events-to-an-activex-control"></a>Controles ActiveX MFC: Adicionando eventos de estoque a um controle ActiveX

Eventos de estoque são diferentes de eventos personalizados que são disparados automaticamente pela classe [COleControl](../mfc/reference/colecontrol-class.md). `COleControl` contém funções de membro predefinidas que acionam eventos resultantes de ações comuns. Algumas ações comuns implementadas pelo `COleControl` incluem único - e duplo - clicks no controle, eventos de teclado e as alterações no estado dos botões do mouse. Entradas de ação eventos sempre são precedidos pelo prefixo EVENT_STOCK de mapa de evento.

##  <a name="_core_stock_events_supported_by_classwizard"></a> Eventos com suporte de estoque a adicionar Assistente de evento

O `COleControl` classe fornece eventos de estoque dez, listados na tabela a seguir. Você pode especificar os eventos desejados em seu controle usando o [Adicionar Assistente de eventos](../ide/add-event-wizard.md).

### <a name="stock-events"></a>Eventos de estoque

|evento|Função acionando|Comentários|
|-----------|---------------------|--------------|
|Clique em|**void (FireClick)**|Acionado quando o controle captura o mouse, qualquer **BUTTONUP** (à esquerda, meio ou à direita) é recebida, e o botão é liberado sobre o controle. O estoque MouseDown e MouseUp eventos ocorrerem antes desse evento.<br /><br /> Entrada de mapa de evento: **EVENT_STOCK_CLICK( )**|
|DblClick|**void FireDblClick( )**|Semelhante a clique, mas disparado quando um **BUTTONDBLCLK** mensagem é recebida.<br /><br /> Entrada de mapa de evento: **EVENT_STOCK_DBLCLICK( )**|
|Erro|**void FireError( SCODE**  *scode* **, LPCSTR**  `lpszDescription` **, UINT**  `nHelpID`  **= 0 )**|Acionado quando ocorre um erro em seu controle ActiveX fora do escopo de um acesso de propriedade ou chamada de método.<br /><br /> Entrada de mapa de evento: **EVENT_STOCK_ERROREVENT( )**|
|KeyDown|**void FireKeyDown( short**  `nChar` **, short**  `nShiftState`  **)**|Acionado quando um `WM_SYSKEYDOWN` ou `WM_KEYDOWN` mensagem é recebida.<br /><br /> Entrada de mapa de evento: **EVENT_STOCK_KEYDOWN( )**|
|KeyPress|**void FireKeyPress( short** <strong>\*</strong>  `pnChar`  **)**|Acionado quando um `WM_CHAR` mensagem é recebida.<br /><br /> Entrada de mapa de evento: **EVENT_STOCK_KEYPRESS( )**|
|KeyUp|**void FireKeyUp( short**  `nChar` **, short**  `nShiftState`  **)**|Acionado quando um `WM_SYSKEYUP` ou `WM_KEYUP` mensagem é recebida.<br /><br /> Entrada de mapa de evento: **EVENT_STOCK_KEYUP( )**|
|MouseDown|**void FireMouseDown( short**  `nButton` **, short**  `nShiftState` **, float**  *x* **, float**  *y*  **)**|Acionado se houver **é** (esquerda, no meio ou à direita) é recebida. O mouse é capturado imediatamente antes que este evento é disparado.<br /><br /> Entrada de mapa de evento: **EVENT_STOCK_MOUSEDOWN( )**|
|MouseMove|**void FireMouseMove( short**  `nButton` **, short**  `nShiftState` **, float**  *x* **, float**  *y*  **)**|Acionado quando uma mensagem WM_MOUSEMOVE é recebida.<br /><br /> Entrada de mapa de evento: **EVENT_STOCK_MOUSEMOVE( )**|
|MouseUp|**void FireMouseUp( short**  `nButton` **, short**  `nShiftState` **, float**  *x* **, float**  *y*  **)**|Acionado se houver **BUTTONUP** (esquerda, no meio ou à direita) é recebida. A captura do mouse é liberada antes que esse evento é acionado.<br /><br /> Entrada de mapa de evento: **EVENT_STOCK_MOUSEUP( )**|
|ReadyStateChange|**void FireReadyStateChange( )**|Acionado quando um controle fizer a transição para o próximo estado pronto devido à quantidade de dados recebidos.<br /><br /> Entrada de mapa de evento: **EVENT_STOCK_READYSTATECHANGE( )**|

##  <a name="_core_adding_a_stock_event_using_classwizard"></a> Adicionar um evento de ação usando o Assistente de eventos para adicionar

Adicionando eventos de estoque exige menos trabalhoso do que adicionando eventos personalizados, porque o acionamento do evento real é manipulado automaticamente pela classe base, `COleControl`. O procedimento a seguir adiciona um evento de estoque a um controle que foi desenvolvido usando [Assistente de controle ActiveX MFC](../mfc/reference/mfc-activex-control-wizard.md). O evento, chamado KeyPress é acionado quando uma tecla é pressionada e o controle está ativo. Esse procedimento também pode ser usado para adicionar outros eventos de estoque. Substitua o nome do evento de ação selecionado para o pressionamento de tecla.

#### <a name="to-add-the-keypress-stock-event-using-the-add-event-wizard"></a>Para adicionar o evento de pressionamento de tecla ações usando o Assistente para adicionar evento

1. Carregar o projeto do seu controle.

1. No modo de exibição de classe, clique com botão direito sua classe de controle ActiveX para abrir o menu de atalho.

1. No menu de atalho, clique em **Add** e, em seguida, clique em **Adicionar evento**.

   Isso abre o Assistente para adicionar eventos.

1. No **nome do evento** lista suspensa, selecione `KeyPress`.

1. Clique em **Finalizar**.

##  <a name="_core_classwizard_changes_for_stock_events"></a> Adicionar Assistente altera o evento para eventos de estoque

Como eventos de estoque são tratados pela classe base do controle, o Assistente para adicionar eventos não altera sua declaração de classe de forma alguma. Ele adiciona o evento ao mapa de evento do controle e faz com que uma entrada no seu. Arquivo IDL. A linha a seguir é adicionada ao mapa de evento do controle, localizado na implementação de classe do controle (. Arquivo CPP):

[!code-cpp[NVC_MFC_AxUI#5](../mfc/codesnippet/cpp/mfc-activex-controls-adding-stock-events-to-an-activex-control_1.cpp)]

Adicionando este código dispara um evento KeyPress quando for recebida uma mensagem WM_CHAR e o controle está ativo. O evento KeyPress pode ser acionado em outros momentos, por sua função de acionamento de chamada (por exemplo, `FireKeyPress`) de dentro do código de controle.

O Assistente para adicionar evento adiciona a seguinte linha de código para o controle. Arquivo IDL:

[!code-cpp[NVC_MFC_AxUI#6](../mfc/codesnippet/cpp/mfc-activex-controls-adding-stock-events-to-an-activex-control_2.idl)]

Esta linha associa o evento KeyPress com sua ID de expedição padrão e permite que o contêiner prever o evento KeyPress.

## <a name="see-also"></a>Consulte também

[Controles ActiveX do MFC](../mfc/mfc-activex-controls.md)<br/>
[Controles ActiveX MFC: Métodos](../mfc/mfc-activex-controls-methods.md)<br/>
[Classe COleControl](../mfc/reference/colecontrol-class.md)
