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
ms.openlocfilehash: 79cd4fc572e55c67cc5a2cfe3a00e04f2a4a7850
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81364683"
---
# <a name="mfc-activex-controls-adding-stock-events-to-an-activex-control"></a>Controles ActiveX MFC: adicionando eventos de estoque a um controle ActiveX

Os eventos de ações diferem dos eventos personalizados, pois são automaticamente disparados pela classe [COleControl](../mfc/reference/colecontrol-class.md). `COleControl`contém funções de membros predefinidas que disparam eventos resultantes de ações comuns. Algumas ações comuns implementadas incluem `COleControl` cliques únicos e duplos no controle, eventos de teclado e alterações no estado dos botões do mouse. As entradas do mapa de eventos para eventos de ações são sempre precedidas pelo prefixo EVENT_STOCK.

## <a name="stock-events-supported-by-the-add-event-wizard"></a><a name="_core_stock_events_supported_by_classwizard"></a>Eventos de ações suportados pelo Assistente de Eventos adicionar

A `COleControl` classe fornece dez eventos de ações, listados na tabela a seguir. Você pode especificar os eventos que deseja em seu controle usando o [Assistente de Adicionar eventos](../ide/add-event-wizard.md).

### <a name="stock-events"></a>Eventos de Ações

|Evento|Função de disparo|Comentários|
|-----------|---------------------|--------------|
|Clique em |**void FireClick( )**|Acionado quando o controle captura o mouse, qualquer mensagem **BUTTONUP** (esquerda, média ou direita) é recebida e o botão é liberado sobre o controle. Os eventos mousedown e mouseup de estoque ocorrem antes deste evento.<br /><br /> Entrada no mapa do evento: **EVENT_STOCK_CLICK( )**|
|DblClick|**vazio FireDblClick( )**|Semelhante ao Click, mas acionado quando uma mensagem **BUTTONDBLCLK** é recebida.<br /><br /> Entrada no mapa do evento: **EVENT_STOCK_DBLCLICK( )**|
|Erro|**void FireError (Código SCODE,***scode* **LPCSTR,** `lpszDescription` **UINT**`nHelpID`= 0 **)**        |Acionado quando ocorre um erro dentro do controle ActiveX fora do escopo de uma chamada de método ou acesso à propriedade.<br /><br /> Entrada no mapa do evento: **EVENT_STOCK_ERROREVENT( )**|
|KeyDown|**vazio FireKeyDown (curto,** `nChar` **curto**`nShiftState`**)**      |Demitido quando `WM_SYSKEYDOWN` `WM_KEYDOWN` uma ou mensagem é recebida.<br /><br /> Entrada no mapa do evento: **EVENT_STOCK_KEYDOWN( )**|
|Keypress|**vazio FireKeyPress (curto)** <strong>\*</strong> `pnChar` **)**    |Demitido quando `WM_CHAR` uma mensagem é recebida.<br /><br /> Entrada no mapa do evento: **EVENT_STOCK_KEYPRESS.**|
|KeyUp|**void FireKeyUp (curto,** `nChar` **curto**`nShiftState`**)**      |Demitido quando `WM_SYSKEYUP` `WM_KEYUP` uma ou mensagem é recebida.<br /><br /> Entrada no mapa do evento: **EVENT_STOCK_KEYUP.**|
|Mousedown|**void FireMouseDown (curto,** `nButton` **curto,** `nShiftState` **flutuante***x,* **flutuar***y***)**          |Demitido se algum **BUTTONDOWN** (esquerdo, médio ou direito) for recebido. O rato é capturado imediatamente antes deste evento ser disparado.<br /><br /> Entrada no mapa do evento: **EVENT_STOCK_MOUSEDOWN**|
|Mousemove|**void FireMouseMove (curto,** `nButton` **curto,** `nShiftState` **flutuante***x,* **flutuar***y***)**          |Demitido quando uma mensagem WM_MOUSEMOVE é recebida.<br /><br /> Entrada no mapa do evento: **EVENT_STOCK_MOUSEMOVE.**|
|Mouseup|**void FireMouseUp (curto,** `nButton` **curto,** `nShiftState` **flutuante***x,* **flutuar***y***)**          |Demitido se algum **BUTTONUP** (esquerdo, médio ou direito) for recebido. A captura do mouse é liberada antes que este evento seja disparado.<br /><br /> Entrada no mapa do evento: **EVENT_STOCK_MOUSEUP( )**|
|ReadyStateChange|**anular FireReadyStateChange( )**|Acionado quando um controle passa para o próximo estado pronto devido à quantidade de dados recebidos.<br /><br /> Entrada no mapa do evento: **EVENT_STOCK_READYSTATECHANGE**|

## <a name="adding-a-stock-event-using-the-add-event-wizard"></a><a name="_core_adding_a_stock_event_using_classwizard"></a>Adicionando um evento de estoque usando o assistente de evento adicionar

Adicionar eventos de estoque requer menos trabalho do que adicionar eventos personalizados porque `COleControl`a demissão do evento real é tratada automaticamente pela classe base, . O procedimento a seguir adiciona um evento de estoque a um controle que foi desenvolvido usando [o MFC ActiveX Control Wizard](../mfc/reference/mfc-activex-control-wizard.md). O evento, chamado KeyPress, é acionado quando uma tecla é pressionada e o controle está ativo. Este procedimento também pode ser usado para adicionar outros eventos de estoque. Substitua o nome do evento de ações selecionado por KeyPress.

#### <a name="to-add-the-keypress-stock-event-using-the-add-event-wizard"></a>Para adicionar o evento de estoque keypress usando o Assistente de Adicionar Eventos

1. Carregue o projeto do seu controle.

1. Na exibição de classe, clique com o botão direito do mouse na classe de controle ActiveX para abrir o menu de atalho.

1. No menu de atalho, clique **em Adicionar** e clique em **Adicionar evento**.

   Isso abre o Assistente de Adicionar Eventos.

1. Na lista de isto nome `KeyPress`do **evento,** selecione .

1. Clique em **Concluir**.

## <a name="add-event-wizard-changes-for-stock-events"></a><a name="_core_classwizard_changes_for_stock_events"></a>Adicionar alterações do assistente de eventos para eventos de estoque

Como os eventos de estoque são tratados pela classe base do controle, o Assistente de Adicionar Evento não altera sua declaração de classe de forma alguma. Ele adiciona o evento ao mapa de eventos do controle e faz uma entrada em seu . Arquivo IDL. A linha a seguir é adicionada ao mapa de eventos do controle, localizado na implementação da classe de controle (. Arquivo CPP):

[!code-cpp[NVC_MFC_AxUI#5](../mfc/codesnippet/cpp/mfc-activex-controls-adding-stock-events-to-an-activex-control_1.cpp)]

A adição deste código é acionada a um evento KeyPress quando uma mensagem WM_CHAR é recebida e o controle está ativo. O evento KeyPress pode ser acionado em outras ocasiões chamando sua função de disparo (por exemplo, `FireKeyPress`) de dentro do código de controle.

O Assistente de Evento adicionar adiciona a seguinte linha de código ao controle . Arquivo IDL:

[!code-cpp[NVC_MFC_AxUI#6](../mfc/codesnippet/cpp/mfc-activex-controls-adding-stock-events-to-an-activex-control_2.idl)]

Esta linha associa o evento KeyPress com seu ID de despacho padrão e permite que o contêiner antecipe o evento KeyPress.

## <a name="see-also"></a>Confira também

[Controles ActiveX do MFC](../mfc/mfc-activex-controls.md)<br/>
[Controles ActiveX do MFC: métodos](../mfc/mfc-activex-controls-methods.md)<br/>
[Classe COleControl](../mfc/reference/colecontrol-class.md)
