---
title: 'Controles ActiveX MFC: Adicionando eventos de estoque a um controle ActiveX | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
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
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 210749906391ccdba2e488b75be98264bcba39cd
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33359332"
---
# <a name="mfc-activex-controls-adding-stock-events-to-an-activex-control"></a>Controles ActiveX MFC: adicionando eventos de estoque a um controle ActiveX
Eventos de estoque são diferentes de eventos personalizados que são disparados automaticamente pela classe [COleControl](../mfc/reference/colecontrol-class.md). `COleControl` contém funções de membro predefinidas que acionam eventos resultante de ações comuns. Algumas ações comuns implementadas pelo `COleControl` incluem único - e duplo - clicks o controle, os eventos de teclado, e as alterações no estado dos botões do mouse. Entradas de mapa de eventos para eventos de estoque sempre são precedidas pelo **EVENT_STOCK** prefixo.  
  
##  <a name="_core_stock_events_supported_by_classwizard"></a> Eventos com suporte de estoque a adicionar Assistente de eventos  
 O `COleControl` classe fornece dez eventos de estoque, listados na tabela a seguir. Você pode especificar os eventos que você deseja em seu controle usando o [Adicionar Assistente de eventos](../ide/add-event-wizard.md).  
  
### <a name="stock-events"></a>Eventos de estoque  
  
|evento|Função acionando|Comentários|  
|-----------|---------------------|--------------|  
|Clique em|**void (FireClick)**|Acionado quando o controle captura o mouse, qualquer **BUTTONUP** (esquerda, central ou direita) é recebida, e o botão é liberado sobre o controle. O estoque MouseDown e MouseUp eventos ocorrerem antes desse evento.<br /><br /> Entrada de mapa de evento: **(EVENT_STOCK_CLICK)**|  
|DblClick|**void (FireDblClick)**|Semelhante ao clique mas acionado quando um **BUTTONDBLCLK** mensagem é recebida.<br /><br /> Entrada de mapa de evento: **(EVENT_STOCK_DBLCLICK)**|  
|Erro|**void FireError (SCODE***scode* **, LPCSTR** `lpszDescription` **, UINT**`nHelpID`**= 0)** |Acionado quando ocorre um erro dentro de seu controle ActiveX fora do escopo de um acesso de propriedade ou chamada de método.<br /><br /> Entrada de mapa de evento: **(EVENT_STOCK_ERROREVENT)**|  
|KeyDown|**void FireKeyDown (curto** `nChar` **curta**`nShiftState`**)** |Acionado quando um `WM_SYSKEYDOWN` ou `WM_KEYDOWN` é recebida.<br /><br /> Entrada de mapa de evento: **(EVENT_STOCK_KEYDOWN)**|  
|KeyPress|**void FireKeyPress (curto\***`pnChar`**)** |Acionado quando um `WM_CHAR` mensagem é recebida.<br /><br /> Entrada de mapa de evento: **(EVENT_STOCK_KEYPRESS)**|  
|KeyUp|**void FireKeyUp (curto** `nChar` **curta**`nShiftState`**)** |Acionado quando um `WM_SYSKEYUP` ou `WM_KEYUP` é recebida.<br /><br /> Entrada de mapa de evento: **(EVENT_STOCK_KEYUP)**|  
|MouseDown|**void FireMouseDown (curto** `nButton` **curta** `nShiftState` **, float***x* **, float** *y***)** |Acionado se houver **é** (esquerda, meio ou direita) é recebida. O mouse é capturado imediatamente antes desse evento é acionado.<br /><br /> Entrada de mapa de evento: **(EVENT_STOCK_MOUSEDOWN)**|  
|MouseMove|**void FireMouseMove (curto** `nButton` **curta** `nShiftState` **, float***x* **, float** *y***)** |Acionado quando um `WM_MOUSEMOVE` mensagem é recebida.<br /><br /> Entrada de mapa de evento: **(EVENT_STOCK_MOUSEMOVE)**|  
|MouseUp|**void FireMouseUp (curto** `nButton` **curta** `nShiftState` **, float***x* **, float** *y***)** |Acionado se houver **BUTTONUP** (esquerda, meio ou direita) é recebida. A captura do mouse é liberada antes que esse evento é acionado.<br /><br /> Entrada de mapa de evento: **(EVENT_STOCK_MOUSEUP)**|  
|ReadyStateChange|**void (FireReadyStateChange)**|Acionado quando um transições de controle para o próximo estado pronto devido à quantidade de dados recebidos.<br /><br /> Entrada de mapa de evento: **(EVENT_STOCK_READYSTATECHANGE)**|  
  
##  <a name="_core_adding_a_stock_event_using_classwizard"></a> Adicionar um evento de ação usando o Assistente de eventos  
 Adicionando eventos de estoque requer menos trabalho que adicionando eventos personalizados, como o acionamento do evento real é tratado automaticamente pela classe base, `COleControl`. O procedimento a seguir adiciona um evento de estoque a um controle que foi desenvolvido usando [Assistente de controle ActiveX MFC](../mfc/reference/mfc-activex-control-wizard.md). O evento KeyPress de chamada é acionado quando uma tecla é pressionada e o controle está ativo. Esse procedimento também pode ser usado para adicionar outros eventos de estoque. Substitua o nome do evento selecionado de estoque para pressionamento de tecla.  
  
#### <a name="to-add-the-keypress-stock-event-using-the-add-event-wizard"></a>Para adicionar o evento de pressionamento de tecla ações usando o Assistente para adicionar eventos  
  
1.  Carregar projeto do controle.  
  
2.  No modo de exibição de classe, clique em sua classe de controle ActiveX para abrir o menu de atalho.  
  
3.  No menu de atalho, clique em **adicionar** e, em seguida, clique em **Adicionar evento**.  
  
     Isso abre o Assistente para adicionar eventos.  
  
4.  No **nome do evento** lista suspensa, selecione `KeyPress`.  
  
5.  Clique em **Finalizar**.  
  
##  <a name="_core_classwizard_changes_for_stock_events"></a> Adicionar Assistente altera o evento para eventos de estoque  
 Como eventos de estoque são tratados pela classe base do controle, o Assistente para adicionar eventos altere sua declaração de classe de qualquer forma. Ele adiciona o evento ao mapa de evento de controle e faz com que uma entrada no seu. Arquivo IDL. A seguinte linha é adicionada ao mapa de evento do controle, localizado na implementação de classe de controle (. Arquivo CPP):  
  
 [!code-cpp[NVC_MFC_AxUI#5](../mfc/codesnippet/cpp/mfc-activex-controls-adding-stock-events-to-an-activex-control_1.cpp)]  
  
 Adicionar este código dispara um evento KeyPress quando um `WM_CHAR` mensagem é recebida e o controle está ativo. O evento KeyPress pode ser acionado em outros momentos, chamando a função de acionamento (por exemplo, `FireKeyPress`) de dentro do código de controle.  
  
 O Assistente para adicionar eventos adiciona a seguinte linha de código para o controle. Arquivo IDL:  
  
 [!code-cpp[NVC_MFC_AxUI#6](../mfc/codesnippet/cpp/mfc-activex-controls-adding-stock-events-to-an-activex-control_2.idl)]  
  
 Essa linha associa o evento KeyPress com sua ID de distribuição padrão e permite que o contêiner prever o evento KeyPress.  
  
## <a name="see-also"></a>Consulte também  
 [Controles ActiveX MFC](../mfc/mfc-activex-controls.md)   
 [Controles ActiveX MFC: métodos](../mfc/mfc-activex-controls-methods.md)   
 [Classe COleControl](../mfc/reference/colecontrol-class.md)
